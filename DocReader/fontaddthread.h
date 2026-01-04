#ifndef FONTADDTHREAD_H
#define FONTADDTHREAD_H

#include <QThread>

class MainWidget;

class FontAddThread : public QThread
{
public:
    FontAddThread(QObject *parent = nullptr);

    void setMainWindwos(MainWidget * mainWindows) {m_MainWidget = mainWindows;}
    void Stop() { isStop = true; }
    bool isRunEnd() { return isEnd;  }
private:
  void run() override;
private:
  MainWidget * m_MainWidget;
  bool isStop;
  bool isEnd;
};

#endif // FONTADDTHREAD_H
