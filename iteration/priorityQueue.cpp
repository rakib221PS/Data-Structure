#include <iostream>

struct Customer
{
    int priority;
    std::string name;
    Customer *next;

    Customer(int _value, std::string _name, Customer *_next = nullptr) : priority(_value), name(_name), next(_next) {}
};

class Information
{
    Customer *head;
    Customer *tail;

public:
    Information() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const
    {
        return (head == nullptr);
    }

    bool highest(const int x) const
    {
        return (x > head->priority);
    }

    bool lowestOrEqual(const int x) const
    {
        return (x <= tail->priority);
    }

    void push(int x, std::string name)
    {
        Customer *tmp = nullptr;
        if (isEmpty())
        {
            head = new Customer(x, name);
            tail = head;
        }
        else if (highest(x))
        {
            tmp = head;
            head = new Customer(x, name);
            head->next = tmp;
        }
        else if (lowestOrEqual(x))
        {
            tail->next = new Customer(x, name);
            tail = tail->next;
        }
        else
        {
            tmp = head;
            while (tmp->next != nullptr)
            {
                if (x > tmp->next->priority)
                {
                    Customer *AnotherTmp = tmp->next;
                    tmp->next = new Customer(x, name);
                    tmp->next->next = AnotherTmp;
                    break;
                }
                tmp = tmp->next;
            }
        }
    }

    Customer *front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        return head;
    }

    void pop_front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        clear();
    }

    ~Information()
    {
        while (head != nullptr)
        {
            clear();
        }
    }

private:
    void clear()
    {
        Customer *tmp = head;
        head = head->next;
        delete tmp;
    }
};

int main()
{
    Information human;
    human.push(1, "Norman Nobody");
    human.push(60, "Marilyn Monroe");
    human.push(100, "Bangabandhu Sheikh Mujibur Rahman");
    human.push(100, "Marie Curie");
    human.push(80, "Freddie Mercury");
    human.push(90, "Martin Luther King");
    human.push(1, "Samuel Someguy");
    human.push(90, "Mahatma Gandhi");
    human.push(100, "Albert Einstein");
    human.push(80, "John Lennon");

    Customer *c;
    c = human.front();
    std::cout << c->priority << ", " << c->name << std::endl;
    human.pop_front();
    c = human.front();
    std::cout << c->priority << ", " << c->name << std::endl;
    return 0;
}