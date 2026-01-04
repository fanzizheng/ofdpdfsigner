#ifndef TOOL_STAMP_H
#define TOOL_STAMP_H

#include <QWidget>

class MainWidget;

class Tool_Stamp : public QWidget
{
    Q_OBJECT
public:
    explicit Tool_Stamp(QWidget *parent = nullptr);

    ~Tool_Stamp();

signals:


public:
    void init(MainWidget * mainWidget);
private:
    void clear();
private:
    MainWidget * m_MainWidget;

};

#endif // TOOL_STAMP_H
