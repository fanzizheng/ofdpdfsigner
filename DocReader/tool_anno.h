#ifndef TOOL_ANNO_H
#define TOOL_ANNO_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include "util.h"

class MainWidget;

class Tool_Anno : public QWidget
{
    Q_OBJECT
public:
    explicit Tool_Anno(QWidget *parent = nullptr);
    ~Tool_Anno();
public:
    void init(MainWidget * mainWidget);

private:
    void clear();

    void btnClicked_find();
private slots:
    void returnPressed_FindEdit();
private:
    QPushButton  * m_Find;
    QToolButton  * m_Sort;//排序
    QToolButton  * m_Sieve;//筛选
    QToolButton  * m_Menu;//菜单
    QLineEdit * m_FindEdit;
    MainWidget * m_MainWidget;


};

#endif // TOOL_ANNO_H
