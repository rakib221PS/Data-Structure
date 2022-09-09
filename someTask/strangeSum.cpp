#include <iostream>
#include <vector>

struct Node
{
    int number;
    Node *prev;
    Node *next;

    Node(int _number) : number(_number),
                        prev(nullptr),
                        next(nullptr) {}
};

struct StrangeSum
{
    Node *head;
    Node *tail;

    StrangeSum() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const { return (head == nullptr); }

    void push_back(const int x)
    {
        if (isEmpty())
        {
            head = new Node(x);
            tail = head;
        }
        else
        {
            Node *tmp = new Node(x);
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
    }

    void push_front(const int x)
    {
        if (isEmpty())
        {
            head = new Node(x);
            tail = head;
        }
        else
        {
            Node *tmp = new Node(x);
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("front() called empty memory! Underflow!");
        }

        if (head == tail)
        {
            Node *tmp = head;
            head = nullptr;
            tail = nullptr;
            delete tmp;
        }
        else
        {
            Node *tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("back() called empty memory! Underflow!");
        }
        if (head == tail)
        {
            Node *tmp = head;
            head = nullptr;
            tail = nullptr;
            delete tmp;
        }
        else
        {
            Node *tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
        }
    }

    int front(){
        if (isEmpty())
        {
            throw std::runtime_error("empty memory!");
        }
        return head->number;
    }

    int back(){
        if (isEmpty())
        {
            throw std::runtime_error("empty memory!");
        }
        return tail->number;
    }

    ~StrangeSum()
    {
        while (head != nullptr)
        {
            Node *delTmp = head;
            head = head->next;
            delete delTmp;
        }
    }
};

int strange_sum(const std::vector<int>vec)
{
    StrangeSum calculation;
    int sum = 0;
    int vectorSize = vec.size();
    if (vectorSize < 1)
    {
        throw std::runtime_error("Vector is empty!");
    }
    else
    {
        for (int i = 0; i < vectorSize; i++)
        {
            if (vec[i] < 0)
            {
                calculation.push_back(vec[i]);
            }
            else
            {
                calculation.push_front(vec[i]);
            }
        }
        if (calculation.isEmpty())
        {
            throw std::runtime_error("memory is empty!");
        }
        while (calculation.head != nullptr && calculation.head->number > 0 && calculation.tail->number < 0)
        {
            calculation.pop_front();
            calculation.pop_back();
        }
        
        Node *tmp = calculation.head;
        while (tmp != nullptr)
        {
            sum += tmp->number;
            tmp = tmp->next;
        }
    }
    return sum;
}

int main()
{
    {
        std::vector xs = {-1, 2};
        std::cout << strange_sum(xs) << std::endl;
    }

    {
        std::vector xs = {1, -1, 2};
        std::cout << strange_sum(xs) << std::endl;
    }

    {
        std::vector xs = {-1, 1, -1, 2};
        std::cout << strange_sum(xs) << std::endl;
    }

    {
        std::vector xs = {1, 1, 1, 1, 1, 1};
        std::cout << strange_sum(xs) << std::endl;
    }

    {
        std::vector xs = {-1, 1, 1, 1, 1, -5};
        std::cout << strange_sum(xs) << std::endl;
    }

    {
        std::vector xs = {1, -1, -2, 1, -5, -5};
        std::cout << strange_sum(xs) << std::endl;
    }

    return 0;
}