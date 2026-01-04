


#include <QApplication>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QDebug>
#include "RestfulServer.h"
#include "rapidjson/document.h"
#include "basic/FZZBytes.h"


#define CORSSTRING  "Access-Control-Allow-Origin: *\r\nAccess-Control-Allow-Methods: GET, POST, OPTIONS\r\nAccess-Control-Allow-Headers: Content-Type\r\n"


//static const char *s_root_dir = "/Users/zizhengfan/work/cpp/ofd/QTProjects/build-webext-Qt_6_3_1_for_macOS-Debug/webapp/";
QString g_Server_Url = "http://www.fzz.com:8080/server";
QString g_root_dir = "";
QByteArray g_root_dir_Byte;

#define CUTIMAGECOUNT 20

#define OFD_SCALE 10
#define PDF_SCALE 5

OFDPDFSignerProxy g_OFDPDFSignerProxy;
QList<QString> g_SystemFontFiles;

const char *s_http_addr = "http://0.0.0.0:7655";
int timeout = 1000*60*4;
//int timeout = 1000;

string decodeURIComponent(string keyWord) {
    char * temKeyWord = NULL;
    string retstr = "";
    temKeyWord = (char *)malloc(keyWord.length()+1);
    if ( temKeyWord == NULL ) {
        return retstr;
    }

    memset(temKeyWord,0x00,keyWord.length()+1);

    mg_url_decode(keyWord.c_str(),keyWord.length(),temKeyWord,keyWord.length(),0);

    retstr = temKeyWord;
    if ( temKeyWord != NULL ) {
        free(temKeyWord);
        temKeyWord = NULL;
    }
    return retstr;
}
//-----------------------------------------------------------------------------------------------------------------
/***********************************************RestfulServer**************************************************************/
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
void process(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{

    if (ev == MG_EV_HTTP_MSG) {
        struct mg_http_message *hm = (struct mg_http_message *) ev_data;
        if (mg_http_match_uri(hm, "/api/stats")) {
            // Print some statistics about currently established connections
            mg_printf(c, "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
            mg_http_printf_chunk(c, "ID PROTO TYPE      LOCAL           REMOTE\n");
            for (struct mg_connection *t = c->mgr->conns; t != NULL; t = t->next) {
                mg_http_printf_chunk(c, "%-3lu %4s %s %M %M\n", t->id,
                                     t->is_udp ? "UDP" : "TCP",
                                     t->is_listening  ? "LISTENING"
                                     : t->is_accepted ? "ACCEPTED "
                                                      : "CONNECTED",
                                     mg_print_ip, &t->loc, mg_print_ip, &t->rem);
            }
            mg_http_printf_chunk(c, "");  // Don't forget the last empty chunk
        } else if (mg_http_match_uri(hm, "/api/f2/*")) {
            mg_http_reply(c, 200,
                          CORSSTRING,
                           "{\"result\": \"%.*s\"}\n", (int) hm->uri.len,
                        hm->uri.ptr);
        } else if ( mg_http_match_uri(hm, "/docview/openfile") ) {
            DocView_OpenFile(c,hm);
        } else if ( mg_http_match_uri(hm, "/docview/openfile_local") ) {
            DocView_OpenFile_Local(c,hm);
        } else if ( mg_http_match_uri(hm, "/docview/getpage") ) {
            DocView_GetPage(c,hm);
        } else if ( mg_http_match_uri(hm, "/docview/docaddwatermark") ) {
            DocView_AddWaterMark(c,hm);
        } else if (mg_http_match_uri(hm, "/docview/ridingstamp")) {
            //DocView_Stamp_Ride(c,hm);
        } else if (mg_http_match_uri(hm, "/docview/postionstamp")) {
            //DocView_Stamp_Pos(c,hm);
        } else if (mg_http_match_uri(hm, "/docview/keywordstamp")) {
            //DocView_Stamp_Keyword(c,hm);
        } else if (mg_http_match_uri(hm, "/docview/verify")) {
           // DocView_Stamp_Verify(c,hm);
        } else if (mg_http_match_uri(hm, "/docview/getfiledata")) {
            DocView_GetFileData(c,hm);
        } else if (mg_http_match_uri(hm, "/docview/saveas")) {
            DocView_SaveAs(c,hm);
        } else if (mg_http_match_uri(hm, "/docview/printdocument")) {
            DocView_Print(c,hm);
        } else if ( mg_http_match_uri(hm, "/docview/setserverurl") ) {
            DocView_SetServerUrl(c,hm);
        } else if (mg_http_match_uri(hm, "/qrcode/getsealqrcodestatus")) {
            
        } else if (mg_http_match_uri(hm, "/qrcode/getsealqrcode")) {
            
        } else if (mg_http_match_uri(hm, "/usbkey/getcert")) {
            
        } else {
            //struct mg_http_serve_opts opts = {.root_dir = s_root_dir};
            mg_http_serve_opts opts;

            g_root_dir_Byte = g_root_dir.toUtf8();
            opts.root_dir = g_root_dir_Byte.constData();
//#ifdef  _MSC_VER || _WIN32 || _WIN64
//            opts.root_dir = g_root_dir.toUtf8().constData();
//#else
//            opts.root_dir = g_root_dir.toUtf8().constData();
//            qDebug() << "g_root_dir => "<< g_root_dir.toUtf8().constData() << Qt::endl;
//            qDebug() << "g_root_dir => "<< opts.root_dir << Qt::endl;
//#endif
            opts.ssi_pattern = NULL;    // SSI file name pattern, e.g. #.shtml
            opts.extra_headers = NULL;  // Extra HTTP headers to add in responses
            opts.mime_types = NULL;     // Extra mime types, ext1=type1,ext2=type2,..
            opts.page404 = NULL;        // Path to the 404 page, or NULL by default
            opts.fs = NULL;
            mg_http_serve_dir(c,(mg_http_message*)ev_data, &opts);
        }
    }
    (void) fn_data;
}
//-----------------------------------------------------------------------------------------------------------------
void DocView_SetServerUrl(mg_connection *c,const struct mg_http_message *hm)
{
    string getParam = "";
    rapidjson::Document dom;

    int status = 0;
    string message = "成功";

    string ServerUrl = "";




    getParam = getGetParam(hm);
    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("serverUrl") && dom["serverUrl"].IsString())) {
        status = -2;
        message = "输入参数没有type字段";
        goto err;
    }

    ServerUrl = dom["serverUrl"].GetString();
    if ( ServerUrl.empty() ) {
        status = -3;
        message = "输入参数serverUrl字段的值为空";
        goto err;
    }

    g_Server_Url = QString::fromStdString(ServerUrl);

    qDebug() << "g_Server_Url => "<< g_Server_Url << Qt::endl;

err:
    mg_http_reply(c, 200,
                  CORSSTRING,
                  "callback({\"status\":%d,\"message\":\"%s\",\"data\":{"

                  "}})\n",status,message.c_str());
}
//-----------------------------------------------------------------------------------------------------------------
void OpenFile(string fileID,string format,FZZBytes *filedata,string type,int * status,string & message,int * pageCount,size_t * imageWidth,size_t * imageHeight )
{

    bool isTF = true;
    
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    char * stroutDatalen = NULL;
    
    vector<string> lenitems;
    vector<string>::const_iterator lenit;
    int page_pos = 0;
    string tempPageLen;
    int pagedatalen = 0;
    FZZBytes pageData;
    int filetype = 0;
    
    if ( format == "pdf" ) {
        filetype = 2;
        HANDLE pdfHandle = g_OFDPDFSignerProxy.pdf_open((unsigned char *)filedata->getData(), filedata->getLen());
        if ( pdfHandle == 0 ) {
            *status = -7;
            message = "打开文件失败！";
            goto err;
        }
        isTF = g_OFDPDFSignerProxy.pdf_toImage(pdfHandle,type.c_str(),PDF_SCALE,&outData,&outDatalen,&stroutDatalen);

        g_OFDPDFSignerProxy.pdf_close(pdfHandle);

    } else if ( format == "ofd" ) {
        filetype = 1;
        HANDLE ofdHandle = g_OFDPDFSignerProxy.ofd_open((unsigned char *)filedata->getData(), filedata->getLen());
        if ( ofdHandle == 0 ) {
            *status = -7;
            message = "打开文件失败！";
            goto err;
        }

        isTF = g_OFDPDFSignerProxy.ofd_toImage(ofdHandle,type.c_str(),OFD_SCALE,&outData,&outDatalen,&stroutDatalen);

        g_OFDPDFSignerProxy.ofd_close(ofdHandle);

        
    } else {
        *status = -4;
        message = "请打开扩展名为ofd或pdf的文件！";
        goto err;
    }
    
    if ( isTF ) {
        AddFiles(fileID,filedata,filetype);
        split(stroutDatalen, ",", lenitems);
        *pageCount = lenitems.size();
        page_pos = 0;
        for (lenit = lenitems.begin(); lenit != lenitems.end(); lenit++) {
            tempPageLen = *lenit;
            pagedatalen = atoi(tempPageLen.c_str());
            if ( lenit == lenitems.begin() ) {
                g_OFDPDFSignerProxy.getImageWidthHeight(outData+page_pos, pagedatalen,imageWidth,imageHeight);
            }
            pageData.setData(outData+page_pos, pagedatalen);
            //test
            //static int uua = 0;
            //uua++;
            //writefile("/Users/zizhengfan/work/cpp/ofd/tmp/imageconverter/aa"+fmt(uua)+".jpg",outData+page_pos, pagedatalen);
            //test end
            AddFiles_Page(fileID,&pageData);
            page_pos += pagedatalen;


        }
    } else {
        *status = -6;
        message = "文档转换为图片失败！";
    }
err:
    if ( outData != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(outData);
        outData = NULL;
    }
    if ( stroutDatalen != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(stroutDatalen);
        stroutDatalen = NULL;
    }

}
//-----------------------------------------------------------------------------------------------------------------
void DocView_OpenFile(mg_connection *c,const struct mg_http_message *hm)
{
    string getParam = "";
    rapidjson::Document dom;
    
    int status = 0;
    string message = "成功";
    int pageCount = 0;
    size_t imageWidth = 0;
    size_t imageHeight = 0;
    
    string doctype = "";
    string fileID = "";
    bool isLast = true;
    string fileData = "";
    
    string type = "JPG";
    string tempfilebase64 = "";
    FZZBytes tempFileData;
    
    
    
    getParam = getGetParam(hm);
    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }
    
    if (!(dom.HasMember("type") && dom["type"].IsString())) {
        status = -2;
        message = "输入参数没有type字段";
        goto err;
    }
    
    doctype = dom["type"].GetString();
    if ( doctype.empty() ) {
        status = -3;
        message = "输入参数type字段的值为空";
        goto err;
    }
    
    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }
    
    fileID = dom["fileID"].GetString();
    
    if (!(dom.HasMember("isLast") && dom["isLast"].IsBool())) {
        status = -2;
        message = "输入参数没有isLast字段";
        goto err;
    }
    
    isLast = dom["isLast"].GetBool();
    
    if (!(dom.HasMember("fileData") && dom["fileData"].IsString())) {
        status = -2;
        message = "输入参数没有fileData字段";
        goto err;
    }
    
    fileData = dom["fileData"].GetString();
    if ( fileData.empty() ) {
        status = -3;
        message = "输入参数fileData字段的值为空！";
        goto err;
    }
    
    transform(doctype.begin(), doctype.end(), doctype.begin(), ::tolower);
    
    if ( fileID.empty() ) {
        fileID = genFileID();
        AddFiles_base64(fileID,fileData);
        if (!isLast) {
            status = 0;
            message = "成功";
            goto err;
        } else {
            tempfilebase64 = getFiles_base64(fileID);
            if ( tempfilebase64.empty() ) {
                status = -5;
                message = "输入参数fileData字段的值为空！";
                goto err;
            }
            Base64_decode(tempfilebase64.c_str(),tempfilebase64.length(),tempFileData);
            if ( tempFileData.getLen() < 30 ) {
                status = -5;
                message = "输入参数fileData字段的值不是文档类型数据！";
                goto err;
            }
            clearFiles_base64(fileID);
            OpenFile(fileID,doctype,&tempFileData,type,&status,message,&pageCount,&imageWidth,&imageHeight);
        }
    } else {
        AddFiles_base64(fileID,fileData);
        if (!isLast) {
            status = 0;
            message = "成功";
            goto err;
        } else {
            tempfilebase64 = getFiles_base64(fileID);
            if ( tempfilebase64.empty() ) {
                status = -5;
                message = "输入参数fileData字段的值为空！";
                goto err;
            }
            Base64_decode(tempfilebase64.c_str(),tempfilebase64.length(),tempFileData);
            
            if ( tempFileData.getLen() < 30 ) {
                status = -5;
                message = "输入参数fileData字段的值不是文档类型数据！";
                goto err;
            }
            clearFiles_base64(fileID);
            OpenFile(fileID,doctype,&tempFileData,type,&status,message,&pageCount,&imageWidth,&imageHeight);
        }
    }
    
