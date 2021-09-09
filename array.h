#include <iostream>
#include "iterator.h"

template <typename T, size_t N>
class Array {
public :
    using valueType = T;
    using pointerType = valueType*;
    using referenceType = valueType&;
    using iterator = Iterator<T>;

public : 
    Array() {
        m_data = new T[N];
    }

    int size() {
        return m_size;
    }

    referenceType operator [] (int index) {
        return m_data[index];
    }

    iterator begin() {
        return iterator(m_data);
    }

    iterator end() {
        return iterator(m_data+m_size);
    }


private :    
    pointerType m_data;
    int m_size = N;
};


