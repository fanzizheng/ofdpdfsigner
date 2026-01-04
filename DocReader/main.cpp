#include "mainwidget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QMovie>
#include <QPixmap>
#include <QSplashScreen>
//#include <QTextCodec>

#ifdef Q_OS_WIN
//#define _HAS_STD_BYTE 0

#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
const ULONG_PTR SEND_CUSTOM_TYPE = 10000;


void onSendMessage(HWND hwnd,QString filename)
{

    //} while (hwnd == (HWND)effectiveWinId()); // 忽略自己

    if (::IsWindow(hwnd))
    {

        QByteArray data = filename.toUtf8();

        COPYDATASTRUCT copydata;
        copydata.dwData = SEND_CUSTOM_TYPE;  // 用户定义数据
        copydata.lpData = data.data();  //数据大小
        copydata.cbData = data.size();  // 指向数据的指针

        //HWND sender = (HWND)effectiveWinId();

        ::SendMessage(hwnd, WM_COPYDATA, NULL, reinterpret_cast<LPARAM>(&copydata));
    }
}
#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QTextCodec * codec = QTextCodec::codecForName("utf-8");
//    a.setApplicationDisplayName("OFD/PDF阅读器");
//    a.setApplicationName("OFD/PDF阅读器");
//    a.setOrganizationName("fzz");
#ifdef Q_OS_WIN
    if(argc > 1){/* 第一个列表是软件路径，第二个是点击的文件路径 */
        QString temp;
        temp = qApp->arguments().at(1).split("\\").join("/");/* 转换为Qt识别的路径 */
        HWND hwnd = NULL;

        QString c_strTitle = "OFD/PDF阅读器";
        LPWSTR path = (LPWSTR)c_strTitle.utf16();  //path = L"SendMessage"
        hwnd = ::FindWindowW(NULL, path);
        if (::IsWindow(hwnd)) {
            onSendMessage(hwnd,temp);
            return 0;
        }

    }
#endif

    a.setWindowIcon(QIcon(":/res/images/logo.png"));

    QPixmap pixmap(":/res/images/logo.png");     //读取图片
    QSplashScreen splash(pixmap); //
    splash.setWindowOpacity(0.8); // 设置窗口透明度

//    QLabel label(&splash);
//    QMovie mv("G.gif");
//    label.setMovie(&mv);
//    mv.start();
//    splash.setMinimumSize(QSize(300,200));
//    splash.setMaximumSize(QSize(300,200));
    splash.show();
    //splash.showMessage("程序正在加载...", Qt::AlignCenter, Qt::black); //显示文字
    splash.showMessage("        程序正在加载...", Qt::AlignVCenter|Qt::AlignLeft, Qt::black); //显示文字

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "DOCReader_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }


    MainWidget w;
    w.show();

    splash.finish(&w); //在主体对象初始化完成后结束启动动画

    if(argc > 1){/* 第一个列表是软件路径，第二个是点击的文件路径 */
        QString temp;
        temp = qApp->arguments().at(1).split("\\").join("/");/* 转换为Qt识别的路径 */
        //qDebug() << "exe param:" << qApp->arguments() << " path: " << temp;
        w.OpenOFDOrPDF(temp);/* 自定义的加载函数 */
    }
    return a.exec();
}
