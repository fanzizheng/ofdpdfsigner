#include "custom_signstamp_pos_dialog.h"
#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QFileDialog>
#include <QStandardPaths>
#include "mymessagebox.h"
//----------------------------------------------------------------------------------------------------------
Custom_SignStamp_Pos_Dialog::Custom_SignStamp_Pos_Dialog(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent,f),m_doctype(0)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | windowFlags());
    setStyleSheet(
                "    background: transparent;"
                  );
    QRect rect = parent->geometry();

    QScreen *desktopSize = QApplication::primaryScreen();

    this->setGeometry((desktopSize->size().width() - 440)/2, (desktopSize->size().height() - 320)/2, 440,320);

    m_ClientParent = new QWidget(this);

    m_ClientParent->setStyleSheet(
                        "background: "
                        BACKGROUD_COLOR_TABBAR
                        //"   border-radius: 10px;"
                          );
    QRect rectClient(0,0,440,320);
    m_ClientParent->setGeometry(rectClient);

    m_Layout = new QGridLayout(m_ClientParent);

    m_QHTitle = new QHBoxLayout();

    m_QLTitle = new QLabel(m_ClientParent);
    m_QLTitle->setText("位置盖章");
    m_QLTitle->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 4px;"
                                "margin-bottom : 4px;"
                                "margin-left : 10px;"
                                "font-size: 14px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    //m_QLTitle->show();
    m_QHTitle->addWidget(m_QLTitle,1,Qt::AlignTop);


    m_CloseButton = new QPushButton(m_ClientParent);
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
    //m_CloseButton->show();
    m_QHTitle->addWidget(m_CloseButton,0);


    m_Layout->addLayout(m_QHTitle,0,0,1,0);



    m_QWTitleLine = new QWidget(m_ClientParent);
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
//-----------------------------------------------------
    QVBoxLayout * QVClient = new QVBoxLayout();
    m_QHClient->addLayout(QVClient);
//cert
    QHBoxLayout* qhblCertTitle = new QHBoxLayout();
    QLabel * qlCert = new QLabel(m_ClientParent);
    qlCert->setText("请选择盖章数字证书文件");
    qlCert->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-left : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlCert->setWordWrap(true);
    //qlCert->show();
    qhblCertTitle->addWidget(qlCert,0,Qt::AlignTop);
    QVClient->addLayout(qhblCertTitle);

    QHBoxLayout* qhblCertselect = new QHBoxLayout();

    m_LeCert = new QLineEdit(m_ClientParent);
    m_LeCert->setFixedHeight(20);
    m_LeCert->setStyleSheet("QLineEdit"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                    "margin-left : 10px;"
                                    "font-size: 12px;"
                                    "padding:2px;"
                                    "background-color : #ffffff"
                               "}"
                              );
    m_LeCert->setClearButtonEnabled(true);

#ifdef __APPLE__
    m_LeCert->setText("/Users/fzz/Documents/test/seal/StampUserCert.cer");
#elif __linux__
    m_LeCert->setText("/home/fzz/testdoc/ofd/sealuser.cer");
#elif _MSC_VER || _WIN32 || _WIN64
    m_LeCert->setText("C:/Users/fzz/Documents/test/sealuser.cer");
#endif
    qhblCertselect->addWidget(m_LeCert,0,Qt::AlignTop);

    QPushButton * apbCertselect = new QPushButton(m_ClientParent);
    apbCertselect->setFixedSize(30,20);
    apbCertselect->setText("...");
    apbCertselect->setStyleSheet("QPushButton"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                  "margin-right : 10px;"
                                  "border-width:1px;"/*边框宽度*/
                                  "border-color:" /*边框颜色*/
                                  BORDE_COLOR
                                  "border-radius:0px;" /*边框倒角*/
                                "font-size: 12px;"
                                    "padding:4px;"
                               "}"
                              );

    apbCertselect->setFlat(false);
    //apbCertselect->show();
    connect(apbCertselect, &QPushButton::clicked, this, &Custom_SignStamp_Pos_Dialog::btnClicked_Certselect);
    qhblCertselect->addWidget(apbCertselect,1,Qt::AlignTop);

    QVClient->addLayout(qhblCertselect);
    //prikey
    QHBoxLayout* qhblPriKeyTitle = new QHBoxLayout();
    QLabel * qlprikey = new QLabel(m_ClientParent);
    qlprikey->setText("请选择盖章数字证书对应私钥文件");
    qlprikey->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-left : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlprikey->setWordWrap(true);
    //qlprikey->show();
    qhblPriKeyTitle->addWidget(qlprikey,0,Qt::AlignTop);
    QVClient->addLayout(qhblPriKeyTitle);

    QHBoxLayout* qhblPrikey = new QHBoxLayout();

    m_LePriKey = new QLineEdit(m_ClientParent);
    m_LePriKey->setFixedHeight(20);
    m_LePriKey->setStyleSheet("QLineEdit"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                    "margin-left : 10px;"
                                    "font-size: 12px;"
                                    "padding:2px;"
                                    "background-color : #ffffff"
                               "}"
                              );
    m_LePriKey->setClearButtonEnabled(true);
