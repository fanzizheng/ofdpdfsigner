#ifndef STAMP_BUTTON_H
#define STAMP_BUTTON_H

#include "util.h"
#include "iteminfo.h"

#include <QTreeWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>

class MainWidget;

class Stamp_Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Stamp_Button(QWidget *parent = nullptr) : QPushButton(parent),m_Item(NULL) {
        connect(this, &QPushButton::clicked, this, &Stamp_Button::btnClicked);
    }
    explicit Stamp_Button(const QString &text, QWidget *parent = nullptr): QPushButton(text,parent),m_Item(NULL) {
        connect(this, &QPushButton::clicked, this, &Stamp_Button::btnClicked);
    }
    Stamp_Button(const QIcon& icon, const QString &text, QWidget *parent = nullptr): QPushButton(icon,text,parent),m_Item(NULL) {
        connect(this, &QPushButton::clicked, this, &Stamp_Button::btnClicked);
    }
public:
    void setItem(QTreeWidgetItem * item) { m_Item = item; }
    QTreeWidgetItem * getItem() { return m_Item; }

    void setMainWidget(MainWidget * mainWidget) { m_MainWidget = mainWidget; }
private:
    void btnClicked();
private:
    QTreeWidgetItem * m_Item;
    MainWidget * m_MainWidget;
};

class Tree_SmallPic;

class SmallPic_Button : public QToolButton
{
    Q_OBJECT
public:
    explicit SmallPic_Button(QWidget *parent = nullptr) : QToolButton(parent),m_Item(NULL),m_obj(NULL) {
        connect(this, &QPushButton::clicked, this, &SmallPic_Button::btnClicked);
    }
    //explicit SmallPic_Button(const QString &text, QWidget *parent = nullptr): QToolButton(text,parent),m_Item(NULL) {
   //     connect(this, &QPushButton::clicked, this, &SmallPic_Button::btnClicked);
    //}
   // SmallPic_Button(const QIcon& icon, const QString &text, QWidget *parent = nullptr): QToolButton(icon,text,parent),m_Item(NULL) {
    //    connect(this, &QPushButton::clicked, this, &SmallPic_Button::btnClicked);
    //}
public:
    void setTree_SmallPic(Tree_SmallPic * obj) { m_obj = obj;}
    void setItem(QTreeWidgetItem * item) { m_Item = item; }
    QTreeWidgetItem * getItem() { return m_Item; }
private:
    void btnClicked();

private:
    QTreeWidgetItem * m_Item;
    Tree_SmallPic * m_obj;
};



#endif // STAMP_BUTTON_H
