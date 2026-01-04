#include "mymessagebox.h"
#include <QApplication>
#include <QScreen>
#include <QDebug>
//----------------------------------------------------------------------------------------------------------
MyMessageBox::MyMessageBox(QWidget * parent, Qt::WindowFlags f )
    :QDialog(parent,f)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | windowFlags());
    setStyleSheet(
                "    background: transparent;"
                  );
    QRect rect = parent->geometry();
//    this->setGeometry(rect);
//    setFixedSize(rect.width(),rect.height());

//    m_SelfParent = new QWidget(this);
//    m_SelfParent->setStyleSheet(
//                            "background: rgba(255, 255, 255, 0.5);"
//                            "   border-radius: 10px;"
//                              );
//    m_SelfParent->setGeometry(0,0,rect.width(),rect.height());

    //m_ClientParent = new QWidget(m_SelfParent);
    //this->setFixedWidth(300);
    //this->setFixedHeight(200);
    QScreen *desktopSize = QApplication::primaryScreen();
    //move((desktopSize->size().width() - 300)/2, (desktopSize->size().height() - 200)/2);



    this->setGeometry((desktopSize->size().width() - 300)/2, (desktopSize->size().height() - 200)/2, 300,200);

    m_ClientParent = new QWidget(this);

    m_ClientParent->setStyleSheet(
                        "background: "
                        BACKGROUD_COLOR_TABBAR
                        //"   border-radius: 10px;"
                          );
    QRect rectClient(0,0,300,200);
    m_ClientParent->setGeometry(rectClient);

    m_Layout = new QGridLayout(m_ClientParent);

    m_QHTitle = new QHBoxLayout();

    m_QLTitle = new QLabel();
    m_QLTitle->setText("提示");
    m_QLTitle->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 4px;"
                                "margin-bottom : 4px;"
                                "margin-left : 10px;"
                                "font-size: 14px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    m_QLTitle->show();
    m_QHTitle->addWidget(m_QLTitle,1,Qt::AlignTop);


    m_CloseButton = new QPushButton();
    m_CloseButton->setIcon(QIcon(":/res/images/close.png"));
    m_CloseButton->setIconSize(QSize(20,20));
    m_CloseButton->setMaximumSize(24,24);
    m_CloseButton->setMinimumSize(24,24);
    m_CloseButton->setStyleSheet("QPushButton"
                               "{"
                               "margin-right : 10px;"
                               "   border:0px solid transparent;"
                               "}"
                              );

    m_CloseButton->setFlat(true);
    m_CloseButton->show();
    m_QHTitle->addWidget(m_CloseButton,0);


    m_Layout->addLayout(m_QHTitle,0,0,1,0);



    m_QWTitleLine = new QWidget();
    m_QWTitleLine->setMinimumHeight(5);
    m_QWTitleLine->setMaximumHeight(5);
    m_QWTitleLine->setStyleSheet("QWidget"
                               "{"
                               "margin-top : 4px;"
                               "   border-radius: 0px;"
                               "   border:0px solid transparent;"
                               "   border-bottom:1px solid "
                               BORDE_COLOR
                               "}"
                              );

    m_Layout->addWidget(m_QWTitleLine,1,0,1,1);



    m_QHClient = new QHBoxLayout();

    m_TishiButton = new QPushButton();
    m_TishiButton->setIcon(QIcon(":/res/images/tishi.png"));
    m_TishiButton->setIconSize(QSize(44,44));
    m_TishiButton->setMaximumSize(54,60);
    m_TishiButton->setMinimumSize(54,60);
    m_TishiButton->setStyleSheet("QPushButton"
                               "{"
                                 "margin-top : 16px;"
                               "margin-left : 10px;"
                               "   border:0px solid transparent;"
                               "}"
                              );

    m_TishiButton->setFlat(true);
    m_TishiButton->show();
    m_QHClient->addWidget(m_TishiButton,0,Qt::AlignTop);
    m_QHClient->setSpacing(6);

    m_QLContent = new QLabel();
    m_QLContent->setText("附件多少了");
    m_QLContent->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-right : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    m_QLContent->setWordWrap(true);
    m_QLContent->show();

    m_QHClient->addWidget(m_QLContent,1,Qt::AlignTop);

    m_Layout->addLayout(m_QHClient,2,0,1,1);

    m_QWButtonsLine = new QWidget();
    m_QWButtonsLine->setMinimumHeight(5);
    m_QWButtonsLine->setMaximumHeight(5);
    m_QWButtonsLine->setStyleSheet("QWidget"
                               "{"
                               "margin-top : 4px;"
                               "   border-radius: 0px;"
                               "   border:0px solid transparent;"
                               "   border-bottom:1px solid "
                               BORDE_COLOR
                               "}"
                              );


    m_Layout->addWidget(m_QWButtonsLine,3,0,1,1);

    m_QHButtons = new QHBoxLayout();

    m_OKButton = new QPushButton();
    m_OKButton->setFixedSize(100,40);
    m_OKButton->setText("确  定");
    m_OKButton->setStyleSheet("QPushButton"
                               "{"
                              "margin-top : 10px;"
                              "margin-bottom : 4px;"
                                  "border-width:1px;"/*边框宽度*/
                                  "border-color:" /*边框颜色*/
                                  BORDE_COLOR
                                  "border-radius:8px;" /*边框倒角*/
                                "font-size: 14px;"
                                    "padding:4px;"
                               "}"
                              );

    m_OKButton->setFlat(false);
    m_OKButton->show();
    m_QHButtons->addWidget(m_OKButton,0);

    m_CancelButton = new QPushButton();
    m_CancelButton->setFixedSize(100,40);
    m_CancelButton->setText("取  消");
    m_CancelButton->setStyleSheet("QPushButton"
                               "{"
                                  "margin-top : 10px;"
                                  "margin-bottom : 4px;"
                                  "border-width:1px;"/*边框宽度*/
                                  "border-color:" /*边框颜色*/
                                  BORDE_COLOR
                                  "border-radius:8px;" /*边框倒角*/
                                "font-size: 14px;"
                                    "padding:4px;"
                               "}"
                              );

    m_CancelButton->setFlat(false);
    m_CancelButton->show();
    m_QHButtons->addWidget(m_CancelButton,0);

    m_Layout->addLayout(m_QHButtons,4,0,1,0);




    m_Layout->setContentsMargins(0,8,0,8);
    m_Layout->setColumnStretch(0,1);
    m_Layout->setRowStretch(0,0);
    m_Layout->setRowStretch(1,1);
    m_Layout->setRowStretch(2,1);
    m_Layout->setRowStretch(3,1);
    m_Layout->setRowStretch(4,0);
    m_Layout->setHorizontalSpacing(0);
    m_Layout->setVerticalSpacing(0);


    connect(m_CloseButton, &QPushButton::clicked, this, &MyMessageBox::btnClicked_Close);
    connect(m_OKButton, &QPushButton::clicked, this, &MyMessageBox::btnClicked_OK);
    connect(m_CancelButton, &QPushButton::clicked, this, &MyMessageBox::btnClicked_Close);

}
//----------------------------------------------------------------------------------------------------------
MyMessageBox::~MyMessageBox()
{
//    if ( m_SelfParent != NULL ) {
//        delete m_SelfParent;
//        m_SelfParent = NULL;
//    }

    if ( m_ClientParent != NULL ) {
        delete m_ClientParent;
        m_ClientParent = NULL;
    }

//    if ( m_Layout != NULL ) {
//        delete m_Layout;
//        m_Layout = NULL;
//    }

//    if ( m_QHTitle != NULL ) {
//        delete m_QHTitle;
//        m_QHTitle = NULL;
//    }

//    if ( m_QHClient != NULL ) {
//        delete m_QHClient;
//        m_QHClient = NULL;
//    }

//    if ( m_QHButtons != NULL ) {
//        delete m_QHButtons;
//        m_QHButtons = NULL;
//    }

//    if ( m_QLTitle != NULL ) {
//        delete m_QLTitle;
//        m_QLTitle = NULL;
//    }

//    if ( m_CloseButton != NULL ) {
//        delete m_CloseButton;
//        m_CloseButton = NULL;
//    }

//    if ( m_QWTitleLine != NULL ) {
//        delete m_QWTitleLine;
//        m_QWTitleLine = NULL;
//    }
}
//----------------------------------------------------------------------------------------------------------
void MyMessageBox::btnClicked_Close()
{
    reject();
}
//----------------------------------------------------------------------------------------------------------
void MyMessageBox::btnClicked_OK()
{
    accept();
}
//----------------------------------------------------------------------------------------------------------