#ifdef __APPLE__
     m_LePriKey->setText("/Users/fzz/Documents/test/seal/StampUserCertPriKey.key");
#elif __linux__
     m_LePriKey->setText("/home/fzz/testdoc/ofd/sealuserpirkey.key");
#elif _MSC_VER || _WIN32 || _WIN64
    m_LePriKey->setText("C:/Users/fzz/Documents/test/sealuserpirkey.key");
#endif

    qhblPrikey->addWidget(m_LePriKey,0,Qt::AlignTop);

    QPushButton * apbprikey = new QPushButton(m_ClientParent);
    apbprikey->setFixedSize(30,20);
    apbprikey->setText("...");
    apbprikey->setStyleSheet("QPushButton"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                  "margin-right : 10px;"
                                  "border-width:1px;"/*边框宽度*/
                                  "border-color:" /*边框颜色*/
                                  BORDE_COLOR
                                  "border-radius:0px;" /*边框倒角*/
                                "font-size: 12px;"
                                    "padding:4px;"
                               "}"
                              );

    apbprikey->setFlat(false);
    //apbprikey->show();
    connect(apbprikey, &QPushButton::clicked, this, &Custom_SignStamp_Pos_Dialog::btnClicked_PriKey);
    qhblPrikey->addWidget(apbprikey,1,Qt::AlignTop);

    QVClient->addLayout(qhblPrikey);
//stamp
    QHBoxLayout* qhblStampTitle = new QHBoxLayout();
    QLabel * qlStamptile = new QLabel(m_ClientParent);
    qlStamptile->setText("请选择印章文件");
    qlStamptile->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-left : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlStamptile->setWordWrap(true);
    //qlStamptile->show();
    qhblStampTitle->addWidget(qlStamptile,0,Qt::AlignTop);
    QVClient->addLayout(qhblStampTitle);

    QHBoxLayout* qhblStamp = new QHBoxLayout();

    m_LeStamp = new QLineEdit(m_ClientParent);
    m_LeStamp->setFixedHeight(20);
    m_LeStamp->setStyleSheet("QLineEdit"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                    "margin-left : 10px;"
                                    "font-size: 12px;"
                                    "padding:2px;"
                                    "background-color : #ffffff"
                               "}"
                              );
    m_LeStamp->setClearButtonEnabled(true);

#ifdef __APPLE__
    m_LeStamp->setText("/Users/fzz/Documents/test/seal/Stamp.sel");
#elif __linux__
    m_LeStamp->setText("/home/fzz/testdoc/ofd/seal.sel");
#elif _MSC_VER || _WIN32 || _WIN64
    m_LeStamp->setText("C:/Users/fzz/Documents/test/seal.sel");
