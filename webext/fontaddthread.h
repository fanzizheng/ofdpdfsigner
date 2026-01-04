#ifndef FONTADDTHREAD_H
#define FONTADDTHREAD_H

#include <QThread>



class FontAddThread : public QThread
{
public:
    FontAddThread(QObject *parent = nullptr);

    //void setMainWindwos(MainWidget * mainWindows) {m_MainWidget = mainWindows;}
    void Stop() { isStop = true; }
    bool isRunEnd() { return isEnd;  }
private:
  void run() override;
private:
  //MainWidget * m_MainWidget;
  bool isStop;
  bool isEnd;
};

//class WebThread : public QThread
//{
//public:
//    WebThread(QObject *parent = nullptr);

//    //void setMainWindwos(MainWidget * mainWindows) {m_MainWidget = mainWindows;}
//    void Stop() { isStop = true; }
//    bool isRunEnd() { return isEnd;  }

//    void setPause( bool pause ) {
//        m_isPause = pause;
//    }

//private:
//  void run() override;
//private:
//  //MainWidget * m_MainWidget;
//  bool isStop;
//  bool isEnd;
//  bool m_isPause;
//};

#endif // FONTADDTHREAD_H
