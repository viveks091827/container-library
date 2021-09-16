template <typename T>
struct node {
        T m_data;
        node *m_next;

        node() {
            m_data = 0;
            m_next = nullptr;
        }
};   

template <typename T>
class ForwordList {
public: 
    using valueType = T;
    using referenceType = valueType&;
    using pointerType = valueType&;

    ForwordList () {
        m_head = nullptr;
        m_tail = nullptr;
    }

    int size() {
        return m_size;
    }

    bool empty() {
        if (m_size == 0) {
            return true;
        }
        return false;
    }

    void clear () {
        node<T> * temp = m_head;
        node<T> *nextNode;
        while (temp) {
            nextNode = temp->m_next;
            delete temp;
            temp = nextNode;
        }
        m_head = nullptr;
        m_tail = nullptr;
    }

    void insertFront(valueType data) {
        node<T> *temp = new node<T>;
        temp->m_data = data;
        temp->m_next = m_head;
        m_head = temp;
        if (m_tail == nullptr) {
            m_tail = temp;
        }
        m_size++;
    }

    void insertEnd(valueType data) {
        node<T> *temp = new node<T>;
        temp->m_data = data;
        if (m_head == nullptr && m_tail == nullptr) {
            m_head = temp;
            m_tail = temp;
        }
        else {
            m_tail->m_next = temp;
            m_tail = temp;
        }
        m_size++;
    }

    void printList() {
        node <T> *temp = m_head;

        while (temp != nullptr) {
            std::cout << temp->m_data << " ";
            temp = temp->m_next;
        }

        std::cout << std::endl;
    }

private: 
     node <T> *m_head;
     node <T> *m_tail;
     int m_size = 0;
};