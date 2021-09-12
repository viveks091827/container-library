
template <typename T, class C>
class Stack
{
public:
    using m_containerType = C;
    using valueType = T;
    using referenceType = valueType &;
    using pointerType = valueType *;

    void push(valueType data)
    {
        m_container.pushBack(data);
    }

    void pop()
    {
        m_container.popBack();
    }

    bool empty()
    {
        if (m_m_container.size() == 0)
        {
            return true;
        }
        return false;
    }

    referenceType top() {
        return m_container.back();
    }

    int size() {
        return m_container.size();
    }

        private:
        m_containerType m_container;
};