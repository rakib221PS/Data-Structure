#include <iostream>
#include <stdexcept>

struct Item
{
    int quantity;
    float cost;
    Item *prev;
    Item *next;

    Item(int _quantity, float _cost) : quantity(_quantity), cost(_cost),
                                       prev(nullptr), next(nullptr)
    {
    }
};

class ItemList
{
    Item *head;
    Item *tail;

public:
    ItemList() : head(nullptr), tail(nullptr)
    {
    }

    bool isEmpty() const
    {
        return (head == nullptr);
    }

    bool isHighestPriority(const float _priority) const
    {
        return (_priority < ((head->quantity) * (head->cost)));
    }

    bool isLowestPriority(const float _priority) const
    {
        return (_priority >= ((tail->quantity) * (tail->cost)));
    }

    void push(const int x, const float y)
    {
        float priority = x * y;
        if (isEmpty())
        {
            head = new Item(x, y);
            tail = head;
        }
        else if (isHighestPriority(priority))
        {
            Item *tmp = new Item(x, y);
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
        else if (isLowestPriority(priority))
        {
            Item *tmp = new Item(x, y);
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        else
        {
            Item *tmp = head;
            while(tmp->next != nullptr){
                if (priority < ((tmp->next->quantity) * (tmp->next->cost)))
                {
                    Item *anotherTmp = tmp->next;
                    Item *newTmp = new Item(x, y);
                    tmp->next = newTmp;
                    newTmp->prev = tmp;
                    newTmp->next = anotherTmp;
                    anotherTmp->prev = newTmp;
                    break;
                }
                tmp = tmp->next;
            }
        }
        
    }

    int last(){
        if (isEmpty())
        {
            throw std::runtime_error("last() call empty memory! Underflow!");
        }
        int highestProduct = tail->quantity * tail->cost;
        if (head == tail)
        {
            Item *tmp = head;
            head = nullptr;
            tail = nullptr;
            delete tmp;
        }
        else
        {
            Item *tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
        }
        return highestProduct;
    }
};

int main()
{
    ItemList priority;
    priority.push(3, 4);
    priority.push(1, 2);
    priority.push(3, 12);
    priority.push(4, 20);
    priority.push(3, 15);
    priority.push(1, 2);
    std::cout<<priority.last()<<std::endl;
    return 0;
}