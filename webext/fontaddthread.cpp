#include "fontaddthread.h"
//#include "mainwidget.h"
#include "RestfulServer.h"



//----------------------------------------------------------------------------------------------------------
FontAddThread::FontAddThread(QObject *parent) : QThread(parent) ,isStop(false),isEnd(false)
{

}
//----------------------------------------------------------------------------------------------------------
void FontAddThread::run()
{
//    if ( m_MainWidget == NULL ) {
//        return;
//    }

    isStop = false;
    isEnd = false;

    QList<QString>::const_iterator it;
    //qDebug() << "FontAddThread => size :" << m_MainWidget->m_SystemFontFiles.size()  << Qt::endl;
    for( it = g_SystemFontFiles.begin(); it != g_SystemFontFiles.end(); it++ ) {
        if ( isStop  ) break;
        QByteArray ba = (*it).toUtf8();
        char* pTempWord = ba.data();
        //qDebug() << "FontAddThread => add begin :" << pTempWord  << Qt::endl;
        g_OFDPDFSignerProxy.saveFontFileNameCache(pTempWord);
        //qDebug() << "FontAddThread => add end :" << pTempWord  << Qt::endl;
        QThread::msleep(100);

    }
    isEnd = true;
}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
//WebThread::WebThread(QObject *parent) : QThread(parent) ,isStop(false),isEnd(false),m_isPause(false)
//{

//}
////----------------------------------------------------------------------------------------------------------
//void WebThread::run()
//{
////    if ( m_MainWidget == NULL ) {
////        return;
////    }

//    isStop = false;
//    isEnd = false;


//    //qDebug() << "FontAddThread => size :" << m_MainWidget->m_SystemFontFiles.size()  << Qt::endl;



//    struct mg_mgr mgr;                            // Event manager
//    mg_log_set(MG_LL_DEBUG);                      // Set log level
//    mg_mgr_init(&mgr);                            // Initialise event manager
//    mg_http_listen(&mgr, s_http_addr, process, NULL);  // Create HTTP listener
//    //mg_http_listen(&mgr, s_https_addr, fn, (void *) 1);  // HTTPS listener
//    //for (;;) mg_mgr_poll(&mgr, timeout);                    // Infinite event loop
//    while(!isStop) {
//        if ( !m_isPause ) {
//            mg_mgr_poll(&mgr, timeout);
//        } else {
//            QThread::msleep(100);
//        }
//    }
//    mg_mgr_free(&mgr);

//    isEnd = true;
//}
////----------------------------------------------------------------------------------------------------------
