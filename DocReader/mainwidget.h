#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QTimer>
#include <QProgressDialog>
#include "mytabbar.h"
#include "tree_smallpic.h"
#include "tool_anno.h"
#include "tool_smallpic.h"
#include "tool_attachment.h"
#include "tool_stamp.h"
#include "tree_docment.h"
#include "tree_anno.h"
#include "tree_attachment.h"
#include "tree_stamp.h"
#include "mymessagebox.h"
#include "myprogressbox.h"
#include "ofdpdfsignerproxy.h"
#include "fontaddthread.h"
#include "stampwidget.h"
#include <QMainWindow>

class QMenu;

//#define OFD_SCALED 3.4
#define OFD_SCALED 1.2

#define PDF_SCALED 1.2

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    enum class LeftBarButtonType { Type_None = 0,Type_SmallPic, Type_Anno,Type_Stamp,Type_Attachment};

    enum class DisplayModeType { Type_ContinuePage = 0,Type_ShowOnepage, Type_ShowTwoPage};
    /**
     * @brief The TitleMode defines the type of titlebar that will be shown.
     */
    enum class TitleMode { CleanTitle = 0, OnlyCloseButton, MenuOff, MaxMinOff, FullScreenMode, MaximizeModeOff, MinimizeModeOff, FullTitle };


    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();



    /**
     * @brief setTitlebarMode With this method the type of titlebar is defined based on TitleMode enum.
     * @param flag The type of titlebar.
     */
    void setTitlebarMode(const TitleMode &flag);
    /**
     * @brief setTitlebarMenu With this method a custom menu for the titlebar can be set.
     * @param menu The custom menu.
     * @param icon The path to the icon.
     */
    void setTitlebarMenu(QMenu *menu, const QString &icon = "");
    /**
     * @brief setCentralWidget This is the main method of the class which is defined the central
     * widget that will be set as centralWidget in the window.
     * @param widget The further centralwidget.
     * @param widgetName The name of the window.
     */
    //void setCentralWidget(QWidget *widget, const QString &widgetName);

    void CloseTab(int index);
    void CloseTabOther(int index);
    void ClickedTab(int index);
    void SmallPic_scaled(double value);
    //点击缩略图，文档滚动到相应item
    void SmallPic_DocmentScrollToItem(int index);

    void Clicked_AttachmentFile_Open();
    void Clicked_AttachmentFile_Save();

    void TreeItemClick_Annot(int index);

    void OpenOFDOrPDF(QString fileName);
#ifdef Q_OS_WIN
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result);
#endif

    void SignStamp_Pos(int pageIndex, int x,int y,QString FullFileName,int docType,
                       QString StampFileName,QString CertFileName,
                       QString prikeyFileName,QString SaveasFileName);

    void Verify_Stamp(QTreeWidgetItem* item);
public:

    OFDPDFSignerProxy m_OFDPDFSigner;
    DisplayModeType m_DisplayModeType;
    QList<QString> m_SystemFontFiles;



protected:
    /**
     * @brief moveWindow Method that moves the window to the new position when the window
     * is moved.
     * @param e The mouse event that sets the new position.
     */
    void moveWindow(QMouseEvent *e);
    void resizeEvent(QResizeEvent *event);

    bool eventFilter(QObject *watched, QEvent *event) override;



private slots:
    void on_pbLeftClient_Close_clicked();

    void on_pbSmallPic_clicked();

    //void onTimeOut();
    void onTimeOut_WindowFinish();

    void returnPressed_leGotoEdit();
    void returnPressed_leFindKey();

    void TreeViewDoubleClick(QTreeWidgetItem* item,int itemID);
    void TreeWidgetClick(QTreeWidgetItem* item,int itemID);

    void on_ScaledValue_Changed(int item);

    void onDocmentScrollChanged(int p);

    void TabbarMenuClicked(QAction* action);

private:
    /**
     * @brief mouseMoveEvent Overloaded member that moves of resizes depending of the
     * configuration sotred at mousePressEvent().
     * @param e The mouse event.
     */
    void mouseMoveEvent(QMouseEvent *e);
    /**
     * @brief mousePressEvent Overloaded member that stores that changes the cursor and
     * configures the side that is changing.
     * @param e The mouse event.
     */
    void mousePressEvent(QMouseEvent *e);
    /**
     * @brief mouseReleaseEvent Overloaded member that removes the configuration set in mousePressEvent().
     * @param e The mouse event.
     */
    void mouseReleaseEvent(QMouseEvent *e);
    /**
     * @brief mouseDoubleClickEvent Overloadad member that maximize/restore the window if is
     * doubleclicked and the position of the mouse is not the top left of the window (menu zone).
     * @param e The mouse event.
     */
    void mouseDoubleClickEvent(QMouseEvent *e);
    /**
     * @brief paintEvent Overloaded method that allows to customize the styles of the window.
     */
    void paintEvent (QPaintEvent *);
    /**
     * @brief resizeWindow Method that calculates the resize and new position of the window an
     * does this actions.
     * @param e The mouse event to calculate the new position and size.
     */
    void resizeWindow(QMouseEvent *e);
    /**
     * @brief maximizeBtnClicked Maximizes or restores the window depending on the last status.
     */
    void maximizeBtnClicked();
    /**
     * @brief minimizeBtnClicked Minimizes or restores the window depending on the last status.
     */
    void minimizeBtnClicked();
    /**
     * @brief resizeWhenVerCursor Method that resizes when the cursor is type VerCursor.
     * @param p The position of the mouse.
     */
    void resizeWhenVerCursor (const QPoint &p);
    /**
     * @brief resizeWhenHorCursor Method that resizes when the cursor is type HorCursor.
     * @param p The position of the mouse.
     */
    void resizeWhenHorCursor (const QPoint &p);
    /**
     * @brief resizeWhenBDiagCursor Method that resizes when the cursor is type  BDiagCursor.
     * @param p The position of the mouse.
     */
    void resizeWhenBDiagCursor (const QPoint &p);
    /**
     * @brief resizeWhenFDiagCursor Method that resizes when the cursor is type FDiagCursor.
     * @param p The position of the mouse.
     */
    void resizeWhenFDiagCursor (const QPoint &p);

    void openDocument();
    void click_pbSave();
    void click_pbSaveAS();
    void click_pbPrint();
    void click_pbAddStamp();
    void click_pbRidingStamp();
    void click_pbKeyWorkStamp();
    //void click_pbMakeCert();
    void click_pbMakeSeal();

    void click_pbAnnot();
    void click_pbStamp();
    void click_pbAttachment();

    void click_pbFirstPage();
    void click_pbPrePage();
    void click_pbNextPage();
    void click_pbLastPage();

    void click_pbContinuePage();
    void click_pbShowOnepage();
    void click_pbShowTwoPage();

    void click_pbWaterMark();

    void pushWindow();


