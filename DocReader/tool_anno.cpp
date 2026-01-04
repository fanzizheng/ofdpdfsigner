#include "tool_anno.h"
#include "mainwidget.h"

//----------------------------------------------------------------------------------------------------------
Tool_Anno::Tool_Anno(QWidget *parent)
    : QWidget{parent},m_Find(NULL),m_Sort(NULL),m_Sieve(NULL),
      m_Menu(NULL),m_FindEdit(NULL),m_MainWidget(NULL)
{

}
//----------------------------------------------------------------------------------------------------------
Tool_Anno::~Tool_Anno()
{
    clear();
}
//----------------------------------------------------------------------------------------------------------
void Tool_Anno::clear()
{
    if ( m_Find != NULL ) {
        delete m_Find;
        m_Find = NULL;
    }

    if ( m_Sort != NULL ) {
        delete m_Sort;
        m_Sort = NULL;
    }

    if ( m_Sieve != NULL ) {
        delete m_Sieve;
        m_Sieve = NULL;
    }

    if ( m_Menu != NULL ) {
        delete m_Menu;
        m_Menu = NULL;
    }



    if ( m_FindEdit != NULL ) {
        delete m_FindEdit;
        m_FindEdit = NULL;
    }




}
//----------------------------------------------------------------------------------------------------------
void Tool_Anno::init(MainWidget * mainWidget)
{
    clear();

    m_MainWidget = mainWidget;
    //m_Layout = new QGridLayout(this);
    //m_HBoxLayout = new QHBoxLayout();

    m_Find = new QPushButton(this);
    m_Sort = new QToolButton(this);//排序
    m_Sieve = new QToolButton(this);//筛选
    m_Menu = new QToolButton(this);//菜单
    m_FindEdit = new QLineEdit(this);

//    if ( m_Layout == NULL || m_HBoxLayout == NULL || m_Find == NULL || m_Sort == NULL || m_Sieve == NULL
//         || m_Menu == NULL || m_Title == NULL || m_FindEdit == NULL) {
//        return;
//    }

    if (  m_Find == NULL || m_Sort == NULL || m_Sieve == NULL
         || m_Menu == NULL || m_FindEdit == NULL) {
        return;
    }

    int width = 266;
    this->setMinimumWidth(width);


    m_Menu->setIcon(QIcon(":/res/images/menusub.png"));
    m_Menu->setIconSize(QSize(16,16));
    m_Menu->setMaximumSize(20,20);
    m_Menu->setMinimumSize(20,20);
    m_Menu->setGeometry(2,6,20,20);

    m_Sieve->setIcon(QIcon(":/res/images/sieve.png"));
    m_Sieve->setIconSize(QSize(16,16));
    m_Sieve->setMaximumSize(20,20);
    m_Sieve->setMinimumSize(20,20);
    m_Sieve->setGeometry(2+20+2,6,20,20);

    m_Sort->setIcon(QIcon(":/res/images/sort.png"));
    m_Sort->setIconSize(QSize(16,16));
    m_Sort->setMaximumSize(20,20);
    m_Sort->setMinimumSize(20,20);
    m_Sort->setGeometry(2+20+2+20+2,6,20,20);

    m_FindEdit->setClearButtonEnabled(true);
    m_FindEdit->setMinimumSize(180,20);
    m_FindEdit->setMaximumSize(180,20);
    m_FindEdit->setGeometry(2+20+2+20+2+20+2,6,180,20);


    m_Find->setIcon(QIcon(":/res/images/find.png"));
    m_Find->setIconSize(QSize(16,16));
    m_Find->setMaximumSize(20,20);
    m_Find->setMinimumSize(20,20);
    m_Find->setFlat(true);
    m_Find->setGeometry(2+20+2+20+2+20+2+180+2,6,20,20);


    connect(m_Find, &QPushButton::clicked, this, &Tool_Anno::btnClicked_find);
    connect(m_FindEdit, SIGNAL(returnPressed()), this, SLOT(returnPressed_FindEdit()));



}
//----------------------------------------------------------------------------------------------------------
void Tool_Anno::btnClicked_find()
{


}
//----------------------------------------------------------------------------------------------------------
void Tool_Anno::returnPressed_FindEdit()
{
    btnClicked_find();
}
//----------------------------------------------------------------------------------------------------------
