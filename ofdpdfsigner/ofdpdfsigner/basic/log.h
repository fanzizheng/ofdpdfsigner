
//
//  Created by zizheng fan on 2021/11/24.
//
#ifndef _LOG_H_
#define _LOG_H_

//spdlog
#define DEBUGLOG

#ifdef ANDROID
    #ifdef DEBUGLOG
        #undef DEBUGLOG
    #endif
#endif

#ifdef HARMONYOS
    #ifdef DEBUGLOG
        #undef DEBUGLOG
    #endif
#endif


//#define WRITELOGFILE
//ps -ef|grep java
//pmap -x 13462 | grep libofdcreate.so

#ifdef DEBUGLOG

    #include <stdio.h>
    #include <time.h>
    #include <sys/timeb.h>

    #ifdef __APPLE__
        #define LOG_OUTPUT_PATH "/Users/fzz/work/cpp/ofd/tmp/imageconverter/ofd.log"
    #elif __linux__
        #define LOG_OUTPUT_PATH "/home/zhtapp/lcap-ess-application/ofd.log"
    #else
        #define LOG_OUTPUT_PATH "d:/ofd.log"
    #endif

    #define LOG()	\
        do{										\
            printf("[%s][%s][%d]\n", __FILE__, __FUNCTION__, __LINE__);	\
        }while(0)
    #ifdef _MSC_VER

    #define LOG2(format, ...) \
        do{										\
            struct timeb raw_time;                        \
            ftime(&raw_time);                        \
            char timestamp[30] = {0};                        \
            struct tm tm_loc;           \
            localtime_s(&tm_loc,&raw_time.time);                        \
            sprintf(timestamp, "%4d-%02d-%02d %02d:%02d:%02d.%03d",tm_loc.tm_year + 1900, tm_loc.tm_mon + 1, tm_loc.tm_mday, tm_loc.tm_hour, tm_loc.tm_min, tm_loc.tm_sec, raw_time.millitm);                        \
            printf("[%s][%s][%s][%d]:",timestamp, __FILE__, __FUNCTION__, __LINE__);	\
            printf(format, ##__VA_ARGS__); \
            printf("\n");				\
        }while(0)
    #else
    #define LOG2(format, ...) \
        do{										\
            struct timeb raw_time;                        \
            ftime(&raw_time);                        \
            char timestamp[30] = {0};                        \
            struct tm tm_loc;           \
            localtime_r(&raw_time.time, &tm_loc);                        \
            sprintf(timestamp, "%4d-%02d-%02d %02d:%02d:%02d.%03d",tm_loc.tm_year + 1900, tm_loc.tm_mon + 1, tm_loc.tm_mday, tm_loc.tm_hour, tm_loc.tm_min, tm_loc.tm_sec, raw_time.millitm);                        \
            printf("[%s][%s][%s][%d]:",timestamp, __FILE__, __FUNCTION__, __LINE__);	\
            printf(format, ##__VA_ARGS__); \
            printf("\n");				\
        }while(0)
    #endif

    #define LOGF()	\
        do{										\
            FILE *fp = NULL;					\
            fp = fopen(LOG_OUTPUT_PATH, "a");	\
            if(NULL != fp)						\ {									\ fprintf(fp, "[%s][%s][%d]\n", __FILE__, __FUNCTION__, __LINE__);	\ fflush(fp);						\ fclose(fp);						\
            }									\
        }while(0)

    #ifdef _MSC_VER

    #define LOGF2(format, ...) \
        do{										\
            FILE *fp = NULL;					\
            fp = fopen(LOG_OUTPUT_PATH, "a");	\
            if(NULL != fp)						\
            {									\
                struct timeb raw_time;                        \
                ftime(&raw_time);                        \
                char timestamp[30] = {0};                        \
                struct tm tm_loc;           \
                localtime_s(&tm_loc,&raw_time.time);                        \
                sprintf(timestamp, "%4d-%02d-%02d %02d:%02d:%02d.%03d",tm_loc.tm_year + 1900, tm_loc.tm_mon + 1, tm_loc.tm_mday, tm_loc.tm_hour, tm_loc.tm_min, tm_loc.tm_sec, raw_time.millitm);                        \
                fprintf(fp, "[%s][%s][%s][%d]:",timestamp,__FILE__, __FUNCTION__, __LINE__);    \
                fprintf(fp, format, ##__VA_ARGS__); \
                fprintf(fp, "\n");				\
                fflush(fp);						\
                fclose(fp);						\
            }									\
        }while(0)

    #else
    #define LOGF2(format, ...) \
        do{										\
            FILE *fp = NULL;					\
            fp = fopen(LOG_OUTPUT_PATH, "a");	\
            if(NULL != fp)						\
            {									\
                struct timeb raw_time;                        \
                ftime(&raw_time);                        \
                char timestamp[30] = {0};                        \
                struct tm tm_loc;           \
                localtime_r(&raw_time.time, &tm_loc);                        \
                sprintf(timestamp, "%4d-%02d-%02d %02d:%02d:%02d.%03d",tm_loc.tm_year + 1900, tm_loc.tm_mon + 1, tm_loc.tm_mday, tm_loc.tm_hour, tm_loc.tm_min, tm_loc.tm_sec, raw_time.millitm);                        \
                fprintf(fp, "[%s][%s][%s][%d]:",timestamp,__FILE__, __FUNCTION__, __LINE__);    \
                fprintf(fp, format, ##__VA_ARGS__); \
                fprintf(fp, "\n");				\
                fflush(fp);						\
                fclose(fp);						\
            }									\
        }while(0)
    #endif

#else
    #define LOG()
    #define LOG2(format, ...)
    #define LOGF()
    #define LOGF2(format, ...)
#endif //DEBUGLOG

#ifdef WRITELOGFILE
    #define DLOG(format, ...) LOGF2(format, ##__VA_ARGS__)
#else
    #define DLOG(format, ...) LOG2(format, ##__VA_ARGS__)
#endif

#endif /* _LOG_H_ */

