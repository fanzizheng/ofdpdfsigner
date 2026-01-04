#ifndef WATERMARK_DIALOG_H
#define WATERMARK_DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

#include "util.h"

class WaterMark_Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit WaterMark_Dialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~WaterMark_Dialog();

public:
    QString getText_FirstLine() {
        QString ret = "";
        if ( m_LeFirstText != NULL  ) {
            ret = m_LeFirstText->text();
        }
        return ret;
    }

    QString getFont_FirstLine() {
        QString ret = "";
        if ( m_FirstFont != NULL  ) {
            ret = m_FirstFont->currentText();
        }
        return ret;
    }

    QString getFontSize_FirstLine() {
        QString ret = "";
        if ( m_LeFirstFontSize != NULL  ) {
            ret = m_LeFirstFontSize->text();
        }
        return ret;
    }

    QString getTextColor_FirstLine() {
        QString ret = "";
        if ( m_LeFirstColor != NULL  ) {
            ret = m_LeFirstColor->text();
        }
        return ret;
    }

    QString getText_SecondLine() {
        QString ret = "";
        if ( m_LeSecondText != NULL  ) {
            ret = m_LeSecondText->text();
        }
        return ret;
    }

    QString getFont_SecondLine() {
        QString ret = "";
        if ( m_SecondFont != NULL  ) {
            ret = m_SecondFont->currentText();
        }
        return ret;
    }

    QString getFontSize_SecondLine() {
        QString ret = "";
        if ( m_LeSecondFontSize != NULL  ) {
            ret = m_LeSecondFontSize->text();
        }
        return ret;
    }

    QString getTextColor_SecondLine() {
        QString ret = "";
        if ( m_LeSecondColor != NULL  ) {
            ret = m_LeSecondColor->text();
        }
        return ret;
    }

    QString getText_ThirdLine() {
        QString ret = "";
        if ( m_LeThirdText != NULL  ) {
            ret = m_LeThirdText->text();
        }
        return ret;
    }

    QString getFont_ThirdLine() {
        QString ret = "";
        if ( m_ThirdFont != NULL  ) {
            ret = m_ThirdFont->currentText();
        }
        return ret;
    }

    QString getFontSize_ThirdLine() {
        QString ret = "";
        if ( m_LeThirdFontSize != NULL  ) {
            ret = m_LeThirdFontSize->text();
        }
        return ret;
    }

    QString getTextColor_ThirdLine() {
        QString ret = "";
        if ( m_LeThirdColor != NULL  ) {
            ret = m_LeThirdColor->text();
        }
        return ret;
    }

    QString getHorizontalSpacing() {
        QString ret = "";
        if ( m_LeLeft != NULL  ) {
            ret = m_LeLeft->text();
        }
        return ret;
    }

    QString getVerticalSpacing() {
        QString ret = "";
        if ( m_LeTop != NULL  ) {
            ret = m_LeTop->text();
        }
        return ret;
    }

    QString getRotate() {
        QString ret = "";
        if ( m_LeRotate != NULL  ) {
            ret = m_LeRotate->text();
        }
        return ret;
    }

    QString getSaveAs() {
        QString ret = "";
        if ( m_LeSaveas != NULL  ) {
            ret = m_LeSaveas->text();
        }
        return ret;
    }

    void setDocType(int doctype)  { m_doctype = doctype; }

signals:

private:
    void btnClicked_Close();
    void btnClicked_OK();

    void btnClicked_Saveas();
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

    QLineEdit* m_LeFirstText;
    QComboBox * m_FirstFont;
    QLineEdit* m_LeFirstFontSize;
    QLineEdit* m_LeFirstColor;

    QLineEdit* m_LeSecondText;
    QComboBox * m_SecondFont;
    QLineEdit* m_LeSecondFontSize;
    QLineEdit* m_LeSecondColor;

    QLineEdit* m_LeThirdText;
    QComboBox * m_ThirdFont;
    QLineEdit* m_LeThirdFontSize;
    QLineEdit* m_LeThirdColor;

    QLineEdit* m_LeLeft;
    QLineEdit* m_LeTop;
    QLineEdit* m_LeRotate;

    QLineEdit* m_LeSaveas;
    int m_doctype;
};

#endif // WATERMARK_DIALOG_H
