#ifndef TOOL_SMALLPIC_H
#define TOOL_SMALLPIC_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include "util.h"

class MainWidget;

class Tool_SmallPic : public QWidget
{
    Q_OBJECT
public:
    explicit Tool_SmallPic(QWidget *parent = nullptr);
    ~Tool_SmallPic();
public:
    void init(MainWidget * MainWidget);
    double getSliderValue();
signals:

private:
    void clear();

    void btnClicked_left();
    void btnClicked_right();
    void slotSliderValueChanged(int value);
private:
    QSlider * m_Slider;
    QPushButton  * m_leftBut;
    QPushButton  * m_rightBut;
    MainWidget * m_MainWidget;
};

#endif // TOOL_SMALLPIC_H
