#ifndef TREE_ATTACHMENT_H
#define TREE_ATTACHMENT_H

#include "util.h"
#include "iteminfo.h"

#include <QTreeWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsView>



class Tree_Attachment : public QObject
{
    Q_OBJECT
public:
    Tree_Attachment(QTreeWidget * treeWidget);
    ~Tree_Attachment();
public:
    void init(QList<ItemInfo*>*  Attachments);
    void clear();
    int getSelectIndex() { return m_SelectIndex; }
public:
    void TreeViewDoubleClick(QTreeWidgetItem* item,int itemID);
    void TreeWidgetClick(QTreeWidgetItem* item,int itemID);
private:
    void addItem(const QString & FileName, const QString & time, const QString &FileSize);
private:
    QTreeWidget * m_TreeWidget;

    QList<ItemInfo*>*  m_Attachments;

    QList<QTreeWidgetItem *> m_TreeWidgetItem;
    QList<QWidget *> m_Widget;
    //vector<QWidget *> m_WidgetMask;
    int m_SelectIndex;
};

#endif // TREE_ATTACHMENT_H
