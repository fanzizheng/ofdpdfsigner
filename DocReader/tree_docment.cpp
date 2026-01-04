#include "tree_docment.h"
#include "QtWidgets/qheaderview.h"

//----------------------------------------------------------------------------------------------------------
Tree_Docment::Tree_Docment(QTreeWidget * treeWidget)
{
    m_TreeWidget = treeWidget;

    m_TreeWidget->clear();    //QTreeWidget清空
    m_TreeWidget->setFrameStyle(QFrame::NoFrame);  //框架样式
    m_TreeWidget->setHeaderLabel("tree widget");  //设置头的标题
    m_TreeWidget->setHeaderHidden(true);     //tree widget头标题是否显示,此处隐藏标题
    m_TreeWidget->setColumnCount(1);    //tree widget展示的列数
    m_TreeWidget->setRootIsDecorated(false);
    m_TreeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_TreeWidget->header()->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_TreeWidget->header()->setSectionResizeMode(0, QHeaderView::ResizeMode::ResizeToContents);
    m_TreeWidget->header()->setStretchLastSection(false);
    //QHeaderView *pHeader = m_TreeWidget->header();
    //pHeader->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
    //pHeader->setStretchLastSection(false);


//    m_TreeWidget->setStyleSheet("QTreeView::branch:has-children:!has-siblings:closed,"
//                                     "QTreeView::branch:closed:has-children:has-siblings{border-image: none; image: none;}"
//                                     "QTreeView::branch:open:has-children:!has-siblings,"
//                                     "QTreeView::branch:open:has-children:has-siblings{border-image: none; image: none;}"
//                                     "QTreeView::branch:selected{selection-background-color: transparent;color : transparent;}"
//                                     "QTreeWidget::item:selected {show-decoration-selected:1;selection-background-color: transparent;color: transparent;}"
//                                    "QTreeView{background-color:"
//                                    BACKGROUD_COLOR_DOCMENT
//                                    "color :"
//                                    BACKGROUD_COLOR_DOCMENT
//                                    "}"


//                                );

    m_TreeWidget->setStyleSheet("QTreeView::branch:has-children:!has-siblings:closed,"
                                     "QTreeView::branch:closed:has-children:has-siblings{border-image: none; image: none;}"
                                     "QTreeView::branch:open:has-children:!has-siblings,"
                                     "QTreeView::branch:open:has-children:has-siblings{border-image: none; image: none;}"
                                     "QTreeView::branch::hover{ background-color: transparent;selection-background-color: transparent;color : transparent;}"
                                     "QTreeView::item::hover{ background-color: transparent;selection-background-color: transparent;color : transparent;}"
                                     "QTreeView::branch:selected{ background-color: transparent;selection-background-color: transparent;color : transparent;}"
                                     "QTreeView::item:selected{ show-decoration-selected:1;background-color: transparent;selection-background-color: transparent;color: transparent; }"
                                    "QTreeView{outline:0px;background-color:"
                                    BACKGROUD_COLOR_DOCMENT
                                    "color :"
                                    BACKGROUD_COLOR_DOCMENT
                                    "}"


                                );




}
//----------------------------------------------------------------------------------------------------------
Tree_Docment::~Tree_Docment()
{
    clear();
}
//----------------------------------------------------------------------------------------------------------
void Tree_Docment::clear()
{
    QList<QTreeWidgetItem *>::const_iterator TreeWidgetItem_iter;
    for (TreeWidgetItem_iter = m_TreeWidgetItem.begin(); TreeWidgetItem_iter != m_TreeWidgetItem.end(); TreeWidgetItem_iter++) {
        QTreeWidgetItem* temp = *TreeWidgetItem_iter;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_TreeWidgetItem.clear();

    QList<QWidget *>::const_iterator Widget_iter;
    for (Widget_iter = m_Widget.begin(); Widget_iter != m_Widget.end(); Widget_iter++) {
        QWidget* temp = *Widget_iter;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_Widget.clear();

//    vector<QGraphicsView *>::const_iterator GraphicsView_iter;
//    for (GraphicsView_iter = m_GraphicsView.begin(); GraphicsView_iter != m_GraphicsView.end(); GraphicsView_iter++) {
//        QGraphicsView* temp = *GraphicsView_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_GraphicsView.clear();

    QList<QGraphicsScene *>::const_iterator GraphicsScene_iter;
    for (GraphicsScene_iter = m_GraphicsScene.begin(); GraphicsScene_iter != m_GraphicsScene.end(); GraphicsScene_iter++) {
        QGraphicsScene* temp = *GraphicsScene_iter;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_GraphicsScene.clear();

//    vector<QGridLayout *>::const_iterator GridLayout_iter;
//    for (GridLayout_iter = m_GridLayouts.begin(); GridLayout_iter != m_GridLayouts.end(); GridLayout_iter++) {
//        QGridLayout* temp = *GridLayout_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_GridLayouts.clear();

//    vector<QHBoxLayout *>::const_iterator HBoxLayout_iter;
//    for (HBoxLayout_iter = m_HBoxLayouts.begin(); HBoxLayout_iter != m_HBoxLayouts.end(); HBoxLayout_iter++) {
//        QHBoxLayout* temp = *HBoxLayout_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_HBoxLayouts.clear();

    m_Pixmaps = NULL;

    m_TreeWidget->clear();
}
//----------------------------------------------------------------------------------------------------------
/*
void Tree_Docment::init(vector<QPixmap*> * pixmaps,double scaledValue)
{

    qDebug() << "Tree_Docment::init " << scaledValue << Qt::endl;

    if ( m_TreeWidget == NULL || pixmaps == NULL) {
        return;
    }

    clear();

    m_Pixmaps = pixmaps;

    m_TreeWidget->clear();    //QTreeWidget清空
//    m_TreeWidget->setFrameStyle(QFrame::NoFrame);  //框架样式
//    m_TreeWidget->setHeaderLabel("tree widget");  //设置头的标题
//    m_TreeWidget->setHeaderHidden(true);     //tree widget头标题是否显示,此处隐藏标题
//    m_TreeWidget->setColumnCount(1);    //tree widget展示的列数
    //隐藏根点的展开折叠图标
//    m_TreeWidget->setRootIsDecorated(false);
    //隐子节点的展开折叠图标
//    m_TreeWidget->setStyleSheet("QTreeView::branch:has-children:!has-siblings:closed,"
//                                     "QTreeView::branch:closed:has-children:has-siblings{border-image: none; image: none;}"
//                                     "QTreeView::branch:open:has-children:!has-siblings,"
//                                     "QTreeView::branch:open:has-children:has-siblings{border-image: none; image: none;}"
//                                     "QTreeView::branch:selected{selection-background-color: transparent;color : transparent;}"
//                                     "QTreeWidget::item:selected {show-decoration-selected:1;selection-background-color: transparent;color: transparent;}"
//                                    "QTreeView{background-color:"
//                                    BACKGROUD_COLOR_DOCMENT
//                                    "color :"
//                                    BACKGROUD_COLOR_DOCMENT
//                                    "}"
//                                );

//    QRect rect = m_TreeWidget->geometry();
//    int rectWidth = 280;
//    if ( rect.width() <= 280 ) {
//        rectWidth = 280;
//    } else {
//        rectWidth = rect.width();
//    }
//    int picWidth = rectWidth * scaledValue;

    vector<QPixmap*>::const_iterator pixmaps_iter;
    for (pixmaps_iter = m_Pixmaps->begin(); pixmaps_iter != m_Pixmaps->end(); pixmaps_iter++) {
        QPixmap* temp = *pixmaps_iter;
        if ( temp != NULL ) {

            QTreeWidgetItem *item = new QTreeWidgetItem(m_TreeWidget);

            QWidget *widgetItem = new QWidget();
            QGridLayout * layout = new QGridLayout(widgetItem);
            QHBoxLayout * hBoxLayout = new QHBoxLayout();
            layout->addLayout(hBoxLayout,0,0);

            m_GridLayouts.push_back(layout);
            m_HBoxLayouts.push_back(hBoxLayout);


            m_TreeWidget->setItemWidget(item,0,widgetItem);

            //QGraphicsView* imageViewItem = new QGraphicsView(widgetItem);
            QGraphicsView* imageViewItem = new QGraphicsView();

            QGraphicsScene *scene = new QGraphicsScene();

            qDebug() << "Tree_Docment::init -> width : " << temp->width() << " scaled " << scaledValue << Qt::endl;

            QPixmap pixmapItem;
            if ( scaledValue == 1 ) {
                pixmapItem = *temp;
            } else {
                pixmapItem = temp->scaledToWidth(temp->width()*scaledValue);
            }

            scene->addPixmap(pixmapItem);

            scene->setSceneRect(0,0,pixmapItem.width(),pixmapItem.height());

            imageViewItem->setScene(scene);

            imageViewItem->setMinimumSize(pixmapItem.width()+2,pixmapItem.height()+2);
            imageViewItem->setMaximumSize(pixmapItem.width()+2,pixmapItem.height()+2);

            if ( pixmaps_iter ==  m_Pixmaps->begin() ) {
                //imageViewItem->setGeometry((rect.width() - picWidth)/2 ,20,pixmapItem.width()+2,pixmapItem.height()+2);
                widgetItem->setMinimumHeight(pixmapItem.height()+20);
            } else if ( pixmaps_iter ==  m_Pixmaps->end() -1 ) {
                //imageViewItem->setGeometry((rect.width() - picWidth)/2 ,10,pixmapItem.width()+2,pixmapItem.height()+2);
                widgetItem->setMinimumHeight(pixmapItem.height()+30);
            } else {
                //imageViewItem->setGeometry((rect.width() - picWidth)/2 ,10,pixmapItem.width()+2,pixmapItem.height()+2);
                widgetItem->setMinimumHeight(pixmapItem.height()+10);
            }

            imageViewItem->show();

            hBoxLayout->addWidget(imageViewItem);


            m_TreeWidgetItem.push_back(item);
            m_Widget.push_back(widgetItem);
            m_GraphicsView.push_back(imageViewItem);
            m_GraphicsScene.push_back(scene);

        }
    }

}
*/
//----------------------------------------------------------------------------------------------------------
void Tree_Docment::addPixmap(const unsigned char * picdata,int piclen)
{
    QPixmap *pixmap = new QPixmap();
    if ( pixmap == NULL ) return;

    if ( !pixmap->loadFromData(picdata,piclen) ) {
        return;
    }

    addPixmap(pixmap);

    delete pixmap;

}
//----------------------------------------------------------------------------------------------------------
void Tree_Docment::addPixmap(QPixmap* pixmap)
{
    if ( m_TreeWidget == NULL || pixmap == NULL) {
        return;
    }

    QRect rect = m_TreeWidget->geometry();
    //qDebug() << "Tree_Docment::init -> width : " << rect.width() << Qt::endl;

    QTreeWidgetItem *item = new QTreeWidgetItem(m_TreeWidget);

    QWidget *widgetItem = new QWidget(m_TreeWidget);
    QGridLayout * layout = new QGridLayout(widgetItem);
    //QHBoxLayout * hBoxLayout = new QHBoxLayout();
    //layout->addLayout(hBoxLayout,0,0);

    m_GridLayouts.push_back(layout);
    //m_HBoxLayouts.push_back(hBoxLayout);


    m_TreeWidget->setItemWidget(item,0,widgetItem);

    //widgetItem->setStyleSheet(
    //            "background: rgb(40, 40, 40);"
    //              );

    //QGraphicsView* imageViewItem = new QGraphicsView(widgetItem);
    QGraphicsView* imageViewItem = new QGraphicsView(widgetItem);


    layout->addWidget(imageViewItem,0,0,Qt::AlignHCenter);

    QGraphicsScene *scene = new QGraphicsScene();



    //QPixmap pixmapItem;
    //if ( scaledValue == 1 ) {
     //   pixmapItem = *pixmap;
    //} else {
   //     pixmapItem = temp->scaledToWidth(temp->width()*scaledValue);
    //}

    scene->addPixmap(*pixmap);

    scene->setSceneRect(0,0,pixmap->width(),pixmap->height());

    imageViewItem->setScene(scene);

    int picWidth = pixmap->width()+2;
    imageViewItem->setMinimumSize(picWidth,pixmap->height()+2);
    imageViewItem->setMaximumSize(picWidth,pixmap->height()+2);

    if ( rect.width()-16 > picWidth  ) {
        widgetItem->setMinimumWidth(rect.width()-16);
        widgetItem->setMaximumWidth(rect.width()-16);
    }


    //qDebug() << "Tree_Docment::add  -> item count : " <<  m_TreeWidget->topLevelItemCount() << Qt::endl;

    //if ( m_TreeWidget->topLevelItemCount() == 1 ) {
        //imageViewItem->setGeometry((rect.width() - picWidth)/2 ,20,pixmapItem.width()+2,pixmapItem.height()+2);
        //widgetItem->setMinimumHeight(pixmapItem.height()+20);
   // } else if ( pixmaps_iter ==  m_Pixmaps->end() -1 ) {
        //imageViewItem->setGeometry((rect.width() - picWidth)/2 ,10,pixmapItem.width()+2,pixmapItem.height()+2);
    //    widgetItem->setMinimumHeight(pixmapItem.height()+30);
    //} else {
        //imageViewItem->setGeometry((rect.width() - picWidth)/2 ,10,pixmapItem.width()+2,pixmapItem.height()+2);
        //widgetItem->setMinimumHeight(pixmapItem.height()+10);
    //}

    imageViewItem->show();

    //hBoxLayout->addWidget(imageViewItem);




    m_TreeWidgetItem.push_back(item);
    m_Widget.push_back(widgetItem);
    m_GraphicsView.push_back(imageViewItem);
    m_GraphicsScene.push_back(scene);


}
//----------------------------------------------------------------------------------------------------------
void Tree_Docment::addPixmap(QPixmap* pixmap1,QPixmap* pixmap2)
{
    if ( m_TreeWidget == NULL || pixmap1 == NULL ) {
        return;
    }

    QRect rect = m_TreeWidget->geometry();
    int picWidth1 = pixmap1->width()+2;
    int picWidth2 = pixmap2 == NULL ? pixmap1->width()+2 : pixmap2->width()+2;

    QTreeWidgetItem *item = new QTreeWidgetItem(m_TreeWidget);
    QWidget *widgetItem = new QWidget(m_TreeWidget);
    QGridLayout * layout = new QGridLayout(widgetItem);



    m_TreeWidget->setItemWidget(item,0,widgetItem);

    QGraphicsView* imageViewItem = new QGraphicsView(widgetItem);

    layout->addWidget(imageViewItem,0,0,Qt::AlignHCenter);

    QGraphicsScene *scene = new QGraphicsScene();

    scene->addPixmap(*pixmap1);

    scene->setSceneRect(0,0,pixmap1->width(),pixmap1->height());

    imageViewItem->setScene(scene);


    imageViewItem->setMinimumSize(picWidth1,pixmap1->height()+2);
    imageViewItem->setMaximumSize(picWidth1,pixmap1->height()+2);

    imageViewItem->show();

    m_GraphicsView.push_back(imageViewItem);
    m_GraphicsScene.push_back(scene);
    //--------------------------------------------


    QGraphicsView* imageViewItem2 = new QGraphicsView(widgetItem);
    layout->addWidget(imageViewItem2,0,1,Qt::AlignHCenter);
    QGraphicsScene *scene2 = new QGraphicsScene();
    if ( pixmap2 != NULL ) {
        scene2->addPixmap(*pixmap2);
        scene2->setSceneRect(0,0,pixmap2->width(),pixmap2->height());
        imageViewItem2->setScene(scene2);
        imageViewItem2->setMinimumSize(picWidth2,pixmap2->height()+2);
        imageViewItem2->setMaximumSize(picWidth2,pixmap2->height()+2);

    } else {
        imageViewItem2->setMinimumSize(picWidth1,pixmap1->height()+2);
        imageViewItem2->setMaximumSize(picWidth1,pixmap1->height()+2);
        imageViewItem2->setStyleSheet(
                    "QGraphicsView{background-color:"
                    BACKGROUD_COLOR_DOCMENT
                    "color :"
                    BACKGROUD_COLOR_DOCMENT
                    "border : 0px solid none;"
                    "}"
                    );


    }

    imageViewItem2->show();


    m_GraphicsView.push_back(imageViewItem2);
    m_GraphicsScene.push_back(scene2);


    if ( rect.width()-16 > picWidth1+picWidth2+16  ) {
        widgetItem->setMinimumWidth(rect.width()-16);
        widgetItem->setMaximumWidth(rect.width()-16);
    }

    m_GridLayouts.push_back(layout);
    m_TreeWidgetItem.push_back(item);
    m_Widget.push_back(widgetItem);


}
//----------------------------------------------------------------------------------------------------------