err:
    mg_http_reply(c, 200,

                CORSSTRING,

                  "callback({\"status\":%d,\"message\":\"%s\",\"data\":{"
                  "\"fileID\":\"%s\","
                  "\"pageCount\":%d,"
                  "\"imageWidth\":%d,"
                  "\"imageHeight\":%d"
                  "}})\n",status,message.c_str(),fileID.c_str(),pageCount,imageWidth,imageHeight);
    

}
//-----------------------------------------------------------------------------------------------------------------
void DocView_OpenFile_Local(mg_connection *c,const struct mg_http_message *hm)
{

    int status = 0;
    string message = "成功";
    string fileID = "";
    int pageCount = 0;
    size_t imageWidth = 0;
    size_t imageHeight = 0;

    rapidjson::Document dom;

    string getParam = "";
    QString filename = "";
    string format = "";
    FZZBytes filedata;
    int pos = 0;

    string type = "JPG";
    char * temKeyWord = NULL;
    QByteArray bfileName;


//    getParam = getGetParam(hm);


//    if (dom.Parse(getParam.c_str()).HasParseError()) {
//        status = -1;
//        message = "不合法的JSON字符串";
//        goto err;
//    }

//    if (!(dom.HasMember("filePath") && dom["filePath"].IsString())) {
//        status = -2;
//        message = "输入参数没有filePath字段";
//        goto err;
//    }

//    filename = dom["filePath"].GetString();
//    if ( filename.isNull() ) {
//        status = -3;
//        message = "输入参数filePath字段的值为空";
//        goto err;
//    }


    //qDebug() << "filename => "<< filename.toLatin1().constData() << Qt::endl;

//    filename = filename.replace("\\","/");

//    pos = filename.lastIndexOf("/");
//    if ( pos != -1 ) {
//        filename = filename.mid(pos+1,filename.length()-pos-1);
//    }

//#ifdef  _MSC_VER || _WIN32 || _WIN64
//    bfileName = filename.toLatin1();
//    temKeyWord = (char *)malloc(bfileName.size());
//    memset(temKeyWord,0x00,bfileName.size());

//    mg_url_decode(bfileName.constData(),bfileName.size(),temKeyWord,bfileName.size(),0);

//    filename = temKeyWord;
//    qDebug() << "filename => "<< filename.toUtf8().constData() << Qt::endl;
//#endif


    //filename = FILEPATH + filename;

    //QString temppath = QStandardPaths::writableLocation(QStandardPaths::TempLocation);

    filename = QFileDialog::getOpenFileName(NULL, QStringLiteral("请选择PDF/OFD文档"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),QStringLiteral("OFD文档(*.ofd);; ""PDF文件(*.pdf)"));

    readfile(filename,filedata);
    if ( filedata.getLen() < 30 ) {
        status = -5;
        message = "不能打开文件";
        goto err;
    }

    fileID = genFileID();

    pos = filename.lastIndexOf(".");
    if ( pos != -1 ) {
#ifdef  _MSC_VER || _WIN32 || _WIN64
            format = filename.mid(pos+1,filename.length()-pos-1).toLatin1().constData();
#else
            format = filename.mid(pos+1,filename.length()-pos-1).toUtf8().constData();
#endif

        transform(format.begin(), format.end(), format.begin(), ::tolower);

        OpenFile(fileID,format,&filedata,type,&status,message,&pageCount,&imageWidth,&imageHeight);
    } else {
        status = -4;
        message = "请打开扩展名为ofd或pdf的文件！";
        goto err;
    }



err:

    if ( temKeyWord != NULL ) {
        free(temKeyWord);
        temKeyWord = NULL;
    }

    mg_http_reply(c, 200,
                  CORSSTRING,
                  "callback({\"status\":%d,\"message\":\"%s\",\"data\":{"
                  "\"fileID\":\"%s\","
                  "\"pageCount\":%d,"
                  "\"imageWidth\":%d,"
                  "\"imageHeight\":%d"
                  "}})\n",status,message.c_str(),fileID.c_str(),pageCount,imageWidth,imageHeight);


}
//-----------------------------------------------------------------------------------------------------------------
void DocView_OpenFile_Local_js_open(mg_connection *c,const struct mg_http_message *hm)
{

    int status = 0;
    string message = "成功";
    string fileID = "";
    int pageCount = 0;
    size_t imageWidth = 0;
    size_t imageHeight = 0;
    
    rapidjson::Document dom;
    
    string getParam = "";
    QString filename = "";
    string format = "";
    FZZBytes filedata;
    int pos = 0;
    
    string type = "JPG";
    char * temKeyWord = NULL;
    //QByteArray bfileName;
    
    
    getParam = getGetParam(hm);

    
    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("filePath") && dom["filePath"].IsString())) {
        status = -2;
        message = "输入参数没有filePath字段";
        goto err;
    }

    filename = dom["filePath"].GetString();
    if ( filename.isNull() ) {
        status = -3;
        message = "输入参数filePath字段的值为空";
        goto err;
    }
    
    //qDebug() << "filename => "<< filename.toLatin1().constData() << Qt::endl;

    filename = filename.replace("\\","/");

    pos = filename.lastIndexOf("/");
    if ( pos != -1 ) {
        filename = filename.mid(pos+1,filename.length()-pos-1);
    }

