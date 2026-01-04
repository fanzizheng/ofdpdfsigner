#include "tree_anno.h"
#include "mainwidget.h"
//----------------------------------------------------------------------------------------------------------
Tree_Anno::Tree_Anno(QTreeWidget * treeWidget): m_Annos(NULL),m_MainWidget(NULL)
{
    m_TreeWidget = treeWidget;
}
//----------------------------------------------------------------------------------------------------------
Tree_Anno::~Tree_Anno()
{
    clear();
}
//----------------------------------------------------------------------------------------------------------
void Tree_Anno::clear()
{
//    vector<QTreeWidgetItem *>::const_iterator TreeWidgetItem_iter;
//    for (TreeWidgetItem_iter = m_RootItem_TreeWidgetItems.begin(); TreeWidgetItem_iter != m_RootItem_TreeWidgetItems.end(); TreeWidgetItem_iter++) {
//        QTreeWidgetItem* temp = *TreeWidgetItem_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_RootItem_TreeWidgetItems.clear();

//    vector<QWidget *>::const_iterator Widget_iter;
//    for (Widget_iter = m_RootItem_Widgets.begin(); Widget_iter != m_RootItem_Widgets.end(); Widget_iter++) {
//        QWidget* temp = *Widget_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_RootItem_Widgets.clear();

//    vector<QGridLayout *>::const_iterator QGridLayout_iter;
//    for (QGridLayout_iter = m_RootItem_QGridLayouts.begin(); QGridLayout_iter != m_RootItem_QGridLayouts.end(); QGridLayout_iter++) {
//        QGridLayout* temp = *QGridLayout_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_RootItem_QGridLayouts.clear();

//    vector<QHBoxLayout *>::const_iterator QHBoxLayout_iter;
//    for (QHBoxLayout_iter = m_RootItem_QHBoxLayouts.begin(); QHBoxLayout_iter != m_RootItem_QHBoxLayouts.end(); QHBoxLayout_iter++) {
//        QHBoxLayout* temp = *QHBoxLayout_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_RootItem_QHBoxLayouts.clear();

//    vector<Anno_Button *>::const_iterator Anno_Button_iter;
//    for (Anno_Button_iter = m_RootItem_Anno_Buttons.begin(); Anno_Button_iter != m_RootItem_Anno_Buttons.end(); Anno_Button_iter++) {
//        Anno_Button* temp = *Anno_Button_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_RootItem_Anno_Buttons.clear();

//    vector<QLabel *>::const_iterator QLabel_iter;
//    for (QLabel_iter = m_RootItem_Rights.begin(); QLabel_iter != m_RootItem_Rights.end(); QLabel_iter++) {
//        QLabel* temp = *QLabel_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_RootItem_Rights.clear();

//    for (QLabel_iter = m_RootItem_Lefts.begin(); QLabel_iter != m_RootItem_Lefts.end(); QLabel_iter++) {
//        QLabel* temp = *QLabel_iter;
//        if ( temp != NULL ) {
//            delete temp;
//        }
//    }
    m_RootItem_Lefts.clear();

    m_Item_Content.clear();

    m_Item_QWidget.clear();

    m_Item_TreeWidgetItems.clear();
    m_subItem_PageIndex.clear();
}
//----------------------------------------------------------------------------------------------------------
void Tree_Anno::init(QMap<int,QList<ItemInfo*>*> * annos)
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
//                                     "QTreeWidget::item:selected {show-decoration-selected:0;selection-background-color: transparent;color: transparent;}"

//                                "QTreeView{background-color:"
//                                BACKGROUD_COLOR_TABBAR
//                                "show-decoration-selected: 0;"
//                                "color :"
//                                BACKGROUD_COLOR_TABBAR
//                                "}"


