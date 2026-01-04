#include "mainwindow.h"

#include <QApplication>
#include <QFileDialog>
#include <QStandardPaths>
#include "RestfulServer.h"
#include <QThread>
#include "fontaddthread.h"

//http://127.0.0.1:7655/showdoc.html

void SystemFontFileName(const void * param,const char* const fullFileName)
{
    g_SystemFontFiles.push_back(fullFileName);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setQuitOnLastWindowClosed(false);

    QString currExePath = QCoreApplication::applicationDirPath();

    currExePath.replace("\\","/");
#ifdef __APPLE__
    int dianpos = currExePath.lastIndexOf("/");
    if ( dianpos != -1 ) {
        currExePath = currExePath.left(dianpos);
    }
    QString dllname = currExePath + "/Frameworks/libofdpdfsigner.dylib";
#elif __linux__
    QString dllname = currExePath + "/lib/libofdpdfsigner.so";
#elif _MSC_VER || _WIN32 || _WIN64
    QString dllname = currExePath + "/ofdpdfsigner.dll";
#endif


    QByteArray bdllname = dllname.toUtf8();
    QByteArray bworkpath = currExePath.toUtf8();
    //qDebug() << "CurrEexePathdll => "<< bdllname.data() << Qt::endl;

    FontAddThread * m_FontAddThread = NULL;
    if ( g_OFDPDFSignerProxy.init(bdllname.data()) ) {

        g_OFDPDFSignerProxy.setWorkPath(bworkpath.data());
#ifdef __APPLE__
        QString strdefautfont = currExePath+"/Resources/OFDFonts/simsun.ttf";
#elif _MSC_VER || _WIN32 || _WIN64
        QString strdefautfont = currExePath + "/OFDFonts/simsun.ttf";
#endif
        QByteArray bdefaultfong = strdefautfont.toUtf8();
        g_OFDPDFSignerProxy.saveFontFileNameCache(bdefaultfong.data());

        g_OFDPDFSignerProxy.getAllSystemFontFileName(SystemFontFileName,NULL);

        m_FontAddThread = new FontAddThread();
        if ( m_FontAddThread != NULL ) {
            //m_FontAddThread->setMainWindwos(this);
            m_FontAddThread->start();
        }

        g_root_dir = currExePath;
        g_root_dir += "/webapp/";


    } else {
        return -1;
    }

    struct mg_mgr mgr;                            // Event manager
    mg_log_set(MG_LL_DEBUG);                      // Set log level
    mg_mgr_init(&mgr);                            // Initialise event manager
    mg_http_listen(&mgr, s_http_addr, process, NULL);  // Create HTTP listener
    //mg_http_listen(&mgr, s_https_addr, fn, (void *) 1);  // HTTPS listener
    for (;;) mg_mgr_poll(&mgr, timeout);                    // Infinite event loop
    mg_mgr_free(&mgr);


    if ( m_FontAddThread != NULL ) {
        m_FontAddThread->Stop();
        while(!(m_FontAddThread->isRunEnd())) {
            QThread::msleep(100);
        }
        m_FontAddThread->exit();
        m_FontAddThread->deleteLater();
    }

    //MainWindow w;
    //w.show();
    //return a.exec();
}



