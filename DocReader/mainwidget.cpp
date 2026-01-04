

#include "mainwidget.h"
#include "./ui_mainwidget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QCursor>
#include <QSettings>
#include <QStyleOption>
#include <QMenu>
#include <QFile>
#include <QValidator>
#include <QToolTip>
#include <QDebug>
#include "tabbutton.h"
#include "util.h"
#include <QFileDialog>
#include <QScrollBar>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QBuffer>
#include <QPrintDialog>
#include <QPrinter>
#include <QDockWidget>

//#include <QMessageBox>

#include "custom_signstamp_pos_dialog.h"
#include "custom_signstamp_keyword_dialog.h"
#include "custom_signstamp_riding_dialog.h"
#include "watermark_dialog.h"

#ifdef Q_OS_WIN

#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
const ULONG_PTR CUSTOM_TYPE = 10000;
#endif

MainWidget* MainWidget::m_SelfPtr = NULL;
//----------------------------------------------------------------------------------------------------------
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget),mousePress_leftClient(false),m_Tree_SmallPic(NULL),m_Tree_Anno(NULL),m_Tree_Attachment(NULL)
    ,m_Tree_Stamp(NULL), m_Tool_SmallPic(NULL),m_Tree_Docment(NULL),m_Tool_Anno(NULL),m_Tool_Stamp(NULL),m_Tool_Attachment(NULL)
    ,m_StampWidget(NULL)

{
    QString styleSheet = "#titleBar"
                         "{"
                         "   background-color : "
                         BACKGROUD_COLOR_TITLEBAR
                         //"   border-radius: 10px;"
                         "}"
                         "#statusBar"
                         "{"
                         "   background-color : "
                         BACKGROUD_COLOR_TITLEBAR
                         //"   border-radius: 10px;"
                         "}"
                         "#centralWidget"
                         "{"
                         "   border-top: 1px solid "
                         BORDE_COLOR
                         "   border-bottom:1px solid "
                         BORDE_COLOR
                         "   background-color : "
                         BACKGROUD_COLOR_TABBAR
                         "}"
                         "#pageBar"
                         "{"
                         "}"
                         "#tabBar"
                         "{"
                         "   border-bottom:1px solid "
                         BORDE_COLOR
                         "}"
                         "#pbMenuTabbar"
                         "{"
                         "   border-right:1px solid "
                         BORDE_COLOR
                         "}"
                         "#leftBar"
                         "{"
                         "    background-color : "
                         BACKGROUD_COLOR_LEFTBAR
                         "}"

                         "#leftClient"
                         "{"

                         "   border-right:1px solid "
                         BORDE_COLOR

                         "}"

                        "#leftClient_ToolBar"
                        "{"
                        "   border-top: 1px solid "
                        BORDE_COLOR
                        "   border-bottom:1px solid "
                        BORDE_COLOR
                        "   background-color : "
                        BACKGROUD_COLOR_TABBAR
                        "}"
                         "QToolButton, QToolButton::menu-indicator, QToolButton::up-arrow, QToolButton::down-arrow, QToolButton::left-arrow, QToolButton::right-arrow, QToolButton::pressed"
                         "{"
                         "    border: 0px solid transparent;"
                         "    background-color: transparent;"
                         "}"
                         "QPushButton, QPushButton::menu-indicator, QPushButton::up-arrow, QPushButton::down-arrow, QPushButton::left-arrow, QPushButton::right-arrow, QPushButton::pressed"
                         "{"
                         "    border: 0px solid transparent;"
                         "    background-color: transparent;"
                         "}"
                         "QPushButton:pressed"
                         "{"
                         "}"
                         "#docmentView"
                         "{"
                         "    border : 0px solid none;"
                         "    background-color : "
                         BACKGROUD_COLOR_DOCMENT
                         "}"
                         "QMenu{"
                          "   background-color : "
                          BACKGROUD_COLOR_TITLEBAR
                          "   border-radius: 6px;"
                          "padding:4px 0px;"
                          "margin-left : 6px;"
                          "margin-right : 6px;"
                          "margin-top : 0px;"
                          "margin-bottom : 0px;"
                          "border-bottom:1px solid "
                          BORDE_COLOR
                          "} "
                          "QMenu::item {"
                           "qproperty-iconSize: 16px;"
                          "background-color: transparent;"
                          "padding:3px 20px;"
                          "margin:5px 10px;"
                          "} "
//                          "QMenu::icon {"
//                           "padding:0px 0px;"
//                          "} "
                          "QMenu::item:selected {"
                          "background-color: "
                          BACKGROUD_COLOR_TABBAR
                          "} "
                         "#pbOpen"
                         "{"
                            "margin-top:-3px;"
                         "} "

                         "#pbMin"
                         "{"
                             "margin-bottom:-8px;"
                         "} "

                         ;

//    "#pbSave"
//    "{"
//       "margin-top:1px;"
//    "} "
//     "#pbSaveAS"
//     "{"
//        "margin-top:1px;"
//     "} "
//    "#pbPrint"
//    "{"
//    "margin-top:1px;"
//    "} "
    setStyleSheet(styleSheet);

//    QFile file(":/res/CustomWindow.css");

//    if (file.open(QFile::ReadOnly))
//    {
//        setStyleSheet(file.readAll());
//        file.close();
//    }

    ui->setupUi(this);

    //setWindowFlags(Qt::CustomizeWindowHint);
    //setWindowFlags(Qt::FramelessWindowHint );
    //setWindowFlags(  Qt::WindowMinimizeButtonHint);

//    setWindowFlags(
//                    Qt::Window
//                    |Qt::FramelessWindowHint
//                    |Qt::WindowSystemMenuHint
//                    |Qt::WindowMinimizeButtonHint
//                    |Qt::WindowMaximizeButtonHint
//                    );

//    setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
//    setMouseTracking(true);



//    ui->titleBar->setMouseTracking(true);
//    ui->LTitle->setMouseTracking(true);
//    ui->tbMenu->setMouseTracking(true);
//    ui->pbMin->setMouseTracking(true);
//    ui->pbMax->setMouseTracking(true);
//    ui->pbClose->setMouseTracking(true);
    ui->LTitle->setVisible(false);
    ui->tbMenu->setVisible(false);
    ui->pbMin->setVisible(false);
    ui->pbMax->setVisible(false);
    ui->pbClose->setVisible(false);

    //ui->centralWidget->setMouseTracking(true);
    //ui->pageBar->setMouseTracking(true);
    ui->leftClient->setMouseTracking(true);
    ui->docmentView->setMouseTracking(true);
    ui->leftClient_Client->setMouseTracking(true);


    setWindowTitle("OFD/PDF阅读器");
    ui->LTitle->setText("OFD/PDF阅读器");

    ui->leFindKey->setClearButtonEnabled(true);



    addAction(ui->actionClose);

    ui->pbSave->setVisible(false);
    ui->pbMakeCert->setVisible(false);
    ui->pbWaterMark->setVisible(false);

    connect(ui->pbMin, &QPushButton::clicked, this, &MainWidget::minimizeBtnClicked);
    connect(ui->pbMax, &QPushButton::clicked, this, &MainWidget::maximizeBtnClicked);
    connect(ui->pbClose, &QPushButton::clicked, this, &MainWidget::close);
    connect(ui->pbOpen, &QPushButton::clicked, this, &MainWidget::openDocument);
    connect(ui->pbSave, &QPushButton::clicked, this, &MainWidget::click_pbSave);
    connect(ui->pbSaveAS, &QPushButton::clicked, this, &MainWidget::click_pbSaveAS);
    connect(ui->pbPrint, &QPushButton::clicked, this, &MainWidget::click_pbPrint);
    connect(ui->pbAddStamp, &QPushButton::clicked, this, &MainWidget::click_pbAddStamp);
    connect(ui->pbKeyWordStamp, &QPushButton::clicked, this, &MainWidget::click_pbKeyWorkStamp);
    connect(ui->pbRidingStamp, &QPushButton::clicked, this, &MainWidget::click_pbRidingStamp);
    connect(ui->pbMakeSeal, &QPushButton::clicked, this, &MainWidget::click_pbMakeSeal);


    connect(ui->pbAnno, &QPushButton::clicked, this, &MainWidget::click_pbAnnot);
    connect(ui->pbStamp, &QPushButton::clicked, this, &MainWidget::click_pbStamp);
    connect(ui->pbAttachment, &QPushButton::clicked, this, &MainWidget::click_pbAttachment);

    connect(ui->tw_LeftClient, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(TreeViewDoubleClick(QTreeWidgetItem*, int)));
    connect(ui->tw_LeftClient,SIGNAL(itemClicked(QTreeWidgetItem*,int)), this,SLOT(TreeWidgetClick(QTreeWidgetItem* ,int)));

    connect(ui->pbFirstPage, &QPushButton::clicked, this, &MainWidget::click_pbFirstPage);
    connect(ui->pbPrePage, &QPushButton::clicked, this, &MainWidget::click_pbPrePage);
    connect(ui->pbNextPage, &QPushButton::clicked, this, &MainWidget::click_pbNextPage);
    connect(ui->pbLastPage, &QPushButton::clicked, this, &MainWidget::click_pbLastPage);

    connect(ui->pbContinuePage, &QPushButton::clicked, this, &MainWidget::click_pbContinuePage);
    connect(ui->pbShowOnepage, &QPushButton::clicked, this, &MainWidget::click_pbShowOnepage);
    connect(ui->pbShowTwoPage, &QPushButton::clicked, this, &MainWidget::click_pbShowTwoPage);
    connect(ui->pbFindKey, &QPushButton::clicked, this, &MainWidget::returnPressed_leFindKey);
    connect(ui->pbWaterMark, &QPushButton::clicked, this, &MainWidget::click_pbWaterMark);


    //connect(ui->pbLeftClient_Close, &QPushButton::clicked, this, &MainWidget::on_pbLeftClient_Close_clicked);
    //connect(ui->pbSmallPic, &QPushButton::clicked, this, &MainWidget::on_pbSmallPic_clicked);

//    QSettings settings("dialogs.ini", QSettings::IniFormat);
//    const auto geo = settings.value("geometry").toRect();
//    //const auto desktopSize = QApplication::desktop();

//    QScreen *desktopSize = QApplication::primaryScreen();




//    if (settings.value("maximized").toBool())
//    {
//        showMaximized();
//        ui->pbMax->setIcon(QIcon(":/res/images/resize.png"));
//    } else {
//        if (geo.height() > 0 and geo.x() < desktopSize->size().width() and geo.width() > 0 and geo.y() < desktopSize->size().height())
//            setGeometry(geo);
//    }

    QRect rect = geometry();
    m_MyTabBar = new MyTabBar(ui->tabBar);
    m_MyTabBar->setMainWindwos(this);
    m_MyTabBar->setWindowsWidth(rect.width());


    //ui->leftClient->move(-ui->leftClient->width(),0);// 左侧停靠
    //ui->pushButton->move(-1,ui->sidewidget->height()/2);
    //ui->pushButton->setIcon(QIcon(":images/right.png"));
//        m_propertyAnimation = new QPropertyAnimation(ui->leftClient,"geometry");
//        m_propertyAnimation->setEasingCurve(QEasingCurve::InOutQuint);
//        m_propertyAnimation->setDuration(300);

        //m_propertyAnimation2 = new QPropertyAnimation(ui->pushButton,"geometry");
       // m_propertyAnimation2->setEasingCurve(QEasingCurve::InOutQuint);
        //m_propertyAnimation2->setDuration(200);

//    QToolButton* m_tabClosebutton = new QToolButton(this);
//        m_tabClosebutton->setIcon(QIcon(":/res/images/max.png"));

//        ui->tabWidget->setCornerWidget(m_tabClosebutton);

//    m_ResizewindWidth = 0;
//    m_ResizeWinFinshTimer = new QTimer();
//    m_ResizeWinFinshTimer->setInterval(200);
//    connect(m_ResizeWinFinshTimer,SIGNAL(timeout()),this,SLOT(onTimeOut()));





    m_Menu_TabBar = new QMenu(this);
    m_Menu_TabBar->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    m_Menu_TabBar->setAttribute(Qt::WA_TranslucentBackground);

    connect(m_Menu_TabBar, SIGNAL(triggered(QAction*)), this, SLOT(TabbarMenuClicked(QAction*)));

    ui->comboBox->addItem("50%");
    ui->comboBox->addItem("75%");
    ui->comboBox->addItem("100%");
    ui->comboBox->addItem("125%");
    ui->comboBox->addItem("150%");
    ui->comboBox->addItem("175%");
    ui->comboBox->addItem("200%");
    ui->comboBox->addItem("250%");
    ui->comboBox->addItem("300%");

    ui->comboBox->setCurrentIndex(2);


    ui->leGotoEdit->setAlignment( Qt::AlignHCenter);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_ScaledValue_Changed(int)));




    connect(ui->leGotoEdit, SIGNAL(returnPressed()), this, SLOT(returnPressed_leGotoEdit()));
    connect(ui->leFindKey, SIGNAL(returnPressed()), this, SLOT(returnPressed_leFindKey()));

    ui->leftClient->setVisible(false);
    ui->pbSetting->setVisible(false);

    m_LeftBarButtonType = LeftBarButtonType::Type_None;
    m_DisplayModeType = DisplayModeType::Type_ContinuePage;
    ui->pbContinuePage->setStyleSheet(
                    "background: rgba(40, 40, 40, 0.2);"
                    );

    ui->pbShowOnepage->setStyleSheet("");
    ui->pbShowTwoPage->setStyleSheet("");

    ui->leftClient->installEventFilter(this);
    ui->docmentView->installEventFilter(this);
    ui->leftClient_Client->installEventFilter(this);

    m_Tree_SmallPic = new Tree_SmallPic(ui->tw_LeftClient);
    m_Tree_Anno = new Tree_Anno(ui->tw_LeftClient);
    m_Tree_Attachment = new Tree_Attachment(ui->tw_LeftClient);
    m_Tree_Stamp = new Tree_Stamp(ui->tw_LeftClient);
    m_Tree_Stamp->setMainWindwos(this);
    m_Tree_Docment = new Tree_Docment(ui->tw_Docment);

    m_Tree_SmallPic->setMainWindwos(this);
    m_Tree_Anno->setMainWindwos(this);




    ui->tw_LeftClient->clear();    //QTreeWidget清空
    ui->tw_LeftClient->setFrameStyle(QFrame::NoFrame);  //框架样式
    ui->tw_LeftClient->setHeaderLabel("tree widget");  //设置头的标题
    ui->tw_LeftClient->setHeaderHidden(true);     //tree widget头标题是否显示,此处隐藏标题
    ui->tw_LeftClient->setColumnCount(1);    //tree widget展示的列数
    ui->tw_LeftClient->setItemsExpandable(true);

    //隐藏根点的展开折叠图标
    ui->tw_LeftClient->setRootIsDecorated(false);
    ui->tw_LeftClient->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    //隐子节点的展开折叠图标
    ui->tw_LeftClient->setStyleSheet("QTreeView::branch:has-children:!has-siblings:closed,"
                                     "QTreeView::branch:closed:has-children:has-siblings{border-image: none; image: none;}"
                                     "QTreeView::branch:open:has-children:!has-siblings,"
                                     "QTreeView::branch:open:has-children:has-siblings{border-image: none; image: none;}"
                                     "QTreeView::branch::hover{ background-color: transparent;selection-background-color: transparent;color : transparent;}"
                                     "QTreeView::item::hover{ background-color: transparent;selection-background-color: transparent;color : transparent;}"
                                     "QTreeView::branch:selected{ background-color: transparent;selection-background-color: transparent;color : transparent;}"
                                     "QTreeView::item:selected{ show-decoration-selected:1;background-color: transparent;selection-background-color: transparent;color: transparent; }"
                                "QTreeView{outline:0px;background-color:"
                                BACKGROUD_COLOR_TABBAR
                                "color :"
                                BACKGROUD_COLOR_TABBAR
                                "show-decoration-selected: 0;"
                                "}"


                                );

    //ui->tw_Docment->clear();    //QTreeWidget清空


    connect(ui->tw_Docment->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onDocmentScrollChanged(int)));


    m_MyProgressBox = new MyProgressBox(this);




    setGotoEditText(0,0);

    m_SelfPtr = this;
    m_FontAddThread = NULL;

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
    qDebug() << "CurrEexePathdll => "<< bdllname.data() << Qt::endl;


    if ( !m_OFDPDFSigner.init(bdllname.data()) ) {
        //m_WindowsFinish = new QTimer();
        m_WindowsFinish.setInterval(200);
        connect(&m_WindowsFinish,SIGNAL(timeout()),this,SLOT(onTimeOut_WindowFinish()));
        m_WindowsFinish.start();
    } else {


        m_OFDPDFSigner.setWorkPath(bworkpath.data());
#ifdef __APPLE__
        QString strdefautfont = currExePath+"/Resources/OFDFonts/simsun.ttf";
#elif _MSC_VER || _WIN32 || _WIN64
        QString strdefautfont = currExePath + "/OFDFonts/simsun.ttf";
#endif
        //QString strdefautfont = currExePath+"/Resources/OFDFonts/simsun.ttf";
        QByteArray bdefaultfong = strdefautfont.toUtf8();
        m_OFDPDFSigner.saveFontFileNameCache(bdefaultfong.data());

        m_OFDPDFSigner.getAllSystemFontFileName(SystemFontFileNameFunc,NULL);

        m_FontAddThread = new FontAddThread();
        if ( m_FontAddThread != NULL ) {
            m_FontAddThread->setMainWindwos(this);
            m_FontAddThread->start();
        }
    }

}
//----------------------------------------------------------------------------------------------------------
MainWidget::~MainWidget()
{
//    if ( m_propertyAnimation != NULL ) {
//        delete m_propertyAnimation;
//        m_propertyAnimation = NULL;
//    }

    //if ( m_propertyAnimation2 != NULL ) {
    //    delete m_propertyAnimation2;
    //    m_propertyAnimation2 = NULL;
    //}

//    if ( m_ResizeWinFinshTimer != NULL ) {
//        delete m_ResizeWinFinshTimer;
//        m_ResizeWinFinshTimer = NULL;
//    }
//    if ( m_WindowsFinish != NULL ) {
//        delete m_WindowsFinish;
//        m_WindowsFinish = NULL;
//    }
    if ( m_FontAddThread != NULL ) {
        m_FontAddThread->Stop();
        while(!(m_FontAddThread->isRunEnd())) {
            QThread::msleep(100);
        }
        m_FontAddThread->exit();
        m_FontAddThread->deleteLater();
    }

    if ( m_MyProgressBox != NULL ) {
        delete m_MyProgressBox;
        m_MyProgressBox = NULL;
    }

    m_MenuActions.clear();
    m_MenuActionTexts.clear();

    ClearFindWordList();

    if ( m_Menu_TabBar != NULL ) {
        delete m_Menu_TabBar;
        m_Menu_TabBar = NULL;
    }

    if ( m_Tree_SmallPic != NULL ) {
        delete m_Tree_SmallPic;
        m_Tree_SmallPic = NULL;
    }

    if ( m_Tree_Anno != NULL ) {
        delete m_Tree_Anno;
        m_Tree_Anno = NULL;
    }

    if ( m_Tree_Attachment != NULL ) {
        delete m_Tree_Attachment;
        m_Tree_Attachment = NULL;
    }

    if ( m_Tree_Stamp != NULL ) {
        delete m_Tree_Stamp;
        m_Tree_Stamp = NULL;
    }

    if ( m_Tool_SmallPic != NULL ) {
        delete m_Tool_SmallPic;
        m_Tool_SmallPic = NULL;
    }

    if ( m_Tool_Anno != NULL ) {
        delete m_Tool_Anno;
        m_Tool_Anno = NULL;
    }

    if ( m_Tool_Stamp != NULL ) {
        delete m_Tool_Stamp;
        m_Tool_Stamp = NULL;
    }

    if ( m_Tool_Attachment != NULL ) {
        delete m_Tool_Attachment;
        m_Tool_Attachment = NULL;
    }


    if ( m_Tree_Docment != NULL ) {
        delete m_Tree_Docment;
        m_Tree_Docment = NULL;
    }

    if ( m_StampWidget != NULL ) {
        delete m_StampWidget;
        m_StampWidget = NULL;
    }


    //QSettings settings("dialogs.ini", QSettings::IniFormat);
    //settings.setValue("geometry", geometry());
    //settings.setValue("maximized", isMaximized());


    delete ui;
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::mouseMoveEvent(QMouseEvent *e)
{
    const auto xMouse = e->pos().x();
    const auto yMouse = e->pos().y();
    const auto wWidth = geometry().width();
    const auto wHeight = geometry().height();

    if (mMoveWidget)
    {
        mInResizeZone = false;
        moveWindow(e);
    }
    else if (mAllowResize)
        resizeWindow(e);
    else if (xMouse >= wWidth - PIXELS_TO_ACT) //Cursor right side
    {
        mInResizeZone = true;

        if (yMouse >= wHeight - PIXELS_TO_ACT) {
            setCursor(Qt::SizeFDiagCursor);
        } else if (yMouse <= PIXELS_TO_ACT) {
            setCursor(Qt::SizeBDiagCursor);
        } else {
            setCursor(Qt::SizeHorCursor);
        }

        resizeWindow(e);
    }
    else if (xMouse <= PIXELS_TO_ACT) //Cursor left side
    {
        mInResizeZone = true;

        if (yMouse >= wHeight - PIXELS_TO_ACT) {
            setCursor(Qt::SizeBDiagCursor);
        } else if (yMouse <= PIXELS_TO_ACT) {
            setCursor(Qt::SizeFDiagCursor);
        } else {
            setCursor(Qt::SizeHorCursor);
        }

        resizeWindow(e);
    }
    else if (yMouse >= wHeight - PIXELS_TO_ACT) //Cursor low side
    {
        mInResizeZone = true;
        setCursor(Qt::SizeVerCursor);

        resizeWindow(e);
    }
    else if (yMouse <= PIXELS_TO_ACT) //Cursor top side
    {
        mInResizeZone = true;
        setCursor(Qt::SizeVerCursor);

        resizeWindow(e);
    }
    else
    {
        mInResizeZone = false;
        setCursor(Qt::ArrowCursor);
    }

    e->accept();
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::mousePressEvent(QMouseEvent *e)
{

    if (e->button() == Qt::LeftButton)
    {
        const auto xPos = e->pos().x();
        const auto yPos = e->pos().y();

        if (mInResizeZone)
        {
            mAllowResize = true;

            if (yPos <= PIXELS_TO_ACT)
            {
                if (xPos <= PIXELS_TO_ACT)
                    mResizeDiagTopLeft = true;
                else if (xPos >= geometry().width() - PIXELS_TO_ACT)
                    mResizeDiagTopRight = true;
                else
                    mResizeVerTop = true;
            }
            else if (xPos <= PIXELS_TO_ACT)
                mResizeHorLeft = true;
        }
        else if (xPos >= PIXELS_TO_ACT and xPos < ui->titleBar->geometry().width()
                 and yPos >= PIXELS_TO_ACT and yPos < ui->titleBar->geometry().height())
        {
            mMoveWidget = true;
            mDragPosition = e->globalPos() - frameGeometry().topLeft();
        }
    }

    e->accept();
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    mMoveWidget = false;
    mAllowResize = false;
    mResizeVerTop = false;
    mResizeHorLeft = false;
    mResizeDiagTopLeft = false;
    mResizeDiagTopRight = false;

    e->accept();
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    const auto tbMenuGeo = ui->tbMenu->geometry();
    const auto titleBarGeo = ui->titleBar->geometry();
    const auto xPos = e->pos().x();
    const auto yPos = e->pos().y();

    if (xPos < tbMenuGeo.right() and yPos < tbMenuGeo.bottom() and xPos >= tbMenuGeo.x() and yPos >= tbMenuGeo.y() and ui->tbMenu->isVisible())
        close();
    else if (mTitleMode != TitleMode::FullScreenMode and xPos < titleBarGeo.width() and yPos < titleBarGeo.height())
        maximizeBtnClicked();

    e->accept();
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::paintEvent (QPaintEvent * event)
{
    QStyleOption opt;
    opt.initFrom(this);
    //opt.init (this);

    QPainter p(this);
    style()->drawPrimitive (QStyle::PE_Widget, &opt, &p, this);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);	// 反锯齿;
    painter.setBrush(QBrush(QColor(233,233,233,255)));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 10, 10);
    //也可用QPainterPath 绘制代替 painter.drawRoundedRect(rect, 15, 15);
//    {
//        QPainterPath painterPath;
//        painterPath.addRoundedRect(rect, 15, 15);
//        p.drawPath(painterPath);
//    }
    QWidget::paintEvent(event);

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::moveWindow(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - mDragPosition);
        e->accept();
    }
}
//----------------------------------------------------------------------------------------------------------
//void MainWidget::onTimeOut()
//{
//    QRect rect = geometry();
//    if ( rect.width() == m_ResizewindWidth ) {
//        m_ResizeWinFinshTimer->stop();
//        m_MyTabBar->setWindowsWidth(rect.width());
//    }


