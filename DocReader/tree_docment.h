#ifndef TREE_DOCMENT_H
#define TREE_DOCMENT_H

#include "util.h"

#include <QTreeWidget>
#include <QGraphicsView>
#include <QGridLayout>
#include <QHBoxLayout>




class Tree_Docment
{
public:
    Tree_Docment(QTreeWidget * treeWidget);
    ~Tree_Docment();
public:
    void clear();
    //void init(vector<QPixmap*> * pixmaps,double scaledValue);

    void addPixmap(QPixmap* pixmap);
    void addPixmap(const unsigned char * picdata,int piclen);

    void addPixmap(QPixmap* pixmap1,QPixmap* pixmap2);

    //int getItemHeght() { return m_ItemHeight; };

    QList<QGraphicsScene *> * getGraphicsScenes() { return &m_GraphicsScene; }
    QList<QGraphicsView *> * getGraphicsViews() { return &m_GraphicsView; }
private:

private:
    QTreeWidget * m_TreeWidget;

    QList<QTreeWidgetItem *> m_TreeWidgetItem;
    QList<QWidget *> m_Widget;
    QList<QGraphicsView *> m_GraphicsView;
    QList<QGraphicsScene *> m_GraphicsScene;
    QList<QGridLayout *> m_GridLayouts;
    QList<QHBoxLayout *> m_HBoxLayouts;
    QList<QPixmap*> * m_Pixmaps;

    //int m_ItemHeight;
};

#endif // TREE_DOCMENT_H
