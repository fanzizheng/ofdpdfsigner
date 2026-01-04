#include "watermark_dialog.h"

#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QFileDialog>
#include <QStandardPaths>
#include <QListView>
#include "mymessagebox.h"
//----------------------------------------------------------------------------------------------------------
WaterMark_Dialog::WaterMark_Dialog(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | windowFlags());
    setStyleSheet(
                "    background: transparent;"
                  );
    QRect rect = parent->geometry();

    QScreen *desktopSize = QApplication::primaryScreen();

    this->setGeometry((desktopSize->size().width() - 440)/2, (desktopSize->size().height() - 530)/2, 440,530);

    m_ClientParent = new QWidget(this);

    m_ClientParent->setStyleSheet(
                        "background: "
                        BACKGROUD_COLOR_TABBAR
                        //"   border-radius: 10px;"
                          );
    QRect rectClient(0,0,440,530);
    m_ClientParent->setGeometry(rectClient);

    m_Layout = new QGridLayout(m_ClientParent);

    m_QHTitle = new QHBoxLayout();

    m_QLTitle = new QLabel(m_ClientParent);
    m_QLTitle->setText("添加水印");
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
    m_CloseButton->show();
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
    qlSaveastile->show();
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
    m_LeSaveas->setText("/Users/fzz/Documents/test/ofd/加水印后文档.ofd");

#ifdef __APPLE__
    m_LeSaveas->setText("/Users/fzz/Documents/test/ofd/加水印后文档.ofd");
#elif __linux__
    m_LeSaveas->setText("/home/fzz/testdoc/ofd/加水印后文档.ofd");
#elif _MSC_VER || _WIN32 || _WIN64
    m_LeSaveas->setText("C:/Users/fzz/Documents/test/ofd/加水印后文档.ofd");
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
    apbSaveas->show();
    connect(apbSaveas, &QPushButton::clicked, this, &WaterMark_Dialog::btnClicked_Saveas);
    qhblSaveas->addWidget(apbSaveas,1,Qt::AlignTop);

    QVClient->addLayout(qhblSaveas);
