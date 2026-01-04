#ifndef ITEMINFO_H
#define ITEMINFO_H

#include <QIcon>
#include <QString>
#include <QLabel>

class Stamp_Button;

class ItemInfo
{
public:
    ItemInfo();
public:
    QIcon  Image;
    QString Tilte;
    QString Time;
    QString Content;
    QString Size;
    QByteArray FileData;
    QString StampVerifyInfo;
    QString Stamper;
    QString StampPageIndex;
    QPixmap StampPic;
    QString StampID;


    Stamp_Button * qlVerifyButton;
    QLabel * qlTime;
    QLabel * qlStamper;
    QLabel * qlTitle;

};

#endif // ITEMINFO_H
