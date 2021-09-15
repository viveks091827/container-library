
#include "array.h"

template <typename T>
class Deque
{
public:
    using valueType = T;
    using referenceType = valueType &;
    using poinerType = valueType *;

    Deque()
    {
        m_deques[10] = new Array<valueType, 10>;
        m_leftArray = 10;
        m_rightArray = 10;
    }

    int size()
    {
        return m_size;
    }

    valueType frontEle()
    {
        try
        {
            if (m_front == -1 && m_front == -1)
            {
                throw(-1);
            }
        }
        catch (int x)
        {
            std::cout << "Empty queue // Error code: ";
            return x;
        }
        return (*m_deques[m_leftArray])[m_front];
    }

    valueType endEle()
    {

        try
        {
            if (m_front == -1 && m_front == -1)
            {
                throw(-1);
            }
        }
        catch (int x)
        {
            std::cout << "Empty queue // Error code: ";
            return x;
        }
        return (*m_deques[m_rightArray])[m_end];
    }

    void pushFront(valueType data)
    {
        if (m_front == -1 && m_end == -1)
        {
            m_front = 0;
            m_end = 0;
            (*m_deques[m_leftArray])[m_front] = data;
        }
        else
        {
            if (m_front == 0)
            {
                m_front = 10;
                m_leftArray--;
                m_deques[m_leftArray] = new Array<valueType, 10>;
            }
            (*m_deques[m_leftArray])[--m_front] = data;
        }
        m_size++;
    }

    void popFront()
    {
        if (m_leftArray == m_rightArray)
        {
            if (m_front == -1 && m_end == -1)
            {
                return;
            }
            if (m_front == m_end)
            {
                m_front = -1;
                m_end = -1;
            }
            else if (m_front < m_end)
            {
                m_front++;
            }
        }
        else
        {
            if (m_front == -1)
            {
                std::cout << "empty" << std::endl;
            }

            else if (m_front < 9)
            {
                m_front++;
            }

            else if (m_front == 9)
            {
                delete[] m_deques[m_leftArray++];
                m_front = 0;
            }
        }
        m_size--;
    }

    void pushEnd(valueType data)
    {
        if (m_front == -1 && m_end == -1)
        {
            m_front = 0;
            m_end = 0;
            (*m_deques[m_rightArray])[m_end] = data;
        }
        else
        {
            if (m_end == 9)
            {
                m_end = -1;
                m_rightArray++;
                m_deques[m_rightArray] = new Array<valueType, 10>;
            }
            (*m_deques[m_rightArray])[++m_end] = data;
        }
        m_size++;
    }

    void popEnd()
    {
        if (m_leftArray == m_rightArray)
        {
            if (m_front == -1 && m_end == -1)
            {
                return;
            }
            if (m_front == m_end)
            {
                m_front = -1;
                m_end = -1;
            }
            else if (m_front < m_end)
            {
                m_end--;
            }
        }
        else
        {
            if (m_end == -1)
            {
                std::cout << "empty" << std::endl;
                return;
            }

            else if (m_end > 0)
            {
                m_end--;
            }

            else if (m_end == 0)
            {
                delete[] m_deques[m_rightArray--];
                m_end = 9;
            }
        }
        m_size--;
    }

private:
    Array<valueType, 10> *m_deques[20];
    int m_leftArray;
    int m_rightArray;
    int m_front = -1;
    int m_end = -1;
    int m_size = 0;
};