//
//  Created by zizheng fan on 2022/01/11.
//
#ifndef FZZATOMICINTEGER_H
#define FZZATOMICINTEGER_H
class FZZAtomicInteger
{
public:
    FZZAtomicInteger();
    FZZAtomicInteger(long initialValue);
    FZZAtomicInteger(const FZZAtomicInteger& obj);
    const FZZAtomicInteger& operator=(const FZZAtomicInteger& obj);
    ~FZZAtomicInteger();
public:
    long get() { return m_munber;}
    void set(long newValue) { m_munber = newValue; }
    
    long getAndIncrement() { return m_munber++;}
    long getAndDecrement() { return m_munber--;}
    long getAndAdd(long delta) {  m_munber += delta; return m_munber; }
    long incrementAndGet() {  return ++m_munber; }
    long decrementAndGet() {  return --m_munber; }
    string toString() { return FZZConst::fmt(m_munber);}
private:
    
    
private:
    long m_munber;
};

#endif //FZZATOMICINTEGER_H

