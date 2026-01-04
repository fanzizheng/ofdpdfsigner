#ifndef ANNO_BUTTON_H
#define ANNO_BUTTON_H


#include "util.h"
#include "iteminfo.h"

#include <QTreeWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>

class Anno_Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Anno_Button(QWidget *parent = nullptr) : QPushButton(parent),m_Item(NULL) {
        connect(this, &QPushButton::clicked, this, &Anno_Button::btnClicked);
    }
    explicit Anno_Button(const QString &text, QWidget *parent = nullptr): QPushButton(text,parent),m_Item(NULL) {
        connect(this, &QPushButton::clicked, this, &Anno_Button::btnClicked);
    }
    Anno_Button(const QIcon& icon, const QString &text, QWidget *parent = nullptr): QPushButton(icon,text,parent),m_Item(NULL) {
        connect(this, &QPushButton::clicked, this, &Anno_Button::btnClicked);
    }

public:
    void setPageIndex(int index) { m_PageIndex = index; }
    void setItem(QTreeWidgetItem * item) { m_Item = item; }
    QTreeWidgetItem * getItem() { return m_Item; }
private:
    void btnClicked()
    {
        if ( m_Item != NULL ) {
            if ( m_Item->isExpanded() ) {
                m_Item->setExpanded(false);
                this->setIcon(QIcon(":/res/images/nextpage.png"));
            } else {
                m_Item->setExpanded(true);
                this->setIcon(QIcon(":/res/images/zhankai.png"));
            }
        }

    }
private:
    int m_PageIndex;
    QTreeWidgetItem * m_Item;

};
#endif // ANNO_BUTTON_H