//}
//----------------------------------------------------------------------------------------------------------
void MainWidget::onTimeOut_WindowFinish()
{
    m_WindowsFinish.stop();
    MyMessageBox myMessageBox(this);
    myMessageBox.setContent("不能加载解析PDF/OFD文档动态库！\n应用程序将退出！");
    myMessageBox.setVisible_CancelButton(false);
    int rec= myMessageBox.exec(); // dia退出的时候就会被销毁；
    close();
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resizeEvent" << Qt::endl;
//    QWidget::resizeEvent(event);
//    if ( !m_ResizeWinFinshTimer->isActive() ) {
//        m_ResizeWinFinshTimer->start();
//    }
//    m_ResizewindWidth = event->size().width();

//    m_ResizeWinFinshTimer->stop();
//    m_ResizeWinFinshTimer->start();
//    m_ResizewindWidth = event->size().width();
//    QWidget::resizeEvent(event);

    if ( event->oldSize().width() > event->size().width() ) {
        int currindex = getCurrDisplayItemIndex();
        ShowDocment(currindex);
        m_MyTabBar->setWindowsWidth(event->size().width());
        QWidget::resizeEvent(event);
    } else {
        QWidget::resizeEvent(event);
        m_MyTabBar->setWindowsWidth(event->size().width());
        int currindex = getCurrDisplayItemIndex();
        ShowDocment(currindex);
    }



}
//----------------------------------------------------------------------------------------------------------
void MainWidget::resizeWindow(QMouseEvent *e)
{

    if (mAllowResize)
    {
        const auto cursorShape = cursor().shape();

        switch (cursorShape)
        {
            case Qt::SizeVerCursor:
                resizeWhenVerCursor(e->pos());
            break;
            case Qt::SizeHorCursor:
                resizeWhenHorCursor(e->pos());
            break;
            case Qt::SizeBDiagCursor:
                resizeWhenBDiagCursor(e->pos());
            break;
            case Qt::SizeFDiagCursor:
                resizeWhenFDiagCursor(e->pos());
            break;
            default:

                setCursor(Qt::ArrowCursor);
            break;
        }

        e->accept();


    } else {

        setCursor(Qt::ArrowCursor);
    }


}
//----------------------------------------------------------------------------------------------------------
void MainWidget::resizeWhenVerCursor (const QPoint &p)
{
    auto yMouse = p.y();
    auto wWidth = geometry().width();
    auto wHeight = geometry().height();

    if (mResizeVerTop)
    {
        int newY = geometry().y() + yMouse;
        int newHeight = wHeight - yMouse;

        if (newHeight > minimumSizeHint().height())
        {
            resize(wWidth, newHeight);
            move(geometry().x(), newY);

        }
    }
    else {
        resize(wWidth, yMouse+1);

    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::resizeWhenHorCursor (const QPoint &p)
{
    auto xMouse = p.x();
    auto wWidth = geometry().width();
    auto wHeight = geometry().height();

    if (mResizeHorLeft)
    {
        int newX = geometry().x() + xMouse;
        int newWidth = wWidth - xMouse;

        if (newWidth > minimumSizeHint().width())
        {
            resize(newWidth, wHeight);
            move(newX, geometry().y());
        }
    }
    else {
        resize(xMouse, wHeight);
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::resizeWhenBDiagCursor(const QPoint &p)
{
    auto xMouse = p.x();
    auto yMouse = p.y();
    auto wWidth = geometry().width();
    auto wHeight = geometry().height();
    auto newX = 0;
    auto newWidth = 0;
    auto newY = 0;
    auto newHeight = 0;

    if (mResizeDiagTopRight)
    {
        newX = geometry().x();
        newWidth = xMouse;
        newY = geometry().y() + yMouse;
        newHeight = wHeight - yMouse;
    }
    else
    {
        newX = geometry().x() + xMouse;
        newWidth = wWidth - xMouse;
        newY = geometry().y();
        newHeight = yMouse;
    }

    if (newWidth >= minimumSizeHint().width() and newHeight >= minimumSizeHint().height())
    {
        resize(newWidth, newHeight);
        move(newX, newY);
    }
    else if (newWidth >= minimumSizeHint().width())
    {
        resize(newWidth, wHeight);
        move(newX, geometry().y());
    }
    else if (newHeight >= minimumSizeHint().height())
    {
        resize(wWidth, newHeight);
        move(geometry().x(), newY);
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::resizeWhenFDiagCursor(const QPoint &p)
{
    auto xMouse = p.x();
    auto yMouse = p.y();
    auto geoX = geometry().x();
    auto geoY = geometry().y();
    auto wWidth = geometry().width();
    auto wHeight = geometry().height();

    if (mResizeDiagTopLeft)
    {
        int newX = geoX + xMouse;
        int newWidth = wWidth - xMouse;
        int newY = geoY + yMouse;
        int newHeight = wHeight - yMouse;

        if (newWidth >= minimumSizeHint().width() and newHeight >= minimumSizeHint().height())
        {
            resize(newWidth, newHeight);
            move(newX, newY);
        }
        else if (newWidth >= minimumSizeHint().width())
        {
            resize(newWidth, wHeight);
            move(newX, geoY);
        }
        else if (newHeight >= minimumSizeHint().height())
        {
            resize(wWidth, newHeight);
            move(geoX, newY);
        }
    }
    else {
        resize(xMouse+1, yMouse+1);
    }


}
//----------------------------------------------------------------------------------------------------------
//void MainWidget::setCentralWidget(QWidget *widget, const QString &widgetName)
//{
//    //We do connect in the old fashion way since it will be decided in execution time
//    connect(widget, SIGNAL(cancelled()), this, SLOT(close()));
//    ui->centralLayout->addWidget(widget);
//    ui->LTitle->setText(widgetName);
//}
//----------------------------------------------------------------------------------------------------------
void MainWidget::setTitlebarMode(const TitleMode &flag)
{
    mTitleMode = flag;

    switch (mTitleMode)
    {
        case TitleMode::CleanTitle:
            ui->tbMenu->setHidden(true);
            ui->pbMin->setHidden(true);
            ui->pbMax->setHidden(true);
            ui->pbClose->setHidden(true);
            break;
        case TitleMode::OnlyCloseButton:
            ui->tbMenu->setHidden(true);
            ui->pbMin->setHidden(true);
            ui->pbMax->setHidden(true);
            break;
        case TitleMode::MenuOff:
            ui->tbMenu->setHidden(true);
            break;
        case TitleMode::MaxMinOff:
            ui->pbMin->setHidden(true);
            ui->pbMax->setHidden(true);
            break;
        case TitleMode::FullScreenMode:
            ui->pbMax->setHidden(true);
            showMaximized();
            break;
        case TitleMode::MaximizeModeOff:
            ui->pbMax->setHidden(true);
            break;
        case TitleMode::MinimizeModeOff:
            ui->pbMin->setHidden(true);
            break;
        case TitleMode::FullTitle:
            ui->tbMenu->setVisible(true);
            ui->pbMin->setVisible(true);
            ui->pbMax->setVisible(true);
            ui->pbClose->setVisible(true);
            break;
    }
    ui->LTitle->setVisible(true);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::setTitlebarMenu(QMenu *menu, const QString &icon)
{
    ui->tbMenu->setMenu(menu);
    ui->tbMenu->setIcon(QIcon(icon));
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::maximizeBtnClicked()
{
    //qDebug() << "maximizeBtnClicked" << Qt::endl;
    if (isFullScreen() or isMaximized())
    {
        ui->pbMax->setIcon(QIcon(":/res/images/max.png"));
        setWindowState(windowState() & ~Qt::WindowMaximized);

    }
    else
    {
        ui->pbMax->setIcon(QIcon(":/res/images/resize.png"));
        setWindowState(windowState() | Qt::WindowMaximized);

    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::minimizeBtnClicked()
{
    if (isMinimized()) {
        //qDebug() << "minimizeBtnClicked 还原" << Qt::endl;
        setWindowState(windowState() & ~Qt::WindowMinimized);
    } else {

        //qDebug() << "minimizeBtnClicked 最小化" << Qt::endl;
        setWindowState(windowState() | Qt::WindowMinimized);

    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::setGotoEditText(int currIndex,int pageCount)
{
    QString strTatalPageNum = QString::number(pageCount);
    QString strInputMask = "";
    for ( int zz = 0; zz < strTatalPageNum.length(); zz++ ) {
        strInputMask += "0";
    }

    if ( pageCount == 0 ) {
        currIndex = 0;
    }
    ui->leGotoEdit->setText(QString("%1").arg(currIndex, strTatalPageNum.length(), 10, QLatin1Char(' ')));

    strTatalPageNum.replace("9", "\\9");
    strTatalPageNum.replace("0", "\\0");
    strInputMask += "/";
    strInputMask += strTatalPageNum;
    strInputMask += ";";
    ui->leGotoEdit->setInputMask(strInputMask);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::pushWindow()
{
 //处理最小化的情况
 if (windowState() & Qt::WindowMinimized)
 {
  setWindowState(windowState() & ~Qt::WindowMinimized | Qt::WindowActive);
 }

 //窗口置顶
//windows下调用win的api
#ifdef Q_OS_WIN
 //::SetWindowPos(HWND(this->winId()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
 //::SetWindowPos(HWND(this->winId()), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
 activateWindow();
 raise();
 show();
#else
    activateWindow();
    raise();

 //麒麟下只执行activateWindow、raise之后无法置顶，需要间隔一定的时间，再次执行activateWindow、raise才能置顶，原因不明。
    QTimer::singleShot(100, this, [this] {
  this->activateWindow();
  this->raise();
  });
#endif
}
#ifdef Q_OS_WIN
bool MainWidget::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG *param = static_cast<MSG *>(message);

    switch (param->message)
    {
    case WM_COPYDATA:
    {
        COPYDATASTRUCT *cds = reinterpret_cast<COPYDATASTRUCT*>(param->lParam);
        if (cds->dwData == CUSTOM_TYPE)
        {
            QString strMessage = QString::fromUtf8(reinterpret_cast<char*>(cds->lpData), cds->cbData);
            OpenOFDOrPDF(strMessage);
            pushWindow();
            *result = 1;

            return true;
        }
    }
    }

    return QWidget::nativeEvent(eventType, message, result);
}
#endif
//----------------------------------------------------------------------------------------------------------
void MainWidget::OpenOFDOrPDF(QString fileName)
{
    QRect rect = geometry();
    if ( ui->pbMenuTabbar->menu() == NULL ) {
        ui->pbMenuTabbar->setMenu(m_Menu_TabBar);
    }

    if ( m_StampWidget != NULL ) {
        m_StampWidget->hide();
    }
//    if ( m_MyProgressBox != NULL ) {
//        m_MyProgressBox->show(this);
//    }


        QString tempFileName = fileName;
        QString title = tempFileName;
        title.replace("\\","/");
        int dianpos = title.lastIndexOf("/");
        //qDebug() << " dianpos:" << dianpos << Qt::endl;
        if ( dianpos != -1 ) {
            m_CurrPath = title.left(dianpos);
        } else {
            m_CurrPath = title;
        }
        //qDebug() << "openDocument : m_CurrPath:" << m_CurrPath << " title:"<< title << " dianpos:" << dianpos << Qt::endl;
        title = title.mid(dianpos+1,title.length()-dianpos-1);
        //qDebug() << "openDocument : title:" << title << Qt::endl;
        //title = title.section('/', -1);
        dianpos = title.lastIndexOf(".");
        if ( dianpos != -1 ) {
            title = title.left(dianpos);
        }


        QFile tempfile(tempFileName);
        if ( !tempfile.open(QFile::ReadOnly) ) return;
        QByteArray temdata = tempfile.readAll();
        tempfile.close();

        QString type = tempFileName.toLower();
        if ( type.endsWith(".pdf") ) {
            type = ":/res/images/pdf_2.png";
            HANDLE PDFObj = m_OFDPDFSigner.pdf_open((const unsigned char *)temdata.data(),temdata.size());
            if ( PDFObj == NULL ) {
                return;
            }



            if ( m_OFDPDFSigner.pdf_getPageCount(PDFObj) <= 0 ) {
                return;
            }

            m_MyTabBar->addTabButton(tempFileName,title,type,rect.width());
            QAction * selectTabAction = m_Menu_TabBar->addAction(title);
            selectTabAction->setData(QVariant::fromValue(m_MyTabBar->getSelectTab_Index())) ;
            m_MenuActions.push_back(selectTabAction);
            m_MyTabBar->setPDFObject(m_MyTabBar->getSelectTab_Index(),PDFObj);

        } else if ( type.endsWith(".ofd" ) ) {
           type = ":/res/images/ofd.png";
           HANDLE OFDObj = m_OFDPDFSigner.ofd_open((const unsigned char *)temdata.data(),temdata.size());
           if ( OFDObj == NULL ) {
               return;
           }

           if ( m_OFDPDFSigner.ofd_getPageCount(OFDObj) <= 0 ) {
               return;
           }


           m_MyTabBar->addTabButton(tempFileName,title,type,rect.width());
           QAction * selectTabAction = m_Menu_TabBar->addAction(title);
           selectTabAction->setData(QVariant::fromValue(m_MyTabBar->getSelectTab_Index())) ;
           m_MenuActions.push_back(selectTabAction);
           m_MyTabBar->setOFDObject(m_MyTabBar->getSelectTab_Index(),OFDObj);

        } else {
           return;
        }




    double scaled = getScaledValue();

    HANDLE tempOFDObj = m_MyTabBar->getOFDObject(m_MyTabBar->getSelectTab_Index());
    HANDLE tempPDFObj = m_MyTabBar->getPDFObject(m_MyTabBar->getSelectTab_Index());
    int TotalPageNum = 0;
    QPixmap * pinmap1 = NULL;
    QPixmap * pinmap2 = NULL;
    if ( tempOFDObj != NULL ) {
        m_Tree_Docment->clear();
        TotalPageNum = m_OFDPDFSigner.ofd_getPageCount(tempOFDObj);
        for( int i = 0; i < TotalPageNum; i++ ) {
            unsigned char * picdata = NULL;
            size_t picdatalen = 0;

						if ( !m_OFDPDFSigner.ofd_pageToImage(tempOFDObj,"PNG",i,scaled,&picdata,&picdatalen) ) {
                continue;
            }

            if ( picdata == NULL || picdatalen == 0 ) {
                continue;
            }

            QPixmap * pinmap = m_MyTabBar->addDocmentPixmap(m_MyTabBar->getSelectTab_Index(),scaled,(const unsigned char *)(picdata),picdatalen);
            switch ( m_DisplayModeType ) {
                case DisplayModeType::Type_ContinuePage:
                    m_Tree_Docment->addPixmap(pinmap);
                    break;
                case DisplayModeType::Type_ShowOnepage:
                    if ( i == 0 ) {
                        m_Tree_Docment->addPixmap(pinmap);
                    }
                    break;
                case DisplayModeType::Type_ShowTwoPage:
                    if ( (i+1) % 2 == 0 ) {
                        pinmap2 = pinmap;
                        m_Tree_Docment->addPixmap(pinmap1,pinmap2);
                    } else {
                        pinmap1 = pinmap;
                        if ( i == TotalPageNum -1 ) {
                            m_Tree_Docment->addPixmap(pinmap1,NULL);
                        }
                    }

                    break;
            }



            m_OFDPDFSigner.FreeHandle(picdata);

        }


    } else if ( tempPDFObj != NULL ) {
        m_Tree_Docment->clear();
        TotalPageNum = m_OFDPDFSigner.pdf_getPageCount(tempPDFObj);

        for( int i = 0; i < TotalPageNum; i++ ) {
            unsigned char * picdata = NULL;
            size_t picdatalen = 0;

            if ( !m_OFDPDFSigner.pdf_pageToImage(tempPDFObj,"PNG",i,scaled,&picdata,&picdatalen) ) {
                continue;
            }

            if ( picdata == NULL || picdatalen == 0 ) {
                continue;
            }

            QPixmap * pinmap = m_MyTabBar->addDocmentPixmap(m_MyTabBar->getSelectTab_Index(),scaled,(const unsigned char *)(picdata),picdatalen);
            switch ( m_DisplayModeType ) {
                case DisplayModeType::Type_ContinuePage:
                    m_Tree_Docment->addPixmap(pinmap);
                    break;
                case DisplayModeType::Type_ShowOnepage:
                    if ( i == 0 ) {
                        m_Tree_Docment->addPixmap(pinmap);
                    }
                    break;
                case DisplayModeType::Type_ShowTwoPage:
                    if ( (i+1) % 2 == 0 ) {
                        pinmap2 = pinmap;
                        m_Tree_Docment->addPixmap(pinmap1,pinmap2);
                    } else {
                        pinmap1 = pinmap;
                        if ( i == TotalPageNum -1 ) {
                            m_Tree_Docment->addPixmap(pinmap1,NULL);
                        }
                    }

                    break;
            }



            m_OFDPDFSigner.FreeHandle(picdata);
        }

    }

    setGotoEditText(1,TotalPageNum);

    Refresh_LeftBar();



    setCursor(Qt::ArrowCursor);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::openDocument()
{
    //QStringList fileNames = QFileDialog::getOpenFileNames(this, QStringLiteral("请选择PDF/OFD文档"), m_CurrPath,QStringLiteral("OFD文档(*.ofd);; ""PDF文件(*.pdf)"));
    QStringList fileNames = QFileDialog::getOpenFileNames(this, QStringLiteral("请选择PDF/OFD文档"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),QStringLiteral("OFD文档(*.ofd);; ""PDF文件(*.pdf)"));
    //QStringList fileNames = QFileDialog::getOpenFileNames(this, QStringLiteral("请选择PDF/OFD文档"), "/Users/fzz/work/cpp/ofd/tmp/ofd",QStringLiteral("OFD文档/PDF文档(*.ofd;*.pdf)"));
    setCursor(Qt::WaitCursor);
    QRect rect = geometry();
    if ( ui->pbMenuTabbar->menu() == NULL ) {
        ui->pbMenuTabbar->setMenu(m_Menu_TabBar);
    }

    if ( m_StampWidget != NULL ) {
        m_StampWidget->hide();
    }
//    if ( m_MyProgressBox != NULL ) {
//        m_MyProgressBox->show(this);
//    }

    for ( int i = 0; i < fileNames.size(); i++ ) {
        QString tempFileName = fileNames[i];
        QString title = tempFileName;
        title.replace("\\","/");
        int dianpos = title.lastIndexOf("/");
        //qDebug() << " dianpos:" << dianpos << Qt::endl;
        if ( dianpos != -1 ) {
            m_CurrPath = title.left(dianpos);
        } else {
            m_CurrPath = title;
        }
        //qDebug() << "openDocument : m_CurrPath:" << m_CurrPath << " title:"<< title << " dianpos:" << dianpos << Qt::endl;
        title = title.mid(dianpos+1,title.length()-dianpos-1);
        //qDebug() << "openDocument : title:" << title << Qt::endl;
        //title = title.section('/', -1);
        dianpos = title.lastIndexOf(".");
        if ( dianpos != -1 ) {
            title = title.left(dianpos);
        }


        QFile tempfile(tempFileName);
        if ( !tempfile.open(QFile::ReadOnly) ) continue;
        QByteArray temdata = tempfile.readAll();
        tempfile.close();

        QString type = tempFileName.toLower();
        if ( type.endsWith(".pdf") ) {
            type = ":/res/images/pdf_2.png";
            HANDLE PDFObj = m_OFDPDFSigner.pdf_open((const unsigned char *)temdata.data(),temdata.size());
            if ( PDFObj == NULL ) {
                continue;
            }



            if ( m_OFDPDFSigner.pdf_getPageCount(PDFObj) <= 0 ) {
                continue;
            }

            m_MyTabBar->addTabButton(tempFileName,title,type,rect.width());
            QAction * selectTabAction = m_Menu_TabBar->addAction(title);
            selectTabAction->setData(QVariant::fromValue(m_MyTabBar->getSelectTab_Index())) ;
            m_MenuActions.push_back(selectTabAction);
            m_MyTabBar->setPDFObject(m_MyTabBar->getSelectTab_Index(),PDFObj);

        } else if ( type.endsWith(".ofd" ) ) {
           type = ":/res/images/ofd.png";
           HANDLE OFDObj = m_OFDPDFSigner.ofd_open((const unsigned char *)temdata.data(),temdata.size());
           if ( OFDObj == NULL ) {
               continue;
           }

           if ( m_OFDPDFSigner.ofd_getPageCount(OFDObj) <= 0 ) {
               continue;
           }


           m_MyTabBar->addTabButton(tempFileName,title,type,rect.width());
           QAction * selectTabAction = m_Menu_TabBar->addAction(title);
           selectTabAction->setData(QVariant::fromValue(m_MyTabBar->getSelectTab_Index())) ;
           m_MenuActions.push_back(selectTabAction);
           m_MyTabBar->setOFDObject(m_MyTabBar->getSelectTab_Index(),OFDObj);

        } else {
           continue;
        }


    }

    double scaled = getScaledValue();

    HANDLE tempOFDObj = m_MyTabBar->getOFDObject(m_MyTabBar->getSelectTab_Index());
    HANDLE tempPDFObj = m_MyTabBar->getPDFObject(m_MyTabBar->getSelectTab_Index());
    int TotalPageNum = 0;
    QPixmap * pinmap1 = NULL;
    QPixmap * pinmap2 = NULL;
    if ( tempOFDObj != NULL ) {
        m_Tree_Docment->clear();
        TotalPageNum = m_OFDPDFSigner.ofd_getPageCount(tempOFDObj);
        for( int i = 0; i < TotalPageNum; i++ ) {
            unsigned char * picdata = NULL;
            size_t picdatalen = 0;

            if ( !m_OFDPDFSigner.ofd_pageToImage(tempOFDObj,"PNG",i,scaled,&picdata,&picdatalen) ) {
                continue;
            }

            if ( picdata == NULL || picdatalen == 0 ) {
                continue;
            }

            QPixmap * pinmap = m_MyTabBar->addDocmentPixmap(m_MyTabBar->getSelectTab_Index(),scaled,(const unsigned char *)(picdata),picdatalen);
            switch ( m_DisplayModeType ) {
                case DisplayModeType::Type_ContinuePage:
                    m_Tree_Docment->addPixmap(pinmap);
                    break;
                case DisplayModeType::Type_ShowOnepage:
                    if ( i == 0 ) {
                        m_Tree_Docment->addPixmap(pinmap);
                    }
                    break;
                case DisplayModeType::Type_ShowTwoPage:
                    if ( (i+1) % 2 == 0 ) {
                        pinmap2 = pinmap;
                        m_Tree_Docment->addPixmap(pinmap1,pinmap2);
                    } else {
                        pinmap1 = pinmap;
                        if ( i == TotalPageNum -1 ) {
                            m_Tree_Docment->addPixmap(pinmap1,NULL);
                        }
                    }

                    break;
            }



            m_OFDPDFSigner.FreeHandle(picdata);

        }


    } else if ( tempPDFObj != NULL ) {
        m_Tree_Docment->clear();
        TotalPageNum = m_OFDPDFSigner.pdf_getPageCount(tempPDFObj);

        for( int i = 0; i < TotalPageNum; i++ ) {
            unsigned char * picdata = NULL;
            size_t picdatalen = 0;

            if ( !m_OFDPDFSigner.pdf_pageToImage(tempPDFObj,"PNG",i,scaled,&picdata,&picdatalen) ) {
                continue;
            }

            if ( picdata == NULL || picdatalen == 0 ) {
                continue;
            }

            QPixmap * pinmap = m_MyTabBar->addDocmentPixmap(m_MyTabBar->getSelectTab_Index(),scaled,(const unsigned char *)(picdata),picdatalen);
            switch ( m_DisplayModeType ) {
                case DisplayModeType::Type_ContinuePage:
                    m_Tree_Docment->addPixmap(pinmap);
                    break;
                case DisplayModeType::Type_ShowOnepage:
                    if ( i == 0 ) {
                        m_Tree_Docment->addPixmap(pinmap);
                    }
                    break;
                case DisplayModeType::Type_ShowTwoPage:
                    if ( (i+1) % 2 == 0 ) {
                        pinmap2 = pinmap;
                        m_Tree_Docment->addPixmap(pinmap1,pinmap2);
                    } else {
                        pinmap1 = pinmap;
                        if ( i == TotalPageNum -1 ) {
                            m_Tree_Docment->addPixmap(pinmap1,NULL);
                        }
                    }

                    break;
            }



            m_OFDPDFSigner.FreeHandle(picdata);
        }

    }

    setGotoEditText(1,TotalPageNum);

    Refresh_LeftBar();



    setCursor(Qt::ArrowCursor);
//    if ( m_MyProgressBox != NULL ) {
//        m_MyProgressBox->close();
//    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbSave()
{

    if ( m_MyProgressBox != NULL ) {
        m_MyProgressBox->show(this);

    }


//    MyMessageBox myMessageBox(this);
//    myMessageBox.setContent("  附件多少了附件的路上附件多少了减肥的路上见风使舵减肥的路上附件多少！\n  减肥的路上附件多少了附件多少了附件是");
//    myMessageBox.setContent("  附件多少了附件的路上附件多少了减肥的路");
//    //myMessageBox.setVisible_CancelButton(false);
//    int rec= myMessageBox.exec(); // dia退出的时候就会被销毁；
//    if(rec==QDialog::Accepted){
//        qDebug()<< "rec=" << rec << " "<< "accept";
//    }else if(rec==QDialog::Rejected) {
//        qDebug()<< "rec=" << rec << " "<< "reject";
//    }

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbSaveAS()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    QString fullFileName = m_MyTabBar->getFullFileName(m_MyTabBar->getSelectTab_Index());
    if ( fullFileName.isEmpty() ) {
        myMessageBox.setContent("当前没有打开有效的文档！");
        myMessageBox.exec();
        return;
    }

    QString fileName = fullFileName;
    fileName.replace("\\","/");
    int dianpos = fileName.lastIndexOf("/");
    if ( dianpos != -1 ) {
        fileName = fileName.mid(dianpos+1,fileName.length()-dianpos-1);
    }

    dianpos = fileName.lastIndexOf(".");
    QString fileNameNotHaveExt = fileName;
    if ( dianpos != -1 ) {
        fileNameNotHaveExt = fileName.mid(0,dianpos);
    }

    QFileDialog fileDialog;
    QString selectType = "";
    QString saveasfileName = fileDialog.getSaveFileName(this,tr("另存为附件"),QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/"+fileNameNotHaveExt,QStringLiteral("OFD文档(*.ofd);; ""PDF文件(*.pdf);; ""JPG文件(*.jpg);; ""PNG文件(*.png);; ""BMP文件(*.bmp)"),&selectType);
    if(saveasfileName == "")
    {
        return;
    }

    unsigned char * picdata = NULL;
    size_t picdatalen = 0;

    QList<QPixmap*> * pixmaplist = m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),getScaledValue());
    
    HANDLE tempOFDObj = m_MyTabBar->getOFDObject(m_MyTabBar->getSelectTab_Index());
    HANDLE tempPDFObj = m_MyTabBar->getPDFObject(m_MyTabBar->getSelectTab_Index());

    QString type = fileName.toLower();
    QString saveastype = selectType.toLower();
    if ( saveastype.lastIndexOf("pdf") != -1 ) {
        if ( !saveasfileName.endsWith(".pdf") ) {
             saveasfileName += ".pdf";
        }
        if ( type.endsWith(".pdf") ) {
            QFile::copy(fullFileName, saveasfileName);
        } else if ( type.endsWith(".ofd" ) ) {
            //QFile tempfile(fullFileName);
            //if ( !tempfile.open(QFile::ReadOnly) ) {
            //    myMessageBox.setContent("不能打开该PDF文档！");
            //    myMessageBox.exec();
            //    return;
            //}
            //QByteArray temdata = tempfile.readAll();
            //tempfile.close();

            m_OFDPDFSigner.ofdToPdf(tempOFDObj,false,false,"",&picdata,&picdatalen);

            if ( picdata == NULL || picdatalen == 0 ) {
                myMessageBox.setContent("转换文档失败！");
                myMessageBox.exec();
                return;
            }

            QFile file(saveasfileName);
            if(file.open(QIODevice::WriteOnly)) {
                QByteArray wirtedata;
                wirtedata.resize(picdatalen);
                memcpy(wirtedata.data(),picdata,picdatalen);
                file.write(wirtedata);
                file.close();
            } else {
                myMessageBox.setContent("不能写该文件！请检查文件权限！");
                myMessageBox.exec();

            }

            m_OFDPDFSigner.FreeHandle(picdata);



        } else {
            myMessageBox.setContent("当前不是有效的PDF/OFD文档！");
            myMessageBox.exec();
            return;
        }
        myMessageBox.setContent("另存为PDF文档成功！");
        myMessageBox.exec();
        return;

    } else if ( saveastype.lastIndexOf("ofd" ) != -1 ) {
        if ( !saveasfileName.endsWith(".ofd") ) {
             saveasfileName += ".ofd";
        }
        if ( type.endsWith(".pdf") ) {
            //QFile tempfile(fullFileName);
            //if ( !tempfile.open(QFile::ReadOnly) ) {
            //    myMessageBox.setContent("不能打开该PDF文档！");
            //    myMessageBox.exec();
            //    return;
            //}
            //QByteArray temdata = tempfile.readAll();
            //tempfile.close();

            m_OFDPDFSigner.pdfToOfd(tempPDFObj,false,&picdata,&picdatalen);

            if ( picdata == NULL || picdatalen == 0 ) {
                myMessageBox.setContent("转换文档失败！");
                myMessageBox.exec();
                return;
            }

            QFile file(saveasfileName);
            if(file.open(QIODevice::WriteOnly)) {
                QByteArray wirtedata;
                wirtedata.resize(picdatalen);
                memcpy(wirtedata.data(),picdata,picdatalen);
                file.write(wirtedata);
                file.close();
            } else {
                myMessageBox.setContent("不能写该文件！请检查文件权限！");
                myMessageBox.exec();

            }

            m_OFDPDFSigner.FreeHandle(picdata);


        } else if ( type.endsWith(".ofd" ) ) {
            QFile::copy(fullFileName, saveasfileName);
        } else {
            myMessageBox.setContent("当前不是有效的PDF/OFD文档！");
            myMessageBox.exec();
            return;
        }
        myMessageBox.setContent("另存为OFD文档成功！");
        myMessageBox.exec();
        return;


    } else if ( saveastype.lastIndexOf("jpg" ) != -1 || saveastype.lastIndexOf("jpeg" ) != -1 ) {

        if ( !saveasfileName.endsWith(".jpg") ) {
             saveasfileName += ".jpg";
        }

        if ( pixmaplist == NULL || pixmaplist->size() <= 0 ) {
            myMessageBox.setContent("没有当前显示分辨率的文档存在！");
            myMessageBox.exec();
            return;
        }

        qDebug()<< "jpg =" << pixmaplist->size() ;

        int temppos = saveasfileName.lastIndexOf(".");
        if ( temppos != -1 ) {
            saveasfileName = saveasfileName.mid(0,temppos);
        }
        QList<QPixmap*>::const_iterator it;
        for( it = pixmaplist->constBegin(); it != pixmaplist->constEnd(); it++  ) {
            QPixmap* temp = *it;
            if ( temp == NULL ) continue;

            temp->save(saveasfileName+QString::number(it-pixmaplist->begin()+1)+".jpg", "JPG");

//            QByteArray bytes;
//            QBuffer buffer(&bytes);
//            buffer.open(QIODevice::WriteOnly);
//            temp->save(&buffer, "PNG");
//            buffer.close();

        }


        myMessageBox.setContent("使用显示文档分辨率另存图片成功！");
        myMessageBox.exec();
        return;
    } else if ( saveastype.lastIndexOf("png" ) != -1 ) {
        if ( !saveasfileName.endsWith(".png") ) {
             saveasfileName += ".png";
        }
        if ( pixmaplist == NULL || pixmaplist->size() <= 0 ) {
            myMessageBox.setContent("没有当前显示分辨率的文档存在！");
            myMessageBox.exec();
            return;
        }

        qDebug()<< "png =" << pixmaplist->size() ;

        int temppos = saveasfileName.lastIndexOf(".");

        if ( temppos != -1 ) {
            saveasfileName = saveasfileName.mid(0,temppos);
        }
        QList<QPixmap*>::const_iterator it;
        for( it = pixmaplist->begin(); it != pixmaplist->end(); it++  ) {
            QPixmap* temp = *it;
            if ( temp == NULL ) continue;

            temp->save(saveasfileName+QString::number(it-pixmaplist->begin()+1)+".png", "PNG");
        }


        myMessageBox.setContent("使用显示文档分辨率另存图片成功！");
        myMessageBox.exec();
        return;
    } else if ( saveastype.lastIndexOf("bmp" ) != -1 ) {
        if ( !saveasfileName.endsWith(".bmp") ) {
             saveasfileName += ".bmp";
        }
        if ( pixmaplist == NULL || pixmaplist->size() <= 0 ) {
            myMessageBox.setContent("没有当前显示分辨率的文档存在！");
            myMessageBox.exec();
            return;
        }

        qDebug()<< "bmp =" << pixmaplist->size() ;

        int temppos = saveasfileName.lastIndexOf(".");
        if ( temppos != -1 ) {
            saveasfileName = saveasfileName.mid(0,temppos);
        }
        QList<QPixmap*>::const_iterator it;
        for( it = pixmaplist->begin(); it != pixmaplist->end(); it++  ) {
            QPixmap* temp = *it;
            if ( temp == NULL ) continue;

            temp->save(saveasfileName+QString::number(it-pixmaplist->begin()+1)+".bmp", "BMP");
        }


        myMessageBox.setContent("使用显示文档分辨率另存图片成功！");
        myMessageBox.exec();
        return;
    } else {
        myMessageBox.setContent("不支持另存为该文档类型！");
        myMessageBox.exec();
        return;
    }

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbPrint()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    QList<QPixmap*> * pixmaplist = m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),getScaledValue());
    if ( pixmaplist == NULL || pixmaplist->size() <= 0 ) {
        myMessageBox.setContent("当前文档不能打印！");
        myMessageBox.exec();
        return;
    }



    QString fullFileName = m_MyTabBar->getFullFileName(m_MyTabBar->getSelectTab_Index());
    if ( fullFileName.isEmpty() ) {
        myMessageBox.setContent("当前没有打开有效的文档！");
        myMessageBox.exec();
        return;
    }

    QString fileName = fullFileName;
    fileName.replace("\\","/");
    int dianpos = fileName.lastIndexOf("/");
    if ( dianpos != -1 ) {
        fileName = fileName.mid(dianpos+1,fileName.length()-dianpos-1);
    }
    QPrinter printer;


    QPrintDialog printDialog(&printer,this);
    printDialog.setWindowTitle(tr("打印 ")+fileName);

    if(printDialog.exec())
    {


        //qDebug() << "click_pbPrint: max: " << printDialog.fromPage() << " min:" << printDialog.toPage() << Qt::endl;


        QPainter painter(&printer);				//指定绘图设备为一个QPrinter对象
        QRect rect =painter.viewport();         //获得QPainter对象的视图矩形区域

        int from = printDialog.fromPage();
        int to = printDialog.toPage();

        if ( from == 0 && to == 0 ) {
            from = 0;
            to = pixmaplist->size()-1;
        } else {
            from = from - 1;
            if ( from <= 0 ) {
                from = 0;
            }

            to = to - 1;
            if ( to <= 0 ) {
                to = 0;
            }
            if ( to >=  pixmaplist->size()-1 ) {
                to = pixmaplist->size()-1;
            }
        }



        QList<QPixmap*>::const_iterator it;
        for( it = pixmaplist->begin(); it != pixmaplist->end(); it++  ) {
            int i = it - pixmaplist->begin();
            if ( i >= from && i <= to ) {
                QPixmap* temp = *it;
                if ( temp == NULL ) continue;
                QSize size = temp->size();				//获得图像的大小
                // 按照图形的比例大小重新设置视图矩形区域
                size.scale(rect.size(),Qt::KeepAspectRatio);
                painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
                painter.setWindow(temp->rect());          //设置QPainter窗口大小为图像的大小
                painter.drawImage(0,0,temp->toImage());

                if ( i <= to-1 ) {
                    printer.newPage();
                    //qDebug() << "click_pbPrint: new page"<< Qt::endl;
                }
            }

            //qDebug() << "click_pbPrint: " << it - pixmaplist->begin() << Qt::endl;
        }

        painter.end ();
    }

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbAddStamp()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    QString fullFileName = m_MyTabBar->getFullFileName(m_MyTabBar->getSelectTab_Index());
    if ( fullFileName.isEmpty() ) {
        myMessageBox.setContent("当前没有打开有效的文档！");
        myMessageBox.exec();
        return;
    }

    if ( m_StampWidget == NULL ) {
        m_StampWidget = new StampWidget(this);
    }
    m_StampWidget->hide();

    int doctype = 0;
    QString tempFileName = fullFileName.toLower();
    if ( tempFileName.endsWith(".ofd" ) ) {
        doctype = 1;
    } else {
        doctype = 2;
    }

    Custom_SignStamp_Pos_Dialog Custom_SignStamp_Pos_Dialog(this);
    Custom_SignStamp_Pos_Dialog.setDocType(doctype);
    if ( Custom_SignStamp_Pos_Dialog.exec() == QDialog::Accepted ) {

        QString stampfilename = Custom_SignStamp_Pos_Dialog.getStampFileName();
        QFile tempfile(stampfilename);
        if ( !tempfile.open(QFile::ReadOnly) ) return;
        QByteArray temdata = tempfile.readAll();
        tempfile.close();

        unsigned char * picimage = NULL;
        size_t picimagelen = 0;
        if ( doctype == 1 ) {
            if ( m_OFDPDFSigner.getSealImageData((unsigned char *)temdata.data(),temdata.size(),&picimage,&picimagelen) == 0 ) {

                temdata.resize(picimagelen);
                memcpy(temdata.data(),picimage,picimagelen);

                if ( picimage != NULL ) {
                    m_OFDPDFSigner.FreeHandle(picimage);
                }
            } else {
                myMessageBox.setContent("不能解析国办印章文件！");
                myMessageBox.exec();
                return;
            }
        }

        m_StampWidget->setFullFileName(fullFileName);
        m_StampWidget->setDocType(doctype);
        m_StampWidget->setSaveAs(Custom_SignStamp_Pos_Dialog.getSaveasFileName());
        m_StampWidget->setStamp(stampfilename);
        m_StampWidget->setCert(Custom_SignStamp_Pos_Dialog.getCertFileName());
        m_StampWidget->setPrikey(Custom_SignStamp_Pos_Dialog.getPriKeyFileName());

        m_StampWidget->SetPixmap((unsigned char *)temdata.data(),temdata.size());
        m_StampWidget->SetDocment(m_Tree_Docment);
        m_StampWidget->SetMainWidget(this);

        QPoint posA = ui->tw_Docment->mapToGlobal(QPoint(0,0));

        m_StampWidget->move(posA);
        m_StampWidget->show();

    }

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::on_pbLeftClient_Close_clicked()
{
    qDebug() << "on_pbLeftClient_Close_clicked: "<< Qt::endl;
    m_LeftBarButtonType = LeftBarButtonType::Type_None;
    Refresh_LeftBar();
    QTimer::singleShot(1, this, [this] {
        int currindex = getCurrDisplayItemIndex();
        ShowDocment(currindex);
  });

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::Refresh_LeftBarClient()
{
    switch (m_LeftBarButtonType) {
        case LeftBarButtonType::Type_SmallPic:
            if ( m_Tree_SmallPic != NULL ) {
                m_Tree_SmallPic->init(m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),getScaledValue()),m_Tool_SmallPic != NULL ? m_Tool_SmallPic->getSliderValue():0.5);
            }
            break;
        case LeftBarButtonType::Type_Anno:
            if ( m_Tree_Anno != NULL ) {
                m_Tree_Anno->RefreshContent();
            }
            break;

    }

    int currindex = getCurrDisplayItemIndex();
    ShowDocment(currindex);
}
//----------------------------------------------------------------------------------------------------------
double MainWidget::getScaledValue()
{
    HANDLE tempOFDObj = m_MyTabBar->getOFDObject(m_MyTabBar->getSelectTab_Index());
    HANDLE tempPDFObj = m_MyTabBar->getPDFObject(m_MyTabBar->getSelectTab_Index());

    QString strScaledValue = ui->comboBox->currentText();
    //qDebug() << "getScaledValue: " << strScaledValue << Qt::endl;
    strScaledValue = strScaledValue.left(strScaledValue.length()-1);
    int intScaledValue = strScaledValue.toInt();
    double scaled = 1;
    if ( tempOFDObj != NULL ) {
        scaled = OFD_SCALED*((double)(intScaledValue))/100;
    } else if (tempPDFObj != NULL ) {
        scaled = PDF_SCALED*((double)(intScaledValue))/100;
    } else {
        scaled = ((double)(intScaledValue))/100;
    }
    return scaled;
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::Refresh_LeftBar()
{
    QString styleSheet = "QPushButton{";
            styleSheet += "background-color:";
            styleSheet += BACKGROUD_COLOR_TABBAR;
            styleSheet += "}";

    QString styleSheet2 = "QPushButton{";
            styleSheet2 += "background-color:";
            styleSheet2 += "transparent;";
            styleSheet2 += "}";
    switch (m_LeftBarButtonType) {
        case LeftBarButtonType::Type_None:
            ui->pbSmallPic->setStyleSheet(styleSheet2);
            ui->pbAnno->setStyleSheet(styleSheet2);
            ui->pbStamp->setStyleSheet(styleSheet2);
            ui->pbAttachment->setStyleSheet(styleSheet2);
            ui->leftClient->setVisible(false);
            break;
        case LeftBarButtonType::Type_SmallPic:
            ui->pbSmallPic->setStyleSheet(styleSheet);
            ui->pbAnno->setStyleSheet(styleSheet2);
            ui->pbStamp->setStyleSheet(styleSheet2);
            ui->pbAttachment->setStyleSheet(styleSheet2);

            ui->leftClient->setVisible(true);

            ui->lLeftTitle->setText("缩略图");
            if ( m_Tool_Anno != NULL ) {
                m_Tool_Anno->setVisible(false);
            }
            if ( m_Tool_Stamp != NULL ) {
                m_Tool_Stamp->setVisible(false);
            }
            if ( m_Tool_Attachment != NULL ) {
                m_Tool_Attachment->setVisible(false);
            }
            ui->leftClient_ToolBar->setVisible(true);
            if ( m_Tool_SmallPic == NULL ) {
                m_Tool_SmallPic = new Tool_SmallPic(ui->leftClient_ToolBar);
                m_Tool_SmallPic->init(this);
            }
            m_Tool_SmallPic->setVisible(true);

            if ( m_Tree_Anno != NULL ) {
                m_Tree_Anno->clear();
            }
            if ( m_Tree_Attachment != NULL ) {
                m_Tree_Attachment->clear();
            }
            if ( m_Tree_Stamp != NULL ) {
                m_Tree_Stamp->clear();
            }
            if ( m_Tree_SmallPic != NULL ) {


                m_Tree_SmallPic->init(m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),getScaledValue()),m_Tool_SmallPic != NULL ? m_Tool_SmallPic->getSliderValue():0.5);
            }

            onDocmentScrollChanged(0);
            break;
        case LeftBarButtonType::Type_Anno:
            ui->pbSmallPic->setStyleSheet(styleSheet2);
            ui->pbAnno->setStyleSheet(styleSheet);
            ui->pbStamp->setStyleSheet(styleSheet2);
            ui->pbAttachment->setStyleSheet(styleSheet2);
            ui->leftClient->setVisible(true);
            if ( m_Tool_SmallPic != NULL ) {
                m_Tool_SmallPic->setVisible(false);
            }
            if ( m_Tool_Stamp != NULL ) {
                m_Tool_Stamp->setVisible(false);
            }
            if ( m_Tool_Attachment != NULL ) {
                m_Tool_Attachment->setVisible(false);
            }
            ui->leftClient_ToolBar->setVisible(true);
            if ( m_Tool_Anno == NULL ) {
                m_Tool_Anno = new Tool_Anno(ui->leftClient_ToolBar);
                m_Tool_Anno->init(this);
            }
            //m_Tool_Anno->setVisible(true);
            //本版本不显示按钮功能
            ui->leftClient_ToolBar->setVisible(false);
            //m_Tool_Anno->setVisible(false);

            ui->lLeftTitle->setText("注释");

            if ( m_Tree_SmallPic != NULL ) {
                m_Tree_SmallPic->clear();
            }
            if ( m_Tree_Attachment != NULL ) {
                m_Tree_Attachment->clear();
            }
            if ( m_Tree_Stamp != NULL ) {
                m_Tree_Stamp->clear();
            }
            getDocmentOtherInfo();
            if ( m_Tree_Anno != NULL ) {
                m_Tree_Anno->init(m_MyTabBar->getAnnos(m_MyTabBar->getSelectTab_Index()));

            }
            break;
        case LeftBarButtonType::Type_Stamp:
            ui->pbSmallPic->setStyleSheet(styleSheet2);
            ui->pbAnno->setStyleSheet(styleSheet2);
            ui->pbStamp->setStyleSheet(styleSheet);
            ui->pbAttachment->setStyleSheet(styleSheet2);
            ui->leftClient->setVisible(true);
            ui->lLeftTitle->setText("印章");
            if ( m_Tool_SmallPic != NULL ) {
                m_Tool_SmallPic->setVisible(false);
            }
            if ( m_Tool_Anno != NULL ) {
                m_Tool_Anno->setVisible(false);
            }
            if ( m_Tool_Attachment != NULL ) {
                m_Tool_Attachment->setVisible(false);
            }

            ui->leftClient_ToolBar->setVisible(false);
//            if ( m_Tool_Stamp == NULL ) {
//                m_Tool_Stamp = new Tool_Stamp(ui->leftClient_ToolBar);
//                m_Tool_Stamp->init(this);
//            }
            //m_Tool_Stamp->setVisible(true);

            if ( m_Tree_SmallPic != NULL ) {
                m_Tree_SmallPic->clear();
            }
            if ( m_Tree_Attachment != NULL ) {
                m_Tree_Attachment->clear();
            }
            if ( m_Tree_Anno != NULL ) {
                m_Tree_Anno->clear();
            }
            getDocmentOtherInfo();
            if ( m_Tree_Stamp != NULL ) {
                m_Tree_Stamp->init(m_MyTabBar->getStramps(m_MyTabBar->getSelectTab_Index()));
            }
            break;
        case LeftBarButtonType::Type_Attachment:
            ui->pbSmallPic->setStyleSheet(styleSheet2);
            ui->pbAnno->setStyleSheet(styleSheet2);
            ui->pbStamp->setStyleSheet(styleSheet2);
            ui->pbAttachment->setStyleSheet(styleSheet);
            ui->leftClient->setVisible(true);
            ui->lLeftTitle->setText("附件");
            if ( m_Tool_SmallPic != NULL ) {
                m_Tool_SmallPic->setVisible(false);
            }
            if ( m_Tool_Anno != NULL ) {
                m_Tool_Anno->setVisible(false);
            }
            if ( m_Tool_Stamp != NULL ) {
                m_Tool_Stamp->setVisible(false);
            }
            ui->leftClient_ToolBar->setVisible(true);
            if ( m_Tool_Attachment == NULL ) {
                m_Tool_Attachment = new Tool_Attachment(ui->leftClient_ToolBar);
                m_Tool_Attachment->init(this);
            }
            m_Tool_Attachment->setVisible(true);
            if ( m_Tree_SmallPic != NULL ) {
                m_Tree_SmallPic->clear();
            }
            if ( m_Tree_Stamp != NULL ) {
                m_Tree_Stamp->clear();
            }
            if ( m_Tree_Anno != NULL ) {
                m_Tree_Anno->clear();
            }


            getDocmentOtherInfo();
            if ( m_Tree_Attachment != NULL ) {
                m_Tree_Attachment->init(m_MyTabBar->getAttachments(m_MyTabBar->getSelectTab_Index()));
            }
            break;
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::on_pbSmallPic_clicked()
{
    if ( m_LeftBarButtonType == LeftBarButtonType::Type_SmallPic ) {
        return;
    }

    m_LeftBarButtonType = LeftBarButtonType::Type_SmallPic;
    Refresh_LeftBar();
    int currindex = getCurrDisplayItemIndex();
    ShowDocment(currindex);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::TabbarMenuClicked(QAction* action)
{
    int index = 0;
    QList<QAction*>::const_iterator it;
    for( it = m_MenuActions.begin(); it != m_MenuActions.end(); it++ ) {
        if ( *it == action ) {
            index = it - m_MenuActions.begin();
            //qDebug() << "MainWidget::TabbarMenuClicked  " << action->text() << " index:" << index << Qt::endl;
            break;
        }
    }
    m_MyTabBar->setSelectTab_index(index);
    ClickedTab(index);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::ClickedTab(int index)
{
    if ( m_StampWidget != NULL ) {
        m_StampWidget->hide();
    }
    if ( m_MyTabBar->getTabButtonCount() > 0 ) {
        ShowDocment(0);
        int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
        setGotoEditText(1,count);
        //m_Tree_SmallPic->init(m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),getScaledValue()),m_Tool_SmallPic != NULL ? m_Tool_SmallPic->getSliderValue():0.5);
    }
    Refresh_LeftBar();
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::CloseTab(int index)
{
    if ( m_StampWidget != NULL ) {
        m_StampWidget->hide();
    }
    //qDebug() << "MainWidget::CloseTab : index " << index << Qt::endl;
    //m_MyTabBar
    if ( index > m_MenuActions.size() -1 ) {
        return;
    }
    QAction * selectTabAction = *(m_MenuActions.begin()+index);
    m_MenuActions.erase(m_MenuActions.begin()+index);
    m_Menu_TabBar->removeAction(selectTabAction);

    if ( m_MenuActions.size() == 0 ) {
        ui->pbMenuTabbar->setMenu(NULL);
    }
    if ( m_MyTabBar->getTabButtonCount() > 0 ) {
        ShowDocment(0);
        m_Tree_SmallPic->init(m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),getScaledValue()),m_Tool_SmallPic != NULL ? m_Tool_SmallPic->getSliderValue():0.5);
    } else {
        m_Tree_Docment->clear();
        m_Tree_SmallPic->clear();
        //ui->tw_Docment->clear();
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::CloseTabOther(int index)
{
    if ( m_StampWidget != NULL ) {
        m_StampWidget->hide();
    }
    //qDebug() << "MainWidget::CloseTabOther : index " << index << Qt::endl;
    if ( index > m_MenuActions.size() -1 ) {
        return;
    }

    QAction * selectTabAction = *(m_MenuActions.begin()+index);
    if ( selectTabAction == NULL ) return;

    int currindex = 0;
    QList<QAction*>::const_iterator action_iter;
    for (action_iter = m_MenuActions.begin(); action_iter != m_MenuActions.end(); action_iter++) {
        QAction* temp = *action_iter;
        if ( temp != NULL && currindex != index ) {
            m_Menu_TabBar->removeAction(temp);
        }
        currindex++;
    }
    m_MenuActions.clear();

    m_MenuActions.push_back(selectTabAction);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbAnnot()
{
    if ( m_LeftBarButtonType == LeftBarButtonType::Type_Anno ) {
        return;
    }
    m_LeftBarButtonType = LeftBarButtonType::Type_Anno;
    Refresh_LeftBar();
    int currindex = getCurrDisplayItemIndex();
    ShowDocment(currindex);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbStamp()
{
    if ( m_LeftBarButtonType == LeftBarButtonType::Type_Stamp ) {
        return;
    }
    m_LeftBarButtonType = LeftBarButtonType::Type_Stamp;
    Refresh_LeftBar();
    int currindex = getCurrDisplayItemIndex();
    ShowDocment(currindex);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbAttachment()
{
    if ( m_LeftBarButtonType == LeftBarButtonType::Type_Attachment ) {
        return;
    }
    m_LeftBarButtonType = LeftBarButtonType::Type_Attachment;
    Refresh_LeftBar();
    int currindex = getCurrDisplayItemIndex();
    ShowDocment(currindex);
}
//----------------------------------------------------------------------------------------------------------
int MainWidget::getCurrDisplayItemIndex()
{
    QString tempstr = ui->leGotoEdit->text();
    //qDebug() << "getCurrDisplayItemIndex : text  "  << tempstr << Qt::endl;
    int dianpos = tempstr.lastIndexOf("/");
    if ( dianpos != -1 ) {
        tempstr = tempstr.left(dianpos);
    }
    //qDebug() << "getCurrDisplayItemIndex : text1  "  << tempstr << Qt::endl;
    int index = tempstr.toInt() - 1;
    //qDebug() << "getCurrDisplayItemIndex : index  "  << index << Qt::endl;
    //int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
    if ( index < 0 ) {
        index = 0;
    }
    /*
    else if ( index + 1 >= count ) {
        index = count - 1;
        if ( index < 0 ) {
            index = 0;
        }
    }*/
    return index;
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::returnPressed_leGotoEdit()
{
    switch ( m_DisplayModeType ) {
        case DisplayModeType::Type_ContinuePage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(getCurrDisplayItemIndex()));
            break;
        case DisplayModeType::Type_ShowOnepage:
            {
                int index = getCurrDisplayItemIndex();
                int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
                setGotoEditText(index+1,count);
                ShowOnepage();
                SmallPicShowMask(index);
            }
            break;
        case DisplayModeType::Type_ShowTwoPage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(getCurrDisplayItemIndex()/2));
            break;
    }
}
//----------------------------------------------------------------------------------------------------------

bool MainWidget::eventFilter(QObject *watched, QEvent *event)
{
    //qDebug() << "eventFilter  "  << event->type() << Qt::endl;
    if (watched == ui->leftClient) {

        //qDebug() << "eventFilter  "  << event->type() << Qt::endl;
        switch (static_cast<int>(event->type())) {
        case QEvent::MouseMove: {

            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

            const auto xMouse = mouseEvent->pos().x();
            const auto yMouse = mouseEvent->pos().y();
            const auto wWidth = ui->leftClient->geometry().width();
            const auto wHeight = ui->leftClient->geometry().height();

            if(mousePress_leftClient) {
                resize_LeftClient(mouseEvent);
            } else {
                if (xMouse >= wWidth - PIXELS_TO_ACT) //Cursor right side
                {

                    if (yMouse >= wHeight - PIXELS_TO_ACT) {
                        setCursor(Qt::ArrowCursor);
                    } else if (yMouse <= PIXELS_TO_ACT) {
                        setCursor(Qt::ArrowCursor);
                    } else {
                        setCursor(Qt::SizeHorCursor);
                    }


                } else {
                    mousePress_leftClient = false;
                    setCursor(Qt::ArrowCursor);
                }
            }
            return true;
        }

        case QEvent::MouseButtonPress: {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if(mouseEvent->button() == Qt::LeftButton) {

                const auto xPos = mouseEvent->pos().x();
                const auto yPos = mouseEvent->pos().y();
                const auto cursorShape = cursor().shape();
                if ( cursorShape == Qt::SizeHorCursor ) {
                    mousePress_leftClient = true;
                }

            }
            return true;
        }

        case QEvent::MouseButtonRelease: {
            //QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if ( mousePress_leftClient ) {
                Refresh_LeftBarClient();
                mousePress_leftClient = false;
            }
            setCursor(Qt::ArrowCursor);
            return true;
        }
        default:
            break;
        }
        return true;
    } else {
        switch (static_cast<int>(event->type())) {
            case QEvent::MouseMove:
            case QEvent::MouseButtonPress:
            case QEvent::MouseButtonRelease:
                if ( mousePress_leftClient ) {
                    Refresh_LeftBarClient();
                    mousePress_leftClient = false;
                }
                setCursor(Qt::ArrowCursor);
                break;
//            case QEvent::ToolTip:
//                if (dynamic_cast<QLabel*>(watched) != NULL) {
//                    //dynamic_cast<QLabel*>(watched)->toolTip();
//                    qDebug() << "eventFilter111  "  << event->type() << Qt::endl;
//                    QToolTip::showText(QCursor::pos(), tr("测试测试"), this);

//                }

//                break;
        }



    }

    return QWidget::eventFilter(watched, event);

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::resize_LeftClient(QMouseEvent *e)
{
    if (mousePress_leftClient)
    {
        const auto cursorShape = cursor().shape();

        switch (cursorShape)
        {

            case Qt::SizeHorCursor: {
                int xMouse = e->pos().x();
                if ( xMouse < 280 ) {
                    xMouse = 280;
                }
                ui->leftClient->setMinimumWidth(xMouse);
                ui->leftClient->setMaximumWidth(xMouse);
                ui->leftClient_titleBar->setMinimumWidth(xMouse);
                ui->leftClient_titleBar->setMaximumWidth(xMouse);
                //左侧TreeView不能改变大小，因为TreeView不支持动态设置item的高度。

            }
            break;

            default:

                setCursor(Qt::ArrowCursor);
            break;
        }

        e->accept();


    } else {

        setCursor(Qt::ArrowCursor);
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::SmallPic_scaled(double value)
{
    if ( m_Tree_SmallPic != NULL ) {
        m_Tree_SmallPic->init(m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),getScaledValue()),value);
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::Verify_Stamp(QTreeWidgetItem* item)
{
    //qDebug() << "Verify_Stamp begin "   << Qt::endl;
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    QString fullFileName = m_MyTabBar->getFullFileName(m_MyTabBar->getSelectTab_Index());
    if ( fullFileName.isEmpty() ) {
        myMessageBox.setContent("当前没有打开有效的文档！");
        myMessageBox.exec();
        return;
    }

    int index = m_Tree_Stamp->getItemIndex(item);
    QList<ItemInfo*>* stamplist = m_MyTabBar->getStramps(m_MyTabBar->getSelectTab_Index());
    ItemInfo * tempItem = stamplist->at(index); //*(stamplist->begin()+index);
    if ( tempItem != NULL ) {

        QFile tempfile(fullFileName);
        if ( !tempfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray temdata = tempfile.readAll();
        tempfile.close();

        HANDLE tempOFDObj = m_MyTabBar->getOFDObject(m_MyTabBar->getSelectTab_Index());
        HANDLE tempPDFObj = m_MyTabBar->getPDFObject(m_MyTabBar->getSelectTab_Index());

        char * signerdn = NULL;
        int signerdnlen = 0;
        char * signtime = NULL;
        int signtimelen = 0;
        int res = 0;

        QByteArray pcharID = tempItem->StampID.toUtf8();

        if ( tempOFDObj != NULL ) {
            res = m_OFDPDFSigner.testOFDVerify((unsigned char *)temdata.data(),temdata.size(),pcharID.data(),&signtime,&signtimelen,&signerdn,&signerdnlen);
            switch (res){
                case 0:
                    tempItem->StampVerifyInfo = "印章有效！";

                    break;
                case -2:
                    tempItem->StampVerifyInfo = "验证失败，\n加载OFD文档失败！";
                    break;
                case -20:
                    tempItem->StampVerifyInfo = "验证失败，\n计算文摘失败！";
                    break;
                case -30:
                    tempItem->StampVerifyInfo = "验证失败，\n文件被篡改！";
                    break;
                case -100:
                    tempItem->StampVerifyInfo = "验证失败，\n无法解析签名数据结构！";
                    break;
                case -101:
                    tempItem->StampVerifyInfo = "验证失败，\n不支持的数据结构！";
                    break;
                case -200:
                    tempItem->StampVerifyInfo = "验证失败，\n验证签名数据失败！";
                    break;
                case -201:
                    tempItem->StampVerifyInfo = "验证失败，\n加载证书失败！";
                    break;
                case -300:
                    tempItem->StampVerifyInfo = "验证失败，\n读取OFD文档失败！";
                    break;
                case -301:
                    tempItem->StampVerifyInfo = "验证失败，\n读取印章数据失败！";
                    break;
                case -302:
                    tempItem->StampVerifyInfo = "验证失败，\n没有设置验证器！";
                    break;
                case -303:
                    tempItem->StampVerifyInfo = "验证失败，\n签名数据是空的！";
                    break;
                case -402:
                    tempItem->StampVerifyInfo = "验证失败，\n分配内存失败！";
                    break;
                default:
                    tempItem->StampVerifyInfo = "验证失败！";
                    break;

            }
        } else if ( tempPDFObj != NULL ) {
            res = m_OFDPDFSigner.testPDFVerify((unsigned char *)temdata.data(),temdata.size(),pcharID.data(),&signtime,&signtimelen,&signerdn,&signerdnlen);
            switch (res){
                case 0:
                    tempItem->StampVerifyInfo = "印章有效！";

                    break;
                case -1:
                    tempItem->StampVerifyInfo = "验证失败，\n加载PDF文档失败！";
                    break;
                case -2:
                    tempItem->StampVerifyInfo = "验证失败，\n没有签名对象！";
                    break;
                case -3:
                    tempItem->StampVerifyInfo = "验证失败，\n签名验证失败！";
                    break;
                case -4:
                    tempItem->StampVerifyInfo = "验证失败，\n计算文摘失败！";
                    break;
                case -402:
                    tempItem->StampVerifyInfo = "验证失败，\n分配内存失败！";
                    break;
                default:
                    tempItem->StampVerifyInfo = "验证失败！";
                    break;
            }
        }

        tempItem->Time = signtime == NULL ? "" : signtime;
        tempItem->Stamper = signerdn == NULL ? "" : signerdn;


        qDebug() << "Verify_Stamp : stamp id:  " << tempItem->StampID << " res: " << res << " time:" << signtime << " signer" << signerdn << Qt::endl;

        if ( signerdn != NULL ) {
            m_OFDPDFSigner.FreeHandle(signerdn);
        }
        if ( signtime != NULL ) {
            m_OFDPDFSigner.FreeHandle(signtime);
        }

        if ( tempItem->qlVerifyButton != NULL ) {
            if ( tempItem->StampVerifyInfo=="未验证" ) {
                tempItem->qlVerifyButton->show();
                tempItem->qlVerifyButton->setVisible(true);
            } else {
                tempItem->qlVerifyButton->setVisible(false);
                if ( tempItem->qlTitle != NULL ) {
                    tempItem->qlTitle->setText(tempItem->StampVerifyInfo);
                }
            }

        }

        if ( tempItem->qlStamper != NULL ) {
            tempItem->qlStamper->setText("签章人: "+ tempItem->Stamper);
        }

        if ( tempItem->qlTime != NULL ) {
            tempItem->qlTime->setText("签章时间: "+ tempItem->Time);
        }


    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::TreeItemClick_Stamp(QTreeWidgetItem* item)
{
    int index = m_Tree_Stamp->getItemIndex(item);
    QList<ItemInfo*>* stamplist = m_MyTabBar->getStramps(m_MyTabBar->getSelectTab_Index());
    ItemInfo * tempItem = stamplist->at(index); //*(stamplist->begin()+index);
    if ( tempItem != NULL ) {
        QString pageIndex = tempItem->StampPageIndex;
        qDebug() << "TreeViewDoubleClick : pageIndex:  " << pageIndex  << Qt::endl;
        QStringList qstrlist = pageIndex.split(",");
        if ( qstrlist.size() > 0 ) {
            index = qstrlist[0].toInt()-1;
            switch ( m_DisplayModeType ) {
                case DisplayModeType::Type_ContinuePage:
                    ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index));
                    break;
                case DisplayModeType::Type_ShowOnepage:
                    {
                    int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
                    setGotoEditText(index+1,count);
                    ShowOnepage();
                    }
                    break;
                case DisplayModeType::Type_ShowTwoPage:
                    ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index/2));
                    break;
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::TreeItemClick_Annot(int index)
{
    switch ( m_DisplayModeType ) {
        case DisplayModeType::Type_ContinuePage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index));
            break;
        case DisplayModeType::Type_ShowOnepage:
            {
            int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
            setGotoEditText(index+1,count);
            ShowOnepage();
            }
            break;
        case DisplayModeType::Type_ShowTwoPage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index/2));
            break;
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::TreeViewDoubleClick(QTreeWidgetItem* item,int itemID)
{
    switch (m_LeftBarButtonType) {
        case LeftBarButtonType::Type_None:
            break;
        case LeftBarButtonType::Type_SmallPic:
            if ( m_Tree_SmallPic != NULL ) {
                m_Tree_SmallPic->TreeViewDoubleClick(item,itemID);
            }
            break;
        case LeftBarButtonType::Type_Anno:
            if ( m_Tree_Anno != NULL ) {
                m_Tree_Anno->TreeViewDoubleClick(item,itemID);

            }
            break;
        case LeftBarButtonType::Type_Stamp:
            if ( m_Tree_Stamp != NULL ) {
                m_Tree_Stamp->TreeViewDoubleClick(item,itemID);
                TreeItemClick_Stamp(item);

            }
            break;
        case LeftBarButtonType::Type_Attachment:
            if ( m_Tree_Attachment != NULL ) {
                m_Tree_Attachment->TreeViewDoubleClick(item,itemID);
            }
            break;
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::TreeWidgetClick(QTreeWidgetItem* item,int itemID)
{
    switch (m_LeftBarButtonType) {
        case LeftBarButtonType::Type_None:
            break;
        case LeftBarButtonType::Type_SmallPic:
            if ( m_Tree_SmallPic != NULL ) {
                m_Tree_SmallPic->TreeWidgetClick(item,itemID);
            }
            break;
        case LeftBarButtonType::Type_Anno:
            if ( m_Tree_Anno != NULL ) {
                m_Tree_Anno->TreeWidgetClick(item,itemID);

            }
            break;
        case LeftBarButtonType::Type_Stamp:
            if ( m_Tree_Stamp != NULL ) {
                m_Tree_Stamp->TreeWidgetClick(item,itemID);
                TreeItemClick_Stamp(item);
            }
            break;
        case LeftBarButtonType::Type_Attachment:
            if ( m_Tree_Attachment != NULL ) {
                m_Tree_Attachment->TreeWidgetClick(item,itemID);
            }
            break;
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::ShowDocment(int pageindex)
{
    int currindex = pageindex;
    double scaled = getScaledValue();
    QPixmap * pinmap1 = NULL;
    QPixmap * pinmap2 = NULL;
    setCursor(Qt::WaitCursor);
    QList<QPixmap*> * pixmaplist = m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),scaled);
    if ( pixmaplist == NULL || pixmaplist->size() <= 0 ) {

        HANDLE tempOFDObj = m_MyTabBar->getOFDObject(m_MyTabBar->getSelectTab_Index());
        HANDLE tempPDFObj = m_MyTabBar->getPDFObject(m_MyTabBar->getSelectTab_Index());
        int TotalPageNum = 0;
        if ( tempOFDObj != NULL ) {
            m_Tree_Docment->clear();
            TotalPageNum = m_OFDPDFSigner.ofd_getPageCount(tempOFDObj);

            for( int i = 0; i < TotalPageNum; i++ ) {
                unsigned char * picdata = NULL;
                size_t picdatalen = 0;

                if ( !m_OFDPDFSigner.ofd_pageToImage(tempOFDObj,"PNG",i,scaled,&picdata,&picdatalen) ) {
                    continue;
                }

                if ( picdata == NULL || picdatalen == 0 ) {
                    continue;
                }

                QPixmap * pixmap = m_MyTabBar->addDocmentPixmap(m_MyTabBar->getSelectTab_Index(),scaled,(const unsigned char *)(picdata),picdatalen);
                switch ( m_DisplayModeType ) {
                    case DisplayModeType::Type_ContinuePage:
                        m_Tree_Docment->addPixmap(pixmap);
                        break;
                    case DisplayModeType::Type_ShowOnepage:
                        if ( i == currindex ) {
                            m_Tree_Docment->addPixmap(pixmap);
                        }
                        break;
                    case DisplayModeType::Type_ShowTwoPage:
                        if ( (i+1) % 2 == 0 ) {
                            pinmap2 = pixmap;
                            m_Tree_Docment->addPixmap(pinmap1,pinmap2);
                        } else {
                            pinmap1 = pixmap;
                            if ( i == TotalPageNum -1 ) {
                                m_Tree_Docment->addPixmap(pinmap1,NULL);
                            }
                        }

                        break;
                }

                m_OFDPDFSigner.FreeHandle(picdata);

            }


        } else if ( tempPDFObj != NULL ) {
            m_Tree_Docment->clear();
            TotalPageNum = m_OFDPDFSigner.pdf_getPageCount(tempPDFObj);

            for( int i = 0; i < TotalPageNum; i++ ) {
                unsigned char * picdata = NULL;
                size_t picdatalen = 0;

                if ( !m_OFDPDFSigner.pdf_pageToImage(tempPDFObj,"PNG",i,scaled,&picdata,&picdatalen) ) {
                    continue;
                }

                if ( picdata == NULL || picdatalen == 0 ) {
                    continue;
                }

                QPixmap * pixmap = m_MyTabBar->addDocmentPixmap(m_MyTabBar->getSelectTab_Index(),scaled,(const unsigned char *)(picdata),picdatalen);
                switch ( m_DisplayModeType ) {
                    case DisplayModeType::Type_ContinuePage:
                        m_Tree_Docment->addPixmap(pixmap);
                        break;
                    case DisplayModeType::Type_ShowOnepage:
                        if ( i == currindex ) {
                            m_Tree_Docment->addPixmap(pixmap);
                        }
                        break;
                    case DisplayModeType::Type_ShowTwoPage:
                        if ( (i+1) % 2 == 0 ) {
                            pinmap2 = pixmap;
                            m_Tree_Docment->addPixmap(pinmap1,pinmap2);
                        } else {
                            pinmap1 = pixmap;
                            if ( i == TotalPageNum -1 ) {
                                m_Tree_Docment->addPixmap(pinmap1,NULL);
                            }
                        }

                        break;
                }

                m_OFDPDFSigner.FreeHandle(picdata);

            }

        }
    } else {
        m_Tree_Docment->clear();
        QList<QPixmap*>::const_iterator it;
        for( it = pixmaplist->constBegin(); it != pixmaplist->constEnd(); it++) {

            if ( *it != NULL ) {
                switch ( m_DisplayModeType ) {
                    case DisplayModeType::Type_ContinuePage:
                        m_Tree_Docment->addPixmap(*it);
                        break;
//                    case DisplayModeType::Type_ShowOnepage:
//                        if ( it-pixmaplist->begin() == currindex ) {
//                            m_Tree_Docment->addPixmap(*it);
//                        }
//                        break;
                     case DisplayModeType::Type_ShowTwoPage:
                        if ( (it-pixmaplist->begin() +1) % 2 == 0 ) {
                            pinmap2 = *it;
                            m_Tree_Docment->addPixmap(pinmap1,pinmap2);
                        } else {
                            pinmap1 = *it;
                            if ( it-pixmaplist->begin() == pixmaplist->size() -1 ) {
                                m_Tree_Docment->addPixmap(pinmap1,NULL);
                            }
                        }
                        break;
                }
            }
        }
    }

    int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),scaled);
    //qDebug() << "on_ScaledValue_Changed : pagecount:  " << count  << Qt::endl;
    switch ( m_DisplayModeType ) {

        case DisplayModeType::Type_ContinuePage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(currindex));
            break;
        case DisplayModeType::Type_ShowOnepage:

            //qDebug() << "on_ScaledValue_Changed : currindex2 :  "  << currindex << Qt::endl;
            setGotoEditText(currindex+1,count);
            ShowOnepage();
            SmallPicShowMask(currindex);
            break;
        case DisplayModeType::Type_ShowTwoPage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(currindex/2));
            break;
    }

    setCursor(Qt::ArrowCursor);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::on_ScaledValue_Changed(int item)
{
    int currindex = getCurrDisplayItemIndex();

    ui->comboBox->setCurrentIndex(item);

    ShowDocment(currindex);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::SmallPic_DocmentScrollToItem(int index)
{

    switch ( m_DisplayModeType ) {
        case DisplayModeType::Type_ContinuePage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index));
            break;
        case DisplayModeType::Type_ShowOnepage:
            {
            int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
            setGotoEditText(index+1,count);
            ShowOnepage();
            SmallPicShowMask(index);
            }
            break;
        case DisplayModeType::Type_ShowTwoPage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index/2));
            break;
    }


}
//----------------------------------------------------------------------------------------------------------
void MainWidget::SmallPicShowMask(int index)
{
    if ( m_LeftBarButtonType == LeftBarButtonType::Type_SmallPic ) {

        if ( m_Tree_SmallPic != NULL ) {
            QTreeWidgetItem * item = ui->tw_LeftClient->topLevelItem(index);
            ui->tw_LeftClient->setCurrentItem(item);

            switch ( m_DisplayModeType ) {
                case DisplayModeType::Type_ShowOnepage:
                case DisplayModeType::Type_ContinuePage:
                    m_Tree_SmallPic->ShowMask(item);
                    break;
                case DisplayModeType::Type_ShowTwoPage:
                    m_Tree_SmallPic->ShowMaskTow(index);
                    break;
            }
        }

    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::onDocmentScrollChanged(int p)
{
    int index = 0;
    switch ( m_DisplayModeType ) {
        case DisplayModeType::Type_ShowTwoPage:
        case DisplayModeType::Type_ContinuePage:
            {
                int pos = ui->tw_Docment->geometry().height()/2;
                pos = pos - pos / 4;
                QTreeWidgetItem * item = ui->tw_Docment->itemAt(0,pos);
                index = ui->tw_Docment->indexOfTopLevelItem(item);
                //qDebug() << "onDocmentScrollChanged : *********  "  << Qt::endl;
                if ( m_DisplayModeType == DisplayModeType::Type_ShowTwoPage ) {
                    index = index*2;
                }
                setGotoEditText(index+1,m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue()));
            }
            break;
        case DisplayModeType::Type_ShowOnepage:
            index = getCurrDisplayItemIndex();
            break;
    }

    SmallPicShowMask(index);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbFirstPage()
{
    switch ( m_DisplayModeType ) {
        case DisplayModeType::Type_ShowTwoPage:
        case DisplayModeType::Type_ContinuePage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(0));
            break;
        case DisplayModeType::Type_ShowOnepage:
            setGotoEditText(1,m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue()));
            ShowOnepage();
            SmallPicShowMask(0);
            break;
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbPrePage()
{
//    int pos = ui->tw_Docment->geometry().height()/2;
//    pos = pos - pos / 4;
//    QTreeWidgetItem * item = ui->tw_Docment->itemAt(0,pos);
//    int index = ui->tw_Docment->indexOfTopLevelItem(item);

    int index = getCurrDisplayItemIndex();
    qDebug() << "click_pbNextPage -- index:" << index << Qt::endl;
    if ( m_DisplayModeType == DisplayModeType::Type_ShowTwoPage ) {
        index -= 2;
    } else {
        index--;
    }

    if ( index < 0 ) {
        index = 0;
    }

    qDebug() << "click_pbNextPage ++ index:" << index << Qt::endl;

    switch ( m_DisplayModeType ) {

        case DisplayModeType::Type_ContinuePage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index));
            break;
        case DisplayModeType::Type_ShowOnepage:
            {
            int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
            setGotoEditText(index+1,count);
            ShowOnepage();
            SmallPicShowMask(index);
            }
            break;
        case DisplayModeType::Type_ShowTwoPage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index/2));
            break;
    }



}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbNextPage()
{
//    int pos = ui->tw_Docment->geometry().height()/2;
//    pos = pos - pos / 4;
//    QTreeWidgetItem * item = ui->tw_Docment->itemAt(0,pos);
//    int index = ui->tw_Docment->indexOfTopLevelItem(item);
    int index = getCurrDisplayItemIndex();

    //qDebug() << "click_pbNextPage -- index:" << index << Qt::endl;

    int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
    if ( m_DisplayModeType == DisplayModeType::Type_ShowTwoPage ) {
        index += 2;
    } else {
        index++;
    }
    if ( index >= count ) {
        index = count - 1;
    }
    //qDebug() << "click_pbNextPage ++ index:" << index << Qt::endl;

    switch ( m_DisplayModeType ) {

        case DisplayModeType::Type_ContinuePage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index));
            break;
        case DisplayModeType::Type_ShowOnepage:
            {
            int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
            setGotoEditText(index+1,count);
            ShowOnepage();
            SmallPicShowMask(index);
            }
            break;
        case DisplayModeType::Type_ShowTwoPage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index/2));
            break;


    }



}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbLastPage()
{
    switch ( m_DisplayModeType ) {

        case DisplayModeType::Type_ContinuePage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue())-1));
            break;
        case DisplayModeType::Type_ShowOnepage:
            {
            int count = m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue());
            setGotoEditText(count,count);
            ShowOnepage();
            SmallPicShowMask(count-1);
            }
            break;
        case DisplayModeType::Type_ShowTwoPage:
            ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem((m_MyTabBar->getDocmentPageCount(m_MyTabBar->getSelectTab_Index(),getScaledValue())-1)/2));
            break;
    }


}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbContinuePage()
{
    if ( m_DisplayModeType == DisplayModeType::Type_ContinuePage ) return;
    m_DisplayModeType = DisplayModeType::Type_ContinuePage;
    ui->pbContinuePage->setStyleSheet(
                    "background: rgba(40, 40, 40, 0.2);"
                    );

    ui->pbShowOnepage->setStyleSheet("");
    ui->pbShowTwoPage->setStyleSheet("");


    double scaled = getScaledValue();

    QList<QPixmap*> * pixmaplist = m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),scaled);
    if ( pixmaplist == NULL || pixmaplist->size() <= 0 ) {
        return;
    } else {
        int index = getCurrDisplayItemIndex();
        m_Tree_Docment->clear();
        QList<QPixmap*>::const_iterator it;
        for( it = pixmaplist->constBegin(); it != pixmaplist->constEnd(); it++) {
            m_Tree_Docment->addPixmap(*it);
        }
        ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index));
        SmallPicShowMask(index);
    }

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::ShowOnepage()
{
    double scaled = getScaledValue();

    QList<QPixmap*> * pixmaplist = m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),scaled);
    if ( pixmaplist == NULL || pixmaplist->size() <= 0 ) {
        return;
    } else {
        int index = getCurrDisplayItemIndex();
        m_Tree_Docment->clear();
        if (index >= 0 && index <= pixmaplist->size() -1  ) {
            QPixmap* temp = *(pixmaplist->begin()+index);
            if ( temp != NULL ) {
                m_Tree_Docment->addPixmap(temp);
            }
        }
        SmallPicShowMask(index);
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbShowOnepage()
{
    if ( m_DisplayModeType == DisplayModeType::Type_ShowOnepage ) return;

    m_DisplayModeType = DisplayModeType::Type_ShowOnepage;
    ui->pbShowOnepage->setStyleSheet(
                    "background: rgba(40, 40, 40, 0.2);"
                    );

    ui->pbContinuePage->setStyleSheet("");
    ui->pbShowTwoPage->setStyleSheet("");

    ShowOnepage();
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbShowTwoPage()
{
    if ( m_DisplayModeType == DisplayModeType::Type_ShowTwoPage ) return;
    m_DisplayModeType = DisplayModeType::Type_ShowTwoPage;
    ui->pbShowTwoPage->setStyleSheet(
                    "background: rgba(40, 40, 40, 0.2);"
                    );

    ui->pbContinuePage->setStyleSheet("");
    ui->pbShowOnepage->setStyleSheet("");

    double scaled = getScaledValue();

    QList<QPixmap*> * pixmaplist = m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),scaled);
    if ( pixmaplist == NULL || pixmaplist->size() <= 0 ) {
        return;
    } else {
        int index = getCurrDisplayItemIndex();
        m_Tree_Docment->clear();
        QList<QPixmap*>::const_iterator it;
        QPixmap * pinmap1 = NULL;
        QPixmap * pinmap2 = NULL;
        for( it = pixmaplist->constBegin(); it != pixmaplist->constEnd(); it++) {
            if ( (it-pixmaplist->begin() +1) % 2 == 0 ) {
                pinmap2 = *it;
                m_Tree_Docment->addPixmap(pinmap1,pinmap2);
            } else {
                pinmap1 = *it;
                if ( it-pixmaplist->begin() == pixmaplist->size() -1 ) {
                    m_Tree_Docment->addPixmap(pinmap1,NULL);
                }
            }

        }

        ui->tw_Docment->scrollToItem(ui->tw_Docment->topLevelItem(index/2));
        SmallPicShowMask(index);
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::getDocmentOtherInfo()
{
    QList<ItemInfo*>* tempAttachments = m_MyTabBar->getAttachments(m_MyTabBar->getSelectTab_Index());
    QList<ItemInfo*>* tempStamps = m_MyTabBar->getStramps(m_MyTabBar->getSelectTab_Index());
    QMap<int,QList<ItemInfo*>*>* tempAnnots = m_MyTabBar->getAnnos(m_MyTabBar->getSelectTab_Index());

    HANDLE tempOFDObj = m_MyTabBar->getOFDObject(m_MyTabBar->getSelectTab_Index());
    HANDLE tempPDFObj = m_MyTabBar->getPDFObject(m_MyTabBar->getSelectTab_Index());

    if ( tempAttachments != NULL && tempAttachments->size() == 0 ) {
        if ( tempOFDObj != NULL ) {
            m_OFDPDFSigner.ofd_getOtherInfo(tempOFDObj,AttachmentFileFunc,NULL,NULL);
        } else if ( tempPDFObj != NULL ) {
            m_OFDPDFSigner.pdf_getOtherInfo(tempPDFObj,AttachmentFileFunc,NULL,NULL);
        }
    }

    if ( tempStamps != NULL && tempStamps->size() == 0 ) {
        if ( tempOFDObj != NULL ) {
            m_OFDPDFSigner.ofd_getOtherInfo(tempOFDObj,NULL,NULL,StampsFunc);
        } else if ( tempPDFObj != NULL ) {
            m_OFDPDFSigner.pdf_getOtherInfo(tempPDFObj,NULL,NULL,StampsFunc);
        }
    }


    if ( tempAnnots != NULL && tempAnnots->size() == 0 ) {
        if ( tempOFDObj != NULL ) {
            m_OFDPDFSigner.ofd_getOtherInfo(tempOFDObj,NULL,AnnotsFunc,NULL);
        } else if ( tempPDFObj != NULL ) {
            m_OFDPDFSigner.pdf_getOtherInfo(tempPDFObj,NULL,AnnotsFunc,NULL);
        }
    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::AttachmentFileFunc(const char* const filename,const char * const time,const unsigned char* const filedata,int filedatalen)
{
    //qDebug() << "AttachmentFileFunc => filename:" << filename << " time:" << time << " filedatatlen:" << filedatalen << Qt::endl;

    MainWidget::m_SelfPtr->m_MyTabBar->addAttachment(MainWidget::m_SelfPtr->m_MyTabBar->getSelectTab_Index(),filename,time,(const unsigned char *)filedata,filedatalen);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::AnnotsFunc(int pagenum,const char * const creator,const char* const time,const char* const type,const char* const remark)
{
    //qDebug() << "AnnotsFunc => pagenum:" << pagenum << " creator:" << creator << " time:" << time << " type:" << type << " remark:" << remark << Qt::endl;
    MainWidget::m_SelfPtr->m_MyTabBar->addAnno(MainWidget::m_SelfPtr->m_MyTabBar->getSelectTab_Index(),pagenum,QIcon(":/res/images/stamp.png"),creator,time,remark);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::StampsFunc(const char* const pagenum,const char * const time,const char * const sid,const unsigned char* imagedata,int imagedatalen)
{
//    unsigned char * picdata = NULL;
//    int picdatalen = 0;

//    if ( !MainWidget::m_SelfPtr->m_OFDPDFSigner.ImageScaledToWidth(imagedata,imagedatalen,80,&picdata,&picdatalen) ) {
//        return;
//    }

//    if ( picdata == NULL || picdatalen == 0 ) {
//        return;
//    }



//    MainWidget::m_SelfPtr->m_MyTabBar->addStramp(MainWidget::m_SelfPtr->m_MyTabBar->getSelectTab_Index(),picdata,picdatalen,"印章无效",time,"",pagenum);

//    MainWidget::m_SelfPtr->m_OFDPDFSigner.FreeHandle(picdata);

    MainWidget::m_SelfPtr->m_MyTabBar->addStramp(MainWidget::m_SelfPtr->m_MyTabBar->getSelectTab_Index(),imagedata,imagedatalen,"未验证",time,"",pagenum,sid);
    qDebug() << "StampsFunc => pagenum:" << pagenum << " time:" << time << " sid:" << sid << " imagedatalen:" << imagedatalen << Qt::endl;
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::Clicked_AttachmentFile_Open()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    QList<ItemInfo*>* tempAttachments = m_MyTabBar->getAttachments(m_MyTabBar->getSelectTab_Index());
    if ( tempAttachments == NULL ) {
        myMessageBox.setContent("当前您没可以打开的附件！");
        myMessageBox.exec();
        return;
    }
    if ( m_Tree_Attachment->getSelectIndex() == -1 ) {

        myMessageBox.setContent("您没有选择要打开的附件！");
        myMessageBox.exec();
        return;
    }
    ItemInfo* iteminfo = *(tempAttachments->begin()+m_Tree_Attachment->getSelectIndex());
    if ( iteminfo == NULL ) {
        myMessageBox.setContent("当前您没可以打开的附件！");
        myMessageBox.exec();
        return;
    }

    if ( iteminfo->FileData.size() <= 0 ) {
        myMessageBox.setContent("当前附件大小为零！\n不能打开该附件！");
        myMessageBox.exec();
        return;
    }

    QString fileName = QStandardPaths::writableLocation(QStandardPaths::TempLocation)+"/"+iteminfo->Tilte;
    qDebug() << "Clicked_AttachmentFile_Open => filename:" << fileName << Qt::endl;
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)) {
        file.write(iteminfo->FileData);
        file.close();
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
    } else {
        myMessageBox.setContent("不能在系统临时目录创建文件！请检查文件权限！");
        myMessageBox.exec();

    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::Clicked_AttachmentFile_Save()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    QList<ItemInfo*>* tempAttachments = m_MyTabBar->getAttachments(m_MyTabBar->getSelectTab_Index());
    if ( tempAttachments == NULL ) {
        myMessageBox.setContent("当前您没可以导出的附件！");
        myMessageBox.exec();
        return;
    }
    if ( m_Tree_Attachment->getSelectIndex() == -1 ) {

        myMessageBox.setContent("您没有选择要导出的附件！");
        myMessageBox.exec();
        return;
    }
    ItemInfo* iteminfo = *(tempAttachments->begin()+m_Tree_Attachment->getSelectIndex());
    if ( iteminfo == NULL ) {
        myMessageBox.setContent("当前您没可以导出的附件！");
        myMessageBox.exec();
        return;
    }

    if ( iteminfo->FileData.size() <= 0 ) {
        myMessageBox.setContent("当前附件大小为零！\n不能导出该附件！");
        myMessageBox.exec();
        return;
    }




    QFileDialog fileDialog;
    QString fileName = fileDialog.getSaveFileName(this,tr("导出附件"),QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/"+iteminfo->Tilte,tr("All File(*.*)"));
    if(fileName == "")
    {
        return;
    }
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)) {
        file.write(iteminfo->FileData);
        file.close();
    } else {
        myMessageBox.setContent("不能写该文件！请检查文件权限！");
        myMessageBox.exec();
    }

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::AddFindWordList(int pageIndex,const char* const word,float x,float y,float w,float h)
{
    DocWord * temp = new DocWord();
    temp->m_PageIndex = pageIndex;
    temp->m_Word = word;
    temp->m_x = x;
    temp->m_y = y;
    temp->m_w = w;
    temp->m_h = h;
    m_FindWordList.push_back(temp);
    qDebug() << "FindWordFunc => pagenum:" << pageIndex << " word:" << word << " x:" << temp->m_x << " y:" << temp->m_y << " w:" << temp->m_w << " h:" << temp->m_h << Qt::endl;
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::ClearFindWordList()
{
    QList<DocWord *>::const_iterator it;
    for( it = m_FindWordList.begin(); it != m_FindWordList.end(); it++ ) {
        DocWord * temp = *it;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_FindWordList.clear();

}
//----------------------------------------------------------------------------------------------------------
void MainWidget::FindWordFunc(int pageIndex,const char* const word,float x,float y,float w,float h)
{
    if ( m_SelfPtr != NULL ) {
        m_SelfPtr->AddFindWordList(pageIndex,word,x,y,w,h);
    }
}
//----------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------
QPixmap MainWidget::DrawFindWord(QPixmap* srcPixmap,int pageIndex,QString word)
{
    QPixmap temppix =  *srcPixmap;
    QPainter painter(&temppix);

    QString lowerWord = word.toLower();
    QString tempKeyWord = "";
    double scaled = getScaledValue();
    QList<DocWord *>::const_iterator it;
    for( it = m_FindWordList.begin(); it != m_FindWordList.end(); it++ ) {
        DocWord * temp = *it;
        if ( temp == NULL ) {
            continue;
        }
        tempKeyWord = temp->m_Word.toLower();
        qDebug() << "DrawFindWord => 2:"<< tempKeyWord << " == " << lowerWord <<Qt::endl;
        if ( temp->m_PageIndex == pageIndex && tempKeyWord == lowerWord ) {


            QRect rect(temp->m_x*scaled-1,temp->m_y*scaled-1,temp->m_w*scaled+2,temp->m_h*scaled+2);
            //QRect rect(0,0,temp->m_w*scaled+2,temp->m_h*scaled+2);

            painter.fillRect(rect, QColor(56,164,186, 180));
            qDebug() << "DrawFindWord => 2:"<< Qt::endl;
        }
    }

    //qDebug() << "DrawFindWord => 1:"<< Qt::endl;
    return temppix;
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::returnPressed_leFindKey()
{
    QString tempWord = ui->leFindKey->text();
    tempWord = tempWord.trimmed();


    QByteArray ba = tempWord.toUtf8();
    char* pTempWord = ba.data();


    //qDebug() << "findword => "<< pTempWord << Qt::endl;

    HANDLE tempOFDObj = m_MyTabBar->getOFDObject(m_MyTabBar->getSelectTab_Index());
    HANDLE tempPDFObj = m_MyTabBar->getPDFObject(m_MyTabBar->getSelectTab_Index());

    ClearFindWordList();

    int TotalPageNum = 0;
    if ( tempOFDObj != NULL ) {
        TotalPageNum = m_OFDPDFSigner.ofd_getPageCount(tempOFDObj);
        for ( int i = 0; i < TotalPageNum; i++ ) {
            m_OFDPDFSigner.ofd_findWord(tempOFDObj,i,pTempWord,FindWordFunc);
        }
    } else if ( tempPDFObj != NULL ) {
        TotalPageNum = m_OFDPDFSigner.pdf_getPageCount(tempPDFObj);
        for ( int i = 0; i < TotalPageNum; i++ ) {
            m_OFDPDFSigner.pdf_findWord(tempPDFObj,i,pTempWord,FindWordFunc);
        }
    }

    double scaled = getScaledValue();
    QList<QPixmap*> * pixmaplist = m_MyTabBar->getDocmentPixmaps(m_MyTabBar->getSelectTab_Index(),scaled);
    if ( m_FindWordList.size() <= 0 || pixmaplist == NULL || pixmaplist->size() <= 0 ) {
        return;
    }

    int currindex = getCurrDisplayItemIndex();

    m_Tree_Docment->clear();
    QPixmap pinmap1;
    QPixmap pinmap2;
    QList<QPixmap*>::const_iterator it;
    for( it = pixmaplist->constBegin(); it != pixmaplist->constEnd(); it++) {
        if ( *it == NULL ) continue;
        QPixmap * tempPixmap = *it;
        int tempPageindex = it-pixmaplist->begin();
        switch ( m_DisplayModeType ) {
            case DisplayModeType::Type_ShowOnepage:
                if ( tempPageindex == currindex ) {
                    QPixmap drawPixmap = DrawFindWord(tempPixmap,tempPageindex,tempWord);
                    m_Tree_Docment->addPixmap(&drawPixmap);
                }

                break;
            case DisplayModeType::Type_ContinuePage:
                {
                    QPixmap drawPixmap = DrawFindWord(tempPixmap,tempPageindex,tempWord);
                    m_Tree_Docment->addPixmap(&drawPixmap);
                }
                break;
             case DisplayModeType::Type_ShowTwoPage:
                {
                    QPixmap drawPixmap = DrawFindWord(tempPixmap,tempPageindex,tempWord);
                    if ( (it-pixmaplist->begin() +1) % 2 == 0 ) {
                        pinmap2 = drawPixmap;
                        m_Tree_Docment->addPixmap(&pinmap1,&pinmap2);
                    } else {
                        pinmap1 = drawPixmap;
                        if ( it-pixmaplist->begin() == pixmaplist->size() -1 ) {
                            m_Tree_Docment->addPixmap(&pinmap1,NULL);
                        }
                    }
                }
                break;
        }

    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::SystemFontFileNameFunc(const void * param,const char* const fullFileName)
{
    m_SelfPtr->m_SystemFontFiles.push_back(fullFileName);
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::SignStamp_Pos(int pageIndex, int x,int y,QString FullFileName,int docType,
                               QString StampFileName,QString CertFileName,
                               QString prikeyFileName,QString SaveasFileName)
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);


    QFile tempfile(FullFileName);
    if ( !tempfile.open(QFile::ReadOnly) ) {
        myMessageBox.setContent("不能打开该文档！");
        myMessageBox.exec();
        return;
    }
    QByteArray temdata = tempfile.readAll();
    tempfile.close();

     QFile certfile(CertFileName);
    if ( !certfile.open(QFile::ReadOnly) ) {
        myMessageBox.setContent("不能打开该文档！");
        myMessageBox.exec();
        return;
    }
    QByteArray certdata = certfile.readAll();
    certfile.close();

    QFile prikeyfile(prikeyFileName);
    if ( !prikeyfile.open(QFile::ReadOnly) ) {
        myMessageBox.setContent("不能打开该文档！");
        myMessageBox.exec();
        return;
    }
    QByteArray prikeydata = prikeyfile.readAll();
    prikeyfile.close();

    unsigned char * outdata = NULL;
    int outdatalen = 0;

    double scaled = getScaledValue();
    if ( docType == 1 ) {

        QFile sealfile(StampFileName);
        if ( !sealfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray sealdata = sealfile.readAll();
        sealfile.close();

        qDebug() << "testOFDPositionSign begin => x :" << x << ", y :" << y << Qt::endl;
        //x = (double)x/scaled * 25.4 / 72;
        //y = (double)y/scaled * 25.4 / 72;
        //毫米扩大到 scaled倍，印章中心位置是x,y(42/2)
        x = (double)x/(scaled * (0.01/0.254*72)) - 42 /2;
        y = (double)y/(scaled * (0.01/0.254*72)) - 42 /2;
        qDebug() << "testOFDPositionSign end => x :" << x << ", y :" << y << Qt::endl;

        m_OFDPDFSigner.testOFDPositionSign((const unsigned char *)sealdata.data(),sealdata.size(),
                                            (const unsigned char *)certdata.data(),certdata.size(),
                                            (const unsigned char *)prikeydata.data(),prikeydata.size(),
                                            (const unsigned char *)temdata.data(),temdata.size(),
                                            pageIndex,x,y,42,42,true,&outdata,&outdatalen);
    } else if (docType == 2) {

         QFile sealfile(StampFileName);
        if ( !sealfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray sealdata = sealfile.readAll();
        sealfile.close();
        //像素扩大到 scaled倍，印章中心位置是x,y(42(毫米)*72/25.4(转换到像素)/2)
        x = (double)x/scaled- 42*72/25.4 /2;
        y = (double)y/scaled- 42*72/25.4 /2;
        m_OFDPDFSigner.testPDFPositionSign((const unsigned char *)sealdata.data(),sealdata.size(),
                                            (const unsigned char *)certdata.data(),certdata.size(),
                                            (const unsigned char *)prikeydata.data(),prikeydata.size(),
                                            (const unsigned char *)temdata.data(),temdata.size(),
                                            pageIndex,x,y,42,42,&outdata,&outdatalen);
    } else {

        myMessageBox.setContent("文档类型不是OFD/PDF！\n不能对该类型文档盖章！");
        myMessageBox.exec();
        return;
    }

    if ( outdata == NULL || outdatalen == 0 ) {
        myMessageBox.setContent("盖章失败！");
        myMessageBox.exec();
        return;
    }





    if(SaveasFileName == "")
    {
        myMessageBox.setContent("您没有保存盖章后的文件！");
        myMessageBox.exec();
        m_OFDPDFSigner.FreeHandle(outdata);
        return;
    }


    QFile file(SaveasFileName);
    if(file.open(QIODevice::WriteOnly)) {
        QByteArray wirtedata;
        wirtedata.resize(outdatalen);
        memcpy(wirtedata.data(),outdata,outdatalen);
        file.write(wirtedata);
        file.close();
    } else {
        myMessageBox.setContent("不能写该文件！请检查文件权限！");
        myMessageBox.exec();
        m_OFDPDFSigner.FreeHandle(outdata);
        return;

    }

    m_OFDPDFSigner.FreeHandle(outdata);

    OpenOFDOrPDF(SaveasFileName);
    //qDebug() << "SignStamp_Pos pageindex : "<< pageIndex << " xy: "<< x << " " << y << Qt::endl;
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbRidingStamp()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    QString FullFileName = m_MyTabBar->getFullFileName(m_MyTabBar->getSelectTab_Index());
    if ( FullFileName.isEmpty() ) {
        myMessageBox.setContent("当前没有打开有效的文档！");
        myMessageBox.exec();
        return;
    }



    int docType = 0;
    QString tempFileName = FullFileName.toLower();
    if ( tempFileName.endsWith(".ofd" ) ) {
        docType = 1;
    } else {
        docType = 2;
    }

    Custom_SignStamp_Riding_Dialog custom_SignStamp_Riding_Dialog(this);
    custom_SignStamp_Riding_Dialog.setDocType(docType);
    if ( custom_SignStamp_Riding_Dialog.exec() == QDialog::Accepted ) {
        QString StampFileName = custom_SignStamp_Riding_Dialog.getStampFileName();
        QString CertFileName = custom_SignStamp_Riding_Dialog.getCertFileName();
        QString prikeyFileName = custom_SignStamp_Riding_Dialog.getPriKeyFileName();
        QString SaveasFileName = custom_SignStamp_Riding_Dialog.getSaveasFileName();
        int ridingType = custom_SignStamp_Riding_Dialog.getRidingType();

        //qDebug() << "click_pbRidingStamp ridingType : "<< ridingType << Qt::endl;

        QFile tempfile(FullFileName);
        if ( !tempfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray temdata = tempfile.readAll();
        tempfile.close();

         QFile certfile(CertFileName);
        if ( !certfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray certdata = certfile.readAll();
        certfile.close();

        QFile prikeyfile(prikeyFileName);
        if ( !prikeyfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray prikeydata = prikeyfile.readAll();
        prikeyfile.close();

        QFile sealfile(StampFileName);
        if ( !sealfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray sealdata = sealfile.readAll();
        sealfile.close();

        unsigned char * outdata = NULL;
        int outdatalen = 0;

        if ( docType == 1 ) {
            m_OFDPDFSigner.testOFDRidingSign((const unsigned char *)sealdata.data(),sealdata.size(),
                                                (const unsigned char *)certdata.data(),certdata.size(),
                                                (const unsigned char *)prikeydata.data(),prikeydata.size(),
                                                (const unsigned char *)temdata.data(),temdata.size(),
                                                ridingType,42,42,true,&outdata,&outdatalen);
        } else if ( docType == 2 ) {
            m_OFDPDFSigner.testPDFRidingSign((const unsigned char *)sealdata.data(),sealdata.size(),
                                                (const unsigned char *)certdata.data(),certdata.size(),
                                                (const unsigned char *)prikeydata.data(),prikeydata.size(),
                                                (const unsigned char *)temdata.data(),temdata.size(),
                                                ridingType,42,42,&outdata,&outdatalen);
        } else {

            myMessageBox.setContent("文档类型不是OFD/PDF！\n不能对该类型文档盖章！");
            myMessageBox.exec();
            return;
        }

        if ( outdata == NULL || outdatalen == 0 ) {
            myMessageBox.setContent("盖章失败！");
            myMessageBox.exec();
            return;
        }





        if(SaveasFileName == "")
        {
            myMessageBox.setContent("您没有保存盖章后的文件！");
            myMessageBox.exec();
            m_OFDPDFSigner.FreeHandle(outdata);
            return;
        }


        QFile file(SaveasFileName);
        if(file.open(QIODevice::WriteOnly)) {
            QByteArray wirtedata;
            wirtedata.resize(outdatalen);
            memcpy(wirtedata.data(),outdata,outdatalen);
            file.write(wirtedata);
            file.close();
        } else {
            myMessageBox.setContent("不能写该文件！请检查文件权限！");
            myMessageBox.exec();
            m_OFDPDFSigner.FreeHandle(outdata);
            return;

        }

        m_OFDPDFSigner.FreeHandle(outdata);

        OpenOFDOrPDF(SaveasFileName);


    }
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbKeyWorkStamp()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);
    QString FullFileName = m_MyTabBar->getFullFileName(m_MyTabBar->getSelectTab_Index());
    if ( FullFileName.isEmpty() ) {
        myMessageBox.setContent("当前没有打开有效的文档！");
        myMessageBox.exec();
        return;
    }



    int docType = 0;
    QString tempFileName = FullFileName.toLower();
    if ( tempFileName.endsWith(".ofd" ) ) {
        docType = 1;
    } else {
        docType = 2;
    }

    Custom_SignStamp_KeyWord_Dialog custom_SignStamp_KeyWord_Dialog(this);
    custom_SignStamp_KeyWord_Dialog.setDocType(docType);
    if ( custom_SignStamp_KeyWord_Dialog.exec() == QDialog::Accepted ) {
        QString StampFileName = custom_SignStamp_KeyWord_Dialog.getStampFileName();
        QString CertFileName = custom_SignStamp_KeyWord_Dialog.getCertFileName();
        QString prikeyFileName = custom_SignStamp_KeyWord_Dialog.getPriKeyFileName();
        QString SaveasFileName = custom_SignStamp_KeyWord_Dialog.getSaveasFileName();
        QString KeyWord = custom_SignStamp_KeyWord_Dialog.getKeyWord();
        QString KeyWordRule = custom_SignStamp_KeyWord_Dialog.getKeyWordRule();

        qDebug() << "click_pbRidingStamp KeyWordRule : "<< KeyWordRule << Qt::endl;

        QFile tempfile(FullFileName);
        if ( !tempfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray temdata = tempfile.readAll();
        tempfile.close();

         QFile certfile(CertFileName);
        if ( !certfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray certdata = certfile.readAll();
        certfile.close();

        QFile prikeyfile(prikeyFileName);
        if ( !prikeyfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray prikeydata = prikeyfile.readAll();
        prikeyfile.close();

        QFile sealfile(StampFileName);
        if ( !sealfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray sealdata = sealfile.readAll();
        sealfile.close();

        unsigned char * outdata = NULL;
        int outdatalen = 0;

        QByteArray bKeyWord = KeyWord.toUtf8();
        QByteArray bKeyWordRule = KeyWordRule.toUtf8();
        if ( docType == 1 ) {

            m_OFDPDFSigner.testOFDKeywordSign((const unsigned char *)sealdata.data(),sealdata.size(),
                                                (const unsigned char *)certdata.data(),certdata.size(),
                                                (const unsigned char *)prikeydata.data(),prikeydata.size(),
                                                (const unsigned char *)temdata.data(),temdata.size(),
                                                bKeyWord.data(),bKeyWordRule.data(),42,42,true,&outdata,&outdatalen);
        } else if ( docType == 2 ) {
            m_OFDPDFSigner.testPDFKeywordSign((const unsigned char *)sealdata.data(),sealdata.size(),
                                                (const unsigned char *)certdata.data(),certdata.size(),
                                                (const unsigned char *)prikeydata.data(),prikeydata.size(),
                                                (const unsigned char *)temdata.data(),temdata.size(),
                                                bKeyWord.data(),bKeyWordRule.data(),42,42,&outdata,&outdatalen);
        } else {

            myMessageBox.setContent("文档类型不是OFD/PDF！\n不能对该类型文档盖章！");
            myMessageBox.exec();
            return;
        }

        if ( outdata == NULL || outdatalen == 0 ) {
            myMessageBox.setContent("盖章失败！");
            myMessageBox.exec();

            return;
        }





        if(SaveasFileName == "")
        {
            myMessageBox.setContent("您没有保存盖章后的文件！");
            myMessageBox.exec();
            m_OFDPDFSigner.FreeHandle(outdata);
            return;
        }


        QFile file(SaveasFileName);
        if(file.open(QIODevice::WriteOnly)) {
            QByteArray wirtedata;
            wirtedata.resize(outdatalen);
            memcpy(wirtedata.data(),outdata,outdatalen);
            file.write(wirtedata);
            file.close();
        } else {
            myMessageBox.setContent("不能写该文件！请检查文件权限！");
            myMessageBox.exec();
            m_OFDPDFSigner.FreeHandle(outdata);
            return;

        }

        m_OFDPDFSigner.FreeHandle(outdata);

        OpenOFDOrPDF(SaveasFileName);
    }
}
//----------------------------------------------------------------------------------------------------------
//void MainWidget::click_pbMakeCert()
//{
//
//}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbMakeSeal()
{
    QString sealfileName = QFileDialog::getOpenFileName(this, QStringLiteral("请选择印章图片文件"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),QStringLiteral("印章图片(*.png);;""印章图片(*.png)"));

    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);

    //qDebug() << "click_pbMakeSeal sealfileName : "<< sealfileName  << Qt::endl;
    QFile tempfile(sealfileName);
    if ( !tempfile.open(QFile::ReadOnly) ) {
        myMessageBox.setContent("不能打开印章图片文件！");
        myMessageBox.exec();
        return;
    }
    QByteArray temdata = tempfile.readAll();
    tempfile.close();

    if ( temdata.size() == 0 ) {
        myMessageBox.setContent("不能打开印章图片文件！");
        myMessageBox.exec();
        return;
    }

    unsigned char * outSeal = NULL;
    int outSeallen = 0;
    unsigned char * outSealUserCert = NULL;
    int outSealUserCertlen = 0;
    unsigned char * outSealUserCertPriKey = NULL;
    int outSealUserCertPriKeylen = 0;

    m_OFDPDFSigner.testCreateSeal((const unsigned char *)temdata.data(),temdata.size(),
                                        &outSeal,&outSeallen,&outSealUserCert,&outSealUserCertlen,
                                          &outSealUserCertPriKey,&outSealUserCertPriKeylen);

    if ( outSeallen == 0 || outSealUserCertlen == 0 || outSealUserCertPriKeylen == 0 ) {
        m_OFDPDFSigner.FreeHandle(outSeal);
        m_OFDPDFSigner.FreeHandle(outSealUserCert);
        m_OFDPDFSigner.FreeHandle(outSealUserCertPriKey);
        myMessageBox.setContent("制作印章失败！");
        myMessageBox.exec();

        return;
    }

    QFileDialog fileDialog;
    QString selectType = "";
    QString saveasfileName = fileDialog.getSaveFileName(this,tr("保存印章文件"),QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/Stamp",QStringLiteral("国办印章文档(*.sel)"),&selectType);


    QString pathName = saveasfileName;
    pathName.replace("\\","/");
    int dianpos = pathName.lastIndexOf("/");
    if ( dianpos != -1 ) {
        pathName = pathName.mid(0,dianpos);
    }

    QFile file(saveasfileName);
    if(file.open(QIODevice::WriteOnly)) {
        QByteArray wirtedata;
        wirtedata.resize(outSeallen);
        memcpy(wirtedata.data(),outSeal,outSeallen);
        file.write(wirtedata);
        file.close();
    } else {
        myMessageBox.setContent("不能写印章文件！请检查文件权限！");
        myMessageBox.exec();
        m_OFDPDFSigner.FreeHandle(outSeal);
        m_OFDPDFSigner.FreeHandle(outSealUserCert);
        m_OFDPDFSigner.FreeHandle(outSealUserCertPriKey);
        return;

    }

    QFile fileCert(pathName+"/StampUserCert.cer");
    if(fileCert.open(QIODevice::WriteOnly)) {
        QByteArray wirtedata;
        wirtedata.resize(outSealUserCertlen);
        memcpy(wirtedata.data(),outSealUserCert,outSealUserCertlen);
        fileCert.write(wirtedata);
        fileCert.close();
    } else {
        myMessageBox.setContent("不能写印章用户证书文件！请检查文件权限！");
        myMessageBox.exec();
        m_OFDPDFSigner.FreeHandle(outSeal);
        m_OFDPDFSigner.FreeHandle(outSealUserCert);
        m_OFDPDFSigner.FreeHandle(outSealUserCertPriKey);
        return;

    }

    QFile fileCertPriKey(pathName+"/StampUserCertPriKey.key");
    if(fileCertPriKey.open(QIODevice::WriteOnly)) {
        QByteArray wirtedata;
        wirtedata.resize(outSealUserCertPriKeylen);
        memcpy(wirtedata.data(),outSealUserCertPriKey,outSealUserCertPriKeylen);
        fileCertPriKey.write(wirtedata);
        fileCertPriKey.close();
    } else {
        myMessageBox.setContent("不能写印章用户证书私钥文件！请检查文件权限！");
        myMessageBox.exec();
        m_OFDPDFSigner.FreeHandle(outSeal);
        m_OFDPDFSigner.FreeHandle(outSealUserCert);
        m_OFDPDFSigner.FreeHandle(outSealUserCertPriKey);
        return;

    }


    m_OFDPDFSigner.FreeHandle(outSeal);
    m_OFDPDFSigner.FreeHandle(outSealUserCert);
    m_OFDPDFSigner.FreeHandle(outSealUserCertPriKey);

    myMessageBox.setContent("制作国办印章成功！");
    myMessageBox.exec();
}
//----------------------------------------------------------------------------------------------------------
void MainWidget::click_pbWaterMark()
{
    MyMessageBox myMessageBox(this);
    myMessageBox.setVisible_CancelButton(false);


    QString FullFileName = m_MyTabBar->getFullFileName(m_MyTabBar->getSelectTab_Index());
    if ( FullFileName.isEmpty() ) {
        myMessageBox.setContent("当前没有打开有效的文档！");
        myMessageBox.exec();
        return;
    }

    int docType = 0;
    QString tempFileName = FullFileName.toLower();
    if ( tempFileName.endsWith(".ofd" ) ) {
        docType = 1;
    } else {
        docType = 2;
    }

    WaterMark_Dialog waterMark_Dialog(this);
    waterMark_Dialog.setDocType(docType);
    if ( waterMark_Dialog.exec() == QDialog::Accepted ) {
        QString text_firstLine = waterMark_Dialog.getText_FirstLine();
        QByteArray qb_text_firstLine = text_firstLine.toUtf8();
        QString text_SecondLine = waterMark_Dialog.getText_SecondLine();
        QByteArray qb_text_SecondLine = text_SecondLine.toUtf8();
        QString text_ThirdLine = waterMark_Dialog.getText_ThirdLine();
        QByteArray qb_text_ThirdLine = text_ThirdLine.toUtf8();

        QString font_firstLine = waterMark_Dialog.getFont_FirstLine();
        QByteArray qb_font_firstLine = font_firstLine.toUtf8();
        QString font_SecondLine = waterMark_Dialog.getFont_SecondLine();
        QByteArray qb_font_SecondLine = font_SecondLine.toUtf8();
        QString font_ThirdLine = waterMark_Dialog.getFont_ThirdLine();
        QByteArray qb_font_ThirdLine = font_ThirdLine.toUtf8();

        QString fontsize_firstLine = waterMark_Dialog.getFontSize_FirstLine();
        QString fontsize_SecondLine = waterMark_Dialog.getFontSize_SecondLine();
        QString fontsize_ThirdLine = waterMark_Dialog.getFontSize_ThirdLine();

        QString Horizontal = waterMark_Dialog.getHorizontalSpacing();
        QString Vertical = waterMark_Dialog.getVerticalSpacing();
        QString Rotate = waterMark_Dialog.getRotate();

        QString color_firstLine = waterMark_Dialog.getTextColor_FirstLine();
        QString color_SecondLine = waterMark_Dialog.getTextColor_SecondLine();
        QString color_ThirdLine = waterMark_Dialog.getTextColor_ThirdLine();

        QStringList color_firstlist = color_firstLine.split(",");
        QStringList color_Secondlist = color_SecondLine.split(",");
        QStringList color_Thirdlist = color_ThirdLine.split(",");

        QString SaveasFileName = waterMark_Dialog.getSaveAs();

        float color_f[4] = {0};
        float color_s[4] = {0};
        float color_t[4] = {0};
        for( int i = 0;  i < color_firstlist.size(); i++ ) {
            color_f[i] = color_firstlist[i].toFloat();
        }
        for( int i = 0;  i < color_Secondlist.size(); i++ ) {
            color_s[i] = color_Secondlist[i].toFloat();
        }
        for( int i = 0;  i < color_Thirdlist.size(); i++ ) {
            color_t[i] = color_Thirdlist[i].toFloat();
        }

        QFile tempfile(FullFileName);
        if ( !tempfile.open(QFile::ReadOnly) ) {
            myMessageBox.setContent("不能打开该文档！");
            myMessageBox.exec();
            return;
        }
        QByteArray temdata = tempfile.readAll();
        tempfile.close();

        unsigned char * outDocData = NULL;
        int outDocDatalen = 0;

        if ( m_OFDPDFSigner.addWaterMark_Text(docType,(const unsigned char *)temdata.data(),temdata.size(),
                                                 Horizontal.toFloat(),Vertical.toFloat(),
                          qb_text_firstLine.data(),qb_font_firstLine.data(),fontsize_firstLine.toFloat(),color_f[0],color_f[1],color_f[2],color_f[3],
                          1.0f,
                          qb_text_SecondLine.data(),qb_font_SecondLine.data(),fontsize_SecondLine.toFloat(),color_s[0],color_s[1],color_s[2],color_s[3],
                          1.0f,
                          qb_text_ThirdLine.data(),qb_font_ThirdLine.data(),fontsize_ThirdLine.toFloat(),color_t[0],color_t[1],color_t[2],color_t[3],
                                                 Rotate.toFloat(),&outDocData,&outDocDatalen) != 0 ) {
            myMessageBox.setContent("添加水印失败！");
            myMessageBox.exec();

        }

//        QString SaveasFileName = saveas;
//        if ( docType == 1 ) {
//            SaveasFileName += "ofd";
//        } else {
//            SaveasFileName += "pdf";
//        }

        if(SaveasFileName == "")
        {
            myMessageBox.setContent("您没有保存盖章后的文件！");
            myMessageBox.exec();
            m_OFDPDFSigner.FreeHandle(outDocData);
            return;
        }


        QFile file(SaveasFileName);
        if(file.open(QIODevice::WriteOnly)) {
            QByteArray wirtedata;
            wirtedata.resize(outDocDatalen);
            memcpy(wirtedata.data(),outDocData,outDocDatalen);
            file.write(wirtedata);
            file.close();
        } else {
            myMessageBox.setContent("不能写该文件！请检查文件权限！");
            myMessageBox.exec();
            m_OFDPDFSigner.FreeHandle(outDocData);
            return;

        }

        m_OFDPDFSigner.FreeHandle(outDocData);

        OpenOFDOrPDF(SaveasFileName);
    }



}
//----------------------------------------------------------------------------------------------------------
