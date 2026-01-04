#include "fontaddthread.h"
#include "mainwidget.h"

//----------------------------------------------------------------------------------------------------------
FontAddThread::FontAddThread(QObject *parent) : QThread(parent) ,m_MainWidget(NULL),isStop(false),isEnd(false)
{

}
//----------------------------------------------------------------------------------------------------------
void FontAddThread::run()
{
    if ( m_MainWidget == NULL ) {
        return;
    }

    isStop = false;
    isEnd = false;

    QList<QString>::const_iterator it;
    qDebug() << "FontAddThread => size :" << m_MainWidget->m_SystemFontFiles.size()  << Qt::endl;
    for( it = m_MainWidget->m_SystemFontFiles.begin(); it != m_MainWidget->m_SystemFontFiles.end(); it++ ) {
        if ( isStop  ) break;
        QByteArray ba = (*it).toUtf8();
        char* pTempWord = ba.data();
        qDebug() << "FontAddThread => add begin :" << pTempWord  << Qt::endl;
        m_MainWidget->m_OFDPDFSigner.saveFontFileNameCache(pTempWord);
        qDebug() << "FontAddThread => add end :" << pTempWord  << Qt::endl;
        QThread::msleep(100);

    }
    isEnd = true;
}
//----------------------------------------------------------------------------------------------------------
