#ifndef MYPROGRESSBOX_H
#define MYPROGRESSBOX_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>

#include "util.h"

/*
 * m_MyProgressBox = new MyProgressBox(this);
    if ( m_MyProgressBox != NULL ) {
        m_MyProgressBox->show(this);
    }

    if ( m_MyProgressBox != NULL ) {
        m_MyProgressBox->close();
    }


    if ( m_MyProgressBox != NULL ) {
        delete m_MyProgressBox;
        m_MyProgressBox = NULL;
    }

*/
class MyProgressBox : public QDialog
{
    Q_OBJECT
public:
    explicit MyProgressBox(QWidget * parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~MyProgressBox();

    void show(QWidget * parent) {
        QRect rect = parent->geometry();
        //rect.setY(rect.y()+40);
        setGeometry(rect);
        setFixedSize(rect.width(),rect.height());
        QDialog::show();
    }

    void setTitle(const QString & title) {
        m_QLTitle->setText(title);
    }

    //minimum和maximum都是0时，来回动。
    void setRange(int minimum, int maximum) {
        m_ProgressBar->setMinimum(minimum);
        m_ProgressBar->setMaximum(maximum);
    }

    void setValue(int value) {
        m_ProgressBar->setValue(value);
    }
private:
    QWidget * m_SelfParent;

    QWidget * m_ClientParent;
    QGridLayout * m_Layout;
    QHBoxLayout * m_QHTitle;
    QHBoxLayout * m_QHClient;
    QLabel * m_QLTitle;
    QProgressBar * m_ProgressBar;
};

#endif // MYPROGRESSBOX_H
