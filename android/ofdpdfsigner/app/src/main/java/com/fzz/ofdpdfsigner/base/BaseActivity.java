package com.fzz.ofdpdfsigner.base;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Toast;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.ConcurrentLinkedQueue;


public class BaseActivity extends AppCompatActivity implements OnClickListener, OnItemClickListener {
    public static ConcurrentLinkedQueue<Activity> sAllActivitys = new ConcurrentLinkedQueue<Activity>();
    //	public LinkedList<OKhttp3_GAPIUtil> httpUtils = new LinkedList<OKhttp3_GAPIUtil>();
    protected Context selfcontext;
    protected long lastClickTime = 0;
    private static Boolean isExit = false;
    protected boolean isCheckNet = false;
    public static Activity g_CurrActivity = null;

    private List<Integer> NoFastDoubleClick = new ArrayList<Integer>();

    public void Add_NoFastDoubleClick(int id)
    {
        NoFastDoubleClick.add(id);
    }

    public Context getSelfContext()
    {
        return selfcontext;
    }

//    public MyApplication getAPP()
//    {
//        return app;
//    }

    @Override
    public void onCreate(Bundle savedInstanceState, PersistableBundle persistentState) {
        super.onCreate(savedInstanceState, persistentState);

        sAllActivitys.add(this);

        //app=(MyApplication)this.getApplication();
        //logger = Logger.getLogger(this.getClass());
        hideBottomUIMenu();
        //去掉崩溃异常拦截，是因为当app为桌面app时，不能自动重新启动。
        Thread.setDefaultUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() {
            public void uncaughtException(Thread thread, Throwable ex) {
                Writer result = new StringWriter();
                PrintWriter printWriter = new PrintWriter(result);
                ex.printStackTrace(printWriter);
                String stacktrace = result.toString();

                printWriter.close();
                //logger.info("BaseActivity Exception:"+stacktrace);
                restart();
            }

        });
        selfcontext = this;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // TODO Auto-generated method stub
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        sAllActivitys.add(this);
        hideBottomUIMenu();

        //app=(MyApplication)this.getApplication();
        //logger = Logger.getLogger(this.getClass());
        //去掉崩溃异常拦截，是因为当app为桌面app时，不能自动重新启动。
        Thread.setDefaultUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() {
            public void uncaughtException(Thread thread, Throwable ex) {
                Writer result = new StringWriter();
                PrintWriter printWriter = new PrintWriter(result);
                ex.printStackTrace(printWriter);
                String stacktrace = result.toString();

                printWriter.close();
                //logger.info("BaseActivity Exception:"+stacktrace);

                restart();
            }

        });
        selfcontext = this;
    }

    @Override
    protected void onResume() {
        super.onResume();
        g_CurrActivity = this;
        hideBottomUIMenu();
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            hideBottomUIMenu();
        }
    }

    public String GetErrorString(String data, String msg)
    {
        String errMsg=msg + "请检查网络连接。\"" + data + "\"";
        //logger.error(errMsg);
        return errMsg;
    }

    protected boolean isFastDoubleClick(long timelong) {
        long time = System.currentTimeMillis();
        long timeD = time - lastClickTime;
        Log.d("时间差", timeD + "");
        if (timeD > timelong) {
            lastClickTime = time;
            return true;
        }
        return false;
    }

    @Override
    public void onClick(View v) {

        if ( !NoFastDoubleClick.contains(v.getId()) ) {
            if (!isFastDoubleClick(2000)) {
                return;
            }
        }

//        if ( isCheckNet && !NetUtil.hasNetwork( selfcontext ) ) {
//            ProgressAlertDialog.error(selfcontext, 3000, "无网络连接可用!\n请在[设置]中开启网络!");
//
//            return;
//        }

        onClickView(v);
    }

    protected void onClickView(View v)
    {

    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        // TODO Auto-generated method stub

    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        switch (resultCode) {
            case ConfigConstant.GOTOSTART:
                Intent mIntent = new Intent();
                setResult(ConfigConstant.GOTOSTART, mIntent);
                finish();
                break;
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();

        sAllActivitys.remove(this);
    }

    public static void finishAll() {
        //logger.info("finishAll");
        for(Activity activity : sAllActivitys) {

            activity.finish();
        }

        sAllActivitys.clear();
    }

    public static void finishOther(BaseActivity otheractivity)
    {
        //logger.info("finishOther:"+otheractivity.getClass().getSimpleName());
        for(Activity activity : sAllActivitys) {
            if ( !activity.getClass().getSimpleName().equals(otheractivity.getClass().getSimpleName()) ) {
                //logger.info("finish "+activity.getClass().getSimpleName());

                activity.finish();
            }
        }
        sAllActivitys.clear();
        sAllActivitys.add(otheractivity);
    }

    public static void finishActivity(String ActivityName)
    {
        //logger.info("finishOther:"+ActivityName);

        for(Activity activity : sAllActivitys) {
            //logger.info("finishOther2:"+activity.getClass().getSimpleName());
            if ( activity.getClass().getSimpleName().equals(ActivityName) ) {
                //logger.info("finish "+activity.getClass().getSimpleName());
                activity.finish();
                sAllActivitys.remove(activity);
            }
        }

    }

    public boolean findActivity(String otheractivity)
    {
        //logger.info("findActivity");
        boolean isTF = false;
        for(Activity activity : sAllActivitys) {
            if ( activity.getClass().getSimpleName().equals(otheractivity) ) {
                isTF = true;
                break;
            }
        }
        return isTF;
    }

    public void ExitOnce()
    {
        finishAll();
    }

    public void restart()
    {
    }

    public  void Exit() {

        Timer tExit = null;
        if (isExit == false) {
            isExit = true; // 准备退出
            Toast.makeText(this, "再按一次退出程序", Toast.LENGTH_SHORT).show();
            tExit = new Timer();
            tExit.schedule(new TimerTask() {
                @Override
                public void run() {
                    isExit = false; // 取消退出
                }
            }, 2000); // 如果2秒钟内没有按下返回键，则启动定时器取消掉刚才执行的任务

        } else {
            ExitOnce();

        }
    }

    public void OnBack()
    {
        this.setResult(ConfigConstant.ONBACKPRESSED);
        finish();
    }

    public boolean onKeyDown(int keyCode, KeyEvent event)
    {
        if (keyCode == KeyEvent.KEYCODE_BACK && event.getRepeatCount() == 0)
        {
            OnBack();


            return true;
        }

        return super.onKeyDown(keyCode, event);
    }

    public View $(int id){
        return findViewById(id);
    }

    public void ExceptionToLog(Exception e)
    {
        Writer result = new StringWriter();
        PrintWriter printWriter = new PrintWriter(result);
        e.printStackTrace(printWriter);
        String stacktrace = result.toString();
        printWriter.close();
        //logger.info(stacktrace);
    }

    protected void hideBottomUIMenu() {
    }
}
