#include <iostream>
#include "iterator.h"

template <typename T>
class Vector {
    public : 
    using valueType = T;
    using pointerType = valueType*;
    using referenceType = valueType&;
    using iterator = Iterator <T>;

    Vector () {
        m_data = new valueType[2];
        m_capacity = 2;
    }

    int size() {
        return m_size;
    }

    void reallocate (int newCapacity) {   
            pointerType newData = new valueType[newCapacity];
            for (int i = 0; i < m_size; i++) {
                newData[i] = m_data[i];
            }
            delete [] m_data;
            m_data = newData;
            m_capacity = newCapacity;
    }

    void pushBack(valueType data) {
        if (m_size == m_capacity) {
            int newCapacity = m_capacity + (m_capacity/2);
            reallocate(newCapacity);
        }

        m_data[m_size++] = data;
    }

    referenceType popBack() {
        if (m_capacity >= 2*m_size) {
            m_capacity /=2;
            reallocate(m_capacity);
        }
        return m_data[--m_size];
    }

    referenceType operator [] (int index) {
        return m_data[index];
    }

    void assign (int size, int data) {
        if (size >= m_capacity) {
        int newCapacity = m_capacity + (m_capacity/2);
            reallocate(newCapacity);
        }

        for (int i = 0; i < size; i++) {
            m_data[i] = data;
        }
        m_size = size;
    }

    void assign (int data, iterator begin, iterator end) {
        int size = end - begin;
        if (size >= m_size) {
            int newCapacity = m_capacity + m_capacity/2;
            reallocate(newCapacity);
        }
        if (size < m_size) {
            reallocate(size);
        }

        begin = iterator(m_data);
        end = iterator(m_data + size);

        for (iterator it = begin; it != end; it++) {
            *it = data;
        }

        m_size = end - begin;
    }

    iterator begin() {
        return iterator(m_data);
    }

    iterator end() {
        return iterator(m_data + m_size);
    }

    private : 
    pointerType m_data;
    int m_size = 0;
    int m_capacity = 0;
};