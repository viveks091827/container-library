template <typename T>
struct node {
        T m_data;
        node *m_next;
        node *m_previous;

        node() {
            m_data = 0;
            m_next = nullptr;
            m_previous = nullptr;
        }
};   

template <typename T>
class List {
public: 
    using valueType = T;
    using referenceType = valueType&;
    using pointerType = valueType&;

    List () {
        m_head = nullptr;
        m_tail = nullptr;
    }

    int size() {
        return m_size;
    }

    bool empty (){
        if (m_size == 0) {
            return true;
        }
        return false;
    }

    void insertFront(valueType data) {
        node<T> *temp = new node<T>;
        temp->m_data = data;
        if (m_head == nullptr && m_tail == nullptr) {
            temp->m_previous = temp;
            temp->m_next = temp;
            m_head = temp;
            m_tail = temp;
        }
        else {
            temp->m_next = m_head;
            m_head->m_previous = temp;
            m_head = temp;
            temp->m_previous = m_tail;
            m_tail->m_next = m_head;
        }
        m_size++; 
    }

    void insertEnd(valueType data) {
        node<T> *temp = new node<T>;
        temp->m_data = data;
            if (m_head == nullptr && m_tail == nullptr) {
            temp->m_previous = temp;
            temp->m_next = temp;
            m_head = temp;
            m_tail = temp;
        }
        else {
            m_tail->m_next = temp;
            temp->m_previous = m_tail;
            temp->m_next = m_head;
            m_head->m_previous = temp;
            m_tail = temp;
        }
        m_size++;
    }

    void printList() {
        node <T> *temp = m_head;

        while (temp != m_tail) {
            std::cout << temp->m_data << " ";
            temp = temp->m_next;
        }

        std::cout << m_tail->m_data;

        std::cout << std::endl;
    }

private: 
     node <T> *m_head;
     node <T> *m_tail;
     int m_size = 0;
};