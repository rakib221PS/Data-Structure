
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
    Node *copy = nullptr;

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
        else
        {
            tail->next = new Node(x);
            tail = tail->next;
        }
    }

    int front()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("Under flow");
        }
        return head->value;
    }

    void pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Under flow");
        }
        if (head->next == nullptr)
        {
            Node *tmp = head;
            head = nullptr;
            tail = nullptr;
            delete tmp;
        }
        else{
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Empty Queue");
        }
        copy = head;

        while (copy != nullptr)
        {
            std::cout << copy->value << " ";
            copy = copy->next;
        }
        std::cout << std::endl;
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

    void rotate(const int x)
    {
        if (isEmpty())
        {
            // throw std::invalid_argument("Trying to evaluate empty memory");
            return;
        }
        for (int i = 0; i < x; i++)
        {
            tail->next = new Node(head->value);
            tail = tail->next;
            pop();
        }
    }

    void shake()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("Trying to evaluate empty memory");
        }
        while (!isEmpty())
        {
            int x = head->value;
            std::cout << x << " ";
            pop();
            rotate(x);
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
    Queue q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    q.print();
    q.rotate(1);
    q.print();
    q.rotate(1);
    q.print();
    q.rotate(2);
    q.print();
    std::cout << "shake" << std::endl;
    q.shake();
    return 0;
}