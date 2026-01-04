#include "tree_attachment.h"


//----------------------------------------------------------------------------------------------------------
Tree_Attachment::Tree_Attachment(QTreeWidget * treeWidget)
{
    m_TreeWidget = treeWidget;
    m_SelectIndex = -1;
}
//----------------------------------------------------------------------------------------------------------
Tree_Attachment::~Tree_Attachment()
{
    clear();
}
//----------------------------------------------------------------------------------------------------------
void Tree_Attachment::clear()
{
    m_TreeWidgetItem.clear();
    m_Widget.clear();
    //m_WidgetMask.clear();

    m_Attachments = NULL;

    m_SelectIndex = -1;
}
//----------------------------------------------------------------------------------------------------------
void Tree_Attachment::init(QList<ItemInfo*>*  Attachments)
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


    if ( Attachments == NULL ) {
        return;
    }
    m_Attachments = Attachments;


    QList<ItemInfo*>::const_iterator stamp_iter;

    for(stamp_iter = m_Attachments->begin(); stamp_iter != m_Attachments->end(); stamp_iter++) {
        ItemInfo* temp = *stamp_iter;
        if ( temp != NULL ) {
            addItem(temp->Tilte,temp->Time,temp->Size);
        }//if ( temp != NULL ) {
    }

    //connect(m_TreeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(TreeViewDoubleClick(QTreeWidgetItem*, int)));
    //connect(m_TreeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)), this,SLOT(TreeWidgetClick(QTreeWidgetItem* ,int)));
}
//----------------------------------------------------------------------------------------------------------
void Tree_Attachment::TreeViewDoubleClick(QTreeWidgetItem* item,int itemID)
{

    QList<QTreeWidgetItem *>::const_iterator QTreeWidgetItem_iter;
    for (QTreeWidgetItem_iter = m_TreeWidgetItem.begin(); QTreeWidgetItem_iter != m_TreeWidgetItem.end(); QTreeWidgetItem_iter++) {
        QTreeWidgetItem* temp = *QTreeWidgetItem_iter;
        if ( temp != NULL ) {

            QWidget *widgetItem = *(m_Widget.begin()+(QTreeWidgetItem_iter-m_TreeWidgetItem.begin()));
            if ( widgetItem != NULL ) {

                if ( temp == item ) {
                    widgetItem->setStyleSheet("QWidget"
                                               "{"
                                              "margin-top : 10px;"
                                              "margin-right : 0px;"
                                              "   background-color : "
                                              LEFTBAR_TREEITEM_SELECT_COLOR
                                              "   border-radius: 6px;"
                                               "   border:1px solid "
                                               BORDE_COLOR
                                               "}"
                                              );
                    m_SelectIndex = (QTreeWidgetItem_iter-m_TreeWidgetItem.begin());

                } else {


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
                }
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------------
void Tree_Attachment::TreeWidgetClick(QTreeWidgetItem* item,int itemID)
{
    qDebug() << "Tree_Attachment::TreeWidgetClick"   << Qt::endl;
    TreeViewDoubleClick(item,itemID);
}
//----------------------------------------------------------------------------------------------------------
void Tree_Attachment::addItem(const QString & FileName, const QString & time, const QString &FileSize)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(m_TreeWidget);
    QWidget *widgetItem = new QWidget(m_TreeWidget);

    widgetItem->setMinimumHeight(96);
    widgetItem->setMaximumHeight(96);
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

    QPushButton * icoButton = new QPushButton(widgetItem);
    icoButton->setIcon(QIcon(":/res/images/attachment.png"));
    icoButton->setIconSize(QSize(20,20));
    icoButton->setMaximumSize(24,24);
    icoButton->setMinimumSize(24,24);
    icoButton->setStyleSheet("QPushButton"
                               "{"
                               "margin-left : 4px;"
                               "   border:0px solid transparent;"
                               "}"
                              );

    icoButton->setFlat(true);
    icoButton->show();
    hBoxLayout->addWidget(icoButton,0);


    //

    QLabel * qlTitle = new QLabel(widgetItem);
    qlTitle->setText(FileName);
    qlTitle->setStyleSheet("QLabel"
                               "{"
                                "margin-right : 4px;"
                                "font-size: 16px;"
                               "   border:0px solid transparent;"
                               "}"
                              );
    qlTitle->show();
    hBoxLayout->addWidget(qlTitle,1,Qt::AlignTop);


    QLabel * qlPos = new QLabel(widgetItem);
    qlPos->setStyleSheet("QLabel"
                               "{"
                               "margin-left : 4px;"
                               "margin-right : 4px;"
                               "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );

    qlPos->setText("大小:"+FileSize);
    qlPos->show();
    layout->addWidget(qlPos,1,0,1,0);


    QLabel * qlTime = new QLabel(widgetItem);
    qlTime->setStyleSheet("QLabel"
                               "{"
                              "margin-left : 4px;"
                              "margin-right : 4px;"
                               "font-size: 12px;"
                               "   border:0px solid transparent;"
                               "}"
                              );

    qlTime->setText("添加时间:"+time);
    qlTime->show();
    layout->addWidget(qlTime,2,0,1,0);




    layout->setContentsMargins(0,8,0,8);
    layout->setColumnStretch(0,1);
    layout->setRowStretch(0,1);
    layout->setRowStretch(1,0);
    layout->setRowStretch(2,0);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);

//    QWidget *widgetItemMask = new QWidget(widgetItem);
//    widgetItemMask->setGeometry(widgetItem->geometry());
//    widgetItemMask->setStyleSheet(
//                "background: rgba(40, 40, 40, 0.2);"
//                "   border-radius: 6px;"
//                  );


//    widgetItemMask->setVisible(true);

    if ( m_Widget.size() == 0 ) {
        m_SelectIndex = 0;
        widgetItem->setStyleSheet("QWidget"
                               "{"
                              "margin-top : 10px;"
                              "margin-right : 0px;"
                              "   background-color : "
                              LEFTBAR_TREEITEM_SELECT_COLOR
                              "   border-radius: 6px;"
                               "   border:1px solid "
                               BORDE_COLOR
                               "}"
                              );
    }


    m_TreeWidgetItem.push_back(item);
    m_Widget.push_back(widgetItem);
    //m_WidgetMask.push_back(widgetItemMask);
}
//----------------------------------------------------------------------------------------------------------
