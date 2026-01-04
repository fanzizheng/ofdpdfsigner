#include "mytabbar.h"
#include "mainwidget.h"
#include <QDebug>
//----------------------------------------------------------------------------------------------------------
MyTabBar::MyTabBar(QWidget *parent )
    : m_MainWidget(NULL),m_selectButton_Index(0)
{
    m_MaxWidth = 400;
    m_Parent = parent;
}
//----------------------------------------------------------------------------------------------------------
MyTabBar::~MyTabBar()
{

    FreeButtons();
}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::FreeButtons()
{
    QList<void*>::const_iterator voidp_iter;
    for (voidp_iter = m_OFD_Obj.begin(); voidp_iter != m_OFD_Obj.end(); voidp_iter++) {
        void* temp = *voidp_iter;
        if ( temp != NULL ) {
            m_MainWidget->m_OFDPDFSigner.ofd_close(temp);
        }
    }
    m_OFD_Obj.clear();

    for (voidp_iter = m_PDF_Obj.begin(); voidp_iter != m_PDF_Obj.end(); voidp_iter++) {
        void* temp = *voidp_iter;
        if ( temp != NULL ) {
            m_MainWidget->m_OFDPDFSigner.pdf_close(temp);
        }
    }
    m_PDF_Obj.clear();


    QList<QMap<double,QList<QPixmap*>*>*>::const_iterator QPixmaps_iter;
    for (QPixmaps_iter = m_DocmentPixmaps.constBegin(); QPixmaps_iter != m_DocmentPixmaps.constEnd(); QPixmaps_iter++) {
        QMap<double,QList<QPixmap*>*>* map_temps = *QPixmaps_iter;
        if ( map_temps != NULL ) {
            QMap<double,QList<QPixmap*>*>::const_iterator QPixmapsMap_iter;
            for (QPixmapsMap_iter = map_temps->begin(); QPixmapsMap_iter != map_temps->end(); QPixmapsMap_iter++) {
                QList<QPixmap*>* temps = QPixmapsMap_iter.value();
                if ( temps != NULL ) {
                    QList<QPixmap*>::const_iterator QPixmap_iter;
                    for (QPixmap_iter = temps->begin(); QPixmap_iter != temps->end(); QPixmap_iter++) {
                        QPixmap* temp = *QPixmap_iter;
                        if ( temp != NULL ) {
                            delete temp;
                        }
                    }

                    temps->clear();
                    delete temps;
                } //if ( temps != NULL )

            } //for (QPixmapsMap_iter = map_temps->begin(); QPixmapsMap_iter != map_temps->end(); QPixmapsMap_iter++)
        } //if ( map_temps != NULL )
        map_temps->clear();
    }
    m_DocmentPixmaps.clear();

//    vector<vector<ItemInfo*>*>::const_iterator ItemInfos_iter;
//    for (ItemInfos_iter = m_Stamps.begin(); ItemInfos_iter != m_Stamps.end(); ItemInfos_iter++) {
//        vector<ItemInfo*>* temps = *ItemInfos_iter;
//        if ( temps != NULL ) {
//            vector<ItemInfo*>::const_iterator ItemInfo_iter;
//            for (ItemInfo_iter = temps->begin(); ItemInfo_iter != temps->end(); ItemInfo_iter++) {
//                ItemInfo* temp = *ItemInfo_iter;
//                if ( temp != NULL ) {
//                    delete temp;
//                }
//            }

//            temps->clear();
//            delete temps;
//        }
//    }
//    m_Stamps.clear();

    for (int m_Stamps_i = 0; m_Stamps_i < m_Stamps.size(); m_Stamps_i++) {
        QList<ItemInfo*>* temps = m_Stamps.at(m_Stamps_i);
        if ( temps != NULL ) {
            for (int temps_i; temps_i < temps->size(); temps_i++ ) {
                ItemInfo* temp = temps->at(temps_i);
                if ( temp != NULL ) {
                    delete temp;
                }
            }

            temps->clear();
            delete temps;
        }
    }
    m_Stamps.clear();

    QList<QList<ItemInfo*>*>::const_iterator ItemInfos_iter;
    for (ItemInfos_iter = m_Attachments.begin(); ItemInfos_iter != m_Attachments.end(); ItemInfos_iter++) {
        QList<ItemInfo*>* temps = *ItemInfos_iter;
        if ( temps != NULL ) {
            QList<ItemInfo*>::const_iterator ItemInfo_iter;
            for (ItemInfo_iter = temps->begin(); ItemInfo_iter != temps->end(); ItemInfo_iter++) {
                ItemInfo* temp = *ItemInfo_iter;
                if ( temp != NULL ) {
                    delete temp;
                }
            }

            temps->clear();
            delete temps;
        }
    }
    m_Attachments.clear();

    QList<QMap<int,QList<ItemInfo*>*>*>::const_iterator Annos_iter;
    for (Annos_iter = m_Annos.begin(); Annos_iter != m_Annos.end(); Annos_iter++) {
        QMap<int,QList<ItemInfo*>*>* temp_AnnosMap = *Annos_iter;
        if ( temp_AnnosMap != NULL ) {
            QMap<int,QList<ItemInfo*>*>::const_iterator AnnosMap_iter;
            QList<ItemInfo*>::const_iterator Anno_iter;


            for(AnnosMap_iter = temp_AnnosMap->begin(); AnnosMap_iter != temp_AnnosMap->end(); AnnosMap_iter++) {
                if ( AnnosMap_iter.value() != NULL ) {
                    QList<ItemInfo*>* temps = AnnosMap_iter.value();
                    if ( temps != NULL ) {
                        for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++) {
                            ItemInfo* temp = *Anno_iter;
                            if ( temp != NULL ) {
                                delete temp;
                            } //f ( temp != NULL )
                        }//for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++)
                        temps->clear();
                        delete temps;
                    }//if ( temps != NULL )
                }//if ( AnnosMap_iter->second != NULL )
            }//for(AnnosMap_iter = temp_AnnosMap->begin(); AnnosMap_iter != temp_AnnosMap->end(); AnnosMap_iter++)


            temp_AnnosMap->clear();
            delete temp_AnnosMap;
        }//if ( temp_AnnosMap != NULL )

    }//for (Annos_iter = m_Annos.begin(); Annos_iter != m_Annos.end(); Annos_iter++)

    m_Annos.clear();

    QList<TabButton*>::const_iterator tabButtons_iter;
    for (tabButtons_iter = m_TabButtons.begin(); tabButtons_iter != m_TabButtons.end(); tabButtons_iter++) {
        TabButton* temp = *tabButtons_iter;
        if ( temp != NULL ) {
            delete temp;
        }
    }
    m_TabButtons.clear();

    m_TabButtonTexts.clear();

    m_TabButtonICons.clear();

    m_FullFileNames.clear();

}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::setWindowsWidth(int windowsWidth)
{
    m_MaxWidth = windowsWidth;
    //qDebug() << "MyTabBar::setWindowsWidth " << m_MaxWidth << Qt::endl;
    resizeButtons();
}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::setSelectTab_index(int index)
{
    m_selectButton_Index = index;
    resizeButtons();
}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::addTabButton(const QString & fullFileName,const QString & title,const QString & icon,int windowsWidth)
{

    m_MaxWidth = windowsWidth;

    m_FullFileNames.push_back(fullFileName);
    m_TabButtonTexts.push_back(title.trimmed());
    m_TabButtonICons.push_back(icon);
    m_selectButton_Index = m_TabButtonTexts.size() - 1;

    m_OFD_Obj.push_back(NULL);
    m_PDF_Obj.push_back(NULL);


    m_DocmentPixmaps.push_back(new QMap<double,QList<QPixmap*>*>());

    //m_Stamps.push_back(new vector<ItemInfo*>());
    m_Stamps.push_back(new QList<ItemInfo*>());
    m_Attachments.push_back(new QList<ItemInfo*>());

    m_Annos.push_back(new QMap<int,QList<ItemInfo*>*>());

    resizeButtons();

//    TabButton * tabButton = new TabButton(m_Parent);
//    tabButton->setGeometry(QRect(50,0,m_MaxWidth-50,40));
//    tabButton->Init(QIcon(icon),title,QIcon(":/res/images/close.png"),this,-1,false);
//    tabButton->show();

}
//----------------------------------------------------------------------------------------------------------
int MyTabBar::getTabButtonCount()
{
    return m_TabButtonTexts.size();
}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::resizeButtons()
{
    if ( m_TabButtonTexts.size() == 0 ) {
        if ( m_TabButtons.size() > 0 ) {
            int tempcount = m_TabButtons.size();
            for ( int i = 0; i < tempcount; i++ ) {
                TabButton * tabButton = *(m_TabButtons.begin());
                m_TabButtons.erase(m_TabButtons.begin());
                if ( tabButton != NULL ) {
                    tabButton->setVisible(false);
                    delete tabButton;
                    //this->removeWidget(tabButton);
                }
            }
        }
        return;

    }

    TabButton * tempButton = NULL;

    if ( m_TabButtons.size() > 0 ) {
        tempButton = *(m_TabButtons.begin());
    } else {
        tempButton = new TabButton(m_Parent);
    }

    if ( tempButton == NULL ) {
        return;
    }

    int selfWidth = m_MaxWidth - 50 - 4;//50第一按钮的宽，2 两侧边距；
    int count = selfWidth/tempButton->getMinWidth();

    if ( m_TabButtons.size() == 0 ) {
        delete tempButton;
    }

    //qDebug() << "MyTabBar::resizeButtons.....1 cout:" << count << " m_TabButtonTexts.size():" << m_TabButtonTexts.size() << Qt::endl;
    count = m_TabButtonTexts.size() >= count ? count : m_TabButtonTexts.size();

    //qDebug() << "MyTabBar::resizeButtons.....2 cout:" << count << " m_TabButtons.size() :" << m_TabButtons.size()  << Qt::endl;

    if ( count > m_TabButtons.size() ) {
        int tempcount = count - m_TabButtons.size();
        for ( int i = 0; i < tempcount; i++ ) {
            TabButton * tabButton = new TabButton(m_Parent);
            tabButton->Init(QIcon(":/res/images/1.png"),"",QIcon(":/res/images/close.png"),this,-1,false);
            m_TabButtons.push_back(tabButton);
            //insertWidget(this->count()-1,tabButton,0);
        }
    } else if (  count < m_TabButtons.size() ) {
        int tempcount = m_TabButtons.size() - count;
        for ( int i = 0; i < tempcount; i++ ) {
            TabButton * tabButton = *(m_TabButtons.begin());
            m_TabButtons.erase(m_TabButtons.begin());
            if ( tabButton != NULL ) {
                tabButton->setVisible(false);
                //this->removeWidget(tabButton);

                delete tabButton;
            }
        }
    }



    int itemWidth = 0;
    if ( m_TabButtons.size() == 1 || m_TabButtons.size() == 2 ) {
        itemWidth = selfWidth / 3;
    } else {
        itemWidth = selfWidth / m_TabButtons.size();
    }

    //qDebug() << "MyTabBar::resizeButtons.....3 itemWidth:" << itemWidth << " m_TabButtons.size() :" << m_TabButtons.size()  << Qt::endl;

    TabButton* temp_pre = NULL;
    QList<TabButton*>::const_iterator tabButtons_iter;
    for (tabButtons_iter = m_TabButtons.begin(); tabButtons_iter != m_TabButtons.end(); tabButtons_iter++) {
        TabButton* temp = *tabButtons_iter;
        if ( temp != NULL ) {
            int index = 0;
            if ( m_selectButton_Index < m_TabButtons.size() ) {
                index = tabButtons_iter-m_TabButtons.begin();
            } else {
                index = (m_selectButton_Index+1)-m_TabButtons.size()+(tabButtons_iter-m_TabButtons.begin());
            }
            //index = m_TabButtonTexts.size()-m_TabButtons.size()+(tabButtons_iter-m_TabButtons.begin());
            QString title = m_TabButtonTexts[index];
            QString iconname = m_TabButtonICons[index];
            temp->setIndex(index);
            temp->setLableText(title);
            temp->setLeftIcon(QIcon(iconname));
            //qDebug() << " tabbutton icon: "<< iconname <<Qt::endl;
            if ( m_selectButton_Index == index ) {
                temp->select();
            } else {
                temp->unselect();
            }


            if ( tabButtons_iter-m_TabButtons.begin() == 0 ) {
                temp->setRect(50,0,itemWidth,40);
                temp_pre = temp;
            } else {
                QRect rect_pre = temp_pre->geometry();
                temp->setRect(rect_pre.right(),0,itemWidth,40);
                temp_pre = temp;
            }
            temp->show();

        }
    }
}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::CloseTab(int index)
{
    //qDebug() << "MyTabBar::CloseTab : index " << index << Qt::endl;
    if ( index > m_TabButtonTexts.size() - 1 ) {
        return;
    }


    m_FullFileNames.erase(m_FullFileNames.begin()+index);
    m_TabButtonTexts.erase(m_TabButtonTexts.begin()+index);
    m_TabButtonICons.erase(m_TabButtonICons.begin()+index);

    void * OFDObj = *(m_OFD_Obj.begin()+index);
    if ( OFDObj != NULL ) {
        m_MainWidget->m_OFDPDFSigner.ofd_close(OFDObj);
    }
    m_OFD_Obj.erase(m_OFD_Obj.begin()+index);

    void * PDFObj = *(m_PDF_Obj.begin()+index);
    if ( PDFObj != NULL ) {
        m_MainWidget->m_OFDPDFSigner.pdf_close(PDFObj);
    }
    m_PDF_Obj.erase(m_PDF_Obj.begin()+index);




    QMap<double,QList<QPixmap*>*>* tempDocmentPixmapsMap = *(m_DocmentPixmaps.begin() +index);
    QMap<double,QList<QPixmap*>*>::const_iterator ocmentPixmaps_temp;
    QList<QPixmap*>::const_iterator QPixmap_iter;
    for(ocmentPixmaps_temp = tempDocmentPixmapsMap->begin(); ocmentPixmaps_temp != tempDocmentPixmapsMap->end(); ocmentPixmaps_temp++) {
        if ( ocmentPixmaps_temp.value() != NULL ) {
            QList<QPixmap*>* temps = ocmentPixmaps_temp.value();
            if ( temps != NULL ) {
                for(QPixmap_iter = temps->begin(); QPixmap_iter != temps->end(); QPixmap_iter++) {
                    QPixmap* temp = *QPixmap_iter;
                    if ( temp != NULL ) {
                        delete temp;
                    }
                }
                temps->clear();
                delete temps;
            }
        }
    }
    tempDocmentPixmapsMap->clear();
    delete tempDocmentPixmapsMap;
    m_DocmentPixmaps.erase(m_DocmentPixmaps.begin()+index);


//    vector<ItemInfo*>* tempItemInfo = *(m_Stamps.begin() +index);
//    if ( tempItemInfo != NULL ) {
//        vector<ItemInfo*>::const_iterator ItemInfo_iter;
//        for (ItemInfo_iter = tempItemInfo->begin(); ItemInfo_iter != tempItemInfo->end(); ItemInfo_iter++) {
//            ItemInfo* temp = *ItemInfo_iter;
//            if ( temp != NULL ) {
//                delete temp;
//            }
//        }

//        tempItemInfo->clear();
//        delete tempItemInfo;
//    }
//    m_Stamps.erase(m_Stamps.begin()+index);

    QList<ItemInfo*>* tempItemInfo_q = m_Stamps.takeAt(index);
    if ( tempItemInfo_q != NULL ) {
        for (int tempItemInfo_i = 0; tempItemInfo_i < tempItemInfo_q->size(); tempItemInfo_i++) {
            ItemInfo* temp = tempItemInfo_q->at(tempItemInfo_i);
            if ( temp != NULL ) {
                delete temp;
            }
        }

        tempItemInfo_q->clear();
        delete tempItemInfo_q;
    }


    QList<ItemInfo*>* tempItemInfo = *(m_Attachments.begin() +index);
    if ( tempItemInfo != NULL ) {
        QList<ItemInfo*>::const_iterator ItemInfo_iter;
        for (ItemInfo_iter = tempItemInfo->begin(); ItemInfo_iter != tempItemInfo->end(); ItemInfo_iter++) {
            ItemInfo* temp = *ItemInfo_iter;
            if ( temp != NULL ) {
                delete temp;
            }
        }

        tempItemInfo->clear();
        delete tempItemInfo;
    }
    m_Attachments.erase(m_Attachments.begin()+index);

    QMap<int,QList<ItemInfo*>*>* tempAnnosMap = *(m_Annos.begin() +index);
    QMap<int,QList<ItemInfo*>*>::const_iterator Annos_temp;
    QList<ItemInfo*>::const_iterator Anno_iter;
    for(Annos_temp = tempAnnosMap->begin(); Annos_temp != tempAnnosMap->end(); Annos_temp++) {
        if ( Annos_temp.value() != NULL ) {
            QList<ItemInfo*>* temps = Annos_temp.value();
            if ( temps != NULL ) {
                for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++) {
                    ItemInfo* temp = *Anno_iter;
                    if ( temp != NULL ) {
                        delete temp;
                    }
                }
                temps->clear();
                delete temps;
            }
        }
    }
    tempAnnosMap->clear();
    delete tempAnnosMap;
    m_Annos.erase(m_Annos.begin()+index);




    if ( m_selectButton_Index == index ) {
        m_selectButton_Index--;
    } else if ( index < m_selectButton_Index ) {
        m_selectButton_Index--;
    }
    if ( m_selectButton_Index <= 0 ) {
        m_selectButton_Index = 0;
    }

    resizeButtons();
    if ( m_MainWidget != NULL ) {
        m_MainWidget->CloseTab(index);
    }
}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::CloseTabOther(int index)
{
    if ( index > m_TabButtonTexts.size() - 1 ) {
        return;
    }

    QString fullFileName = *(m_FullFileNames.begin()+index);
    QString text = *(m_TabButtonTexts.begin()+index);
    QString iconname = *(m_TabButtonICons.begin()+index);

    m_FullFileNames.clear();
    m_TabButtonTexts.clear();
    m_TabButtonICons.clear();

    m_FullFileNames.push_back(fullFileName);
    m_TabButtonTexts.push_back(text);
    m_TabButtonICons.push_back(iconname);

    m_selectButton_Index = 0;

    QList<void*>::const_iterator voidp_iter;
    void * OFDObj = *(m_OFD_Obj.begin()+index);
    for (voidp_iter = m_OFD_Obj.begin(); voidp_iter != m_OFD_Obj.end(); voidp_iter++) {
        void* temp = *voidp_iter;
        if ( temp != NULL &&  (voidp_iter - m_OFD_Obj.begin()) != index ) {
            m_MainWidget->m_OFDPDFSigner.ofd_close(temp);
        }
    }
    m_OFD_Obj.clear();
    m_OFD_Obj.push_back(OFDObj);

    void * PDFObj = *(m_PDF_Obj.begin()+index);
    for (voidp_iter = m_PDF_Obj.begin(); voidp_iter != m_PDF_Obj.end(); voidp_iter++) {
        void* temp = *voidp_iter;
        if ( temp != NULL &&  (voidp_iter - m_PDF_Obj.begin()) != index ) {
            m_MainWidget->m_OFDPDFSigner.pdf_close(temp);
        }
    }
    m_PDF_Obj.clear();
    m_PDF_Obj.push_back(PDFObj);

//    map<double,vector<QPixmap*>*>* tempDocmentPixmapsMap = *(m_DocmentPixmaps.begin() +index);
//    vector<map<double,vector<QPixmap*>*>*>::const_iterator DocmentPixmaps_iter;
//    for (DocmentPixmaps_iter = m_DocmentPixmaps.begin(); DocmentPixmaps_iter != m_DocmentPixmaps.end(); DocmentPixmaps_iter++) {
//        map<double,vector<QPixmap*>*>* temp_DocmentPixmapsMap = *DocmentPixmaps_iter;
//        if ( temp_DocmentPixmapsMap != NULL &&  (DocmentPixmaps_iter - m_DocmentPixmaps.begin()) != index ) {
//            map<double,vector<QPixmap*>*>::const_iterator Map_iter;
//            vector<QPixmap*>::const_iterator Pixmaps_iter;


//            for(Map_iter = temp_DocmentPixmapsMap->begin(); Map_iter != temp_DocmentPixmapsMap->end(); Map_iter++) {
//                if ( Map_iter->second != NULL ) {
//                    vector<QPixmap*>* temps = Map_iter->second;
//                    if ( temps != NULL ) {
//                        for(Pixmaps_iter = temps->begin(); Pixmaps_iter != temps->end(); Pixmaps_iter++) {
//                            QPixmap* temp = *Pixmaps_iter;
//                            if ( temp != NULL ) {
//                                delete temp;
//                            } //f ( temp != NULL )
//                        }//for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++)
//                        temps->clear();
//                        delete temps;
//                    }//if ( temps != NULL )
//                }//if ( AnnosMap_iter->second != NULL )
//            }//for(AnnosMap_iter = temp_AnnosMap->begin(); AnnosMap_iter != temp_AnnosMap->end(); AnnosMap_iter++)


//            temp_DocmentPixmapsMap->clear();
//            delete temp_DocmentPixmapsMap;
//        }//if ( temp_AnnosMap != NULL )

//    }//for (Annos_iter = m_Annos.begin(); Annos_iter != m_Annos.end(); Annos_iter++)

//    m_DocmentPixmaps.clear();
//    m_DocmentPixmaps.push_back(tempDocmentPixmapsMap);
    QMap<double,QList<QPixmap*>*>* tempDocmentPixmapsMap = *(m_DocmentPixmaps.begin() +index);
    QList<QMap<double,QList<QPixmap*>*>*>::const_iterator DocmentPixmaps_iter;
    for (DocmentPixmaps_iter = m_DocmentPixmaps.constBegin(); DocmentPixmaps_iter != m_DocmentPixmaps.constEnd(); DocmentPixmaps_iter++) {
        QMap<double,QList<QPixmap*>*>* temp_DocmentPixmapsMap = *DocmentPixmaps_iter;
        if ( temp_DocmentPixmapsMap != NULL &&  (DocmentPixmaps_iter - m_DocmentPixmaps.begin()) != index ) {
            QMap<double,QList<QPixmap*>*>::const_iterator Map_iter;
            QList<QPixmap*>::const_iterator Pixmaps_iter;


            for(Map_iter = temp_DocmentPixmapsMap->constBegin(); Map_iter != temp_DocmentPixmapsMap->constEnd(); Map_iter++) {
                if ( Map_iter.value() != NULL ) {
                    QList<QPixmap*>* temps = Map_iter.value();
                    if ( temps != NULL ) {
                        for(Pixmaps_iter = temps->begin(); Pixmaps_iter != temps->end(); Pixmaps_iter++) {
                            QPixmap* temp = *Pixmaps_iter;
                            if ( temp != NULL ) {
                                delete temp;
                            } //f ( temp != NULL )
                        }//for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++)
                        temps->clear();
                        delete temps;
                    }//if ( temps != NULL )
                }//if ( AnnosMap_iter->second != NULL )
            }//for(AnnosMap_iter = temp_AnnosMap->begin(); AnnosMap_iter != temp_AnnosMap->end(); AnnosMap_iter++)


            temp_DocmentPixmapsMap->clear();
            delete temp_DocmentPixmapsMap;
        }//if ( temp_AnnosMap != NULL )

    }//for (Annos_iter = m_Annos.begin(); Annos_iter != m_Annos.end(); Annos_iter++)

    m_DocmentPixmaps.clear();
    m_DocmentPixmaps.push_back(tempDocmentPixmapsMap);



//    vector<vector<ItemInfo*>*>::const_iterator ItemInfos_iter;

//    vector<ItemInfo*>* tempItemInfos = *(m_Stamps.begin() +index);
//    for (ItemInfos_iter = m_Stamps.begin(); ItemInfos_iter != m_Stamps.end(); ItemInfos_iter++) {
//        vector<ItemInfo*>* temps = *ItemInfos_iter;
//        if ( temps != NULL &&  (ItemInfos_iter - m_Stamps.begin()) != index) {
//            vector<ItemInfo*>::const_iterator iteminfo_iter;
//            for (iteminfo_iter = temps->begin(); iteminfo_iter != temps->end(); iteminfo_iter++) {
//                ItemInfo* temp = *iteminfo_iter;
//                if ( temp != NULL ) {
//                    delete temp;
//                }
//            }

//            temps->clear();
//            delete temps;
//        }
//    }
//    m_Stamps.clear();
//    m_Stamps.push_back(tempItemInfos);
    QList<ItemInfo*>* tempItemInfos_q = m_Stamps.at(index);
    for(int tempItemInfos_q_i = 0; tempItemInfos_q_i < m_Stamps.size(); tempItemInfos_q_i++) {
        QList<ItemInfo*>* temps = m_Stamps.at(tempItemInfos_q_i);
        if ( temps != NULL &&  tempItemInfos_q_i != index) {
            for( int i = 0; i < temps->size(); i++ ) {
                ItemInfo* temp = temps->at(i);
                if ( temp != NULL ) {
                    delete temp;
                }
            }
            temps->clear();
            delete temps;
        }
    }
    m_Stamps.clear();
    m_Stamps.push_back(tempItemInfos_q);

    QList<QList<ItemInfo*>*>::const_iterator ItemInfos_iter;
    QList<ItemInfo*>* tempItemInfos = *(m_Attachments.begin() +index);
    for (ItemInfos_iter = m_Attachments.begin(); ItemInfos_iter != m_Attachments.end(); ItemInfos_iter++) {
        QList<ItemInfo*>* temps = *ItemInfos_iter;
        if ( temps != NULL &&  (ItemInfos_iter - m_Attachments.begin()) != index) {
            QList<ItemInfo*>::const_iterator iteminfo_iter;
            for (iteminfo_iter = temps->begin(); iteminfo_iter != temps->end(); iteminfo_iter++) {
                ItemInfo* temp = *iteminfo_iter;
                if ( temp != NULL ) {
                    delete temp;
                }
            }

            temps->clear();
            delete temps;
        }
    }
    m_Attachments.clear();
    m_Attachments.push_back(tempItemInfos);



    QMap<int,QList<ItemInfo*>*>* tempAnnosMap = *(m_Annos.begin() +index);
    QList<QMap<int,QList<ItemInfo*>*>*>::const_iterator Annos_iter;
    for (Annos_iter = m_Annos.begin(); Annos_iter != m_Annos.end(); Annos_iter++) {
        QMap<int,QList<ItemInfo*>*>* temp_AnnosMap = *Annos_iter;
        if ( temp_AnnosMap != NULL &&  (Annos_iter - m_Annos.begin()) != index ) {
            QMap<int,QList<ItemInfo*>*>::const_iterator AnnosMap_iter;
            QList<ItemInfo*>::const_iterator Anno_iter;


            for(AnnosMap_iter = temp_AnnosMap->begin(); AnnosMap_iter != temp_AnnosMap->end(); AnnosMap_iter++) {
                if ( AnnosMap_iter.value() != NULL ) {
                    QList<ItemInfo*>* temps = AnnosMap_iter.value();
                    if ( temps != NULL ) {
                        for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++) {
                            ItemInfo* temp = *Anno_iter;
                            if ( temp != NULL ) {
                                delete temp;
                            } //f ( temp != NULL )
                        }//for(Anno_iter = temps->begin(); Anno_iter != temps->end(); Anno_iter++)
                        temps->clear();
                        delete temps;
                    }//if ( temps != NULL )
                }//if ( AnnosMap_iter->second != NULL )
            }//for(AnnosMap_iter = temp_AnnosMap->begin(); AnnosMap_iter != temp_AnnosMap->end(); AnnosMap_iter++)


            temp_AnnosMap->clear();
            delete temp_AnnosMap;
        }//if ( temp_AnnosMap != NULL )

    }//for (Annos_iter = m_Annos.begin(); Annos_iter != m_Annos.end(); Annos_iter++)

    m_Annos.clear();
    m_Annos.push_back(tempAnnosMap);


    resizeButtons();
    if ( m_MainWidget != NULL ) {
        m_MainWidget->CloseTabOther(index);
    }
}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::ClickedTab(int index)
{
    if ( index > m_TabButtonTexts.size() - 1 ) {
        return;
    }
    m_selectButton_Index = index;
    resizeButtons();
    if ( m_MainWidget != NULL ) {
        m_MainWidget->ClickedTab(index);
    }
}