//cert
    QHBoxLayout* qhblFirstTitle = new QHBoxLayout();
    QLabel * qlFirst = new QLabel(m_ClientParent);
    qlFirst->setFixedHeight(36);
    qlFirst->setText("请输入水印第一行文字");
    qlFirst->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-left : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlFirst->setWordWrap(true);
    qlFirst->show();
    qhblFirstTitle->addWidget(qlFirst,0,Qt::AlignTop);
    QVClient->addLayout(qhblFirstTitle);

    QHBoxLayout* qhblFirstselect = new QHBoxLayout();

    m_LeFirstText = new QLineEdit(m_ClientParent);
    m_LeFirstText->setFixedHeight(20);
    m_LeFirstText->setStyleSheet("QLineEdit"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                    "margin-left : 10px;"

                                    "font-size: 12px;"
                                    "padding:2px;"
                                    "background-color : #ffffff"
                               "}"
                              );
    m_LeFirstText->setClearButtonEnabled(true);
    m_LeFirstText->setText("水印第一行文字");
    qhblFirstselect->addWidget(m_LeFirstText,0,Qt::AlignTop);

    QPushButton * apbFirstspacing = new QPushButton(m_ClientParent);
    apbFirstspacing->setFixedSize(10,20);
    apbFirstspacing->setText("");
    apbFirstspacing->setStyleSheet("QPushButton"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                  "margin-right : 0px;"
                                  "border-width:0px;"/*边框宽度*/
                                  "border-color:" /*边框颜色*/
                                  BORDE_COLOR
                                  "border-radius:0px;" /*边框倒角*/
                                "font-size: 12px;"
                                    "padding:4px;"
                               "}"
                              );

    apbFirstspacing->setFlat(false);
    apbFirstspacing->show();
    //connect(apbCertselect, &QPushButton::clicked, this, &Custom_SignStamp_Riding_Dialog::btnClicked_Certselect);
    qhblFirstselect->addWidget(apbFirstspacing,1,Qt::AlignTop);

    QVClient->addLayout(qhblFirstselect);
    //prikey
    QHBoxLayout* qhblFirstFontTitleHBox = new QHBoxLayout();

    QLabel * qlFirstFont = new QLabel(m_ClientParent);
    qlFirstFont->setFixedSize(100,36);
    qlFirstFont->setText("请选择字体");
    qlFirstFont->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-left : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlFirstFont->setWordWrap(true);
    qlFirstFont->show();

    qhblFirstFontTitleHBox->addWidget(qlFirstFont,0,Qt::AlignTop);

    QLabel * qlFirstFontSize = new QLabel(m_ClientParent);
    qlFirstFontSize->setFixedSize(100,36);
    qlFirstFontSize->setText("请输入字体大小");
    qlFirstFontSize->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-left : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlFirstFontSize->setWordWrap(true);
    qlFirstFontSize->show();

    qhblFirstFontTitleHBox->addWidget(qlFirstFontSize,1,Qt::AlignTop);

    QLabel * qlFirstFontColor = new QLabel(m_ClientParent);
    qlFirstFontColor->setFixedHeight(36);
    qlFirstFontColor->setText("请输入文字颜色(红,蓝,绿,透明度)");
    qlFirstFontColor->setStyleSheet("QLabel"
                               "{"
                                "margin-top : 16px;"
                               "margin-bottom : 6px;"
                                "margin-left : 10px;"
                                "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlFirstFontColor->setWordWrap(true);
    qlFirstFontColor->show();

    qhblFirstFontTitleHBox->addWidget(qlFirstFontColor,2,Qt::AlignTop);

    QVClient->addLayout(qhblFirstFontTitleHBox);

    QHBoxLayout* qhblFirstFontHBox = new QHBoxLayout();

    m_FirstFont = new QComboBox(m_ClientParent);
    m_FirstFont->setFixedSize(100,20);
    m_FirstFont->setStyleSheet(
                                 "QComboBox"
                                 "{"
                                     "margin-left : 10px;"
                                     "margin-right : 0px;"
                                 "    background-color:rgba(255, 255, 255, 255);"
                                 "    color:#000000;"
                                 "    border:1px solid rgba(200, 200, 200, 255);"
                                 "    padding-left: 12px;"
                                 "}"
                                " QComboBox::drop-down"
                                " {"
                                "   subcontrol-origin: padding;"
                                "   subcontrol-position: top right;"
                                "   width: 15px;"
                                "   border-left-width: 0px;"
                                "   border-left-color: darkgray;"
                                "   border-left-style: solid; "/* just a single line */
                                "   border-top-right-radius: 3px;" /* same radius as the QComboBox */
                                "   border-bottom-right-radius: 3px;"
                                "  }"
                                " QComboBox::down-arrow"
                                " {"
                                 "    image: none;"
                                 "}"
                                 "QComboBox::down-arrow:on"
                                 "{"
                                 "    top: 1px;"
                                 "    left: 1px;"
                                 "}"

                              );

    m_FirstFont->addItem("宋体");
    m_FirstFont->addItem("楷体");
    m_FirstFont->addItem("仿宋");
    m_FirstFont->addItem("黑体");
    m_FirstFont->addItem("微软雅黑");
    m_FirstFont->setCurrentIndex(1);
    qhblFirstFontHBox->addWidget(m_FirstFont,0,Qt::AlignTop);

    m_LeFirstFontSize = new QLineEdit(m_ClientParent);
    m_LeFirstFontSize->setFixedSize(100,20);
    m_LeFirstFontSize->setStyleSheet("QLineEdit"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                    "margin-left : 10px;"

                                    "font-size: 12px;"
                                    "padding:2px;"
                                    "background-color : #ffffff"
                               "}"
                              );
    m_LeFirstFontSize->setClearButtonEnabled(true);
    m_LeFirstFontSize->setText("18");
    qhblFirstFontHBox->addWidget(m_LeFirstFontSize,1,Qt::AlignTop);

    m_LeFirstColor = new QLineEdit(m_ClientParent);
    m_LeFirstColor->setFixedHeight(20);
    m_LeFirstColor->setStyleSheet("QLineEdit"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"
                                    "margin-left : 10px;"

                                    "font-size: 12px;"
                                    "padding:2px;"
                                    "background-color : #ffffff"
                               "}"
                              );
    m_LeFirstColor->setClearButtonEnabled(true);
    m_LeFirstColor->setText("154.0,124.0,63.0,50.0");
    qhblFirstFontHBox->addWidget(m_LeFirstColor,2,Qt::AlignTop);


    QPushButton * apbFirstFont = new QPushButton(m_ClientParent);
    apbFirstFont->setFixedSize(10,20);
    apbFirstFont->setText("");
    apbFirstFont->setStyleSheet("QPushButton"
                               "{"
                                  "margin-top : 0px;"
                                  "margin-bottom : 0px;"

                                  "border-width:0px;"/*边框宽度*/
                                  "border-color:" /*边框颜色*/
                                  BORDE_COLOR
                                  "border-radius:0px;" /*边框倒角*/
                                "font-size: 12px;"
                                    "padding:4px;"
                               "}"
                              );

    apbFirstFont->setFlat(false);
    apbFirstFont->show();
    //connect(apbprikey, &QPushButton::clicked, this, &Custom_SignStamp_Riding_Dialog::btnClicked_PriKey);
    qhblFirstFontHBox->addWidget(apbFirstFont,3,Qt::AlignTop);

    QVClient->addLayout(qhblFirstFontHBox);
    //--------------------------------------------
    //-----------------------------------------------------

        QHBoxLayout* qhblSecondTitle = new QHBoxLayout();
        QLabel * qlSecond = new QLabel(m_ClientParent);
        qlSecond->setFixedHeight(36);
        qlSecond->setText("请输入水印第二行文字");
        qlSecond->setStyleSheet("QLabel"
                                   "{"
                                    "margin-top : 16px;"
                                   "margin-bottom : 6px;"
                                    "margin-left : 10px;"
                                    "font-size: 12px;"
                                   "   border:0px solid transparent;"
                                   "}"
                                  );
        qlSecond->setWordWrap(true);
        qlSecond->show();
        qhblSecondTitle->addWidget(qlSecond,0,Qt::AlignTop);
        QVClient->addLayout(qhblSecondTitle);

        QHBoxLayout* qhblSecondselect = new QHBoxLayout();

        m_LeSecondText = new QLineEdit(m_ClientParent);
        m_LeSecondText->setFixedHeight(20);
        m_LeSecondText->setStyleSheet("QLineEdit"
                                   "{"
                                      "margin-top : 0px;"
                                      "margin-bottom : 0px;"
                                        "margin-left : 10px;"

                                        "font-size: 12px;"
                                        "padding:2px;"
                                        "background-color : #ffffff"
                                   "}"
                                  );
        m_LeSecondText->setClearButtonEnabled(true);
        m_LeSecondText->setText("");
        qhblSecondselect->addWidget(m_LeSecondText,0,Qt::AlignTop);

        QPushButton * apbSecondspacing = new QPushButton(m_ClientParent);
        apbSecondspacing->setFixedSize(10,20);
        apbSecondspacing->setText("");
        apbSecondspacing->setStyleSheet("QPushButton"
                                   "{"
                                      "margin-top : 0px;"
                                      "margin-bottom : 0px;"
                                      "margin-right : 0px;"
                                      "border-width:0px;"/*边框宽度*/
                                      "border-color:" /*边框颜色*/
                                      BORDE_COLOR
                                      "border-radius:0px;" /*边框倒角*/
                                    "font-size: 12px;"
                                        "padding:4px;"
                                   "}"
                                  );

        apbSecondspacing->setFlat(false);
        apbSecondspacing->show();
        //connect(apbCertselect, &QPushButton::clicked, this, &Custom_SignStamp_Riding_Dialog::btnClicked_Certselect);
        qhblSecondselect->addWidget(apbSecondspacing,1,Qt::AlignTop);

        QVClient->addLayout(qhblSecondselect);
        //prikey
        QHBoxLayout* qhblSecondFontTitleHBox = new QHBoxLayout();

        QLabel * qlSecondFont = new QLabel(m_ClientParent);
        qlSecondFont->setFixedSize(100,36);
        qlSecondFont->setText("请选择字体");
        qlSecondFont->setStyleSheet("QLabel"
                                   "{"
                                    "margin-top : 16px;"
                                   "margin-bottom : 6px;"
                                    "margin-left : 10px;"
                                    "font-size: 12px;"
                                   "   border:0px solid transparent;"
                                   "}"
                                  );
        qlSecondFont->setWordWrap(true);
        qlSecondFont->show();

        qhblSecondFontTitleHBox->addWidget(qlSecondFont,0,Qt::AlignTop);

        QLabel * qlSecondFontSize = new QLabel(m_ClientParent);
        qlSecondFontSize->setFixedSize(100,36);
        qlSecondFontSize->setText("请输入字体大小");
        qlSecondFontSize->setStyleSheet("QLabel"
                                   "{"
                                    "margin-top : 16px;"
                                   "margin-bottom : 6px;"
                                    "margin-left : 10px;"
                                    "font-size: 12px;"
                                   "   border:0px solid transparent;"
                                   "}"
                                  );
        qlSecondFontSize->setWordWrap(true);
        qlSecondFontSize->show();

        qhblSecondFontTitleHBox->addWidget(qlSecondFontSize,1,Qt::AlignTop);

        QLabel * qlSecondFontColor = new QLabel(m_ClientParent);
        qlSecondFontColor->setFixedHeight(36);
        qlSecondFontColor->setText("请输入文字颜色(红,蓝,绿,透明度)");
        qlSecondFontColor->setStyleSheet("QLabel"
                                   "{"
                                    "margin-top : 16px;"
                                   "margin-bottom : 6px;"
                                    "margin-left : 10px;"
                                    "font-size: 12px;"
                                   "   border:0px solid transparent;"
                                   "}"
                                  );
        qlSecondFontColor->setWordWrap(true);
        qlSecondFontColor->show();

        qhblSecondFontTitleHBox->addWidget(qlSecondFontColor,2,Qt::AlignTop);

        QVClient->addLayout(qhblSecondFontTitleHBox);

        QHBoxLayout* qhblSecondFontHBox = new QHBoxLayout();

        m_SecondFont = new QComboBox(m_ClientParent);
        m_SecondFont->setFixedSize(100,20);
        m_SecondFont->setStyleSheet(
                                     "QComboBox"
                                     "{"
                                         "margin-left : 10px;"
                                         "margin-right : 0px;"
                                     "    background-color:rgba(255, 255, 255, 255);"
                                     "    color:#000000;"
                                     "    border:1px solid rgba(200, 200, 200, 255);"
                                     "    padding-left: 12px;"
                                     "}"
                                    " QComboBox::drop-down"
                                    " {"
                                    "   subcontrol-origin: padding;"
                                    "   subcontrol-position: top right;"
                                    "   width: 15px;"
                                    "   border-left-width: 0px;"
                                    "   border-left-color: darkgray;"
                                    "   border-left-style: solid; "/* just a single line */
                                    "   border-top-right-radius: 3px;" /* same radius as the QComboBox */
                                    "   border-bottom-right-radius: 3px;"
                                    "  }"
                                    " QComboBox::down-arrow"
                                    " {"
                                     "    image: none;"
                                     "}"
                                     "QComboBox::down-arrow:on"
                                     "{"
                                     "    top: 1px;"
                                     "    left: 1px;"
                                     "}"

                                  );

        m_SecondFont->addItem("宋体");
        m_SecondFont->addItem("楷体");
        m_SecondFont->addItem("仿宋");
        m_SecondFont->addItem("黑体");
        m_SecondFont->addItem("微软雅黑");
        m_SecondFont->setCurrentIndex(1);
        qhblSecondFontHBox->addWidget(m_SecondFont,0,Qt::AlignTop);

        m_LeSecondFontSize = new QLineEdit(m_ClientParent);
        m_LeSecondFontSize->setFixedSize(100,20);
        m_LeSecondFontSize->setStyleSheet("QLineEdit"
                                   "{"
                                      "margin-top : 0px;"
                                      "margin-bottom : 0px;"
                                        "margin-left : 10px;"

                                        "font-size: 12px;"
                                        "padding:2px;"
                                        "background-color : #ffffff"
                                   "}"
                                  );
        m_LeSecondFontSize->setClearButtonEnabled(true);
        m_LeSecondFontSize->setText("18");
        qhblSecondFontHBox->addWidget(m_LeSecondFontSize,1,Qt::AlignTop);

        m_LeSecondColor = new QLineEdit(m_ClientParent);
        m_LeSecondColor->setFixedHeight(20);
        m_LeSecondColor->setStyleSheet("QLineEdit"
                                   "{"
                                      "margin-top : 0px;"
                                      "margin-bottom : 0px;"
                                        "margin-left : 10px;"

                                        "font-size: 12px;"
                                        "padding:2px;"
                                        "background-color : #ffffff"
                                   "}"
                                  );
        m_LeSecondColor->setClearButtonEnabled(true);
        m_LeSecondColor->setText("154.0,124.0,63.0,50.0");
        qhblSecondFontHBox->addWidget(m_LeSecondColor,2,Qt::AlignTop);


        QPushButton * apbSecondFont = new QPushButton(m_ClientParent);
        apbSecondFont->setFixedSize(10,20);
        apbSecondFont->setText("");
        apbSecondFont->setStyleSheet("QPushButton"
                                   "{"
                                      "margin-top : 0px;"
                                      "margin-bottom : 0px;"

                                      "border-width:0px;"/*边框宽度*/
                                      "border-color:" /*边框颜色*/
                                      BORDE_COLOR
                                      "border-radius:0px;" /*边框倒角*/
                                    "font-size: 12px;"
                                        "padding:4px;"
                                   "}"
                                  );

        apbSecondFont->setFlat(false);
        apbSecondFont->show();
        //connect(apbprikey, &QPushButton::clicked, this, &Custom_SignStamp_Riding_Dialog::btnClicked_PriKey);
        qhblSecondFontHBox->addWidget(apbSecondFont,3,Qt::AlignTop);

        QVClient->addLayout(qhblSecondFontHBox);
        //--------------------------------------------
        //-----------------------------------------------------

            QHBoxLayout* qhblThirdTitle = new QHBoxLayout();
            QLabel * qlThird = new QLabel(m_ClientParent);
            qlThird->setFixedHeight(36);
            qlThird->setText("请输入水印第三行文字");
            qlThird->setStyleSheet("QLabel"
                                       "{"
                                        "margin-top : 16px;"
                                       "margin-bottom : 6px;"
                                        "margin-left : 10px;"
                                        "font-size: 12px;"
                                       "   border:0px solid transparent;"
                                       "}"
                                      );
            qlThird->setWordWrap(true);
            qlThird->show();
            qhblThirdTitle->addWidget(qlThird,0,Qt::AlignTop);
            QVClient->addLayout(qhblThirdTitle);

            QHBoxLayout* qhblThirdselect = new QHBoxLayout();

            m_LeThirdText = new QLineEdit(m_ClientParent);
            m_LeThirdText->setFixedHeight(20);
            m_LeThirdText->setStyleSheet("QLineEdit"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"
                                            "margin-left : 10px;"

                                            "font-size: 12px;"
                                            "padding:2px;"
                                            "background-color : #ffffff"
                                       "}"
                                      );
            m_LeThirdText->setClearButtonEnabled(true);
            m_LeThirdText->setText("");
            qhblThirdselect->addWidget(m_LeThirdText,0,Qt::AlignTop);

            QPushButton * apbThirdspacing = new QPushButton(m_ClientParent);
            apbThirdspacing->setFixedSize(10,20);
            apbThirdspacing->setText("");
            apbThirdspacing->setStyleSheet("QPushButton"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"
                                          "margin-right : 0px;"
                                          "border-width:0px;"/*边框宽度*/
                                          "border-color:" /*边框颜色*/
                                          BORDE_COLOR
                                          "border-radius:0px;" /*边框倒角*/
                                        "font-size: 12px;"
                                            "padding:4px;"
                                       "}"
                                      );

            apbThirdspacing->setFlat(false);
            apbThirdspacing->show();
            //connect(apbCertselect, &QPushButton::clicked, this, &Custom_SignStamp_Riding_Dialog::btnClicked_Certselect);
            qhblThirdselect->addWidget(apbThirdspacing,1,Qt::AlignTop);

            QVClient->addLayout(qhblThirdselect);
            //prikey
            QHBoxLayout* qhblThirdFontTitleHBox = new QHBoxLayout();

            QLabel * qlThirdFont = new QLabel(m_ClientParent);
            qlThirdFont->setFixedSize(100,36);
            qlThirdFont->setText("请选择字体");
            qlThirdFont->setStyleSheet("QLabel"
                                       "{"
                                        "margin-top : 16px;"
                                       "margin-bottom : 6px;"
                                        "margin-left : 10px;"
                                        "font-size: 12px;"
                                       "   border:0px solid transparent;"
                                       "}"
                                      );
            qlThirdFont->setWordWrap(true);
            qlThirdFont->show();

            qhblThirdFontTitleHBox->addWidget(qlThirdFont,0,Qt::AlignTop);

            QLabel * qlThirdFontSize = new QLabel(m_ClientParent);
            qlThirdFontSize->setFixedSize(100,36);
            qlThirdFontSize->setText("请输入字体大小");
            qlThirdFontSize->setStyleSheet("QLabel"
                                       "{"
                                        "margin-top : 16px;"
                                       "margin-bottom : 6px;"
                                        "margin-left : 10px;"
                                        "font-size: 12px;"
                                       "   border:0px solid transparent;"
                                       "}"
                                      );
            qlThirdFontSize->setWordWrap(true);
            qlThirdFontSize->show();

            qhblThirdFontTitleHBox->addWidget(qlThirdFontSize,1,Qt::AlignTop);

            QLabel * qlThirdFontColor = new QLabel(m_ClientParent);
            qlThirdFontColor->setFixedHeight(36);
            qlThirdFontColor->setText("请输入文字颜色(红,蓝,绿,透明度)");
            qlThirdFontColor->setStyleSheet("QLabel"
                                       "{"
                                        "margin-top : 16px;"
                                       "margin-bottom : 6px;"
                                        "margin-left : 10px;"
                                        "font-size: 12px;"
                                       "   border:0px solid transparent;"
                                       "}"
                                      );
            qlThirdFontColor->setWordWrap(true);
            qlThirdFontColor->show();

            qhblThirdFontTitleHBox->addWidget(qlThirdFontColor,2,Qt::AlignTop);

            QVClient->addLayout(qhblThirdFontTitleHBox);

            QHBoxLayout* qhblThirdFontHBox = new QHBoxLayout();

            m_ThirdFont = new QComboBox(m_ClientParent);
            m_ThirdFont->setFixedSize(100,20);
            m_ThirdFont->setStyleSheet(
                                         "QComboBox"
                                         "{"
                                             "margin-left : 10px;"
                                             "margin-right : 0px;"
                                         "    background-color:rgba(255, 255, 255, 255);"
                                         "    color:#000000;"
                                         "    border:1px solid rgba(200, 200, 200, 255);"
                                         "    padding-left: 12px;"
                                         "}"
                                        " QComboBox::drop-down"
                                        " {"
                                        "   subcontrol-origin: padding;"
                                        "   subcontrol-position: top right;"
                                        "   width: 15px;"
                                        "   border-left-width: 0px;"
                                        "   border-left-color: darkgray;"
                                        "   border-left-style: solid; "/* just a single line */
                                        "   border-top-right-radius: 3px;" /* same radius as the QComboBox */
                                        "   border-bottom-right-radius: 3px;"
                                        "  }"
                                        " QComboBox::down-arrow"
                                        " {"
                                         "    image: none;"
                                         "}"
                                         "QComboBox::down-arrow:on"
                                         "{"
                                         "    top: 1px;"
                                         "    left: 1px;"
                                         "}"

                                      );

            m_ThirdFont->addItem("宋体");
            m_ThirdFont->addItem("楷体");
            m_ThirdFont->addItem("仿宋");
            m_ThirdFont->addItem("黑体");
            m_ThirdFont->addItem("微软雅黑");
            m_ThirdFont->setCurrentIndex(1);
            qhblThirdFontHBox->addWidget(m_ThirdFont,0,Qt::AlignTop);

            m_LeThirdFontSize = new QLineEdit(m_ClientParent);
            m_LeThirdFontSize->setFixedSize(100,20);
            m_LeThirdFontSize->setStyleSheet("QLineEdit"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"
                                            "margin-left : 10px;"

                                            "font-size: 12px;"
                                            "padding:2px;"
                                            "background-color : #ffffff"
                                       "}"
                                      );
            m_LeThirdFontSize->setClearButtonEnabled(true);
            m_LeThirdFontSize->setText("18");
            qhblThirdFontHBox->addWidget(m_LeThirdFontSize,1,Qt::AlignTop);

            m_LeThirdColor = new QLineEdit(m_ClientParent);
            m_LeThirdColor->setFixedHeight(20);
            m_LeThirdColor->setStyleSheet("QLineEdit"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"
                                            "margin-left : 10px;"

                                            "font-size: 12px;"
                                            "padding:2px;"
                                            "background-color : #ffffff"
                                       "}"
                                      );
            m_LeThirdColor->setClearButtonEnabled(true);
            m_LeThirdColor->setText("154.0,124.0,63.0,50.0");
            qhblThirdFontHBox->addWidget(m_LeThirdColor,2,Qt::AlignTop);


            QPushButton * apbThirdFont = new QPushButton(m_ClientParent);
            apbThirdFont->setFixedSize(10,20);
            apbThirdFont->setText("");
            apbThirdFont->setStyleSheet("QPushButton"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"

                                          "border-width:0px;"/*边框宽度*/
                                          "border-color:" /*边框颜色*/
                                          BORDE_COLOR
                                          "border-radius:0px;" /*边框倒角*/
                                        "font-size: 12px;"
                                            "padding:4px;"
                                       "}"
                                      );

            apbThirdFont->setFlat(false);
            apbThirdFont->show();
            //connect(apbprikey, &QPushButton::clicked, this, &Custom_SignStamp_Riding_Dialog::btnClicked_PriKey);
            qhblThirdFontHBox->addWidget(apbThirdFont,3,Qt::AlignTop);

            QVClient->addLayout(qhblThirdFontHBox);
            //--------------------------------------------
            //--------------------------------------------
            QHBoxLayout* qhblALLTitleHBox = new QHBoxLayout();

            QLabel * qlLeftRight = new QLabel(m_ClientParent);
            qlLeftRight->setFixedSize(100,36);
            qlLeftRight->setText("请输入左右间隔");
            qlLeftRight->setStyleSheet("QLabel"
                                       "{"
                                        "margin-top : 16px;"
                                       "margin-bottom : 6px;"
                                        "margin-left : 10px;"
                                        "font-size: 12px;"
                                       "   border:0px solid transparent;"
                                       "}"
                                      );
            qlLeftRight->setWordWrap(true);
            qlLeftRight->show();

            qhblALLTitleHBox->addWidget(qlLeftRight,0,Qt::AlignTop);

            QLabel * qlTop = new QLabel(m_ClientParent);
            qlTop->setFixedSize(100,36);
            qlTop->setText("请输入上下间隔");
            qlTop->setStyleSheet("QLabel"
                                       "{"
                                        "margin-top : 16px;"
                                       "margin-bottom : 6px;"
                                        "margin-left : 10px;"
                                        "font-size: 12px;"
                                       "   border:0px solid transparent;"
                                       "}"
                                      );
            qlTop->setWordWrap(true);
            qlTop->show();

            qhblALLTitleHBox->addWidget(qlTop,1,Qt::AlignTop);

            QLabel * qlrotate = new QLabel(m_ClientParent);
            qlrotate->setFixedHeight(36);
            qlrotate->setText("请输入旋转角度");
            qlrotate->setStyleSheet("QLabel"
                                       "{"
                                        "margin-top : 16px;"
                                       "margin-bottom : 6px;"
                                        "margin-left : 10px;"
                                        "font-size: 12px;"
                                       "   border:0px solid transparent;"
                                       "}"
                                      );
            qlrotate->setWordWrap(true);
            qlrotate->show();

            qhblALLTitleHBox->addWidget(qlrotate,2,Qt::AlignTop);

            QVClient->addLayout(qhblALLTitleHBox);

            QHBoxLayout* qhblAllHBox = new QHBoxLayout();


            m_LeLeft = new QLineEdit(m_ClientParent);
            m_LeLeft->setFixedSize(100,20);
            m_LeLeft->setStyleSheet("QLineEdit"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"
                                            "margin-left : 10px;"

                                            "font-size: 12px;"
                                            "padding:2px;"
                                            "background-color : #ffffff"
                                       "}"
                                      );
            m_LeLeft->setClearButtonEnabled(true);
            m_LeLeft->setText("40");

            qhblAllHBox->addWidget(m_LeLeft,0,Qt::AlignTop);

            m_LeTop = new QLineEdit(m_ClientParent);
            m_LeTop->setFixedSize(100,20);
            m_LeTop->setStyleSheet("QLineEdit"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"
                                            "margin-left : 10px;"

                                            "font-size: 12px;"
                                            "padding:2px;"
                                            "background-color : #ffffff"
                                       "}"
                                      );
            m_LeTop->setClearButtonEnabled(true);
            m_LeTop->setText("60");
            qhblAllHBox->addWidget(m_LeTop,1,Qt::AlignTop);

            m_LeRotate = new QLineEdit(m_ClientParent);
            m_LeRotate->setFixedHeight(20);
            m_LeRotate->setStyleSheet("QLineEdit"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"
                                            "margin-left : 10px;"

                                            "font-size: 12px;"
                                            "padding:2px;"
                                            "background-color : #ffffff"
                                       "}"
                                      );
            m_LeRotate->setClearButtonEnabled(true);
            m_LeRotate->setText("-40");
            qhblAllHBox->addWidget(m_LeRotate,2,Qt::AlignTop);


            QPushButton * apbAll = new QPushButton(m_ClientParent);
            apbAll->setFixedSize(10,20);
            apbAll->setText("");
            apbAll->setStyleSheet("QPushButton"
                                       "{"
                                          "margin-top : 0px;"
                                          "margin-bottom : 0px;"

                                          "border-width:0px;"/*边框宽度*/
                                          "border-color:" /*边框颜色*/
                                          BORDE_COLOR
                                          "border-radius:0px;" /*边框倒角*/
                                        "font-size: 12px;"
                                            "padding:4px;"
                                       "}"
                                      );

            apbAll->setFlat(false);
            apbAll->show();
            //connect(apbprikey, &QPushButton::clicked, this, &Custom_SignStamp_Riding_Dialog::btnClicked_PriKey);
            qhblAllHBox->addWidget(apbAll,3,Qt::AlignTop);

            QVClient->addLayout(qhblAllHBox);
            //--------------------------------------------

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
    qlNULLtile->show();
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
    m_OKButton->show();
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


    connect(m_CloseButton, &QPushButton::clicked, this, &WaterMark_Dialog::btnClicked_Close);
    connect(m_OKButton, &QPushButton::clicked, this, &WaterMark_Dialog::btnClicked_OK);
    connect(m_CancelButton, &QPushButton::clicked, this, &WaterMark_Dialog::btnClicked_Close);
}

