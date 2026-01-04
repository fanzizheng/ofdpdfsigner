#include "tree_smallpic.h"
#include "mainwidget.h"

//----------------------------------------------------------------------------------------------------------
Tree_SmallPic::Tree_SmallPic(QTreeWidget * treeWidget) : m_MainWidget(NULL)
{
    m_TreeWidget = treeWidget;
}
//----------------------------------------------------------------------------------------------------------
Tree_SmallPic::~Tree_SmallPic()
{
    clear();
}
//----------------------------------------------------------------------------------------------------------
void Tree_SmallPic::clear()
{
//    vector<QTreeWidgetItem *>::const_iterator TreeWidgetItem_iter;
//    for (TreeWidgetItem_iter = m_TreeWidgetItem.begin(); TreeWidgetItem_iter != m_TreeWidgetItem.end(); TreeWidgetItem_iter++) {
//        QTreeWidgetItem* temp = *TreeWidgetItem_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_TreeWidgetItem.clear();

//    vector<QWidget *>::const_iterator Widget_iter;
//    for (Widget_iter = m_Widget.begin(); Widget_iter != m_Widget.end(); Widget_iter++) {
//        QWidget* temp = *Widget_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
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
    for (GraphicsScene_iter = m_GraphicsScene.constBegin(); GraphicsScene_iter != m_GraphicsScene.constEnd(); GraphicsScene_iter++) {
        QGraphicsScene* temp = *GraphicsScene_iter;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_GraphicsScene.clear();

    m_WidgetMask.clear();

    m_Pixmaps = NULL;

    m_TreeWidget->clear();
}
//----------------------------------------------------------------------------------------------------------
void Tree_SmallPic::init(QList<QPixmap*> * pixmaps,double scaledValue)
{
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

    QRect rect = m_TreeWidget->geometry();
    int rectWidth = 280;
    if ( rect.width() <= 280 ) {
        rectWidth = 280;
    } else {
        rectWidth = rect.width();
    }
    int picWidth = rectWidth * scaledValue;
    //vector<QPixmap*>::const_iterator pixmaps_iter;
    for (int i = 0; i < m_Pixmaps->size(); i++) {
        QPixmap* temp = m_Pixmaps->at(i); //*pixmaps_iter;
        if ( temp != NULL ) {

            QTreeWidgetItem *item = new QTreeWidgetItem(m_TreeWidget);

            QWidget *widgetItem = new QWidget(m_TreeWidget);

            m_TreeWidget->setItemWidget(item,0,widgetItem);

            SmallPic_Button * imageViewItem = new SmallPic_Button(widgetItem);

            QPixmap pixmapItem = temp->scaledToWidth(picWidth);

            imageViewItem->setIcon(QIcon(pixmapItem));
            imageViewItem->setIconSize(QSize(pixmapItem.width(),pixmapItem.height()));
            imageViewItem->setItem(item);
            imageViewItem->setTree_SmallPic(this);

            QString pageNum = "第 ";
            pageNum += QString::number(i+1);
            pageNum += " 页";
            imageViewItem->setText(pageNum);
            imageViewItem->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

            imageViewItem->setStyleSheet("QToolButton"
                                       "{"
                                        "font-size: 12px;"
                                       "}"
                                      );
            //QGraphicsView* imageViewItem = new QGraphicsView(widgetItem);
            //QGraphicsScene *scene = new QGraphicsScene();


            //scene->addPixmap(pixmapItem);

            //scene->setSceneRect(0,0,pixmapItem.width(),pixmapItem.height());

            //imageViewItem->setScene(scene);


            if ( i ==  0 ) {

                imageViewItem->setGeometry((rect.width() - picWidth)/2 ,20,pixmapItem.width()+2,pixmapItem.height()+2+20);
                widgetItem->setMinimumHeight(pixmapItem.height()+20+20);
            } else if ( i ==  m_Pixmaps->size() -1 ) {
                imageViewItem->setGeometry((rect.width() - picWidth)/2 ,10,pixmapItem.width()+2,pixmapItem.height()+2+20);
                widgetItem->setMinimumHeight(pixmapItem.height()+30+20);
            } else {
                imageViewItem->setGeometry((rect.width() - picWidth)/2 ,10,pixmapItem.width()+2,pixmapItem.height()+2+20);
                widgetItem->setMinimumHeight(pixmapItem.height()+10+20);
            }

            imageViewItem->show();


            QWidget *widgetItemMask = new QWidget(widgetItem);
            widgetItemMask->setGeometry(imageViewItem->geometry());
            widgetItemMask->setStyleSheet(
                        "background: rgba(40, 40, 40, 0.2);"
                          );

            //widgetItemMask->show();
            if ( i == 0 ) {
                widgetItemMask->setVisible(true);
            } else {
                widgetItemMask->setVisible(false);
            }

            m_WidgetMask.push_back(widgetItemMask);

            m_TreeWidgetItem.push_back(item);
            m_Widget.push_back(widgetItem);
            m_GraphicsView.push_back(imageViewItem);
            //m_GraphicsScene.push_back(scene);

        }
    }

    //connect(m_TreeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(TreeViewDoubleClick(QTreeWidgetItem*, int)));
    //connect(m_TreeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)), this,SLOT(TreeWidgetClick(QTreeWidgetItem* ,int)));


}
//----------------------------------------------------------------------------------------------------------
void Tree_SmallPic::ShowMask(QTreeWidgetItem* item)
{
    QList<QTreeWidgetItem *>::const_iterator QTreeWidgetItem_iter;
    for (QTreeWidgetItem_iter = m_TreeWidgetItem.constBegin(); QTreeWidgetItem_iter != m_TreeWidgetItem.constEnd(); QTreeWidgetItem_iter++) {
        QTreeWidgetItem* temp = *QTreeWidgetItem_iter;
        if ( temp != NULL ) {
            QWidget *widgetItemMask = *(m_WidgetMask.begin()+(QTreeWidgetItem_iter-m_TreeWidgetItem.constBegin()));
            if ( widgetItemMask != NULL ) {
                if ( temp == item ) {
                    widgetItemMask->setVisible(true);
                } else {
                    widgetItemMask->setVisible(false);
                }
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------
void Tree_SmallPic::ShowMaskTow(int index)
{

    int index1 = index;
    int index2 = index;

    if ( (index + 1) % 2 == 0 ) {
        index2--;
    } else {
        index2++;
    }

    qDebug() << "Tree_SmallPic::ShowMaskTow index:" << index << " index1:" << index1 << " index2:" << index2 << Qt::endl;

    QList<QTreeWidgetItem *>::const_iterator QTreeWidgetItem_iter;
    for (QTreeWidgetItem_iter = m_TreeWidgetItem.constBegin(); QTreeWidgetItem_iter != m_TreeWidgetItem.constEnd(); QTreeWidgetItem_iter++) {
        int currIndex = QTreeWidgetItem_iter-m_TreeWidgetItem.constBegin();
        QWidget *widgetItemMask = *(m_WidgetMask.begin()+(currIndex));
        if ( widgetItemMask != NULL ) {
            if ( currIndex == index1 || currIndex == index2 ) {
                widgetItemMask->setVisible(true);
            } else {
                widgetItemMask->setVisible(false);
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------
void Tree_SmallPic::TreeViewDoubleClick(QTreeWidgetItem* item,int itemID)
{
//    vector<QTreeWidgetItem *>::const_iterator QTreeWidgetItem_iter;
//    for (QTreeWidgetItem_iter = m_TreeWidgetItem.begin(); QTreeWidgetItem_iter != m_TreeWidgetItem.end(); QTreeWidgetItem_iter++) {
//        QTreeWidgetItem* temp = *QTreeWidgetItem_iter;
//        if ( temp != NULL ) {
//            QWidget *widgetItemMask = *(m_WidgetMask.begin()+(QTreeWidgetItem_iter-m_TreeWidgetItem.begin()));
//            if ( widgetItemMask != NULL ) {
//                if ( temp == item ) {
//                    widgetItemMask->setVisible(true);
//                } else {
//                    widgetItemMask->setVisible(false);
//                }
//            }
//        }
//    }
    if ( m_MainWidget->m_DisplayModeType == MainWidget::DisplayModeType::Type_ShowTwoPage ) {
        int index = 0;
        QList<QTreeWidgetItem *>::const_iterator QTreeWidgetItem_iter;
        for (QTreeWidgetItem_iter = m_TreeWidgetItem.constBegin(); QTreeWidgetItem_iter != m_TreeWidgetItem.constEnd(); QTreeWidgetItem_iter++) {
            QTreeWidgetItem* temp = *QTreeWidgetItem_iter;
            if ( temp != NULL && temp == item) {
                index = QTreeWidgetItem_iter - m_TreeWidgetItem.begin();
                break;
            }
        }
        ShowMaskTow(index);
    } else {
        ShowMask(item);
    }
    //qDebug() << "Tree_SmallPic::TreeWidgetClick"   << Qt::endl;
    if ( m_MainWidget != NULL ) {
        m_MainWidget->SmallPic_DocmentScrollToItem(m_TreeWidget->indexOfTopLevelItem(item));
    }
}
//----------------------------------------------------------------------------------------------------------
void Tree_SmallPic::TreeWidgetClick(QTreeWidgetItem* item,int itemID)
{
    TreeViewDoubleClick(item,itemID);


}
//----------------------------------------------------------------------------------------------------------
void Tree_SmallPic::GraphicsViewClick(QTreeWidgetItem* item)
{
    TreeViewDoubleClick(item,0);
}
//----------------------------------------------------------------------------------------------------------
//void Tree_SmallPic::resize()
//{
//    QRect rect = m_TreeWidget->geometry();
//    int picWidth = rect.width() * 0.5;

//    vector<QPixmap*>::const_iterator pixmaps_iter;
//    for (pixmaps_iter = m_Pixmaps->begin(); pixmaps_iter != m_Pixmaps->end(); pixmaps_iter++) {
//        QPixmap* temp = *pixmaps_iter;
//        if ( temp != NULL ) {
//            QPixmap pixmapItem = temp->scaledToWidth(picWidth);

//            QGraphicsScene *scene = *(m_GraphicsScene.begin()+(pixmaps_iter-m_Pixmaps->begin()));
//            if ( scene != NULL ) {
//               //delete scene;
//               //scene = new QGraphicsScene();
//               scene->addPixmap(pixmapItem);
//               scene->setSceneRect(0,0,pixmapItem.width(),pixmapItem.height());
//               //m_GraphicsScene[(pixmaps_iter-m_Pixmaps->begin())] = scene;
//            }

//            QWidget *widgetItem = *(m_Widget.begin()+(pixmaps_iter-m_Pixmaps->begin()));
//            QGraphicsView* imageViewItem = *(m_GraphicsView.begin()+(pixmaps_iter-m_Pixmaps->begin()));
//            QTreeWidgetItem *item = *(m_TreeWidgetItem.begin()+(pixmaps_iter-m_Pixmaps->begin()));
//            if ( widgetItem != NULL && imageViewItem != NULL && item != NULL ) {
//                //imageViewItem->setScene(scene);
//                QSize size = item->sizeHint(0);

//                if ( pixmaps_iter ==  m_Pixmaps->begin() ) {
//                    imageViewItem->setGeometry((rect.width() - picWidth)/2 ,20,pixmapItem.width()+2,pixmapItem.height()+2);
//                    widgetItem->setMinimumHeight(pixmapItem.height()+20);
//                    size.setHeight(pixmapItem.height()+20);
//                } else if ( pixmaps_iter ==  m_Pixmaps->end() -1 ) {
//                    imageViewItem->setGeometry((rect.width() - picWidth)/2 ,10,pixmapItem.width()+2,pixmapItem.height()+2);
//                    widgetItem->setMinimumHeight(pixmapItem.height()+30);
//                    size.setHeight(pixmapItem.height()+30);
//                } else {
//                    imageViewItem->setGeometry((rect.width() - picWidth)/2 ,10,pixmapItem.width()+2,pixmapItem.height()+2);
//                    widgetItem->setMinimumHeight(pixmapItem.height()+10);
//                    size.setHeight(pixmapItem.height()+10);
//                }
//                imageViewItem->show();

//                item->
//                //item->setSizeHint(0,size);

//            }



//        }
//    }

//}
//----------------------------------------------------------------------------------------------------------
//void Tree_SmallPic::scaled(double value)
//{
//    QRect rect = m_TreeWidget->geometry();
//    int picWidth = rect.width() * value;

//}
//----------------------------------------------------------------------------------------------------------
