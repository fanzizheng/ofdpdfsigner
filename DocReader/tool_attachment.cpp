#include "tool_attachment.h"
#include "mainwidget.h"
//----------------------------------------------------------------------------------------------------------
Tool_Attachment::Tool_Attachment(QWidget *parent)
    : QWidget{parent},m_MainWidget(NULL),m_Open(NULL),m_Save(NULL)
{

}
//----------------------------------------------------------------------------------------------------------
Tool_Attachment::~Tool_Attachment()
{
    clear();
}
//----------------------------------------------------------------------------------------------------------
void Tool_Attachment::clear()
{
    if ( m_Open != NULL ) {
        delete m_Open;
        m_Open = NULL;
    }

    if ( m_Save != NULL ) {
        delete m_Save;
        m_Save = NULL;
    }
}
//----------------------------------------------------------------------------------------------------------
void Tool_Attachment::init(MainWidget * mainWidget)
{
    clear();

    m_MainWidget = mainWidget;

    m_Open = new QPushButton(this);
    m_Save = new QPushButton(this);

    if (  m_Open == NULL || m_Save == NULL ) {
        return;
    }

    int width = 266;
    this->setMinimumWidth(width);

    m_Open->setIcon(QIcon(":/res/images/file.png"));
    m_Open->setIconSize(QSize(18,18));
    m_Open->setMaximumSize(20,20);
    m_Open->setMinimumSize(20,20);
    m_Open->setFlat(true);
    m_Open->setToolTip("打开文件");
    m_Open->setGeometry(2,6,20,20);

    m_Save->setIcon(QIcon(":/res/images/daochu.png"));
    m_Save->setIconSize(QSize(16,16));
    m_Save->setMaximumSize(20,20);
    m_Save->setMinimumSize(20,20);
    m_Save->setFlat(true);
    m_Save->setToolTip("保存文件");
    m_Save->setGeometry(2+20+2,6,20,20);


    connect(m_Open, &QPushButton::clicked, this, &Tool_Attachment::btnClicked_open);
    connect(m_Save, &QPushButton::clicked, this, &Tool_Attachment::btnClicked_save);
}
//----------------------------------------------------------------------------------------------------------
void Tool_Attachment::btnClicked_open()
{
    if ( m_MainWidget != NULL ) {
        m_MainWidget->Clicked_AttachmentFile_Open();
    }
}
//----------------------------------------------------------------------------------------------------------
void Tool_Attachment::btnClicked_save()
{
    if ( m_MainWidget != NULL ) {
        m_MainWidget->Clicked_AttachmentFile_Save();
    }
}
//----------------------------------------------------------------------------------------------------------


