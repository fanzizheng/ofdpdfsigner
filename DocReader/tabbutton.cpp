#include "tabbutton.h"
#include "mytabbar.h"
#include "util.h"
#include <QMenu>
#include "ofdpdfsignerproxy.h"
//----------------------------------------------------------------------------------------------------------
TabButton::TabButton(QWidget *parent)
    : QGroupBox{parent},m_leftBut(NULL),m_rightBut(NULL),m_layout(NULL),m_CentLableText(""),m_MyTabBar(NULL)
    ,m_index(0),m_Menu(NULL)
{

}
//----------------------------------------------------------------------------------------------------------
TabButton::~TabButton()
{

    FreeButton();
}
//----------------------------------------------------------------------------------------------------------
void TabButton::FreeButton()
{
/*
    map<int,vector<ItemInfo*>*>::const_iterator Annos_temp;
    vector<ItemInfo*>::const_iterator Anno_iter;
    for(Annos_temp = m_Annos.begin(); Annos_temp != m_Annos.end(); Annos_temp++) {
        if ( Annos_temp->second != NULL ) {
            vector<ItemInfo*>* temps = Annos_temp->second;
            for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++) {
                ItemInfo* temp = *Anno_iter;
                if ( temp != NULL ) {
                    delete temp;
                }
            }
            delete temps;
        }
    }
    m_Annos.clear();

    vector<QPixmap*>::const_iterator pixmaps_iter;
    for (pixmaps_iter = m_DocmentPixmaps.begin(); pixmaps_iter != m_DocmentPixmaps.end(); pixmaps_iter++) {
        QPixmap* temp = *pixmaps_iter;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_DocmentPixmaps.clear();

    vector<ItemInfo*>::const_iterator ItemInfo_iter;
    for (ItemInfo_iter = m_Stamps.begin(); ItemInfo_iter != m_Stamps.end(); ItemInfo_iter++) {
        ItemInfo* temp = *ItemInfo_iter;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_Stamps.clear();

    for (ItemInfo_iter = m_Attachments.begin(); ItemInfo_iter != m_Attachments.end(); ItemInfo_iter++) {
        ItemInfo* temp = *ItemInfo_iter;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_Attachments.clear();
    */

    if ( m_leftBut != NULL ) {
        delete m_leftBut;
        m_leftBut = NULL;
    }

    if ( m_rightBut != NULL ) {
        delete m_rightBut;
        m_rightBut = NULL;
    }

    if ( m_layout != NULL ) {
        delete m_layout;
        m_layout = NULL;
    }

    if ( m_Menu != NULL ) {
        delete m_Menu;
        m_Menu = NULL;
    }


}
//----------------------------------------------------------------------------------------------------------
void TabButton::Init(const QIcon & leftimage,const QString & title,const QIcon & rightimage,MyTabBar * myTabBars,int index,bool isSelect)
{
    FreeButton();

    m_CentLableText = title;
    m_leftBut = new QPushButton(leftimage,m_CentLableText);
    m_rightBut = new QPushButton(rightimage,"");
    m_layout = new QGridLayout(this);


    if ( m_leftBut == NULL || m_rightBut == NULL || m_layout == NULL ) {
        return;
    }

    m_index = index;
    m_MyTabBar = myTabBars;
    this->setToolTip(m_CentLableText);

    QFontMetrics elideFont(m_leftBut->font());
    int charWidth = elideFont.maxWidth()*5;

    int selfWidth = charWidth+22+24;
    int selfHeight = 40;
    setMinimumSize(QSize(selfWidth,selfHeight));
    setMaximumSize(QSize(selfWidth,selfHeight));

    m_layout->setContentsMargins(6,0,0,0);

    //m_leftBut->setMaximumSize(QSize(selfWidth-20,selfHeight));
    //m_leftBut->setMinimumSize(QSize(selfWidth-20,selfHeight));
    m_leftBut->setMaximumHeight(selfHeight);
    m_leftBut->setMinimumHeight(selfHeight);
    m_leftBut->setIconSize(QSize(16,16));
    m_leftBut->setFlat(true);



    m_rightBut->setMaximumSize(QSize(20,selfHeight));
    m_rightBut->setMinimumSize(QSize(20,selfHeight));
    m_rightBut->setIconSize(QSize(16,16));
    m_rightBut->setFlat(true);



//    m_layout->addWidget(m_leftBut,0,0,4,1,Qt::AlignVCenter | Qt::AlignLeft);
//    m_layout->addWidget(m_rightBut,0,1,4,1,Qt::AlignVCenter | Qt::AlignRight);

    //m_layout->addWidget(m_groupBox,0,0);

    //m_layout->addWidget(m_leftBut,0);
    //m_layout->addWidget(m_rightBut,1);
//    m_layout->addWidget(m_leftBut,0,0,2,1,Qt::AlignLeft);
//    m_layout->addWidget(m_CentLable,0,1,1,1,Qt::AlignHCenter);
//    m_layout->addWidget(m_rightBut,0,2,1,1, Qt::AlignRight);
    m_layout->addWidget(m_leftBut,0,0,1,1,Qt::AlignHCenter|Qt::AlignLeft);
    m_layout->addWidget(m_rightBut,0,1,1,1, Qt::AlignHCenter|Qt::AlignRight);

    m_layout->setColumnStretch(0,1);
    m_layout->setColumnStretch(1,0);
//    m_layout->setColumnStretch(2,0);
    m_layout->setHorizontalSpacing(0);
    m_layout->setVerticalSpacing(0);


//    QString styleSheet = "QWidget{border-top:1px solid rgb(200,200,200);";
//            styleSheet += "border-right:1px solid rgb(200,200,200);";
//            styleSheet += "border-left:1px solid rgb(200,200,200);";
//            //styleSheet += "margin-bottom:-6px;";
//            styleSheet += "border-bottom:1px solid rgb(245,245,245);";
//            styleSheet += "border-bottom-color: rgb(245,245,245);";
//            styleSheet += "background-color:rgb(245,245,245); }";
//            styleSheet += "QPushButton{text-align:left;border:0px solid transparent;background-color: transparent;}";
//    setStyleSheet(styleSheet);



    connect(m_rightBut, &QPushButton::clicked, this, &TabButton::btnClicked_Close);
    connect(m_leftBut, &QPushButton::clicked, this, &TabButton::btnClicked);


    if ( isSelect ) {
        select();
    } else {
        unselect();
    }

    this->setContextMenuPolicy(Qt::DefaultContextMenu);

}
//----------------------------------------------------------------------------------------------------------
int TabButton::getWidth()
{
    QRect rect = geometry();
    return rect.width();
}
//----------------------------------------------------------------------------------------------------------
int TabButton::getMinWidth()
{
    QPushButton * temp = m_leftBut;
    if ( m_leftBut == NULL ) {
        temp = new QPushButton(m_CentLableText);
    }
    QFontMetrics elideFont(temp->font());
    int charWidth = elideFont.maxWidth()*5;
    if ( m_leftBut == NULL ) {
        delete temp;
    }

    return charWidth + 22 + 24;
}
//----------------------------------------------------------------------------------------------------------
void TabButton::setRect(int x,int y,int width,int Heigt)
{
//    if ( getWidth() <= width ) {
//        return;
//    }

    if ( m_leftBut == NULL ) {
        return;
    }

    QFontMetrics elideFont(m_leftBut->font());
    int charWidth = elideFont.maxWidth()*5;


    int leftwidth = width - 22 - 24;
    if ( leftwidth <= charWidth ) {
        return;
    }
    m_leftBut->setText(elideFont.elidedText(m_CentLableText, Qt::ElideRight, leftwidth));

    setMinimumWidth(width);
    setMaximumWidth(width);
    setGeometry(x,y,width,Heigt);

}
//----------------------------------------------------------------------------------------------------------
void TabButton::btnClicked_Close()
{
    if ( m_MyTabBar != NULL ) {
        m_MyTabBar->CloseTab(m_index);
    }
}
//----------------------------------------------------------------------------------------------------------
void TabButton::btnClicked()
{
    if ( m_MyTabBar != NULL ) {
        m_MyTabBar->ClickedTab(m_index);
    }
}
//----------------------------------------------------------------------------------------------------------
void TabButton::mouseReleaseEvent(QMouseEvent* event)
{
    QGroupBox::mouseReleaseEvent(event);

    btnClicked();
}
//----------------------------------------------------------------------------------------------------------
void TabButton::select()
{
    QString styleSheet = "QGroupBox{border-top:1px solid ";
            styleSheet += BORDE_COLOR;
            styleSheet += "border-right:1px solid ";
            styleSheet += BORDE_COLOR;
            styleSheet += "border-left:1px solid ";
            styleSheet += BORDE_COLOR;
            //styleSheet += "margin-bottom:-2px;";
//            styleSheet += "border-bottom:0px solid ";
//            styleSheet += BACKGROUD_COLOR_DOCMENT;
            styleSheet += "border-bottom:1px solid ";
            styleSheet += BORDE_COLOR;
            //styleSheet += "border-bottom-color: ";
            //styleSheet += BACKGROUD_COLOR_DOCMENT;
            styleSheet += "background-color:";
            styleSheet += BACKGROUD_COLOR_DOCMENT;
            styleSheet += "}";
            styleSheet += "QPushButton{text-align:left;border:0px solid transparent;background-color: transparent;}";
    setStyleSheet(styleSheet);
}
//----------------------------------------------------------------------------------------------------------
void TabButton::unselect()
{
    QString styleSheet = "QGroupBox{border-top:1px solid ";
            styleSheet += BORDE_COLOR;
            styleSheet += "border-right:1px solid ";
            styleSheet += BORDE_COLOR;
            styleSheet += "border-left:1px solid ";
            styleSheet += BORDE_COLOR;
            //styleSheet += "margin-bottom:-6px;";
            styleSheet += "border-bottom:1px solid ";
            styleSheet += BORDE_COLOR;
            //styleSheet += "border-bottom-color: ";
            //styleSheet += BACKGROUD_COLOR_TABBAR;
            styleSheet += "background-color:";
            styleSheet += BACKGROUD_COLOR_TABBAR;
            styleSheet += "}";
            styleSheet += "QPushButton{text-align:left;border:0px solid transparent;background-color: transparent;}";
    setStyleSheet(styleSheet);
}
//----------------------------------------------------------------------------------------------------------
void TabButton::contextMenuEvent(QContextMenuEvent * e)
{
    if ( m_Menu == NULL ) {
        m_Menu = new QMenu(this);
        QAction * claseTabSelfAction = m_Menu->addAction("关闭标签");
        QAction * closeTabOtherAction = m_Menu->addAction("关闭其他标签");
        QAction * closeTabLeftAction = m_Menu->addAction("关闭左侧标签");
        QAction * closeTabRightAction = m_Menu->addAction("关闭右侧标签");

        connect(claseTabSelfAction, SIGNAL(triggered(bool)), this, SLOT(claseTabSelf()));
        connect(closeTabOtherAction, SIGNAL(triggered(bool)), this, SLOT(closeTabOther()));
        connect(closeTabLeftAction, SIGNAL(triggered(bool)), this, SLOT(closeTabLeft()));
        connect(closeTabRightAction, SIGNAL(triggered(bool)), this, SLOT(closeTabRight()));

        QString styleSheet = "QMenu{"
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
                             "background-color: transparent;"
                             "padding:3px 20px;"
                             "margin:5px 10px;"
                             "} "
                             "QMenu::item:selected {"
                             "background-color: "
                             BACKGROUD_COLOR_TABBAR
                             "} "
                             ;
        m_Menu->setStyleSheet(styleSheet);
        m_Menu->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
        m_Menu->setAttribute(Qt::WA_TranslucentBackground);
    }

    m_Menu->exec(QCursor::pos());//在当前鼠标位置显示
    //cmenu->exec(pos)是在viewport显示
}
//----------------------------------------------------------------------------------------------------------
void TabButton::claseTabSelf()
{
    if ( m_MyTabBar != NULL ) {
        m_MyTabBar->CloseTab(m_index);
    }
}
//----------------------------------------------------------------------------------------------------------
void TabButton::closeTabOther()
{
    if ( m_MyTabBar != NULL ) {
        m_MyTabBar->CloseTabOther(m_index);
    }
}
//----------------------------------------------------------------------------------------------------------
void TabButton::closeTabLeft()
{
    if ( m_MyTabBar != NULL ) {
        m_MyTabBar->CloseTab(m_index-1);
    }
}
//----------------------------------------------------------------------------------------------------------
void TabButton::closeTabRight()
{
    if ( m_MyTabBar != NULL ) {
        m_MyTabBar->CloseTab(m_index+1);
    }
}
//----------------------------------------------------------------------------------------------------------
//bool TabButton::addDocmentPixmap(const unsigned char * data,int datalen)
//{
//    bool ret = false;
//    QPixmap *pixmap = new QPixmap();
//    if ( pixmap == NULL ) return ret;

