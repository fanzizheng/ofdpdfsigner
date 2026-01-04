#include "tool_smallpic.h"
#include "mainwidget.h"
//----------------------------------------------------------------------------------------------------------
Tool_SmallPic::Tool_SmallPic(QWidget *parent)
    : QWidget{parent} ,m_Slider(NULL),m_leftBut(NULL),m_rightBut(NULL),m_MainWidget(NULL)
{

}
//----------------------------------------------------------------------------------------------------------
Tool_SmallPic::~Tool_SmallPic()
{
    clear();
}
//----------------------------------------------------------------------------------------------------------
void Tool_SmallPic::clear()
{
    if ( m_leftBut != NULL ) {
        delete m_leftBut;
        m_leftBut = NULL;
    }

    if ( m_rightBut != NULL ) {
        delete m_rightBut;
        m_rightBut = NULL;
    }

    if ( m_Slider != NULL ) {
        delete m_Slider;
        m_Slider = NULL;
    }

}
//----------------------------------------------------------------------------------------------------------
void Tool_SmallPic::init(MainWidget *MainWidget)
{
    clear();

    m_leftBut = new QPushButton(QIcon(":/res/images/jian.png"),"",this);
    m_rightBut = new QPushButton(QIcon(":/res/images/jiahao.png"),"",this);
    m_Slider = new QSlider(Qt::Orientation::Horizontal,this);
    if ( m_leftBut == NULL || m_rightBut == NULL || m_Slider == NULL ) {
        return;
    }

    m_MainWidget = MainWidget;

    int width = 262;
    this->setMinimumWidth(width);

    m_leftBut->setMaximumSize(20,20);
    m_leftBut->setMinimumSize(20,20);
    m_leftBut->setIconSize(QSize(12,12));
    m_leftBut->setFlat(true);
    m_leftBut->setGeometry(2,6,20,20);


    m_Slider->setMaximumSize(180,20);
    m_Slider->setMinimumSize(180,20);
    m_Slider->setGeometry(width- 20 - 18 - 180 - 2 ,6,180,20);

    m_rightBut->setMaximumSize(20,20);
    m_rightBut->setMinimumSize(20,20);
    m_rightBut->setIconSize(QSize(12,12));
    m_rightBut->setFlat(true);
    m_rightBut->setGeometry(width- 18,6,20,20);


    /*horizontal ：水平QSlider*/
    QString styleSheet = "QSlider::groove:horizontal {"
                            "border: 0px solid #bbb;"
                         "}"
                        /*1.滑动过的槽设计参数*/
                        "QSlider::sub-page:horizontal {"
                        /*槽颜色*/
                        "background: rgb(90,49,255);"
                        /*外环区域倒圆角度*/
                        "border-radius: 2px;"
                        /*上遮住区域高度*/
                        "margin-top:8px;"
                        /*下遮住区域高度*/
                        "margin-bottom:8px;"
                        /*width在这里无效，不写即可*/
                        "}"

                        /*2.未滑动过的槽设计参数*/
                        "QSlider::add-page:horizontal {"
                        /*槽颜色*/
                        "background: rgb(255,255, 255);"
                        /*外环大小0px就是不显示，默认也是0*/
                        "border: 0px solid #777;"
                        /*外环区域倒圆角度*/
                        "border-radius: 2px;"
                         /*上遮住区域高度*/
                        "margin-top:9px;"
                         /*下遮住区域高度*/
                        "margin-bottom:9px;"
                        "}"

                        /*3.平时滑动的滑块设计参数*/
                        "QSlider::handle:horizontal {"
                        /*滑块颜色*/
                        "background: rgb(193,204,208);"
                        /*滑块的宽度*/
                        "width: 5px;"
                        /*滑块外环为1px，再加颜色*/
                        "border: 1px solid rgb(193,204,208);"
                         /*滑块外环倒圆角度*/
                        "border-radius: 2px;"
                         /*上遮住区域高度*/
                        "margin-top:6px;"
                         /*下遮住区域高度*/
                        "margin-bottom:6px;"
                        "}"

                        /*4.手动拉动时显示的滑块设计参数*/
                        "QSlider::handle:horizontal:hover {"
                        /*滑块颜色*/
                        "background: rgb(193,204,208);"
                        /*滑块的宽度*/
                        "width: 10px;"
                        /*滑块外环为1px，再加颜色*/
                        "border: 1px solid rgb(193,204,208);"
                         /*滑块外环倒圆角度*/
                        "border-radius: 5px;"
                         /*上遮住区域高度*/
                        "margin-top:4px;"
                         /*下遮住区域高度*/
                        "margin-bottom:4px;"
                        "}"
                        ;
    m_Slider->setStyleSheet(styleSheet);
    m_Slider->setRange(50, 80);
    m_Slider->setValue(50);

    connect(m_Slider,&QSlider::valueChanged,this,&Tool_SmallPic::slotSliderValueChanged);
    connect(m_rightBut, &QPushButton::clicked, this, &Tool_SmallPic::btnClicked_right);
    connect(m_leftBut, &QPushButton::clicked, this, &Tool_SmallPic::btnClicked_left);

}
//----------------------------------------------------------------------------------------------------------
void Tool_SmallPic::btnClicked_left()
{
    if ( m_MainWidget != NULL ) {
        int value = 50;
        if ( m_Slider->value()-5  > 50 ) {
            value = m_Slider->value()-5;
        }
        m_MainWidget->SmallPic_scaled(((double)value)/100);
        m_Slider->setValue(value);
    }
}
//----------------------------------------------------------------------------------------------------------
void Tool_SmallPic::btnClicked_right()
{
    if ( m_MainWidget != NULL ) {
        int value = 80;
        if ( m_Slider->value()+5  < 80 ) {
            value = m_Slider->value()+5;
        }
        m_MainWidget->SmallPic_scaled(((double)value)/100);
        m_Slider->setValue(value);
    }
}
//----------------------------------------------------------------------------------------------------------
void Tool_SmallPic::slotSliderValueChanged(int value)
{
    if ( m_MainWidget != NULL ) {
        m_MainWidget->SmallPic_scaled(((double)m_Slider->value())/100);
    }
}
//----------------------------------------------------------------------------------------------------------
double Tool_SmallPic::getSliderValue()
{
    int value = 50;
    if ( m_Slider != NULL ) {
        if ( m_Slider->value()  <= 50 ) {
            value = 50;

        } else if (m_Slider->value()  >= 80) {
            value = 80;
        } else {
            value = m_Slider->value();
        }
    }
    return ((double)value)/100;
}
//----------------------------------------------------------------------------------------------------------