#endif
    qhblStamp->addWidget(m_LeStamp,0,Qt::AlignTop);

    QPushButton * apbStamp = new QPushButton(m_ClientParent);
    apbStamp->setFixedSize(30,20);
    apbStamp->setText("...");
    apbStamp->setStyleSheet("QPushButton"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                  "margin-right : 10px;"
                                  "border-width:1px;"/*边框宽度*/
                                  "border-color:" /*边框颜色*/
                                  BORDE_COLOR
                                  "border-radius:0px;" /*边框倒角*/
                                "font-size: 12px;"
                                    "padding:4px;"
                               "}"
                              );

    apbStamp->setFlat(false);
    //apbStamp->show();
    connect(apbStamp, &QPushButton::clicked, this, &Custom_SignStamp_Pos_Dialog::btnClicked_Stamp);
    qhblStamp->addWidget(apbStamp,1,Qt::AlignTop);

    QVClient->addLayout(qhblStamp);
    //saveas
    QHBoxLayout* qhblSaveTitle = new QHBoxLayout();
    QLabel * qlSaveastile = new QLabel(m_ClientParent);
    qlSaveastile->setText("请选择盖章后文件的保存位置");
    qlSaveastile->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-left : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlSaveastile->setWordWrap(true);
    //qlSaveastile->show();
    qhblSaveTitle->addWidget(qlSaveastile,0,Qt::AlignTop);
    QVClient->addLayout(qhblSaveTitle);

    QHBoxLayout* qhblSaveas = new QHBoxLayout();

    m_LeSaveas = new QLineEdit(m_ClientParent);
    m_LeSaveas->setFixedHeight(20);
    m_LeSaveas->setStyleSheet("QLineEdit"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                    "margin-left : 10px;"
                                    "font-size: 12px;"
                                    "padding:2px;"
                                    "background-color : #ffffff"
                               "}"
                              );
    m_LeSaveas->setClearButtonEnabled(true);

#ifdef __APPLE__
    m_LeSaveas->setText("/Users/fzz/Documents/test/ofd/盖章后文档.ofd");
#elif __linux__
    m_LeSaveas->setText("/home/fzz/testdoc/ofd/盖章后文档.ofd");
#elif _MSC_VER || _WIN32 || _WIN64
    m_LeSaveas->setText("C:/Users/fzz/Documents/test/ofd/盖章后文档.ofd");
