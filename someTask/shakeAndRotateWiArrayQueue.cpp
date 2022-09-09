#include <iostream>
#include <stdexcept>

class Queue
{
    public:
    int capacity;
    int elements;
    int first;
    int *mem;

public:
    Queue() : capacity(10),
              elements(0),
              first(0),
              mem(new int[capacity])
    {
    }

    ~Queue()
    {
        delete[] mem;
    }

    bool empty()
    {
        return (elements == 0);
    }
    bool isFull()
    {
        return (capacity == elements);
    }
    void push(int x)
    {
        if (isFull())
        {
            int *newMem = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newMem[i] = mem[i];
            }
            delete[] mem;
            mem = newMem;
            capacity *= 2;
        }

        int insertion_location = (first + elements) % capacity;

        mem[insertion_location] = x;

        elements++;
    }

    void pop()
    {
        if (empty())
        {
            throw std::runtime_error("Trying to delete from an empty queue");
        }
        first = (first + 1) % capacity;
        elements--;
    }

    int front()
    {
        if (empty())
        {
            throw std::runtime_error("Trying to get element from an empty queue");
        }

        return mem[first];
    }

    int last()
    {
        if (empty())
        {
            throw std::runtime_error("Trying to get element from an empty queue");
        }
        return mem[elements];
    }
};

int main()
{
    Queue q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    return 0;
}