//                                );

    if ( annos == NULL ) {
        return;
    }
    m_Annos = annos;

    QMap<int,QList<ItemInfo*>*>::const_iterator Annos_temp;
    QList<ItemInfo*>::const_iterator Anno_iter;
    for(Annos_temp = m_Annos->begin(); Annos_temp != m_Annos->end(); Annos_temp++) {
        QList<ItemInfo*>* temps = Annos_temp.value();
        if ( temps != NULL ) {
            QTreeWidgetItem * rootitem = addRootItem(Annos_temp.key(),temps->size());
            for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++) {
                ItemInfo* temp = *Anno_iter;
                if ( temp != NULL ) {
                    addSubItem(Annos_temp.key(),rootitem,temp->Image,temp->Tilte,temp->Time,temp->Content);
                }//if ( temp != NULL ) {
            }
        }//if ( Annos_temp->second != NULL ) {
    }


    //connect(m_TreeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(TreeViewDoubleClick(QTreeWidgetItem*, int)));
    //connect(m_TreeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)), this,SLOT(TreeWidgetClick(QTreeWidgetItem* ,int)));

    m_TreeWidget->expandAll();

    RefreshContent();
}
//----------------------------------------------------------------------------------------------------------
void Tree_Anno::addSubItem(int pageindex,QTreeWidgetItem *rootItem,const QIcon & Image,const QString & Tilte, const QString & Time,const QString & Content)
{
    QTreeWidgetItem * subItem = new QTreeWidgetItem(rootItem);
    QWidget *widgetItem = new QWidget(m_TreeWidget);
    widgetItem->setMinimumHeight(90);
    widgetItem->setMaximumHeight(90);
    widgetItem->setStyleSheet("QWidget"
                               "{"
                              "margin-top : 10px;"
                              "margin-right : 20px;"
                              "   background-color : "
                              BACKGROUD_COLOR_DOCMENT
                              "   border-radius: 6px;"
                               "   border:1px solid "
                               BORDE_COLOR
                               "}"
                              );
    m_TreeWidget->setItemWidget(subItem,0,widgetItem);
    QGridLayout * layout = new QGridLayout(widgetItem);
    QHBoxLayout * hBoxLayout = new QHBoxLayout(widgetItem);
    layout->addLayout(hBoxLayout,0,0,1,0);
    QPushButton * button = new QPushButton(widgetItem);
    button->setIcon(Image);
    button->setIconSize(QSize(16,16));
    button->setMaximumSize(20,26);
    button->setMinimumSize(20,26);
    button->setFlat(true);
    button->setStyleSheet("QPushButton"
                               "{"

                                  "margin-right : 0px;"

                               "   border:0px solid transparent;"
                               "}"
                              );

    hBoxLayout->addWidget(button,0);
    //hBoxLayout->addSpacing(6);

    QLabel * qlTitle = new QLabel(widgetItem);
    qlTitle->setText(Tilte);
    qlTitle->setStyleSheet("QLabel"
                               "{"
                                "font-size: 14px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlTitle->show();
    hBoxLayout->addWidget(qlTitle,1);

    QLabel * qlContent = new QLabel(widgetItem);
    qlContent->setStyleSheet("QLabel"
                               "{"
                               "font-size: 10px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlContent->setToolTip(Content);
    //qlContent->setMaximumHeight(60);
    //qlContent->setMinimumHeight(60);
    qlContent->setText(Content);
    //qlContent->setWordWrap(true);
    qlContent->show();



    layout->addWidget(qlContent,1,0,1,1);

    QLabel * qlTime = new QLabel(widgetItem);
    qlTime->setStyleSheet("QLabel"
                               "{"
                               "font-size: 10px;"
                               "color:"
                                LEFTBAR_TIME_COLOR
                               "   border:0px solid transparent;"
                               "}"
                              );

    qlTime->setText(Time);
    qlTime->show();
    layout->addWidget(qlTime,2,0,1,0);

    layout->setContentsMargins(4,8,2,8);
    layout->setColumnStretch(0,1);
    layout->setRowStretch(0,0);
    layout->setRowStretch(1,1);
    layout->setRowStretch(2,0);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);

    m_Item_Content.push_back(qlContent);
    m_Item_QWidget.push_back(widgetItem);
    m_Item_TreeWidgetItems.push_back(subItem);

    //subItem->setData(0,0,Content);

    m_subItem_PageIndex.push_back(pageindex);
}
//----------------------------------------------------------------------------------------------------------
//void Tree_Anno::addSubItem1(QTreeWidgetItem *rootItem,const QIcon & Image,const QString & Tilte, const QString & Time,const QString & Content)
//{

//    QTreeWidgetItem * subItem = new QTreeWidgetItem(rootItem);


//    QWidget *widgetItem = new QWidget();
//    widgetItem->setMinimumHeight(100);
//    widgetItem->setMaximumHeight(100);
//    widgetItem->setStyleSheet("QWidget"
//                               "{"
//                              "margin-top : 20px;"
//                              "margin-bottom : 0px;"
//                              "   background-color : "
//                              BACKGROUD_COLOR_DOCMENT
//                              "   border-radius: 6px;"
//                               "   border:1px solid "
//                               BORDE_COLOR
//                               "}"
//                              );
//    m_TreeWidget->setItemWidget(subItem,0,widgetItem);


//    QGridLayout * layout = new QGridLayout(widgetItem);
//    QVBoxLayout * vBoxLayout = new QVBoxLayout();
//    vBoxLayout->setSpacing(0);
//    layout->addLayout(vBoxLayout,0,0,1,0);



//    QHBoxLayout * hBoxLayout = new QHBoxLayout();


//    QPushButton * button = new QPushButton();
//    button->setIcon(Image);
//    button->setIconSize(QSize(16,16));
//    button->setMaximumSize(28,28);
//    button->setMinimumSize(28,28);
//    button->setFlat(true);
//    button->setStyleSheet("QPushButton"
//                               "{"
//                               "   border:0px solid transparent;"
//                               "}"
//                              );

//    hBoxLayout->addWidget(button,0);
//    //hBoxLayout->addSpacing(6);

//    QLabel * qlTitle = new QLabel();
//    qlTitle->setText(Tilte);
//    qlTitle->setStyleSheet("QLabel"
//                               "{"
//                               "   border:0px solid transparent;"
//                               "}"
//                              );
//    qlTitle->show();
//    hBoxLayout->addWidget(qlTitle,1);
//    vBoxLayout->addLayout(hBoxLayout,0);


//    QHBoxLayout * hBoxLayout1 = new QHBoxLayout();


//    QLabel * qlContent = new QLabel();
//    //qlContent->setMaximumHeight(60);
//    //qlContent->setMinimumHeight(60);



//    qlContent->setText(Content);
//    //qlContent->setWordWrap(true);
//    qlContent->show();
//    hBoxLayout1->addWidget(qlContent,1);
//    vBoxLayout->addLayout(hBoxLayout1,1);

//    QHBoxLayout * hBoxLayout2 = new QHBoxLayout();


//    QLabel * qlTime = new QLabel();
//    qlTime->setStyleSheet("QLabel"
//                               "{"
//                               "   border:0px solid transparent;"
//                               "}"
//                              );
//    qlTime->setText(Time);
//    qlTime->show();
//    hBoxLayout2->addWidget(qlTime,0);
//    vBoxLayout->addLayout(hBoxLayout2,0);



//    layout->setContentsMargins(2,6,2,6);
//    layout->setRowStretch(0,0);
//    layout->setRowStretch(1,1);
//    layout->setRowStretch(2,0);
//    layout->setHorizontalSpacing(0);
//    layout->setVerticalSpacing(0);

////    m_RootItem_TreeWidgetItems.push_back(item);
////    m_RootItem_Widgets.push_back(widgetItem);
////    m_RootItem_Lefts.push_back(lableLeft);
////    m_RootItem_Rights.push_back(lableRight);
////    m_RootItem_Anno_Buttons.push_back(button);
////    m_RootItem_QGridLayouts.push_back(layout);
////    m_RootItem_QHBoxLayouts.push_back(hBoxLayout);



//}
//----------------------------------------------------------------------------------------------------------
QTreeWidgetItem * Tree_Anno::addRootItem(int pageindex, int annoCount)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(m_TreeWidget);


    QWidget *widgetItem = new QWidget(m_TreeWidget);
    widgetItem->setStyleSheet("QWidget"
                               "{"
                              "margin-top : 10px;"
                               "   border-bottom:1px solid "
                               BORDE_COLOR
                               "}"
                              );

    m_TreeWidget->setItemWidget(item,0,widgetItem);

    widgetItem->setMinimumHeight(50);

    QGridLayout * layout = new QGridLayout(widgetItem);
    QHBoxLayout * hBoxLayout = new QHBoxLayout(widgetItem);
    layout->addLayout(hBoxLayout,0,0,1,0);

    QLabel * lableLeft = new QLabel(widgetItem);
    lableLeft->setText("第 "+ QString::number(pageindex+1)  +" 页");
    lableLeft->show();
    hBoxLayout->addWidget(lableLeft,1);
    QLabel * lableRight = new QLabel(widgetItem);
    lableRight->setText(QString::number(annoCount));
    lableRight->show();
    hBoxLayout->addWidget(lableRight,0);

    hBoxLayout->addSpacing(6);

    Anno_Button * button = new Anno_Button(widgetItem);
    button->setIcon(QIcon(":/res/images/zhankai.png"));
    button->setIconSize(QSize(16,16));
    button->setMaximumSize(28,28);
    button->setMinimumSize(28,28);
    button->setFlat(true);
    button->setStyleSheet("QPushButton"
                               "{"
                               "   border-bottom:0px solid transparent;"
                               "}"
                              );
    button->setPageIndex(pageindex);
    button->setItem(item);




    hBoxLayout->addWidget(button,0);


    layout->setContentsMargins(0,6,0,6);
    layout->setColumnStretch(0,1);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);

    m_RootItem_TreeWidgetItems.push_back(item);
    m_RootItem_Widgets.push_back(widgetItem);
    m_RootItem_Lefts.push_back(lableLeft);
    m_RootItem_Rights.push_back(lableRight);
    m_RootItem_Anno_Buttons.push_back(button);
    m_RootItem_QGridLayouts.push_back(layout);
    m_RootItem_QHBoxLayouts.push_back(hBoxLayout);

    return item;
}
//----------------------------------------------------------------------------------------------------------
void Tree_Anno::TreeViewDoubleClick(QTreeWidgetItem* item,int itemID)
{
    bool isFind = false;
    QList<Anno_Button *>::const_iterator Anno_Button_iter;
    for (Anno_Button_iter = m_RootItem_Anno_Buttons.begin(); Anno_Button_iter != m_RootItem_Anno_Buttons.end(); Anno_Button_iter++) {
        Anno_Button* temp = *Anno_Button_iter;
        if ( temp != NULL ) {
            if ( temp->getItem() == item ) {
                if ( item->isExpanded() ) {

                    temp->setIcon(QIcon(":/res/images/nextpage.png"));
                } else {

                    temp->setIcon(QIcon(":/res/images/zhankai.png"));
                }
                isFind = true;
                break;
            }
        }
    }
    if ( isFind ) return;
    //如果没有找到，继续找子节点
    TreeWidgetClick(item,itemID);

}
//----------------------------------------------------------------------------------------------------------
void Tree_Anno::RefreshContent()
{
    QList<QLabel *>::const_iterator QLabel_iter;
    for (QLabel_iter = m_Item_Content.begin(); QLabel_iter != m_Item_Content.end(); QLabel_iter++) {
        QLabel* temp = *QLabel_iter;
        QWidget* tempWidget = *(m_Item_QWidget.begin()+(QLabel_iter-m_Item_Content.begin()));
        if ( temp != NULL && tempWidget != NULL ) {

            QRect rect = tempWidget->geometry();

            QFontMetrics elideFont(temp->font());
            int charWidth = elideFont.maxWidth()*5;

            //qDebug() << "Tree_Anno::RefreshContent  "  << rect.width() << temp->toolTip() << Qt::endl;
            int leftwidth = rect.width()-40-4;
            if ( leftwidth <= charWidth ) {
                return;
            }
            temp->setText(elideFont.elidedText(temp->toolTip(), Qt::ElideRight, leftwidth));
        }
    }
}
//----------------------------------------------------------------------------------------------------------
void Tree_Anno::TreeWidgetClick(QTreeWidgetItem* item,int itemID)
{

    QList<QTreeWidgetItem *>::const_iterator QTreeWidgetItem_iter;
    for (QTreeWidgetItem_iter = m_Item_TreeWidgetItems.begin(); QTreeWidgetItem_iter != m_Item_TreeWidgetItems.end(); QTreeWidgetItem_iter++) {
        QTreeWidgetItem* temp = *QTreeWidgetItem_iter;
        if ( temp != NULL ) {
            QWidget *widgetItem = *(m_Item_QWidget.begin()+(QTreeWidgetItem_iter-m_Item_TreeWidgetItems.begin()));
            if ( widgetItem != NULL ) {
                if ( temp == item ) {

                    widgetItem->setStyleSheet("QWidget"
                                               "{"
                                              "margin-top : 10px;"
                                              "margin-right : 20px;"
                                              "   background-color : "
                                              LEFTBAR_TREEITEM_SELECT_COLOR
                                              "   border-radius: 6px;"
                                               "   border:1px solid "
                                               BORDE_COLOR
                                               "}"
                                              );
                    if ( m_MainWidget != NULL ) {
                        m_MainWidget->TreeItemClick_Annot(*(m_subItem_PageIndex.begin()+ (QTreeWidgetItem_iter-m_Item_TreeWidgetItems.begin())));
                    }
                    //QString aa = temp->data(0,0).value<QString>();
                    //qDebug() << "Tree_Anno::TreeWidgetClick :  "  << aa << Qt::endl;
                } else {
                    widgetItem->setStyleSheet("QWidget"
                                               "{"
                                              "margin-top : 10px;"
                                              "margin-right : 20px;"
                                              "   background-color : "
                                              BACKGROUD_COLOR_DOCMENT
                                              "   border-radius: 6px;"
                                               "   border:1px solid "
                                               BORDE_COLOR
                                               "}"
                                              );
                }
            }
        }
    }


}
//----------------------------------------------------------------------------------------------------------
