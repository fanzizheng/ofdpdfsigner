#include "stampwidget.h"
#include "QtWidgets/qgridlayout.h"
#include <QEvent>
#include <QMouseEvent>
#include "mainwidget.h"

//-------------------------------------------------------------------------------------------
/*******************************************StampWidget*************************************/
//-------------------------------------------------------------------------------------------
StampWidget::StampWidget(QWidget * parent)
    :QWidget(parent) ,m_imageView(NULL),m_scene(NULL),m_pixmap(NULL),m_mousePress(false),
      m_point(0,0),m_Docment(NULL),m_MainWidget(NULL)
{
    setWindowFlags(
                    Qt::Window
                    |Qt::FramelessWindowHint
                    |Qt::WindowSystemMenuHint
                    |Qt::WindowMinimizeButtonHint
                    |Qt::WindowMaximizeButtonHint
                    |Qt::WindowStaysOnTopHint
                    );

    setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    setMouseTracking(true);
    installEventFilter(this);


    connect(this, SIGNAL(doubleClicked()), this, SLOT(onDoubleClicked()));
    connect(this, SIGNAL(rightClicked()), this, SLOT(onRightClicked()));

}
//-------------------------------------------------------------------------------------------
StampWidget::~StampWidget()
{
    if ( m_pixmap != NULL ) {
        delete m_pixmap;
        m_pixmap = NULL;
    }
}
//-------------------------------------------------------------------------------------------
bool StampWidget::SetPixmap(unsigned char * data, int datalen)
{
    if ( m_pixmap != NULL ) {
        delete m_pixmap;
        m_pixmap = NULL;
    }

    m_pixmap = new QPixmap();
    if ( m_pixmap == NULL ) {
        return false;
    }

    bool ret = m_pixmap->loadFromData(data,datalen);
    if ( !ret ) {
        return ret;
    }

//    if ( m_imageView == NULL ) {
//        QGridLayout * layout = new QGridLayout(this);

//        m_imageView = new QGraphicsView(this);

//        layout->setContentsMargins(0,0,0,0);
//        layout->addWidget(m_imageView,0,0,Qt::AlignCenter);

//        m_scene = new QGraphicsScene();
//        m_imageView->setScene(m_scene);

//        m_imageView->setStyleSheet("background: transparent;border:0px");
//        m_imageView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//        m_imageView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//        m_imageView->setMouseTracking(true);
//        m_imageView->installEventFilter(this);

//    }

    *m_pixmap = m_pixmap->scaledToWidth(m_pixmap->width()*0.75 < 120 ? 120 : m_pixmap->width()*0.75);

//    m_scene->clear();
//    m_scene->addPixmap(*m_pixmap);
//    m_scene->setSceneRect(0,0,m_pixmap->width(),m_pixmap->height());
    int picWidth = m_pixmap->width();
//    m_imageView->setMinimumSize(picWidth,m_pixmap->height());
//    m_imageView->setMaximumSize(picWidth,m_pixmap->height());

//    QRect rect = geometry();

    setMinimumSize(picWidth,m_pixmap->height());
    setMaximumSize(picWidth,m_pixmap->height());

//    m_imageView->show();

    return ret;



}
//-------------------------------------------------------------------------------------------
void StampWidget::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),*m_pixmap);
    painter.setPen(QColor(Qt::darkGray));

    QRect rect = this->geometry();
    painter.drawText(0,0,rect.width(),rect.height(),Qt::AlignLeft|Qt::AlignTop,"鼠标双击完成盖章\n鼠标右键取消操作");
}
//-------------------------------------------------------------------------------------------
bool StampWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this) { // 监视不同的窗口时，需要把this改成对应窗口的指针
        switch (static_cast<int>(event->type())) {
        case QEvent::MouseMove: {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if(m_mousePress) {
                QPoint p = mouseEvent->globalPos();
                this->move(p - m_point);
            }
            return true;
        }

        case QEvent::MouseButtonPress: {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if(mouseEvent->button() == Qt::LeftButton) {
                m_mousePress = true;
                m_point = mouseEvent->globalPos() - this->pos();

            }
            return true;
        }
        case QEvent::MouseButtonRelease: {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if(mouseEvent->button() == Qt::LeftButton) {
                m_mousePress = false;

            } else if (mouseEvent->button() == Qt::RightButton) {
                emit rightClicked();
            }
            return true;
        }
        case QEvent::MouseButtonDblClick :{
            //QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            //QPoint posA = mouseEvent->scenePosition().toPoint();
            //qDebug() << "MouseButtonDblClick x:"<< posA.x() << " y:" << posA.y() << Qt::endl;
            emit doubleClicked();

            return true;
        }

        default:
            break;
        }
    }

    return QWidget::eventFilter(watched, event);
}
//-------------------------------------------------------------------------------------------
void StampWidget::onRightClicked()
{
    this->hide();
}
//-------------------------------------------------------------------------------------------
void StampWidget::onDoubleClicked()
{
    if ( m_Docment == NULL || m_MainWidget == NULL ) return;


    QPoint pos = mapToGlobal(QPoint(0,0));
    pos.setX(pos.x()+this->width()/2);
    pos.setY(pos.y()+this->height()/2);

    //qDebug() << "onDoubleClicked x:"<< pos.x() << " y:" << pos.y() << Qt::endl;

    QList<QGraphicsView *> * graphicsViews = m_Docment->getGraphicsViews();

    int pageindex = 0;
    QList<QGraphicsView *>::const_iterator GraphicsView_iter;
    for (GraphicsView_iter = graphicsViews->begin(); GraphicsView_iter != graphicsViews->end(); GraphicsView_iter++) {
        pageindex++;
        QGraphicsView* temp = *GraphicsView_iter;
        if ( temp != NULL ) {
            QPoint tempPos = temp->mapToGlobal(QPoint(0,0));
            QRect rect = temp->geometry();
            rect.setRect(tempPos.x(),tempPos.y(),rect.width(),rect.height());
            //qDebug() << "onDoubleClicked item rect : " << rect.x() << " "<< rect.y() << " " << rect.width() << " "<< rect.height() << Qt::endl;
            if ( rect.contains(pos) ) {

                int currx = pos.x() - rect.x();
                int curry = pos.y() - rect.y();
                this->hide();

                m_MainWidget->SignStamp_Pos(pageindex,currx,curry,m_FullFileName,m_docType,m_Stamp,m_Cert,m_PriKey,m_SaveAs);

                //qDebug() << "onDoubleClicked pageindex : "<< pageindex << " xy: "<< currx << " " << curry << Qt::endl;

                break;

            }
        }
    }







}
//-------------------------------------------------------------------------------------------