void TabbarMenuClicked(QAction* action)
{

}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::setOFDObject(int index,void * obj)
{
    if ( m_OFD_Obj.size() < index + 1 ) {
        return;
    }
    m_OFD_Obj[index] = obj;
}
//----------------------------------------------------------------------------------------------------------
void MyTabBar::setPDFObject(int index,void * obj)
{
    if ( m_PDF_Obj.size() < index + 1 ) {
        return;
    }
    m_PDF_Obj[index] = obj;
}
//----------------------------------------------------------------------------------------------------------
void * MyTabBar::getOFDObject(int index)
{
    if ( m_OFD_Obj.size() < index + 1 ) {
        return NULL;
    }
    return *(m_OFD_Obj.begin()+index);
}
//----------------------------------------------------------------------------------------------------------
void * MyTabBar::getPDFObject(int index)
{
    if ( m_PDF_Obj.size() < index + 1 ) {
        return NULL;
    }
    return *(m_PDF_Obj.begin()+index);
}
//----------------------------------------------------------------------------------------------------------
QPixmap * MyTabBar::addDocmentPixmap(int index,double scaledValue,const unsigned char * data,int datalen)
{
    QPixmap *pixmap = NULL;
    if ( m_DocmentPixmaps.size() < index + 1 ) {
        return pixmap;
    }

    pixmap = new QPixmap();
    if ( pixmap == NULL ) return pixmap;

    bool ret = pixmap->loadFromData(data,datalen);
    if ( ret ) {

        QMap<double,QList<QPixmap*>*>* tempmap = *(m_DocmentPixmaps.begin() +index);
        if ( tempmap != NULL ) {
            QMap<double,QList<QPixmap*>*>::iterator it = tempmap->find(scaledValue);
            if (it != tempmap->end()) {
                QList<QPixmap*>* temps_Iteminfo = it.value();
                temps_Iteminfo->push_back(pixmap);
            } else {
                QList<QPixmap*>* temps_Iteminfo = new QList<QPixmap*>();
                temps_Iteminfo->push_back(pixmap);
                tempmap->insert(scaledValue ,temps_Iteminfo);
            }
        }else {

            delete pixmap;
            pixmap = NULL;
        }

    } else {
        delete pixmap;
        pixmap = NULL;
    }
    return pixmap;
}
//----------------------------------------------------------------------------------------------------------
QList<QPixmap*> * MyTabBar::getDocmentPixmaps(int index,double scaledValue)
{
    QList<QPixmap*> * ret = NULL;
    if ( m_DocmentPixmaps.size() < index + 1 ) {
        return ret;
    }

    QMap<double,QList<QPixmap*>*>* tempmap = *(m_DocmentPixmaps.begin() +index);

    QMap<double,QList<QPixmap*>*>::iterator it = tempmap->find(scaledValue);
    if (it != tempmap->end()) {
        ret = it.value();

    } else {
        ret = NULL;
    }
    return ret;
}
//----------------------------------------------------------------------------------------------------------
int MyTabBar::getDocmentPageCount(int index,double scaledValue)
{
    QList<QPixmap*> * pixmaplist = getDocmentPixmaps(index,scaledValue);
    int count = pixmaplist == NULL ? 0 : pixmaplist->size();
    //qDebug() << "MyTabBar::getDocmentPageCount:  "  << count << Qt::endl;
    return count;
}
//----------------------------------------------------------------------------------------------------------
QList<ItemInfo*>* MyTabBar::getStramps(int index)
{
    QList<ItemInfo*> * ret = NULL;
    if ( m_Stamps.size() < index + 1 ) {
        return ret;
    }

    ret = m_Stamps.at(index);
    return ret;
}
//----------------------------------------------------------------------------------------------------------
QList<ItemInfo*> * MyTabBar::getAttachments(int index)
{
    QList<ItemInfo*> * ret = NULL;
    if ( m_Attachments.size() < index + 1 ) {
        return ret;
    }

    ret = *(m_Attachments.begin() +index);
    return ret;
}
//----------------------------------------------------------------------------------------------------------
bool MyTabBar::addStramp(int index,const unsigned char * stampdata,int stampdatalen,const QString & StampVerifyInfo,
                         const QString & time, const QString &Stamper,const QString & StampPageIndex,
                         const QString & StampID )
{
    bool ret = false;
    if ( m_Stamps.size() < index + 1 ) {
        return ret;
    }

    ItemInfo * temp = new ItemInfo();
    if ( temp == NULL ) return ret;

    ret = temp->StampPic.loadFromData(stampdata,stampdatalen);
    if ( ret ) {

        //vector<ItemInfo*>* temps = *(m_Stamps.begin() +index);
        QList<ItemInfo*>* temps = m_Stamps.at(index);
        if ( temps != NULL ) {
            temp->StampVerifyInfo = StampVerifyInfo;
            temp->Time = time;
            temp->Stamper = Stamper;
            temp->StampPageIndex = StampPageIndex;
            temp->StampID = StampID;
            temps->push_back(temp);
            ret = true;
        } else {
            ret = false;
            delete temp;
        }

    } else {
        delete temp;
    }
    return ret;

}
//----------------------------------------------------------------------------------------------------------
bool MyTabBar::addAttachment(int index,const QString &filename,const QString &time,const unsigned char * filedata,int filedatalen)
{
    bool ret = false;
    if ( m_Attachments.size() < index + 1 ) {
        return ret;
    }

    ItemInfo * temp = new ItemInfo();
    if ( temp == NULL ) return ret;

    QList<ItemInfo*>* temps = *(m_Attachments.begin() +index);
    if ( temps != NULL ) {
        temp->FileData.resize(filedatalen);
        memcpy(temp->FileData.data(),filedata,filedatalen);
        temp->Tilte = filename;
        temp->Time = time;
        temps->push_back(temp);
        ret = true;
    } else {
        ret = false;
        delete temp;
    }

    return ret;
}
//----------------------------------------------------------------------------------------------------------
QMap<int,QList<ItemInfo*>*> * MyTabBar::getAnnos(int index)
{
    QMap<int,QList<ItemInfo*>*> * ret = NULL;
    if ( m_Annos.size() < index + 1 ) {
        return ret;
    }

    ret = *(m_Annos.begin() +index);
    return ret;
}
//----------------------------------------------------------------------------------------------------------
bool MyTabBar::addAnno(int index,int pageindex, const QIcon & icon,const QString & title,const QString & time,const QString & content)
{
    bool ret = false;
    if ( m_Annos.size() < index + 1 ) {
        return ret;
    }

    QMap<int,QList<ItemInfo*>*>* temps = *(m_Annos.begin() +index);
    if ( temps != NULL ) {
        ItemInfo * temp = new ItemInfo();
        if ( temp == NULL ) return ret;
        temp->Image = icon;
        temp->Tilte = title;
        temp->Time = time;
        temp->Content = content;

        QMap<int,QList<ItemInfo*>*>::iterator it = temps->find(pageindex);
        if (it != temps->end()) {
            QList<ItemInfo*>* temps_Iteminfo = it.value();
            temps_Iteminfo->push_back(temp);
        } else {
            QList<ItemInfo*>* temps_Iteminfo = new QList<ItemInfo*>();
            temps_Iteminfo->push_back(temp);
            temps->insert(pageindex ,temps_Iteminfo);
        }

        ret = true;
    }

    return ret;
}
//----------------------------------------------------------------------------------------------------------

