#ifndef MYMESSAGEBOX_H
#define MYMESSAGEBOX_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include "util.h"

/*
   MyMessageBox myMessageBox(this);
    myMessageBox.setContent("  附件多少了附件的路上附件多少了减肥的路上见风使舵减肥的路上附件多少！\n  减肥的路上附件多少了附件多少了附件是");
    myMessageBox.setContent("  附件多少了附件的路上附件多少了减肥的路");
    //myMessageBox.setVisible_CancelButton(false);
    int rec= myMessageBox.exec(); // dia退出的时候就会被销毁；
    if(rec==QDialog::Accepted){
        qDebug()<< "rec=" << rec << " "<< "accept";
    }else if(rec==QDialog::Rejected) {
        qDebug()<< "rec=" << rec << " "<< "reject";
    }



//    MyMessageBox myMessageBox(this);
//    myMessageBox.setContent("  附件多少了附件的路上附件多少了减肥的路上见风使舵减肥的路上附件多少！\n  减肥的路上附件多少了附件多少了附件是");
//    myMessageBox.setContent("  附件多少了附件的路上附件多少了减肥的路");
//    //myMessageBox.setVisible_CancelButton(false);
//    int rec= myMessageBox.exec(); // dia退出的时候就会被销毁；
//    if(rec==QDialog::Accepted){
//        qDebug()<< "rec=" << rec << " "<< "accept";
//    }else if(rec==QDialog::Rejected) {
//        qDebug()<< "rec=" << rec << " "<< "reject";
//    }
*/

class MyMessageBox : public QDialog
{
    Q_OBJECT
public:
    explicit MyMessageBox(QWidget * parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~MyMessageBox();

    void setShowParent(QWidget * parent) {
        QRect rect = parent->geometry();
        setGeometry(rect);
        setFixedSize(rect.width(),rect.height());
    }

    void setVisible_CancelButton(bool isVisible) {
        m_CancelButton->setVisible(isVisible);
    }

    void setContent(const QString & content) {
        m_QLContent->setText(content);
    }

    void setIcon(const QIcon & Image)
    {
        m_TishiButton->setIcon(Image);
    }



private:
    void btnClicked_Close();
    void btnClicked_OK();

private:
    QWidget * m_SelfParent;

    QWidget * m_ClientParent;
    QGridLayout * m_Layout;
    QHBoxLayout * m_QHTitle;
    QHBoxLayout * m_QHClient;
    QHBoxLayout * m_QHButtons;
    QLabel * m_QLTitle;
    QPushButton * m_CloseButton;
    QWidget *m_QWTitleLine;
    QWidget *m_QWButtonsLine;

    QPushButton * m_TishiButton;
    QPushButton * m_OKButton;
    QPushButton * m_CancelButton;
    QLabel * m_QLContent;

    QString m_Title;


};

#endif // MYMESSAGEBOX_H