#ifdef  _MSC_VER || _WIN32 || _WIN64
    bfileName = filename.toLatin1();
    temKeyWord = (char *)malloc(bfileName.size());
    memset(temKeyWord,0x00,bfileName.size());

    mg_url_decode(bfileName.constData(),bfileName.size(),temKeyWord,bfileName.size(),0);

    filename = temKeyWord;
    qDebug() << "filename => "<< filename.toUtf8().constData() << Qt::endl;
#endif


    filename = FILEPATH + filename;
    
    readfile(filename,filedata);
    if ( filedata.getLen() < 30 ) {
        status = -5;
        message = "不能打开文件";
        goto err;
    }
    
    fileID = genFileID();
    
    pos = filename.lastIndexOf(".");
    if ( pos != -1 ) {
#ifdef  _MSC_VER || _WIN32 || _WIN64
            format = filename.mid(pos+1,filename.length()-pos-1).toLatin1().constData();
#else
            format = filename.mid(pos+1,filename.length()-pos-1).toUtf8().constData();
#endif

        transform(format.begin(), format.end(), format.begin(), ::tolower);

        OpenFile(fileID,format,&filedata,type,&status,message,&pageCount,&imageWidth,&imageHeight);
    } else {
        status = -4;
        message = "请打开扩展名为ofd或pdf的文件！";
        goto err;
    }
    

    
err:

    if ( temKeyWord != NULL ) {
        free(temKeyWord);
        temKeyWord = NULL;
    }

    mg_http_reply(c, 200, CORSSTRING, "callback({\"status\":%d,\"message\":\"%s\",\"data\":{"
                  "\"fileID\":\"%s\","
                  "\"pageCount\":%d,"
                  "\"imageWidth\":%d,"
                  "\"imageHeight\":%d"
                  "}})\n",status,message.c_str(),fileID.c_str(),pageCount,imageWidth,imageHeight);
    

}
//-----------------------------------------------------------------------------------------------------------------
void DocView_GetPage(mg_connection *c,const struct mg_http_message *hm)
{

    int status = 0;
    string message = "成功";
    string images_base64 = "";
    
    string getParam = "";
    string fileID = "";
    int pageCode = 0;
    FZZBytes* pageData;
    int i = 0, count = 1;
    string type = "JPG";
    unsigned char * outData = NULL;
    size_t outDatalen = 0;
    char * stroutDatalen = NULL;
    bool isTF = false;
    vector<string> lenitems;
    vector<string>::const_iterator lenit;
    int page_pos = 0;
    int pagedatalen = 0;
    string tempPageLen = "";
    rapidjson::Document dom;
    
    getParam = getGetParam(hm);
    
    
    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }

    fileID = dom["fileID"].GetString();
    if ( fileID.empty() ) {
        status = -3;
        message = "输入参数没有fileID字段的值为空";
        goto err;
    }
    
    if (!(dom.HasMember("pageCode") && dom["pageCode"].IsInt())) {
        status = -2;
        message = "输入参数没有pageCode字段";
        goto err;
    }

    pageCode = dom["pageCode"].GetInt();
    
    pageData = getFiles_Page(fileID,pageCode);
    if ( pageData == NULL ) {
        status = -3;
        message = "该页面不存在！";
        goto err;
    }
    
    //writefile("/Users/zizhengfan/work/cpp/ofd/tmp/signpdf/aa.jpg",(const unsigned char *)pageData->getData(),pageData->getLen());
    
    isTF = g_OFDPDFSignerProxy.splitImage(pageData->getData(), pageData->getLen(),type.c_str(),false,CUTIMAGECOUNT,&outData,&outDatalen,&stroutDatalen,NULL,NULL);
    
    if ( isTF ) {
        split(stroutDatalen, ",", lenitems);
        count = lenitems.size();
        page_pos = 0;
        for (lenit = lenitems.begin(); lenit != lenitems.end(); lenit++) {
            tempPageLen = *lenit;
            pagedatalen = atoi(tempPageLen.c_str());
            
            images_base64 += "\"";
            images_base64 += Base64Encode(outData+page_pos, pagedatalen);
         
            if ( (lenit - lenitems.begin()) == lenitems.size()-1 ) {
                images_base64 += "\"";
            } else {
                images_base64 += "\",";
            }
            page_pos += pagedatalen;
            

        }
        
        
    } else {
        status = -6;
        message = "拆分图片失败！";
    }
    
    //writefile("/Users/zizhengfan/work/cpp/ofd/tmp/signpdf/aa.txt",(const unsigned char *)images_base64.c_str(),images_base64.length());
    
