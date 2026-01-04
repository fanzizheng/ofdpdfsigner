#ifndef TABBUTTON_H
#define TABBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include "util.h"
#include "iteminfo.h"

class MyTabBar;

class TabButton : public QGroupBox
{
    Q_OBJECT
public:
    explicit TabButton(QWidget *parent = nullptr);
    ~TabButton();

    void Init(const QIcon & leftimage,const QString & title,const QIcon & rightimage,MyTabBar * myTabBar,int index,bool isSelect);
    int getWidth();
    void setRect(int x,int y,int width,int Heigt);
    int getMinWidth();
    void setLableText(const QString & title) {
        m_CentLableText = title;
        setToolTip(m_CentLableText);
    }
    void setLeftIcon(const QIcon & leftimage) {
        m_LeftIcon = leftimage;
        m_leftBut->setIcon(m_LeftIcon);
    }
    void setIndex(int index) {
        m_index = index;
    }


    void select();
    void unselect();

//    bool addDocmentPixmap(const unsigned char * data,int datalen);


//    vector<QPixmap*> * getDocmentPixmaps() {
//        return &m_DocmentPixmaps;
//    }

//    bool addAnno(int pageindex, const QIcon & icon,const QString & title,const QString & time,const QString & content);


//    map<int,vector<ItemInfo*>*> * getAnnos() {
//        return &m_Annos;
//    }

//    //StampPageIndex:位于第1页 ； 位于第1，2，3页
//    bool addStramp(const unsigned char * stampdata,int stampdatalen,const QString & StampVerifyInfo, const QString & time, const QString &Stamper,const QString & StampPageIndex);
//    vector<ItemInfo*> * getStamps() {
//        return &m_Stamps;
//    }

//    bool addAttachment(const QString &filename,const QString &time,const unsigned char * filedata,int filedatalen);
//    vector<ItemInfo*> * getAttachments() {
//        return &m_Attachments;
//    }

//    void setOFDObject(void * obj) { m_OFD_Obj = obj; }
//    void * getOFDObject() { return m_OFD_Obj; }
//    void setPDFObject(void * obj) { m_PDF_Obj = obj; }
//    void * getPDFObject() { return m_PDF_Obj; }


public Q_SLOTS:
    void claseTabSelf();
    void closeTabOther();
    void closeTabLeft();
    void closeTabRight();

protected:
  void mouseReleaseEvent(QMouseEvent* event);
  void contextMenuEvent(QContextMenuEvent *);
private:
    void FreeButton();

    void btnClicked_Close();

    void btnClicked();


private:
    QPushButton  * m_leftBut;
    QPushButton  * m_rightBut;
    QGridLayout * m_layout;
    QString m_CentLableText;
    QIcon m_LeftIcon;
    //QGroupBox * m_groupBox;
    MyTabBar * m_MyTabBar;
    int m_index;

    QMenu * m_Menu;





};

#endif // TABBUTTON_H
