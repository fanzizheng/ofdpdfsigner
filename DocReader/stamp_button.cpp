#include "stamp_button.h"
#include "tree_smallpic.h"
#include "mainwidget.h"

void Stamp_Button::btnClicked()
{

    //qDebug() << "Stamp_Button::btnClicked "  << Qt::endl;
    if ( m_MainWidget != NULL && m_Item != NULL ) {
        m_MainWidget->Verify_Stamp(m_Item);
    }

}

void SmallPic_Button::btnClicked()
{
    if ( m_obj != NULL ) {
        m_obj->GraphicsViewClick(m_Item);
    }
}


