#include "iterator.h"

template <typename T, size_t N>
class Array {
public :
    using valueType = T;
    using pointerType = valueType*;
    using referenceType = valueType&;
    using iterator = Iterator<T>;

public : 
    Array () {
        
    }

    int size () {
        return m_size;
    }
    
    int maxSize () {
        return m_maxSize;
    }

    referenceType operator [] (int index) {
        if (index >= m_size) {
            m_size = index+1;
        }
        return m_data[index];
    }

    referenceType at (int index) {
         if (index >= m_size) {
            m_size = index+1;
        }
        return m_data[index];
    }

    referenceType back () {
        return m_data[m_size-1];
    }

    pointerType data () {
        return &m_data;
    }

    bool empty () {
        if (m_size == 0) {
            return true;
        }
        return false;
    }

    referenceType front () {
        return m_data[0];
    }

    void fill (int data) {
        for (int i = 0; i < m_size; i++) {
            m_data[i] = data;
        }
    }

    iterator begin() {
        return iterator(m_data);
    }


    iterator end() {
        return iterator(m_data+m_size);
    }


private :    
    valueType m_data[N];
    int m_size = 0;
    int m_maxSize = N;
    
};


