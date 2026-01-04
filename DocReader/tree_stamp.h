#ifndef TREE_STAMP_H
#define TREE_STAMP_H

#include "util.h"
#include "iteminfo.h"

#include <QTreeWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsView>
#include "stamp_button.h"




class MainWidget;

class Tree_Stamp : public QObject
{
    Q_OBJECT
public:
    Tree_Stamp(QTreeWidget * treeWidget);
    ~Tree_Stamp();
public:
    void init(QList<ItemInfo*>*  Stamps);
    void clear();
    int getItemIndex(QTreeWidgetItem * item);

    void setMainWindwos(MainWidget * mainWindows) {m_MainWidget = mainWindows;}

public:
    void TreeViewDoubleClick(QTreeWidgetItem* item,int itemID);
    void TreeWidgetClick(QTreeWidgetItem* item,int itemID);
private:

    //void addItem(const QString & StampVerifyInfo, const QString & time, const QString &Stamper,const QString & StampPageIndex,const QPixmap& stamppic);
    void addItem(ItemInfo* itemInfo);

private:
    QTreeWidget * m_TreeWidget;

    QList<ItemInfo*>*  m_Stamps;

    QList<QGraphicsScene *> m_GraphicsScene;
    QList<QTreeWidgetItem *> m_TreeWidgetItem;

    MainWidget * m_MainWidget;
};

#endif // TREE_STAMP_H
