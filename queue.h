#include "algorithm.h"

template <typename T, class C>
class Queue
{
public:
    using containerType = C;
    using valueType = T;
    using referenceType = valueType &;
    using pointerType = valueType *;

    int size()
    {
        return m_container.size();
    }

    bool empty()
    {
        if (m_container.size() == 0)
        {
            return true;
        }
        return false;
    }

    void push(valueType data)
    {
        m_container.pushBack(data);
    }

    void pop()
    {
        m_front++;
    }

    referenceType front()
    {
        return m_container.at(m_front);
    }

    referenceType back()
    {
        return m_container.back();
    }

private:
    containerType m_container;
    int m_front = 0;
};

template <typename T, class C, class A>
class PriorityQueue
{
public:
    using valueType = T;
    using container = C;
    using algorithm = A;

    int size()
    {
        return m_container.size();
    }

    void buildHeap(int node)
    {
        int parent = (node - 1) / 2;
        if (m_algo.compair(m_container[node], m_container[parent])) {
            valueType temp = m_container[parent];
            m_container[parent] = m_container[node];
            m_container[node] = temp;
            if (parent > 0)
            {
                buildHeap(parent);
            }
        }
    }

    void push(valueType data)
    {
        m_container.pushBack(data);
        buildHeap(m_container.size() - 1);
    }

    void heapify(int parent)
    {
        int leftChild = (parent * 2) + 1;
        int rightChild = (parent * 2) + 2;
        int largerNode = parent;

        if (leftChild < m_container.size() && m_algo.compair(m_container[leftChild], m_container[rightChild]))
        {
            largerNode = leftChild;
        }

        if (rightChild < m_container.size() && m_algo.compair(m_container[rightChild], m_container[largerNode]))
        {
            largerNode = rightChild;
        }

        if (largerNode != parent)
        {
            valueType temp = m_container[parent];
            m_container[parent] = m_container[largerNode];
            m_container[largerNode] = temp;
            heapify(largerNode);
        }
    }

    void pop()
    {
        m_container.front() = m_container.back();
        m_container.popBack();
        heapify(0);
    }

    valueType top() {
        return m_container.front();
    }

    bool empty() {
        if (m_container.size() == 0) {
            return true;
        }
        return false;
    }

private:
    container m_container;
    algorithm m_algo;
};