//----------------------------------------------------------------------------------------------------------
WaterMark_Dialog::~WaterMark_Dialog()
{
    if ( m_ClientParent != NULL ) {
        delete m_ClientParent;
        m_ClientParent = NULL;
    }
}
//----------------------------------------------------------------------------------------------------------
void WaterMark_Dialog::btnClicked_Close()
{
    reject();
}
//----------------------------------------------------------------------------------------------------------
void WaterMark_Dialog::btnClicked_OK()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    if ( getText_FirstLine().trimmed().isEmpty() ) {
        myMessageBox.setContent("请输入水印第一行文字！");
        myMessageBox.exec();
        return;
    }
    if ( getFont_FirstLine().trimmed().isEmpty() ) {
        myMessageBox.setContent("请选择第一行文字字体！");
        myMessageBox.exec();
        return;
    }

    if ( getFontSize_FirstLine().trimmed().isEmpty() ) {
        myMessageBox.setContent("请输入第一行文字字体大小！");
        myMessageBox.exec();
        return;
    }

    if ( getTextColor_FirstLine().trimmed().isEmpty() ) {
        myMessageBox.setContent("请输入第一行文字颜色！");
        myMessageBox.exec();
        return;
    }

    if ( getHorizontalSpacing().trimmed().isEmpty() ) {
        myMessageBox.setContent("请输入左右间隔！");
        myMessageBox.exec();
        return;
    }

    if ( getVerticalSpacing().trimmed().isEmpty() ) {
        myMessageBox.setContent("请输入上下间隔！");
        myMessageBox.exec();
        return;
    }

    if ( getRotate().trimmed().isEmpty() ) {
        myMessageBox.setContent("请输入旋转角度！");
        myMessageBox.exec();
        return;
    }

    if ( getSaveAs().trimmed().isEmpty() ) {
        myMessageBox.setContent("请旋转保存文件！");
        myMessageBox.exec();
        return;
    }



    accept();
}
//----------------------------------------------------------------------------------------------------------
void WaterMark_Dialog::btnClicked_Saveas()
{
    QFileDialog fileDialog;
    QString selectType = "";
    QString saveasfileName = "";
    if ( m_doctype == 1 ) {
        saveasfileName = fileDialog.getSaveFileName(this,tr("保存加水印后的文件"),QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/加水印后文档",QStringLiteral("OFD文档(*.ofd)"),&selectType);
    } else if ( m_doctype == 2 ) {
        saveasfileName = fileDialog.getSaveFileName(this,tr("保存加水印后的文件"),QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/加水印后文档",QStringLiteral("OFD文档(*.pdf)"),&selectType);
    }
#ifdef __linux__
    if ( m_doctype == 1 ) {
        saveasfileName += ".ofd";
    } else if ( m_doctype == 2 ) {
        saveasfileName += ".pdf";
    }
#endif
    m_LeSaveas->setText(saveasfileName);
}
//----------------------------------------------------------------------------------------------------------
