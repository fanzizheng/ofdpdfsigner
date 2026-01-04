#ifndef TREE_ANNO_H
#define TREE_ANNO_H

#include "util.h"
#include "iteminfo.h"

#include <QTreeWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "anno_button.h"




class MainWidget;

class Tree_Anno : public QObject
{
    Q_OBJECT
public:
    Tree_Anno(QTreeWidget * treeWidget);
    ~Tree_Anno();
public:
    void setMainWindwos(MainWidget * mainWindows) {m_MainWidget = mainWindows;}
    void init(QMap<int,QList<ItemInfo*>*> * annos);
    void clear();
    void RefreshContent();
public:
    void TreeViewDoubleClick(QTreeWidgetItem* item,int itemID);
    void TreeWidgetClick(QTreeWidgetItem* item,int itemID);
private:
    QTreeWidgetItem * addRootItem(int pageindex, int annoCount);
    void addSubItem(int pageindex,QTreeWidgetItem *rootItem,const QIcon & Image,const QString & Tilte, const QString & Time,const QString & Content);
    //void addSubItem1(QTreeWidgetItem *rootItem,const QIcon & Image,const QString & Tilte, const QString & Time,const QString & Content);
private:
    QTreeWidget * m_TreeWidget;
    QMap<int,QList<ItemInfo*>*> * m_Annos;

    QList<QTreeWidgetItem *> m_RootItem_TreeWidgetItems;
    QList<QWidget *> m_RootItem_Widgets;
    QList<QLabel *> m_RootItem_Lefts;
    QList<QLabel *> m_RootItem_Rights;
    QList<Anno_Button *> m_RootItem_Anno_Buttons;
    QList<QGridLayout *> m_RootItem_QGridLayouts;
    QList<QHBoxLayout *> m_RootItem_QHBoxLayouts;

    QList<QLabel *> m_Item_Content;
    QList<QWidget *> m_Item_QWidget;
    QList<QTreeWidgetItem *> m_Item_TreeWidgetItems;
    QList<int> m_subItem_PageIndex;

    MainWidget * m_MainWidget;
};

#endif // TREE_ANNO_H