#endif
    qhblSaveas->addWidget(m_LeSaveas,0,Qt::AlignTop);

    QPushButton * apbSaveas = new QPushButton(m_ClientParent);
    apbSaveas->setFixedSize(30,20);
    apbSaveas->setText("...");
    apbSaveas->setStyleSheet("QPushButton"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                  "margin-right : 10px;"
                                  "border-width:1px;"/*边框宽度*/
                                  "border-color:" /*边框颜色*/
                                  BORDE_COLOR
                                  "border-radius:0px;" /*边框倒角*/
                                "font-size: 12px;"
                                    "padding:4px;"
                               "}"
                              );

    apbSaveas->setFlat(false);
    //apbSaveas->show();
    connect(apbSaveas, &QPushButton::clicked, this, &Custom_SignStamp_Pos_Dialog::btnClicked_Saveas);
    qhblSaveas->addWidget(apbSaveas,1,Qt::AlignTop);

    QVClient->addLayout(qhblSaveas);
    //null =》 16px
    QHBoxLayout* qhblNULLTitle = new QHBoxLayout();
    QLabel * qlNULLtile = new QLabel(m_ClientParent);
    qlNULLtile->setText("");
    qlNULLtile->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 0px;"
                               "margin-bottom : 0px;"
                                "margin-left : 0px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlNULLtile->setWordWrap(true);
    //qlNULLtile->show();
    qhblNULLTitle->addWidget(qlNULLtile,0,Qt::AlignTop);
    QVClient->addLayout(qhblNULLTitle);
    //-----------------------------------------------------

    m_Layout->addLayout(m_QHClient,2,0,1,1);

    m_QWButtonsLine = new QWidget(m_ClientParent);
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

    m_OKButton = new QPushButton(m_ClientParent);
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
    //m_OKButton->show();
    m_QHButtons->addWidget(m_OKButton,0);

    m_CancelButton = new QPushButton(m_ClientParent);
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
    //m_CancelButton->show();
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


    connect(m_CloseButton, &QPushButton::clicked, this, &Custom_SignStamp_Pos_Dialog::btnClicked_Close);
    connect(m_OKButton, &QPushButton::clicked, this, &Custom_SignStamp_Pos_Dialog::btnClicked_OK);
    connect(m_CancelButton, &QPushButton::clicked, this, &Custom_SignStamp_Pos_Dialog::btnClicked_Close);

}
//----------------------------------------------------------------------------------------------------------
Custom_SignStamp_Pos_Dialog::~Custom_SignStamp_Pos_Dialog()
{
    if ( m_ClientParent != NULL ) {
        delete m_ClientParent;
        m_ClientParent = NULL;
    }
}
//----------------------------------------------------------------------------------------------------------
void Custom_SignStamp_Pos_Dialog::btnClicked_Close()
{
    reject();
}
//----------------------------------------------------------------------------------------------------------
void Custom_SignStamp_Pos_Dialog::btnClicked_OK()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    if ( getCertFileName().trimmed().isEmpty() ) {
        myMessageBox.setContent("请选择签章证书！");
        myMessageBox.exec();
        return;
    }
    if ( getPriKeyFileName().trimmed().isEmpty() ) {
        myMessageBox.setContent("请选择签章私钥！");
        myMessageBox.exec();
        return;
    }

    if ( getStampFileName().trimmed().isEmpty() ) {
        myMessageBox.setContent("请选择印章图片文件！");
        myMessageBox.exec();
        return;
    }

    if ( getSaveasFileName().trimmed().isEmpty() ) {
        myMessageBox.setContent("请选择保存盖章后的文件！");
        myMessageBox.exec();
        return;
    }

    QString stampFilename = getStampFileName();
    QString saveas = getSaveasFileName();
    if ( m_doctype == 1 ) {
        saveas = saveas.toLower();
        if ( !saveas.endsWith(".ofd") ) {
            myMessageBox.setContent("请选择保存盖章后的文件类型为OFD！");
            myMessageBox.exec();
            return;
        }

        stampFilename = stampFilename.toLower();
        if ( !stampFilename.endsWith(".sel") ) {
            myMessageBox.setContent("请选择sel类型的印章文件！");
            myMessageBox.exec();
            return;
        }

    } else {
        saveas = saveas.toLower();
        if ( !saveas.endsWith(".pdf") ) {
            myMessageBox.setContent("请选择保存盖章后的文件类型为PDF！");
            myMessageBox.exec();
            return;
        }

        stampFilename = stampFilename.toLower();
        if ( !stampFilename.endsWith(".png") ) {
            myMessageBox.setContent("请选择png类型的印章文件！");
            myMessageBox.exec();
            return;
        }
    }

    accept();
}
//----------------------------------------------------------------------------------------------------------
void Custom_SignStamp_Pos_Dialog::btnClicked_Saveas()
{
    QFileDialog fileDialog;
    QString selectType = "";
    QString saveasfileName = "";
    if ( m_doctype == 1 ) {
        saveasfileName = fileDialog.getSaveFileName(this,tr("保存盖章后的文件"),QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/盖章后文档",QStringLiteral("OFD文档(*.ofd)"),&selectType);
    } else if ( m_doctype == 2 ) {
        saveasfileName = fileDialog.getSaveFileName(this,tr("保存盖章后的文件"),QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/盖章后文档",QStringLiteral("OFD文档(*.pdf)"),&selectType);
    }
    m_LeSaveas->setText(saveasfileName);
}
//----------------------------------------------------------------------------------------------------------
void Custom_SignStamp_Pos_Dialog::btnClicked_Stamp()
{
    QString sealfileName = "";
    if ( m_doctype == 1 ) {
        sealfileName = QFileDialog::getOpenFileName(this, QStringLiteral("请选择国办印章文件"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),QStringLiteral("印章文件(*.sel);; ""印章文件(*.dat)"));
    } else if ( m_doctype == 2 ) {
        sealfileName = QFileDialog::getOpenFileName(this, QStringLiteral("请选择印章图片文件"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),QStringLiteral("印章图片(*.png);;""印章图片(*.png)"));
    }
    m_LeStamp->setText(sealfileName);
}
//----------------------------------------------------------------------------------------------------------
void Custom_SignStamp_Pos_Dialog::btnClicked_PriKey()
{
    QString privateKeyfileName = QFileDialog::getOpenFileName(this, QStringLiteral("请选择签章私钥"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),QStringLiteral("私钥文件(*.key);; ""私钥文件(*.dat)"));
    m_LePriKey->setText(privateKeyfileName);
}
//----------------------------------------------------------------------------------------------------------
void Custom_SignStamp_Pos_Dialog::btnClicked_Certselect()
{
    QString certfileName = QFileDialog::getOpenFileName(this, QStringLiteral("请选择签章证书"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),QStringLiteral("证书文件(*.cer);; ""证书文件(*.dat)"));
    m_LeCert->setText(certfileName);
}
//----------------------------------------------------------------------------------------------------------
