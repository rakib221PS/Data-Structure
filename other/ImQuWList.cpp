// . Use the push method in the copy constructor.
#include <iostream>
#include <stdexcept>

class Node
{
public:
    int value;
    Node *next;

    Node(int _value, Node *_next = nullptr) : value(_value), next(_next)
    {
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue() : head(nullptr), tail(nullptr)
    {
    }
    bool isEmpty() const
    {
        return head == nullptr;
    }

    void push(int x)
    {
        if (isEmpty())
        {
            head = new Node(x);
            tail = head;
        }
        tail->next = new Node(x);
        tail = tail->next;
    }

    int front()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("Under flow");
        }
        return head->value;
    }

    int pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Under flow");
        }
        if (head->next == nullptr)
        {
            Node *tmp = head;
            int topValue = head->value;
            head = nullptr;
            tail = nullptr;
            delete tmp;
            return topValue;
        }
        Node *tmp = head;
        int topValue = head->value;
        head = head->next;
        delete tmp;
        return topValue;
    }
    void clear()
    {
        while (!isEmpty())
        {
            deleteHead();
        }
    }
    ~Queue()
    {
        clear();
    }

    Queue(const Queue &original) : head(nullptr)
    {
        if (!original.isEmpty())
        {
            head = new Node(original.head->value);
            Node *src = original.head->next;
            Node *dsc = head;
            while (src != nullptr)
            {
                dsc->next = new Node(src->value);
                dsc = dsc->next;
                src = src->next;
            }
            delete src;
            // delete dsc;
        }
    }

private:
    void deleteHead()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
};

int main()
{
    Queue queue;
    for (int i = 0; i < 3; i++)
    {
        queue.push(i);
    }
    std::cout << queue.front();
    Queue copyQueue(queue);
    queue.pop();
    return 0;
}