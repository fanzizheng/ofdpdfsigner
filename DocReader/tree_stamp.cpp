#include "tree_stamp.h"


//----------------------------------------------------------------------------------------------------------
Tree_Stamp::Tree_Stamp(QTreeWidget * treeWidget)
{
    m_TreeWidget = treeWidget;
    m_MainWidget = NULL;
}
//----------------------------------------------------------------------------------------------------------
Tree_Stamp::~Tree_Stamp()
{
    clear();
}
//----------------------------------------------------------------------------------------------------------
void Tree_Stamp::clear()
{

//    vector<QGraphicsScene *>::const_iterator GraphicsScene_iter;
//    for (GraphicsScene_iter = m_GraphicsScene.begin(); GraphicsScene_iter != m_GraphicsScene.end(); GraphicsScene_iter++) {
//        QGraphicsScene* temp = *GraphicsScene_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
//    m_GraphicsScene.clear();

    for (int i = 0; i < m_GraphicsScene.size(); i++) {
        QGraphicsScene* temp = m_GraphicsScene.at(i);
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_GraphicsScene.clear();


    m_TreeWidgetItem.clear();

}
//----------------------------------------------------------------------------------------------------------
void Tree_Stamp::init(QList<ItemInfo*>*  Stamps)
{
    if ( m_TreeWidget == NULL ) {
        return;
    }
    clear();

    m_TreeWidget->clear();    //QTreeWidget清空
//    m_TreeWidget->setFrameStyle(QFrame::NoFrame);  //框架样式
//    m_TreeWidget->setHeaderLabel("tree widget");  //设置头的标题
//    m_TreeWidget->setHeaderHidden(true);     //tree widget头标题是否显示,此处隐藏标题
//    m_TreeWidget->setColumnCount(1);    //tree widget展示的列数
//    //隐藏根点的展开折叠图标
//    m_TreeWidget->setRootIsDecorated(false);
//    //隐子节点的展开折叠图标
//    m_TreeWidget->setStyleSheet("QTreeView::branch:has-children:!has-siblings:closed,"
//                                     "QTreeView::branch:closed:has-children:has-siblings{border-image: none; image: none;}"
//                                     "QTreeView::branch:open:has-children:!has-siblings,"
//                                     "QTreeView::branch:open:has-children:has-siblings{border-image: none; image: none;}"
//                                     "QTreeView::branch:selected{selection-background-color: transparent;color : transparent;}"
//                                     "QTreeWidget::item:selected {show-decoration-selected:1;selection-background-color: transparent;color: transparent;}"
//                                "QTreeView{background-color:"
//                                BACKGROUD_COLOR_TABBAR
//                                "color :"
//                                BACKGROUD_COLOR_TABBAR
//                                "}"


//                                );

    if ( Stamps == NULL ) {
        return;
    }
    m_Stamps = Stamps;


//    vector<ItemInfo*>::const_iterator stamp_iter;

//    for(stamp_iter = m_Stamps->begin(); stamp_iter != m_Stamps->end(); stamp_iter++) {
//        ItemInfo* temp = *stamp_iter;
//        if ( temp != NULL ) {
//            addItem(temp->StampVerifyInfo,temp->Time,temp->Stamper,temp->StampPageIndex,temp->StampPic);
//        }//if ( temp != NULL ) {
//    }


    for(int i = 0; i < m_Stamps->size(); i++) {
        ItemInfo* temp = m_Stamps->at(i);
        if ( temp != NULL ) {
            //addItem(temp->StampVerifyInfo,temp->Time,temp->Stamper,temp->StampPageIndex,temp->StampPic);
            addItem(temp);
        }//if ( temp != NULL ) {
    }

    //connect(m_TreeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(TreeViewDoubleClick(QTreeWidgetItem*, int)));
    //connect(m_TreeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)), this,SLOT(TreeWidgetClick(QTreeWidgetItem* ,int)));

}
//----------------------------------------------------------------------------------------------------------
void Tree_Stamp::addItem(ItemInfo* itemInfo)
//void Tree_Stamp::addItem(const QString & StampVerifyInfo, const QString & time, const QString &Stamper,const QString & StampPageIndex,const QPixmap& stamppic)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(m_TreeWidget);
    QWidget *widgetItem = new QWidget(m_TreeWidget);

    widgetItem->setMinimumHeight(210);
    widgetItem->setMaximumHeight(210);
    widgetItem->setStyleSheet("QWidget"
                               "{"
                              "margin-top : 10px;"
                              "margin-right : 0px;"
                              "   background-color : "
                              BACKGROUD_COLOR_DOCMENT
                              "   border-radius: 6px;"
                               "   border:1px solid "
                               BORDE_COLOR
                               "}"
                              );

    m_TreeWidget->setItemWidget(item,0,widgetItem);

    QGridLayout * layout = new QGridLayout(widgetItem);


    QHBoxLayout * hBoxLayout = new QHBoxLayout(widgetItem);
    layout->addLayout(hBoxLayout,0,0,1,0);

    QGraphicsView* imageViewItem = new QGraphicsView(widgetItem);
    QGraphicsScene *scene = new QGraphicsScene();



    QPixmap pixmapItem = itemInfo->StampPic.scaledToWidth(80);
    //QPixmap pixmapItem = stamppic;
    scene->addPixmap(pixmapItem);

    int picw = pixmapItem.width();
    int pich = pixmapItem.height();
    //qDebug() << "Stamps inage => w:" << picw << " h:" << pich << Qt::endl;
    scene->setSceneRect(0,0,picw,pich);

    imageViewItem->setScene(scene);
    imageViewItem->setMinimumSize(picw+10,pich+10);
    imageViewItem->setMaximumSize(picw+10,pich+10);
    imageViewItem->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    imageViewItem->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    imageViewItem->setStyleSheet("QGraphicsView"
                                 "{"
                                 "margin-left : 4px;"
                                 "margin-right : 0px;"
                                 "   border:0px solid transparent;"
                                 "}"
                                );

    imageViewItem->show();

    hBoxLayout->addWidget(imageViewItem,0);

    //

    QLabel * qlTitle = new QLabel(widgetItem);
    //qlTitle->setText(StampVerifyInfo);
    qlTitle->setText("");
    qlTitle->setStyleSheet("QLabel"
                               "{"
                                "font-size: 16px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlTitle->show();
    itemInfo->qlTitle = qlTitle;
    hBoxLayout->addWidget(qlTitle,1,Qt::AlignTop);

    Stamp_Button * qlVerifyButton = new Stamp_Button(widgetItem);
    qlVerifyButton->setText("验章");
    qlVerifyButton->setStyleSheet("QPushButton"
                               "{"
                               "font-size: 16px; color:blue;"
                               "   border:0px solid transparent;"
                               "text-decoration:underline;"
                               "}"
                              );

    qlVerifyButton->setFlat(true);
    qlVerifyButton->setItem(item);
    qlVerifyButton->setMainWidget(m_MainWidget);

    if ( itemInfo->StampVerifyInfo=="未验证" ) {
        qlVerifyButton->show();
        qlVerifyButton->setVisible(true);
    } else {
        qlVerifyButton->setVisible(false);
    }
    itemInfo->qlVerifyButton = qlVerifyButton;

    hBoxLayout->addWidget(qlVerifyButton,0,Qt::AlignTop);
    hBoxLayout->addSpacing(6);

    QWidget *titleItem = new QWidget(m_TreeWidget);
    titleItem->setMinimumHeight(5);
    titleItem->setMaximumHeight(5);
    titleItem->setStyleSheet("QWidget"
                               "{"
                               "margin-top : 4px;"
                               "   border-radius: 0px;"
                               "   border:0px solid transparent;"
                               "   border-bottom:1px solid "
                               BORDE_COLOR
                               "}"
                              );


    layout->addWidget(titleItem,1,0,1,1);



    QLabel * qlStamper = new QLabel(titleItem);
    qlStamper->setStyleSheet("QLabel"
                               "{"
                             "margin-left : 4px;"
                             "margin-right : 4px;"
                               "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlStamper->setToolTip(itemInfo->Stamper);
    //qlContent->setMaximumHeight(60);
    //qlContent->setMinimumHeight(60);
    qlStamper->setText("签章人: "+itemInfo->Stamper);
    //qlContent->setWordWrap(true);
    qlStamper->show();

    itemInfo->qlStamper = qlStamper;


    layout->addWidget(qlStamper,2,0,1,1);

    QLabel * qlTime = new QLabel(titleItem);
    qlTime->setStyleSheet("QLabel"
                               "{"
                              "margin-left : 4px;"
                              "margin-right : 4px;"
                               "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );

    qlTime->setText("签章时间: "+itemInfo->Time);
    qlTime->show();
    itemInfo->qlTime = qlTime;

    layout->addWidget(qlTime,3,0,1,0);

    QLabel * qlPos = new QLabel(titleItem);
    qlPos->setStyleSheet("QLabel"
                               "{"
                               "margin-left : 4px;"
                               "margin-right : 4px;"
                               "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );

    qlPos->setText("位于第 "+itemInfo->StampPageIndex+" 页");
    qlPos->show();
    layout->addWidget(qlPos,4,0,1,0);


    layout->setContentsMargins(0,8,0,8);
    layout->setColumnStretch(0,1);
    layout->setRowStretch(0,1);
    layout->setRowStretch(1,0);
    layout->setRowStretch(2,0);
    layout->setRowStretch(3,0);
    layout->setRowStretch(4,0);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);

    m_GraphicsScene.push_back(scene);

    m_TreeWidgetItem.push_back(item);
}
//----------------------------------------------------------------------------------------------------------
int Tree_Stamp::getItemIndex(QTreeWidgetItem * item)
{
    int index = 0;
    //vector<QTreeWidgetItem *>::const_iterator it;
    //for( it = m_TreeWidgetItem.begin(); it != m_TreeWidgetItem.end(); it++ ) {
    for (int i = 0; i < m_TreeWidgetItem.size(); i++) {
        //QTreeWidgetItem * temp  = *it;
        QTreeWidgetItem * temp  = m_TreeWidgetItem.at(i);
        if ( temp == item ) {
            //index = it - m_TreeWidgetItem.begin();
            index = i;
            break;
        }
    }
    return index;
}
//----------------------------------------------------------------------------------------------------------
void Tree_Stamp::TreeViewDoubleClick(QTreeWidgetItem* item,int itemID)
{

}
//----------------------------------------------------------------------------------------------------------
void Tree_Stamp::TreeWidgetClick(QTreeWidgetItem* item,int itemID)
{

}
//----------------------------------------------------------------------------------------------------------

