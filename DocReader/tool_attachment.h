#ifndef TOOL_ATTACHMENT_H
#define TOOL_ATTACHMENT_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include "util.h"

class MainWidget;

class Tool_Attachment : public QWidget
{
    Q_OBJECT
public:
    explicit Tool_Attachment(QWidget *parent = nullptr);
    ~Tool_Attachment();

signals:


public:
    void init(MainWidget * mainWidget);
private:
    void clear();
    void btnClicked_open();
    void btnClicked_save();
private:
    MainWidget * m_MainWidget;
    QPushButton  * m_Open;
    QPushButton  * m_Save;

};

#endif // TOOL_ATTACHMENT_H