//    ret = pixmap->loadFromData(data,datalen);
//    if ( ret ) {
//        m_DocmentPixmaps.push_back(pixmap);
//    } else {
//        delete pixmap;
//    }
//    return ret;
//}
////----------------------------------------------------------------------------------------------------------
//bool TabButton::addAnno(int pageindex, const QIcon & icon,const QString & title,const QString & time,const QString & content)
//{
//    bool ret = false;
//    ItemInfo * temp = new ItemInfo();
//    if ( temp == NULL ) ret;
//    temp->Image = icon;
//    temp->Tilte = title;
//    temp->Time = time;
//    temp->Content = content;

//    map<int,vector<ItemInfo*>*>::iterator it = m_Annos.find(pageindex);
//    if (it != m_Annos.end()) {
//        vector<ItemInfo*>* temps = it->second;
//        temps->push_back(temp);
//    } else {
//        vector<ItemInfo*>* temps = new vector<ItemInfo*>();
//        temps->push_back(temp);
//        m_Annos.insert(pair<int,vector<ItemInfo*>*>(pageindex ,temps));
//    }

//    ret = true;
//    return ret;
//}
////----------------------------------------------------------------------------------------------------------
//bool TabButton::addStramp(const unsigned char * stampdata,int stampdatalen,const QString & StampVerifyInfo, const QString & time, const QString &Stamper,const QString & StampPageIndex)
//{
//    bool ret = false;
//    ItemInfo * temp = new ItemInfo();
//    if ( temp == NULL ) ret;

//    ret = temp->StampPic.loadFromData(stampdata,stampdatalen);
//    if ( ret ) {
//        temp->StampVerifyInfo = StampVerifyInfo;
//        temp->Time = time;
//        temp->Stamper = Stamper;
//        temp->StampPageIndex = StampPageIndex;
//        m_Stamps.push_back(temp);
//        ret = true;
//    } else {
//        delete temp;
//        ret = false;
//    }
//    return ret;
//}
////----------------------------------------------------------------------------------------------------------
//bool TabButton::addAttachment(const QString &filename,const QString &time,const unsigned char * filedata,int filedatalen)
//{
//    bool ret = false;
//    ItemInfo * temp = new ItemInfo();
//    if ( temp == NULL ) ret;

//    temp->FileData.resize(filedatalen);
//    memcpy(temp->FileData.data(),filedata,filedatalen);
//    temp->Tilte = filename;
//    temp->Time = time;
//    m_Attachments.push_back(temp);
//    ret = true;

//    return ret;
//}
//----------------------------------------------------------------------------------------------------------