private:
    void Refresh_LeftBarClient();
    void Refresh_LeftBar();
    void resize_LeftClient(QMouseEvent *e);

    void setGotoEditText(int currIndex,int pageCount);

    double getScaledValue();
    int getCurrDisplayItemIndex();
    void ShowOnepage();
    void SmallPicShowMask(int index);
    void ShowDocment(int pageindex);

    void getDocmentOtherInfo();
    void TreeItemClick_Stamp(QTreeWidgetItem* item);

    void ClearFindWordList();
    void AddFindWordList(int pageIndex,const char* const word,float x,float y,float w,float h);
    QPixmap DrawFindWord(QPixmap* srcPixmap,int pageIndex,QString word);


    static void AttachmentFileFunc(const char* const filename,
                                       const char * const time,
                                       const unsigned char* const filedata,
                                       int filedatalen);
    static void AnnotsFunc(int pagenum,
                     const char * const creator,
                     const char* const time,
                     const char* const type,
                               const char* const remark);
    static void StampsFunc(const char* const pagenum,
                const char * const time,
                const char * const sid,
                const unsigned char* imagedata,
                       int imagedatalen);


    static void FindWordFunc(int pageIndex,const char* const word,float x,float y,float w,float h);

    static void SystemFontFileNameFunc(const void * param,const char* const fullFileName);




private:
    Ui::MainWidget *ui;
    /**
     * @brief dragPosition Increment of the position movement.
     */
    QPoint mDragPosition;
    /**
     * @brief m_titleMode Flags that defines the current titlebar mode.
     */
    TitleMode mTitleMode = TitleMode::FullTitle;
    /**
     * @brief moveWidget Specifies if the window is in move action.
     */
    bool mMoveWidget = false;
    /**
     * @brief inResizeZone Specifies if the mouse is in resize zone.
     */
    bool mInResizeZone = false;
    /**
     * @brief allowToResize Specifies if the mouse is allowed to resize.
     */
    bool mAllowResize = false;
    /**
     * @brief resizeVerSup Specifies if the resize is in the top of the window.
     */
    bool mResizeVerTop = false;
    /**
     * @brief resizeHorEsq Specifies if the resize is in the left of the window.
     */
    bool mResizeHorLeft = false;
    /**
     * @brief resizeDiagSupEsq Specifies if the resize is in the top left of the window.
     */
    bool mResizeDiagTopLeft = false;
    /**
     * @brief resizeDiagSupDer Specifies if the resize is in the top right of the window.
     */
    bool mResizeDiagTopRight = false;
    /**
      + @brief Pixels around the border to mouse cursor change.
      */
    const static int PIXELS_TO_ACT = 5;


    //QPropertyAnimation* m_propertyAnimation;
    //QPropertyAnimation* m_propertyAnimation2;

    //不用释放，qt 会释放它
    MyTabBar * m_MyTabBar;
    QMenu * m_Menu_TabBar;
    QList<QAction*> m_MenuActions;
    QList<QString> m_MenuActionTexts;

    LeftBarButtonType m_LeftBarButtonType;


    bool mousePress_leftClient;

     Tree_SmallPic * m_Tree_SmallPic;
     Tree_Anno * m_Tree_Anno;
     Tree_Attachment * m_Tree_Attachment;
     Tree_Stamp * m_Tree_Stamp;
    Tree_Docment * m_Tree_Docment;

    //QTimer *m_ResizeWinFinshTimer;
    QTimer m_WindowsFinish;
//    int m_ResizewindWidth;
//    int m_ResizewindTimeWidth;
     Tool_SmallPic * m_Tool_SmallPic;
     Tool_Anno * m_Tool_Anno;
     Tool_Stamp * m_Tool_Stamp;
     Tool_Attachment * m_Tool_Attachment;

     MyProgressBox* m_MyProgressBox;

     QString m_CurrPath;

     QList<DocWord *> m_FindWordList;


    FontAddThread* m_FontAddThread;

    static MainWidget* m_SelfPtr;
    StampWidget* m_StampWidget;
};



#endif // MAINWIDGET_H
