//
//  Created by zizheng fan on 2024/07/16.
//
#ifndef FZZOBJECT_H
#define FZZOBJECT_H

class FZZObject
{
public:
    FZZObject();
    FZZObject(fz_context * ctx);
    virtual ~FZZObject();
public:
    fz_context * getContext() { return m_CTX; }
    
private:
    bool isFreeCTX;
protected:
    
    fz_context * m_CTX;
};

#endif //FZZOBJECT_H

