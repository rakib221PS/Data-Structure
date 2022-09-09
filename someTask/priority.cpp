#include <iostream>

struct Item
{
    int quantity;
    float cost;
    Item *next;

    Item(int _quantity, float _cost, Item *_next = nullptr) : quantity(_quantity), cost(_cost), next(_next) {}
};

class SortedItems
{
    Item *head;
    Item *tail;

public:
    SortedItems() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const
    {
        return (head == nullptr);
    }

    bool highest(const float x) const
    {
        return (x < ((head->quantity) * (head->cost)));
    }

    bool lowestOrEqual(const float x) const
    {
        return (x >= ((tail->quantity) * (tail->cost)));
    }

    void push(int x, float cost)
    {
        Item *tmp = nullptr;
        float priority = x * cost;
        if (isEmpty())
        {
            head = new Item(x, cost);
            tail = head;
        }
        else if (highest(priority))
        {
            tmp = head;
            head = new Item(x, cost);
            head->next = tmp;
        }
        else if (lowestOrEqual(priority))
        {
            tail->next = new Item(x, cost);
            tail = tail->next;
        }
        else
        {
            tmp = head;
            while (tmp->next != nullptr)
            {
                if (priority < ((tmp->next->quantity) * (tmp->next->cost)))
                {
                    Item *AnotherTmp = tmp->next;
                    tmp->next = new Item(x, cost);
                    tmp->next->next = AnotherTmp;
                    break;
                }
                tmp = tmp->next;
            }
        }
    }

    Item *front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        return head;
    }

    int last()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        Item *tmp = head;
        while (tmp->next->next != nullptr)
        {
            tmp = tmp->next;
        }
        int highestProduct = (tail->quantity) * (tail->cost);
        tmp->next = nullptr;
        delete tail;
        tail = tmp;
        return highestProduct;
    }
    // 1 2 3 4 5 null ptr

    void pop_front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Underflow");
        }
        clear();
    }

    ~SortedItems()
    {
        while (head != nullptr)
        {
            clear();
        }
    }

private:
    void clear()
    {
        Item *tmp = head;
        head = head->next;
        delete tmp;
    }
};

int main()
{
    SortedItems it;
    it.push(1, 67.3);
    it.push(3, 1.3);
    it.push(1, 0.3);
    it.push(3, 4.65);
    it.push(1, 67.3);
    it.push(5, 1.3);
    it.push(100, 67.3);
    it.push(3, 1.3);
    std::cout<<it.last()<<std::endl;
    return 0;
}