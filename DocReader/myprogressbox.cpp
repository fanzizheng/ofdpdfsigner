#include "myprogressbox.h"

//----------------------------------------------------------------------------------------------------------
MyProgressBox::MyProgressBox(QWidget * parent, Qt::WindowFlags f )
    :QDialog(parent,f)
{

    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setStyleSheet(
                "    background: transparent;"
                  );
    //this->setModal(true);
    QRect rect = parent->geometry();
    this->setGeometry(rect);
    setFixedSize(rect.width(),rect.height());

    m_SelfParent = new QWidget(this);
    m_SelfParent->setStyleSheet(
                            "background: rgba(255, 255, 255, 0.5);"
                            "   border-radius: 10px;"
                              );
    m_SelfParent->setGeometry(0,0,rect.width(),rect.height());

    m_ClientParent = new QWidget(m_SelfParent);

    m_ClientParent->setStyleSheet(
                        "background: "
                        BACKGROUD_COLOR_TABBAR
                        "   border-radius: 10px;"
                          );
    QRect rectClient((rect.width()-300)/2,(rect.height()-80)/2,300,80);
    m_ClientParent->setGeometry(rectClient);

    m_Layout = new QGridLayout(m_ClientParent);

    m_QHTitle = new QHBoxLayout();

    m_QLTitle = new QLabel();
    m_QLTitle->setText("提示");
    m_QLTitle->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 10px;"
                                "margin-bottom : 4px;"
                                "margin-left : 10px;"
                                "font-size: 14px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    m_QLTitle->show();
    m_QHTitle->addWidget(m_QLTitle,1,Qt::AlignTop);

    m_Layout->addLayout(m_QHTitle,0,0,1,0);

    m_QHClient = new QHBoxLayout();

    m_QHClient->addSpacing(10);
    m_ProgressBar = new QProgressBar();
    m_ProgressBar->setStyleSheet("QProgressBar"
                               "{"
                                "margin-top : 6px;"
                                "margin-bottom : 4px;"
                                "margin-left : 0px;"
                                "margin-right : 10px;"

                               "}"
                              );
    m_ProgressBar->setMinimum(0);
    m_ProgressBar->setMaximum(0);


    m_QHClient->addWidget(m_ProgressBar,0);

    m_Layout->addLayout(m_QHClient,1,0,1,1);

    m_Layout->setContentsMargins(0,8,0,8);
    m_Layout->setColumnStretch(0,1);
    m_Layout->setRowStretch(0,0);
    m_Layout->setRowStretch(1,1);
    m_Layout->setHorizontalSpacing(0);
    m_Layout->setVerticalSpacing(0);
}
//----------------------------------------------------------------------------------------------------------
MyProgressBox::~MyProgressBox()
{
    if ( m_SelfParent != NULL ) {
        delete m_SelfParent;
        m_SelfParent = NULL;
    }
}
//----------------------------------------------------------------------------------------------------------

