#include "iterator.h"

template <typename T>
class Vector
{
public:
    using valueType = T;
    using pointerType = valueType *;
    using referenceType = valueType &;
    using iterator = Iterator<T>;

    Vector()
    {
        m_data = new valueType[2];
        m_capacity = 2;
    }

    int size()
    {
        return m_size;
    }

    void reallocate(int newCapacity)
    {
        pointerType newData = new valueType[newCapacity];
        for (int i = 0; i < m_size; i++)
        {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }

    void pushBack(valueType data)
    {
        if (m_size == m_capacity)
        {
            int newCapacity = m_capacity + (m_capacity / 2);
            reallocate(newCapacity);
        }

        m_data[m_size++] = data;
    }

    referenceType popBack()
    {
        try
        {
            if (m_size < 1)
            {
                throw -1;
            }
            if (m_capacity >= 2 * m_size)
            {
                m_capacity /= 2;
                reallocate(m_capacity);
            }
            
        }
        catch (int error)
        {
            std::cout << "array is empty" << std::endl;
        }
        return m_data[--m_size];
    }

    referenceType operator[](int index)
    {
        return m_data[index];
    }

    referenceType at(int index)
    {
        return m_data[index];
    }

    referenceType back()
    {
        return m_data[m_size - 1];
    }

    valueType capacity()
    {
        return m_capacity;
    }

    void clear()
    {
        m_size = 0;
    }

    pointerType data()
    {
        return m_data;
    }

    bool empty()
    {
        if (m_size == 0)
        {
            return true;
        }
        return false;
    }

    referenceType front()
    {
        return m_data[0];
    }

    void resize(int size, int data)
    {
        if (m_size < size)
        {
            if (size >= m_capacity)
            {
                reallocate(size + size / 2);
            }
            for (m_size; m_size < size; m_size++)
            {
                m_data[m_size] = data;
            }
        }
        m_size = size;
    }

    void resize(int size)
    {
        if (m_size < size)
        {
            if (size >= m_capacity)
            {
                reallocate(size + size / 2);
            }
            for (m_size; m_size <= size; m_size++)
            {
                m_data[m_size] = 0;
            }
        }
        m_size = size;
    }

    void shrinkToFit()
    {
        reallocate(m_size);
        m_capacity = m_size;
    }

    void assign(int size, int data)
    {
        if (size >= m_capacity)
        {
            int newCapacity = m_capacity + (m_capacity / 2);
            reallocate(newCapacity);
        }

        for (int i = 0; i < size; i++)
        {
            m_data[i] = data;
        }
        m_size = size;
    }

    void assign(int data, iterator begin, iterator end)
    {
        int size = end - begin;
        if (size >= m_size)
        {
            int newCapacity = m_capacity + m_capacity / 2;
            reallocate(newCapacity);
        }
        if (size < m_size)
        {
            reallocate(size);
        }

        begin = iterator(m_data);
        end = iterator(m_data + size);

        for (iterator it = begin; it != end; it++)
        {
            *it = data;
        }

        m_size = end - begin;
    }

    iterator begin()
    {
        return iterator(m_data);
    }

    iterator end()
    {
        return iterator(m_data + m_size);
    }

    ~Vector() {
        delete[] m_data;
    }

private:
    pointerType m_data;
    int m_size = 0;
    int m_capacity = 0;
};