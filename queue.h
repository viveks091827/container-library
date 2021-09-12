template<typename T, class C>
class Queue {
    public: 
        using containerType = C;
        using valueType = T;
        using referenceType = valueType&;
        using pointerType = valueType*;

        int size() {
            return m_container.size();
        }

        bool empty() {
            if(m_container.size() == 0) {
                return true;
            }
            return false;
        }

        void push(valueType data) {
            m_container.pushBack(data);
        }

        void pop() {
            m_front++;
        }

        referenceType front() {
            return m_container.at(m_front);
        }

        referenceType back() {
            return m_container.back();
        }
    private: 
        containerType m_container;
        int m_front = 0;
};