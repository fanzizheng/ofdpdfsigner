#ifndef TREE_SMALLPIC_H
#define TREE_SMALLPIC_H

#include "util.h"

#include <QTreeWidget>
#include <QGraphicsView>
#include <QPushButton>
#include "stamp_button.h"




class MainWidget;

class Tree_SmallPic : public QObject
{
    Q_OBJECT
public:
    Tree_SmallPic(QTreeWidget * treeWidget);
    ~Tree_SmallPic();
public:
    void setMainWindwos(MainWidget * mainWindows) {m_MainWidget = mainWindows;}
    void init(QList<QPixmap*> * pixmaps,double scaledValue);
    void clear();
    //void resize();
    //void scaled(double value);
    void GraphicsViewClick(QTreeWidgetItem* item);
public:
    void TreeViewDoubleClick(QTreeWidgetItem* item,int itemID);
    void TreeWidgetClick(QTreeWidgetItem* item,int itemID);

    void ShowMask(QTreeWidgetItem* item);
    void ShowMaskTow(int index);
private:

private:
    QTreeWidget * m_TreeWidget;

    QList<QTreeWidgetItem *> m_TreeWidgetItem;
    QList<QWidget *> m_Widget;
    QList<QWidget *> m_WidgetMask;
    QList<SmallPic_Button *> m_GraphicsView;
    QList<QGraphicsScene *> m_GraphicsScene;
    QList<QPixmap*> * m_Pixmaps;

    MainWidget * m_MainWidget;
};

#endif // TREE_SMALLPIC_H
