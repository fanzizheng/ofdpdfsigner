
#ifndef RESTFULSERVER_H
#define RESTFULSERVER_H


#include "Util.h"
#include "ofdpdfsignerproxy.h"

extern OFDPDFSignerProxy g_OFDPDFSignerProxy;
extern QList<QString> g_SystemFontFiles;
extern QString g_root_dir;
extern QByteArray g_root_dir_Byte;

extern QString g_Server_Url;

extern const char *s_http_addr;
extern int timeout;

void process(struct mg_connection *c, int ev, void *ev_data, void *fn_data);
void DocView_SetServerUrl(mg_connection *c,const struct mg_http_message *hm);
void DocView_OpenFile(mg_connection *c,const struct mg_http_message *hm);
void DocView_OpenFile_Local(mg_connection *c,const struct mg_http_message *hm);
void DocView_GetPage(mg_connection *c,const struct mg_http_message *hm);
void DocView_GetFileData(mg_connection *c,const struct mg_http_message *hm);
void DocView_SaveAs(mg_connection *c,const struct mg_http_message *hm);
void DocView_Print(mg_connection *c,const struct mg_http_message *hm);
void DocView_Stamp_Ride(mg_connection *c,const struct mg_http_message *hm);
void DocView_Stamp_Keyword(mg_connection *c,const struct mg_http_message *hm);
void DocView_Stamp_Pos(mg_connection *c,const struct mg_http_message *hm);
void DocView_Stamp_Verify(mg_connection *c,const struct mg_http_message *hm);

void DocView_AddWaterMark(mg_connection *c,const struct mg_http_message *hm);

#endif //RESTFULSERVER_H

