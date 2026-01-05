//
//  Created by zizheng fan on 2022/11/16.
//
#ifndef FZZSES_ESPICTRUEINFO_V4_H
#define FZZSES_ESPICTRUEINFO_V4_H



class FZZSES_ESPictrueInfo_V4
{
public:
    FZZSES_ESPictrueInfo_V4();
    FZZSES_ESPictrueInfo_V4(const unsigned char * data,size_t datalen);
    FZZSES_ESPictrueInfo_V4(const FZZBytes & data);
    FZZSES_ESPictrueInfo_V4(const FZZSES_ESPictrueInfo_V4& obj);
	virtual ~FZZSES_ESPictrueInfo_V4();
public:
    string getType(){return m_type;}
    void setType(string type) { m_type = type; }
    
    FZZBytes getData() {return m_data;}
    void setData( const FZZBytes & data ) { m_data.setData(data.getData(),data.getLen()); }
    
    int getHeight() { return m_height; }
    void setHeight(int height) { m_height = height; }
    
    int getWidth() { return m_width; }
    void setWidth(int width) { m_width = width; }
    
    FZZBytes Encode();
    bool Deccode(const unsigned char * indata,size_t inlenght);
protected:
	
private:

private:
    string m_type;
    FZZBytes m_data;
    //Distance measured in mm
    uint32_t m_width;
    //Distance measured in mm
    uint32_t m_height;
    
};

#endif //FZZSES_ESPICTRUEINFO_V4_H

