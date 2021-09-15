#include <iostream>

#ifndef __ITERATOR
#define __ITERATOR

template <typename T> 
class Iterator {
public :
    using valueType = T;
    using pointer = valueType*;
    using reference = valueType&;

    Iterator(pointer ptr) {
        
        m_ref = ptr;
    }

    bool operator != (Iterator right) {
        if (m_ref != right.m_ref) {
            return true;
        }
        return false;
    } 
    
    Iterator<T> operator + (int num) {
        m_ref += num;
        return *this;
    }
    
    int operator - (Iterator<T> other) {
        return m_ref - other.m_ref;
    }

    void operator ++ (int) {
        m_ref++;
        return;
    }

    reference operator * () {
        return *m_ref;
    }

private : 
    pointer m_ref;
};


#endif