err:

    qDebug() << "DocView_GetPage => status :" << status << " , send.len = "<< c->send.len << Qt::endl;

    mg_http_reply_longdata(c, 200,
                  CORSSTRING,
                  "callback({\"status\":%d,\"message\":\"%s\",\"data\":["
                  "%s"
                  "]})\n",status,message.c_str(),images_base64.c_str());
    
    if ( outData != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(outData);
        outData = NULL;
    }
    if ( stroutDatalen != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(stroutDatalen);
        stroutDatalen = NULL;
    }

    qDebug() << "DocView_GetPage => ok, images_base64.len :" << images_base64.length()  << Qt::endl;
}
//-----------------------------------------------------------------------------------------------------------------
FZZBytes * GetFileData(mg_connection *c,const struct mg_http_message *hm,int* status,string& message,int * fileType)
{
    string getParam = "";
    string fileID = "";
    FZZBytes * tempdata = NULL;

    rapidjson::Document dom;

    *status = 0;
    message = "成功";

    getParam = getGetParam(hm);

    if (dom.Parse(getParam.c_str()).HasParseError()) {
        *status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        *status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }

    fileID = dom["fileID"].GetString();
    if ( fileID.empty() ) {
        *status = -3;
        message = "输入参数没有fileID字段的值为空";
        goto err;
    }

    *fileType = getFiles_FileType(fileID);
    tempdata = getFiles_FileData(fileID);

    if ( tempdata == NULL ) {
        *status = -4;
        message = "没有找到文件数据！";
        goto err;
    }
err:
    return tempdata;
}
//-----------------------------------------------------------------------------------------------------------------
void DocView_GetFileData(mg_connection *c,const struct mg_http_message *hm)
{

    int status = 0;
    string message = "成功";
    int fileType = 0;
    
    FZZBytes * tempdata = GetFileData(c,hm,&status,message,&fileType);
    string filebase64 = "";
    if ( tempdata != NULL ) {
        filebase64 = Base64Encode(tempdata->getData(),tempdata->getLen());
    }
    
    mg_http_reply(c, 200,
                  CORSSTRING,
                  "callback({\"status\":%d,\"message\":\"%s\",\"data\":\""
                  "%s"
                  "\"})\n",status,message.c_str(),filebase64.c_str());

}
//-----------------------------------------------------------------------------------------------------------------
void DocView_SaveAs(mg_connection *c,const struct mg_http_message *hm)
{

    int status = 0;
    string message = "成功";
    int fileType = 0;

    FZZBytes * tempdata = GetFileData(c,hm,&status,message,&fileType);

    mg_http_reply(c, 200, CORSSTRING, "callback({\"status\":%d,\"message\":\"%s\",\"data\":\""
                  "\"})\n",status,message.c_str());

    if ( tempdata != NULL ) {

        QFileDialog fileDialog;
        QString selectType = "";
        QString saveasfileName = "";

        if ( fileType == 1 ) {
            saveasfileName = fileDialog.getSaveFileName(qApp->activeWindow(),"保存文档",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/保存文档",QStringLiteral("OFD文档(*.ofd)"),&selectType);
        } else if ( fileType == 2 ) {
            saveasfileName = fileDialog.getSaveFileName(qApp->activeWindow(),"保存文档",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/保存文档",QStringLiteral("PDF文档(*.pdf)"),&selectType);
        } else {
            saveasfileName = fileDialog.getSaveFileName(qApp->activeWindow(),"保存文档",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/保存文档",QStringLiteral("PDF文档(*.pdf)"),&selectType);
        }

        QApplication::processEvents();
        QApplication::sendPostedEvents();

        //QByteArray bfilename = saveasfileName.toStdU16String();
        //string strsavefilename = bfilename.data();
        //qDebug() << "strsavefilename => "<< strsavefilename.c_str() << Qt::endl;
        //writefile(strsavefilename,tempdata->getData(),tempdata->getLen());
        QFile file(saveasfileName);
        if(file.open(QIODevice::WriteOnly)) {
            QByteArray wirtedata;
            wirtedata.resize(tempdata->getLen());
            memcpy(wirtedata.data(),tempdata->getData(),tempdata->getLen());
            file.write(wirtedata);
            file.close();
        }
    }


}
//-----------------------------------------------------------------------------------------------------------------
void DocView_Print(mg_connection *c,const struct mg_http_message *hm)
{

    int status = 0;
    string message = "成功";
    string fileID = "";
    string getParam = "";
    rapidjson::Document dom;
    int pageCount = 0;
    int pageindex = 0;
    QPrinter printer;

    QPrintDialog printDialog(&printer,qApp->activeWindow());
    printDialog.setWindowTitle("打印 ");

    getParam = getGetParam(hm);


    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }

    fileID = dom["fileID"].GetString();
    if ( fileID.empty() ) {
        status = -3;
        message = "输入参数没有fileID字段的值为空";
        goto err;
    }

    pageCount = getFiles_PageCount(fileID);
    if ( pageCount == 0 ) {
        status = -4;
        message = "该文档没有要打印的页面！";
        goto err;
    }

err:

    mg_http_reply(c, 200,
                  CORSSTRING,
                  "callback({\"status\":%d,\"message\":\"%s\",\"data\":\""
                  "\"})\n",status,message.c_str());

    if(printDialog.exec())
    {


        //qDebug() << "click_pbPrint: max: " << printDialog.fromPage() << " min:" << printDialog.toPage() << Qt::endl;


        QPainter painter(&printer);				//指定绘图设备为一个QPrinter对象
        QRect rect =painter.viewport();         //获得QPainter对象的视图矩形区域

        int from = printDialog.fromPage();
        int to = printDialog.toPage();

        if ( from == 0 && to == 0 ) {
            from = 0;
            to = pageCount-1;
        } else {
            from = from - 1;
            if ( from <= 0 ) {
                from = 0;
            }

            to = to - 1;
            if ( to <= 0 ) {
                to = 0;
            }
            if ( to >=  pageCount-1 ) {
                to = pageCount-1;
            }
        }




        for( pageindex = 0; pageindex < pageCount; pageindex++  ) {

            if ( pageindex >= from && pageindex <= to ) {

                FZZBytes * tempdata =  getFiles_Page(fileID, pageindex);
                if ( tempdata == NULL ) continue;
                QPixmap temp;
                temp.loadFromData(tempdata->getData(),tempdata->getLen());
                QSize size = temp.size();				//获得图像的大小
                // 按照图形的比例大小重新设置视图矩形区域
                size.scale(rect.size(),Qt::KeepAspectRatio);
                painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
                painter.setWindow(temp.rect());          //设置QPainter窗口大小为图像的大小
                painter.drawImage(0,0,temp.toImage());

                if ( pageindex <= to-1 ) {
                    printer.newPage();
                    //qDebug() << "click_pbPrint: new page"<< Qt::endl;
                }
            }

            //qDebug() << "click_pbPrint: " << it - pixmaplist->begin() << Qt::endl;
        }

        painter.end ();
    }

    QApplication::processEvents();
    QApplication::sendPostedEvents();

}
//-----------------------------------------------------------------------------------------------------------------
/*
void DocView_Stamp_Ride(mg_connection *c,const struct mg_http_message *hm)
{
    int status = 0;
    string message = "成功";
    string fileID = "";
    string getParam = "";
    rapidjson::Document dom;

    int pageCount = 0;
    int imageWidth = 0;
    int imageHeight = 0;

    int fileType = 0;
    FZZBytes * srcFileData = NULL;

    unsigned char * outdata = NULL;
    int outdatalen = 0;

    //0:TYPE_Left,1:TYPE_Right,2:TYPE_Top,3:TYPE_Bottom,4:CuttingRide=>TYPE_Right,5:CuttingRide=>TYPE_Top
    int ridingType = 1;

    FZZBytes sealdata;
    FZZBytes certdata;
    FZZBytes prikeydata;
    string type = "JPG";
    FZZBytes signFileData;
    string format = "";
    QString tempFileName = "";

    //qDebug() << "DocView_Stamp_Ride"   << Qt::endl;

    getParam = getGetParam(hm);



    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }

    fileID = dom["fileID"].GetString();
    if ( fileID.empty() ) {
        status = -3;
        message = "输入参数没有fileID字段的值为空";
        goto err;
    }

    fileType = getFiles_FileType(fileID);
    srcFileData = getFiles_FileData(fileID);

    if ( srcFileData->getLen() <= 30 ) {
        status = -7;
        message = "获取原始文档数据失败！";
        goto err;
    }

    tempFileName = g_root_dir;
    tempFileName += "sealuser.cer";
    readfile(tempFileName,certdata);

    if ( certdata.getLen() <= 30 ) {
        status = -5;
        message = "不能读取证书文件";
        goto err;
    }

    tempFileName = g_root_dir;
    tempFileName += "sealuserpirkey.key";
    readfile(tempFileName,prikeydata);

    if ( prikeydata.getLen() <= 30 ) {
        status = -5;
        message = "不能读取私钥文件";
        goto err;
    }

    tempFileName = g_root_dir;

    if ( fileType == 1 ) {
        format = "ofd";
        tempFileName += "seal.sel";
        readfile(tempFileName,sealdata);

        if ( sealdata.getLen() <= 30 ) {
            status = -5;
            message = "不能读取印章文件";
            goto err;
        }

        g_OFDPDFSignerProxy.SignStamp_Riding_OFD((const unsigned char *)sealdata.getData(),sealdata.getLen(),
                                               (const unsigned char *)certdata.getData(),certdata.getLen(),
                                               (const unsigned char *)prikeydata.getData(),prikeydata.getLen(),
                                               (const unsigned char *)srcFileData->getData(),srcFileData->getLen(),
                                               ridingType,42,42,true,&outdata,&outdatalen);
    } else if (fileType == 2) {
        format = "pdf";
        tempFileName += "companystamp.png";
        readfile(tempFileName,sealdata);

        if ( sealdata.getLen() <= 30 ) {
            status = -5;
            message = "不能读取印章文件";
            goto err;
        }
        g_OFDPDFSignerProxy.SignStamp_Riding_PDF((const unsigned char *)sealdata.getData(),sealdata.getLen(),
                                               (const unsigned char *)certdata.getData(),certdata.getLen(),
                                               (const unsigned char *)prikeydata.getData(),prikeydata.getLen(),
                                               (const unsigned char *)srcFileData->getData(),srcFileData->getLen(),
                                               ridingType,42,42,&outdata,&outdatalen);
    } else {
        status = -4;
        message = "未知的文档类型！";
        goto err;
    }

    if ( outdatalen <= 30 ) {
        status = -6;
        message = "对文档盖章失败！";
        goto err;
    }

    signFileData.setData(outdata,outdatalen);

    fileID = genFileID();

    OpenFile(fileID,format,&signFileData,type,&status,message,&pageCount,&imageWidth,&imageHeight);



err:



    mg_http_reply(c, 200, CORSSTRING, "callback({\"status\":%d,\"message\":\"%s\",\"data\":{"
                  "\"fileID\":\"%s\","
                  "\"pageCount\":%d,"
                  "\"imageWidth\":%d,"
                  "\"imageHeight\":%d"
                  "}})\n",status,message.c_str(),fileID.c_str(),pageCount,imageWidth,imageHeight);

    if ( outdata != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(outdata);
        outdata = NULL;
    }


}
//-----------------------------------------------------------------------------------------------------------------
void DocView_Stamp_Keyword(mg_connection *c,const struct mg_http_message *hm)
{
    int status = 0;
    string message = "成功";
    string fileID = "";
    string getParam = "";
    rapidjson::Document dom;

    int pageCount = 0;
    int imageWidth = 0;
    int imageHeight = 0;

    int fileType = 0;
    FZZBytes * srcFileData = NULL;

    unsigned char * outdata = NULL;
    int outdatalen = 0;

    FZZBytes sealdata;
    FZZBytes certdata;
    FZZBytes prikeydata;
    string type = "JPG";
    FZZBytes signFileData;
    string format = "";
    QString tempFileName = "";

    string keyWord = "";
    string keyWordRule = "";
    char * temKeyWord = NULL;

    //qDebug() << "DocView_Stamp_Keyword"   << Qt::endl;

    getParam = getGetParam(hm);

    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }

    fileID = dom["fileID"].GetString();
    if ( fileID.empty() ) {
        status = -3;
        message = "输入参数没有fileID字段的值为空";
        goto err;
    }

    keyWord = dom["keyWord"].GetString();
    if ( keyWord.empty() ) {
        status = -3;
        message = "输入参数没有keyWord字段的值为空";
        goto err;
    }

    temKeyWord = (char *)malloc(keyWord.length());
    memset(temKeyWord,0x00,keyWord.length());

    mg_url_decode(keyWord.c_str(),keyWord.length(),temKeyWord,keyWord.length(),0);

    keyWord = temKeyWord;

    //qDebug() << "DocView_Stamp_Keyword word:"   << keyWord.c_str() << Qt::endl;

    fileType = getFiles_FileType(fileID);
    srcFileData = getFiles_FileData(fileID);

    if ( srcFileData->getLen() <= 30 ) {
        status = -7;
        message = "获取原始文档数据失败！";
        goto err;
    }

    tempFileName = g_root_dir;
    tempFileName += "sealuser.cer";
    readfile(tempFileName,certdata);

    if ( certdata.getLen() <= 30 ) {
        status = -5;
        message = "不能读取证书文件";
        goto err;
    }

    tempFileName = g_root_dir;
    tempFileName += "sealuserpirkey.key";
    readfile(tempFileName,prikeydata);

    if ( prikeydata.getLen() <= 30 ) {
        status = -5;
        message = "不能读取私钥文件";
        goto err;
    }



    keyWordRule = "{"
                  "\"KeyWordPosInfo\":"
                  "["
                      "{"
                          "\"PageIndex\":0,"  //-1，所有页面
                          "\"KeyWordIndexs\":"
                          "["
                              "{"
                                  "\"Index\":0,"  //-1，所有关键字
                                  "\"Offset-X\":0," //0,中心
                                  "\"Offset-Y\":0" //0,中心
                              "},"
                              "{"
                                  "\"Index\":2,"
                                  "\"Offset-X\":10,"
                                  "\"Offset-Y\":0"
                              "}"
                          "]"
                      "}"
                  "]"
              "}";

    tempFileName = g_root_dir;

    if ( fileType == 1 ) {
        format = "ofd";
        tempFileName += "seal.sel";
        readfile(tempFileName,sealdata);

        if ( sealdata.getLen() <= 30 ) {
            status = -5;
            message = "不能读取印章文件";
            goto err;
        }

        g_OFDPDFSignerProxy.SignStamp_KeyWord_OFD((const unsigned char *)sealdata.getData(),sealdata.getLen(),
                                               (const unsigned char *)certdata.getData(),certdata.getLen(),
                                               (const unsigned char *)prikeydata.getData(),prikeydata.getLen(),
                                               (const unsigned char *)srcFileData->getData(),srcFileData->getLen(),
                                               keyWord.c_str(),keyWordRule.c_str(),42,42,true,&outdata,&outdatalen);
    } else if (fileType == 2) {
        format = "pdf";
        tempFileName += "companystamp.png";
        readfile(tempFileName,sealdata);

        if ( sealdata.getLen() <= 30 ) {
            status = -5;
            message = "不能读取印章文件";
            goto err;
        }
        g_OFDPDFSignerProxy.SignStamp_KeyWord_PDF((const unsigned char *)sealdata.getData(),sealdata.getLen(),
                                               (const unsigned char *)certdata.getData(),certdata.getLen(),
                                               (const unsigned char *)prikeydata.getData(),prikeydata.getLen(),
                                               (const unsigned char *)srcFileData->getData(),srcFileData->getLen(),
                                               keyWord.c_str(),keyWordRule.c_str(),42,42,&outdata,&outdatalen);
    } else {
        status = -4;
        message = "未知的文档类型！";
        goto err;
    }


    if ( outdatalen <= 30 ) {
        status = -6;
        message = "对文档盖章失败！";
        goto err;
    }


    signFileData.setData(outdata,outdatalen);

    fileID = genFileID();

    OpenFile(fileID,format,&signFileData,type,&status,message,&pageCount,&imageWidth,&imageHeight);



err:

    if ( temKeyWord != NULL ) {
        free(temKeyWord);
        temKeyWord = NULL;
    }

    mg_http_reply(c, 200, CORSSTRING, "callback({\"status\":%d,\"message\":\"%s\",\"data\":{"
                  "\"fileID\":\"%s\","
                  "\"pageCount\":%d,"
                  "\"imageWidth\":%d,"
                  "\"imageHeight\":%d"
                  "}})\n",status,message.c_str(),fileID.c_str(),pageCount,imageWidth,imageHeight);

    if ( outdata != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(outdata);
        outdata = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void DocView_Stamp_Pos(mg_connection *c,const struct mg_http_message *hm)
{
    int status = 0;
    string message = "成功";
    string fileID = "";
    string getParam = "";
    rapidjson::Document dom;

    int pageCount = 0;
    int imageWidth = 0;
    int imageHeight = 0;

    int fileType = 0;
    FZZBytes * srcFileData = NULL;

    unsigned char * outdata = NULL;
    int outdatalen = 0;

    //0:TYPE_Left,1:TYPE_Right,2:TYPE_Top,3:TYPE_Bottom,4:CuttingRide=>TYPE_Right,5:CuttingRide=>TYPE_Top
    int pageindex = 0;
    double left = 0;
    double top = 0;

    FZZBytes sealdata;
    FZZBytes certdata;
    FZZBytes prikeydata;
    string type = "JPG";
    FZZBytes signFileData;
    string format = "";
    QString tempFileName = "";



    getParam = getGetParam(hm);



    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }

    fileID = dom["fileID"].GetString();
    if ( fileID.empty() ) {
        status = -3;
        message = "输入参数没有fileID字段的值为空";
        goto err;
    }

    pageindex = dom["pageCode"].GetInt();
    if ( pageindex < 0  ) {
        status = -3;
        message = "输入参数没有pageCode字段的值为空";
        goto err;
    }

    left = dom["left"].GetDouble();
    if ( left < 0  ) {
        status = -3;
        message = "输入参数没有left字段的值为空";
        goto err;
    }

    top = dom["top"].GetDouble();
    if ( top < 0  ) {
        status = -3;
        message = "输入参数没有top字段的值为空";
        goto err;
    }

    //qDebug() << "DocView_Stamp_Pos pageindex: "   << pageindex << " left: "<<left << " top:" << top << Qt::endl;

    fileType = getFiles_FileType(fileID);
    srcFileData = getFiles_FileData(fileID);

    if ( srcFileData->getLen() <= 30 ) {
        status = -7;
        message = "获取原始文档数据失败！";
        goto err;
    }

    tempFileName = g_root_dir;
    tempFileName += "sealuser.cer";
    if ( !readfile(tempFileName,certdata) ) {
        status = -5;
        message = "不能读取证书文件!";
        goto err;
    }

    if ( certdata.getLen() <= 30 ) {
        status = -5;
        message = "不能读取证书文件";
        goto err;
    }

    //writefile("C:\\aa.cer",certdata.getData(),certdata.getLen());

    tempFileName = g_root_dir;
    tempFileName += "sealuserpirkey.key";
    readfile(tempFileName,prikeydata);

    if ( prikeydata.getLen() <= 30 ) {
        status = -5;
        message = "不能读取私钥文件";
        goto err;
    }

    tempFileName = g_root_dir;

    if ( fileType == 1 ) {
        format = "ofd";
        tempFileName += "seal.sel";
        readfile(tempFileName,sealdata);

        if ( sealdata.getLen() <= 30 ) {
            status = -5;
            message = "不能读取印章文件";
            goto err;
        }

        left = (double)left/OFD_SCALE;
        top = (double)top/OFD_SCALE;

        g_OFDPDFSignerProxy.SignStamp_Pos_OFD((const unsigned char *)sealdata.getData(),sealdata.getLen(),
                                               (const unsigned char *)certdata.getData(),certdata.getLen(),
                                               (const unsigned char *)prikeydata.getData(),prikeydata.getLen(),
                                               (const unsigned char *)srcFileData->getData(),srcFileData->getLen(),
                                               pageindex+1,left,top,42,42,true,&outdata,&outdatalen);
    } else if (fileType == 2) {
        format = "pdf";
        tempFileName += "companystamp.png";
        readfile(tempFileName,sealdata);

        if ( sealdata.getLen() <= 30 ) {
            status = -5;
            message = "不能读取印章文件";
            goto err;
        }

        left = left /PDF_SCALE;
        top = top/PDF_SCALE;



        g_OFDPDFSignerProxy.SignStamp_Pos_PDF((const unsigned char *)sealdata.getData(),sealdata.getLen(),
                                               (const unsigned char *)certdata.getData(),certdata.getLen(),
                                               (const unsigned char *)prikeydata.getData(),prikeydata.getLen(),
                                               (const unsigned char *)srcFileData->getData(),srcFileData->getLen(),
                                               pageindex,left,top,42,42,&outdata,&outdatalen);
    } else {
        status = -4;
        message = "未知的文档类型！";
        goto err;
    }

    if ( outdatalen <= 30 ) {
        status = -6;
        message = "对文档盖章失败！";
        goto err;
    }

    signFileData.setData(outdata,outdatalen);

    fileID = genFileID();

    OpenFile(fileID,format,&signFileData,type,&status,message,&pageCount,&imageWidth,&imageHeight);

err:

    mg_http_reply(c, 200, CORSSTRING, "callback({\"status\":%d,\"message\":\"%s\",\"data\":{"
                  "\"fileID\":\"%s\","
                  "\"pageCount\":%d,"
                  "\"imageWidth\":%d,"
                  "\"imageHeight\":%d"
                  "}})\n",status,message.c_str(),fileID.c_str(),pageCount,imageWidth,imageHeight);

    if ( outdata != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(outdata);
        outdata = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void DocView_Stamp_Verify(mg_connection *c,const struct mg_http_message *hm)
{
    int status = 0;
    string message = "成功";
    string fileID = "";
    string getParam = "";
    rapidjson::Document dom;

    string retstring = "";
    int fileType = 0;
    FZZBytes * srcFileData = NULL;

    char * outdata = NULL;
    int outdatalen = 0;

    getParam = getGetParam(hm);

    //qDebug() << "DocView_Stamp_Verify " << Qt::endl;

    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }

    fileID = dom["fileID"].GetString();
    if ( fileID.empty() ) {
        status = -3;
        message = "输入参数没有fileID字段的值为空";
        goto err;
    }

    fileType = getFiles_FileType(fileID);
    srcFileData = getFiles_FileData(fileID);

    g_OFDPDFSignerProxy.Verify(srcFileData->getData(),srcFileData->getLen(),fileType,&outdata,&outdatalen) + 10;

    //if ( status == 0 ) {
        retstring = outdata;
//    } else {
//        retstring = "[]";
//        if ( status == -0 ) {
//            message = "输入参数没有fileID字段的值为空";
//            goto err;
//        }
//    }

    qDebug() << "DocView_Stamp_Verify ret: " << status << " ret:" << retstring.c_str() << Qt::endl;

//    retstring += "{";
//    retstring += "\"verify\":true,";
//    retstring += "\"certCN\":\"cn=fzz,c=cn\",";
//    retstring += "\"signDate\":\"2000-02-02 16:32:30\",";
//    retstring += "\"signAlg\":\"SM3-SM2\"";
//    retstring += "}";

err:

    if ( outdata != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(outdata);
        outdata = NULL;
    }

//    mg_http_reply(c, 200, CORSSTRING, "callback({\"status\":%d,\"message\":\"%s\",\"data\":["
//                  "%s"
//                  "]})\n",status,message.c_str(),retstring.c_str());

    mg_http_reply(c, 200, CORSSTRING, "callback({\"status\":%d,\"message\":\"%s\",\"data\":"
                  "%s"
                  "})\n",status,message.c_str(),retstring.c_str());


}
*/
//-----------------------------------------------------------------------------------------------------------------
void DocView_AddWaterMark(mg_connection *c,const struct mg_http_message *hm)
{
    int status = 0;
    string message = "成功";
    string fileID = "";
    string getParam = "";
    rapidjson::Document dom;

    int pageCount = 0;
    size_t imageWidth = 0;
    size_t imageHeight = 0;

    int fileType = 0;
    FZZBytes * srcFileData = NULL;

    unsigned char * outdata = NULL;
    int outdatalen = 0;

    int pageindex = 0;
    double horizontalSpacing = 0;
    double verticalSpacing = 0;
    string firstLineText = "";
    string firstLineText_FontName = "";
    double firstLineText_fontSize = 0;
    double firstLineText_color_R = 0;
    double firstLineText_color_G = 0;
    double firstLineText_color_B = 0;
    double firstLineText_alpha = 0;
    double lineSpacing0_1 = 0;
    string secondLineText = "";
    string secondLineText_FontName = "";
    double secondLineText_fontSize = 0;
    double secondLineText_color_R = 0;
    double secondLineText_color_G = 0;
    double secondLineText_color_B = 0;
    double secondLineText_alpha = 0;
    double lineSpacing1_2 = 0;
    string thirdLineText = "";
    string thirdLineText_FontName = "";
    double thirdLineText_fontSize = 0;
    double thirdLineText_color_R = 0;
    double thirdLineText_color_G = 0;
    double thirdLineText_color_B = 0;
    double thirdLineText_alpha = 0;
    double rotate = 0;

    //FZZBytes sealdata;
    //FZZBytes certdata;
    //FZZBytes prikeydata;
    string type = "JPG";
    FZZBytes signFileData;
    string format = "";
    //QString tempFileName = "";


    qDebug() << "DocView_AddWaterMark"   << Qt::endl;

    getParam = getGetParam(hm);



    if (dom.Parse(getParam.c_str()).HasParseError()) {
        status = -1;
        message = "不合法的JSON字符串";
        goto err;
    }

    if (!(dom.HasMember("fileID") && dom["fileID"].IsString())) {
        status = -2;
        message = "输入参数没有fileID字段";
        goto err;
    }

    fileID = dom["fileID"].GetString();
    if ( fileID.empty() ) {
        status = -3;
        message = "输入参数没有fileID字段的值为空";
        goto err;
    }

    pageindex = dom["pageCode"].GetInt();
    if ( pageindex < 0  ) {
        status = -3;
        message = "输入参数没有pageCode字段的值为空";
        goto err;
    }

    horizontalSpacing = dom["horizontalSpacing"].GetDouble();
//    if ( horizontalSpacing < 0  ) {
//        status = -3;
//        message = "输入参数horizontalSpacing字段的值为空";
//        goto err;
//    }

    verticalSpacing = dom["verticalSpacing"].GetDouble();
//    if ( verticalSpacing < 0  ) {
//        status = -3;
//        message = "输入参数verticalSpacing字段的值为空";
//        goto err;
//    }

    if (!(dom.HasMember("firstLineText") && dom["firstLineText"].IsString())) {
        status = -2;
        message = "输入参数没有firstLineText字段";
        goto err;
    }

    firstLineText = dom["firstLineText"].GetString();
    if ( firstLineText.empty() ) {
        status = -3;
        message = "输入参数没有firstLineText字段的值为空";
        goto err;
    }

    firstLineText = decodeURIComponent(firstLineText);

    if (!(dom.HasMember("firstLineText_FontName") && dom["firstLineText_FontName"].IsString())) {
        status = -2;
        message = "输入参数没有firstLineText_FontName字段";
        goto err;
    }

    firstLineText_FontName = dom["firstLineText_FontName"].GetString();
//    if ( firstLineText_FontName.empty() ) {
//        status = -3;
//        message = "输入参数没有firstLineText_FontName字段的值为空";
//        goto err;
//    }
    firstLineText_FontName = decodeURIComponent(firstLineText_FontName);

    firstLineText_fontSize = dom["firstLineText_fontSize"].GetDouble();
//    if ( firstLineText_fontSize < 0  ) {
//        status = -3;
//        message = "输入参数firstLineText_fontSize字段的值为空";
//        goto err;
//    }

    firstLineText_color_R = dom["firstLineText_color_R"].GetDouble();
//    if ( firstLineText_color_R < 0  ) {
//        status = -3;
//        message = "输入参数firstLineText_color_R字段的值为空";
//        goto err;
//    }

    firstLineText_color_G = dom["firstLineText_color_G"].GetDouble();
//    if ( firstLineText_color_G < 0  ) {
//        status = -3;
//        message = "输入参数firstLineText_color_G字段的值为空";
//        goto err;
//    }

    firstLineText_color_B = dom["firstLineText_color_B"].GetDouble();
//    if ( firstLineText_color_B < 0  ) {
//        status = -3;
//        message = "输入参数firstLineText_color_B字段的值为空";
//        goto err;
//    }

    firstLineText_alpha = dom["firstLineText_alpha"].GetDouble();
//    if ( firstLineText_alpha < 0  ) {
//        status = -3;
//        message = "输入参数firstLineText_alpha字段的值为空";
//        goto err;
//    }

    if (!(dom.HasMember("secondLineText") && dom["secondLineText"].IsString())) {
        status = -2;
        message = "输入参数没有firstLineText字段";
        goto err;
    }

    secondLineText = dom["secondLineText"].GetString();
//    if ( secondLineText.empty() ) {
//        status = -3;
//        message = "输入参数没有secondLineText字段的值为空";
//        goto err;
//    }
    secondLineText = decodeURIComponent(secondLineText);


    if (!(dom.HasMember("secondLineText_FontName") && dom["secondLineText_FontName"].IsString())) {
        status = -2;
        message = "输入参数没有secondLineText_FontName字段";
        goto err;
    }

    secondLineText_FontName = dom["secondLineText_FontName"].GetString();
//    if ( secondLineText_FontName.empty() ) {
//        status = -3;
//        message = "输入参数没有secondLineText_FontName字段的值为空";
//        goto err;
//    }
    secondLineText_FontName = decodeURIComponent(secondLineText_FontName);

    secondLineText_fontSize = dom["secondLineText_fontSize"].GetDouble();
//    if ( secondLineText_fontSize < 0  ) {
//        status = -3;
//        message = "输入参数secondLineText_fontSize字段的值为空";
//        goto err;
//    }

    secondLineText_color_R = dom["secondLineText_color_R"].GetDouble();
//    if ( secondLineText_color_R < 0  ) {
//        status = -3;
//        message = "输入参数secondLineText_color_R字段的值为空";
//        goto err;
//    }

    secondLineText_color_G = dom["secondLineText_color_G"].GetDouble();
//    if ( secondLineText_color_G < 0  ) {
//        status = -3;
//        message = "输入参数secondLineText_color_G字段的值为空";
//        goto err;
//    }

    secondLineText_color_B = dom["secondLineText_color_B"].GetDouble();
//    if ( secondLineText_color_B < 0  ) {
//        status = -3;
//        message = "输入参数secondLineText_color_B字段的值为空";
//        goto err;
//    }

    secondLineText_alpha = dom["secondLineText_alpha"].GetDouble();
//    if ( secondLineText_alpha < 0  ) {
//        status = -3;
//        message = "输入参数secondLineText_alpha字段的值为空";
//        goto err;
//    }

    lineSpacing0_1 = dom["lineSpacing0_1"].GetDouble();
//    if ( lineSpacing0_1 < 0  ) {
//        status = -3;
//        message = "输入参数lineSpacing0_1字段的值为空";
//        goto err;
//    }

    lineSpacing1_2 = dom["lineSpacing1_2"].GetDouble();
//    if ( lineSpacing1_2 < 0  ) {
//        status = -3;
//        message = "输入参数lineSpacing1_2字段的值为空";
//        goto err;
//    }

    if (!(dom.HasMember("thirdLineText") && dom["thirdLineText"].IsString())) {
        status = -2;
        message = "输入参数没有thirdLineText字段";
        goto err;
    }

    thirdLineText = dom["thirdLineText"].GetString();
//    if ( thirdLineText.empty() ) {
//        status = -3;
//        message = "输入参数没有thirdLineText字段的值为空";
//        goto err;
//    }
    thirdLineText = decodeURIComponent(thirdLineText);


    if (!(dom.HasMember("thirdLineText_FontName") && dom["thirdLineText_FontName"].IsString())) {
        status = -2;
        message = "输入参数没有thirdLineText_FontName字段";
        goto err;
    }

    thirdLineText_FontName = dom["thirdLineText_FontName"].GetString();
//    if ( thirdLineText_FontName.empty() ) {
//        status = -3;
//        message = "输入参数没有thirdLineText_FontName字段的值为空";
//        goto err;
//    }
    thirdLineText_FontName = decodeURIComponent(thirdLineText_FontName);

    thirdLineText_fontSize = dom["thirdLineText_fontSize"].GetDouble();
//    if ( thirdLineText_fontSize < 0  ) {
//        status = -3;
//        message = "输入参数thirdLineText_fontSize字段的值为空";
//        goto err;
//    }

    thirdLineText_color_R = dom["thirdLineText_color_R"].GetDouble();
//    if ( thirdLineText_color_R < 0  ) {
//        status = -3;
//        message = "输入参数thirdLineText_color_R字段的值为空";
//        goto err;
//    }

    thirdLineText_color_G = dom["thirdLineText_color_G"].GetDouble();
//    if ( thirdLineText_color_G < 0  ) {
//        status = -3;
//        message = "输入参数thirdLineText_color_G字段的值为空";
//        goto err;
//    }

    thirdLineText_color_B = dom["thirdLineText_color_B"].GetDouble();
//    if ( thirdLineText_color_B < 0  ) {
//        status = -3;
//        message = "输入参数thirdLineText_color_B字段的值为空";
//        goto err;
//    }

    thirdLineText_alpha = dom["thirdLineText_alpha"].GetDouble();
//    if ( thirdLineText_alpha < 0  ) {
//        status = -3;
//        message = "输入参数thirdLineText_alpha字段的值为空";
//        goto err;
//    }

    rotate = dom["rotate"].GetDouble();
//    if ( rotate < 0  ) {
//        status = -3;
//        message = "输入参数rotate字段的值为空";
//        goto err;
//    }

    //qDebug() << "DocView_Stamp_Pos pageindex: "   << pageindex << " left: "<<left << " top:" << top << Qt::endl;

    fileType = getFiles_FileType(fileID);
    srcFileData = getFiles_FileData(fileID);

    if ( srcFileData->getLen() <= 30 ) {
        status = -7;
        message = "获取原始文档数据失败！";
        goto err;
    }

    if ( fileType == 1 ) {
        format = "ofd";
    } else if (fileType == 2) {
        format = "pdf";
    } else {
        status = -4;
        message = "未知的文档类型！";
        goto err;
    }

    g_OFDPDFSignerProxy.addWaterMark_Text(fileType,(const unsigned char *)srcFileData->getData(),srcFileData->getLen(),
                                         horizontalSpacing,verticalSpacing,(char *)(firstLineText.c_str()),
                                         (char *)(firstLineText_FontName.c_str()),  firstLineText_fontSize, firstLineText_color_R,
                                         firstLineText_color_G, firstLineText_color_B, firstLineText_alpha,
                                         lineSpacing0_1, (char *)secondLineText.c_str(),(char *)secondLineText_FontName.c_str(),
                                         secondLineText_fontSize, secondLineText_color_R,secondLineText_color_G,
                                         secondLineText_color_B, secondLineText_alpha,lineSpacing1_2,
                                         (char *)thirdLineText.c_str(), (char *)thirdLineText_FontName.c_str(),
                                         thirdLineText_fontSize, thirdLineText_color_R,thirdLineText_color_G, thirdLineText_color_B,
                                         thirdLineText_alpha,rotate, &outdata,&outdatalen);



    if ( outdatalen <= 30 ) {
        status = -6;
        message = "对文档添加水印失败！";
        goto err;
    }

    signFileData.setData(outdata,outdatalen);

    fileID = genFileID();

    OpenFile(fileID,format,&signFileData,type,&status,message,&pageCount,&imageWidth,&imageHeight);

err:

    mg_http_reply(c, 200, CORSSTRING, "callback({\"status\":%d,\"message\":\"%s\",\"data\":{"
                  "\"fileID\":\"%s\","
                  "\"pageCount\":%d,"
                  "\"imageWidth\":%d,"
                  "\"imageHeight\":%d"
                  "}})\n",status,message.c_str(),fileID.c_str(),pageCount,imageWidth,imageHeight);

    if ( outdata != NULL ) {
        g_OFDPDFSignerProxy.FreeHandle(outdata);
        outdata = NULL;
    }
}
//-----------------------------------------------------------------------------------------------------------------
