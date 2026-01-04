#ifndef STAMPWIDGET_H
#define STAMPWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QGraphicsView>
#include <QTreeWidget>
#include "tree_docment.h"

class MainWidget;

class StampWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StampWidget(QWidget *parent = nullptr);
    ~StampWidget();

signals:

    void doubleClicked();
    void rightClicked();
public slots:

    void onDoubleClicked();
    void onRightClicked();

public:
    bool SetPixmap(unsigned char * data, int datalen);
    void SetDocment(Tree_Docment * docment) { m_Docment = docment; }
    void SetMainWidget(MainWidget * mainWidget) { m_MainWidget = mainWidget; }

    void setSaveAs(QString saveas) { m_SaveAs = saveas; }
    QString getSaveAs() { return m_SaveAs; }

    void setStamp(QString stamp) { m_Stamp = stamp; }
    QString getStamp() { return m_Stamp; }

    void setCert(QString cert) { m_Cert = cert; }
    QString getCert() { return m_Cert; }

    void setPrikey(QString prikey) { m_PriKey = prikey; }
    QString getPrikey() { return m_PriKey; }

    void setFullFileName(QString fullFileanme) { m_FullFileName = fullFileanme; }
    QString getFullFileName() { return m_FullFileName; }

    void setDocType(int doctype) { m_docType = doctype; }
    int getDocType() { return m_docType; }

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void paintEvent (QPaintEvent * event) override;

private:
    QGraphicsView* m_imageView;
    QGraphicsScene * m_scene;
    QPixmap * m_pixmap;

    bool m_mousePress;
    QPoint m_point;
    Tree_Docment * m_Docment;
    MainWidget * m_MainWidget;

    QString m_SaveAs;
    QString m_Stamp;
    QString m_Cert;
    QString m_PriKey;
    QString m_FullFileName;
    int m_docType;

};

#endif // STAMPWIDGET_H
