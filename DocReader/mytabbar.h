#ifndef MYTABBAR_H
#define MYTABBAR_H

#include <QWidget>
#include "tabbutton.h"
#include "util.h"



class MainWidget;

class MyTabBar
{
public:
    MyTabBar(QWidget *parent);
    ~MyTabBar();

    void setMainWindwos(MainWidget * mainWindows) {m_MainWidget = mainWindows;}
    void setWindowsWidth(int windowsWidth);
    void addTabButton(const QString & fullFileName,const QString & title,const QString & icon,int windowsWidth);
    int getTabButtonCount();

    void CloseTab(int index);
    void CloseTabOther(int index);
    void ClickedTab(int index);

    int getSelectTab_Index() { return m_selectButton_Index; }
    void setSelectTab_index(int index);


    void setOFDObject(int index,void * obj);
    void setPDFObject(int index,void * obj);
    void * getOFDObject(int index);
    void * getPDFObject(int index);

    QString getFullFileName(int index) {
        if (m_FullFileNames.size() <= 0 ) return "";
        if ( index <= 0 ) index = 0;
        if ( index >= m_FullFileNames.size() ) index = m_FullFileNames.size() - 1;
        return *(m_FullFileNames.begin()+index);
    }

    QPixmap * addDocmentPixmap(int index,double scaledValue,const unsigned char * data,int datalen);
    QList<QPixmap*> * getDocmentPixmaps(int index,double scaledValue);
    int getDocmentPageCount(int index,double scaledValue);
    QList<ItemInfo*> * getStramps(int index);
    QList<ItemInfo*> * getAttachments(int index);
    bool addStramp(int index,const unsigned char * stampdata,int stampdatalen,const QString & StampVerifyInfo,
                   const QString & time, const QString &Stamper,const QString & StampPageIndex,const QString & StampID);
    bool addAttachment(int index,const QString &filename,const QString &time,const unsigned char * filedata,int filedatalen);
    QMap<int,QList<ItemInfo*>*> * getAnnos(int index);
    bool addAnno(int index,int pageindex, const QIcon & icon,const QString & title,const QString & time,const QString & content);

signals:
private:
    void FreeButtons();
    void resizeButtons();
private:
    //不用释放，qt 会释放它
    //QSpacerItem * m_sp_h;
    //不用释放，qt 会释放它
    QList<TabButton*> m_TabButtons;
    QList<QString> m_TabButtonTexts;
    QList<QString> m_TabButtonICons;
    int m_MaxWidth;

    MainWidget * m_MainWidget;
    int m_selectButton_Index;

    QWidget * m_Parent;


    QList<QMap<double,QList<QPixmap*>*>*> m_DocmentPixmaps;
    //vector<map<double,vector<QPixmap*>*>*> m_DocmentPixmaps_FindWord;
    QList<QMap<int,QList<ItemInfo*>*>*> m_Annos;
    QList<QList<ItemInfo*>*>  m_Stamps;
    QList<QList<ItemInfo*>*>  m_Attachments;

    QList<void *> m_OFD_Obj;
    QList<void *> m_PDF_Obj;
    QList<QString> m_FullFileNames;
    //vector<QString> m_isFindWord;


};

#endif // MYTABBAR_H
