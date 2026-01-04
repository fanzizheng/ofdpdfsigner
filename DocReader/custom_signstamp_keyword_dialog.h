#ifndef CUSTOM_SIGNSTAMP_KEYWORD_DIALOG_H
#define CUSTOM_SIGNSTAMP_KEYWORD_DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QMenu>
#include "util.h"

class Custom_SignStamp_KeyWord_Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Custom_SignStamp_KeyWord_Dialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~Custom_SignStamp_KeyWord_Dialog();

    void setShowParent(QWidget * parent) {
        QRect rect = parent->geometry();
        setGeometry(rect);
        setFixedSize(rect.width(),rect.height());
    }
    void setDocType(int doctype)  { m_doctype = doctype; }

    QString getCertFileName() {
        QString ret = "";
        if ( m_LeCert != NULL  ) {
            ret = m_LeCert->text();
        }
        return ret;
    }

    QString getPriKeyFileName() {
        QString ret = "";
        if ( m_LePriKey != NULL  ) {
            ret = m_LePriKey->text();
        }
        return ret;
    }

    QString getStampFileName() {
        QString ret = "";
        if ( m_LeStamp != NULL  ) {
            ret = m_LeStamp->text();
        }
        return ret;
    }

    QString getSaveasFileName() {
        QString ret = "";
        if ( m_LeSaveas != NULL  ) {
            ret = m_LeSaveas->text();
        }
        return ret;
    }

    QString getKeyWord() {
        QString ret = "";
        if ( m_LeKeyWord != NULL  ) {
            ret = m_LeKeyWord->text();
        }
        return ret;
    }

    QString getKeyWordRule();
//    QString getKeyWordRule() {
//        QString ret = "";
////        if ( m_LePageIndex != NULL  ) {
////            ret = m_LePageIndex->text();
////        }
//        ret = "{"
//                  "\"KeyWordPosInfo\":"
//                  "["
//                      "{"
//                          "\"PageIndex\":0,"  //-1，所有页面
//                          "\"KeyWordIndexs\":"
//                          "["
//                              "{"

//                                  "\"Index\":2,"  //-1，所有关键字
//                                  "\"Offset-X\":0," //0,中心
//                                  "\"Offset-Y\":0" //0,中心

//                              "}"

//                           "]"
//                        "}"
//                    "]"
//                "}";
//        return ret;
//    }

signals:

private slots:
    void slotShowMenu(const QPoint &pos);
    void MenuClicked(QAction* action);
private:
    void btnClicked_Close();
    void btnClicked_OK();
    void btnClicked_Saveas();
    void btnClicked_Stamp();
    void btnClicked_PriKey();
    void btnClicked_Certselect();

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

    //QPushButton * m_TishiButton;
    QPushButton * m_OKButton;
    QPushButton * m_CancelButton;
    //QLabel * m_QLContent;

    QString m_Title;

    QLineEdit* m_LeStamp;
    QLineEdit* m_LeCert;
    QLineEdit* m_LePriKey;
    QLineEdit* m_LeSaveas;
    int m_doctype;
    QLineEdit* m_LeKeyWord;
    //QLineEdit* m_LePageIndex;
    QTableView * m_TableView;
    QMenu * m_mainMenu;
    QModelIndex m_CurrIndex;

};

#endif // CUSTOM_SIGNSTAMP_KEYWORD_DIALOG_H
