#include <cmath>
#include <iostream>
#include <stdexcept>
#include <time.h>
struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int v) : value(v),
                  next(nullptr),
                  prev(nullptr) {}
};

class DoubleLinkedList
{
public:
    Node *head;
    Node *tail;
    // write a constructor
    DoubleLinkedList() : head(nullptr), tail(nullptr)
    {
    }

    // write a destructor
    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            Node *delTmp = head;
            head = head->next;
            delete delTmp;
        }
    }
    void printList()
    {
        if (!isEmpty())
        {
            Node *temporary = head;
            while (temporary != nullptr)
            {
                std::cout << temporary->value << " ";
                temporary = temporary->next;
            }
        }
        else
        {
            throw std::runtime_error("Try to read from an empty array");
        }
        std::cout << std::endl;
    }
    bool isEmpty() const
    {
        return (head == nullptr);
    }

    Node *end()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        return tail;
    }

    Node *begin()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        return head;
    }

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
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Trying to delete from an empty memory");
        }
        if (tail == head)
        {
            Node *tmp = head;
            head = nullptr;
            tail = nullptr;
            // std::cout << tmp->value << std::endl;
            delete tmp;
        }
        else
        {
            Node *tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            std::cout << tmp->value << std::endl;
            delete tmp;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Trying to delete from an empty memory");
        }
        if (tail == head)
        {
            Node *tmp = head;
            head = nullptr;
            tail = nullptr;
            // std::cout << tmp->value << std::endl;
            delete tmp;
        }
        else
        {
            Node *tmp = head;
            head = head->next;
            head->prev = nullptr;
            std::cout << tmp->value << std::endl;
            delete tmp;
        }
    }

    bool isRangeAvailable(Node *st)
    {
        Node *tp = head; 
        while (tp != nullptr)
        {
            if (tp == st)
            {
                return true;
            }
            tp = tp->next;
        }
        return false;
    }

    int numberOfNode()
    {
        int number = 0;
        Node *p = head;
        while (p != nullptr)
        {
            p = p->next;
            number++;
        }
        return number;
    }

    void remove(struct Node *Link)
    {
        if (isEmpty())
        {
            throw std::runtime_error("trying to read from an empty memory");
        }
        if (Link->prev == nullptr)
        {
            Node *tmp = Link;
            head = Link->next;
            head->prev = nullptr;
            delete tmp;
        }
        else if (Link->next == nullptr)
        {
            Node *tmp = Link;
            tail = Link->prev;
            tail->next = nullptr;
            delete tmp;
        }
        else
        {
            Node *tmp = Link;
            Link->prev->next = Link->next;
            Link->next->prev = Link->prev;
            delete tmp;
        }
    }

    void insert_before(const int x, Node *ins)
    {
        if (ins != nullptr)
        {
            if (ins != head)
            {
                Node *tmp = head;
                while (tmp != ins->prev)
                {
                    tmp = tmp->next;
                }
                Node *t = new Node(x);
                tmp->next = t;
                t->prev = tmp;
                t->next = ins;
                ins->prev = t;
            }
            else
            {
                Node *tmp = new Node(x);
                ins->prev = tmp;
                tmp->next = ins;
                ins = tmp;
            }
        }
        else
        {
            push_back(x);
        }
    }
    Node *find(Node *from, Node *end, const int x)
    {
        bool isFound = false;
        if (isRangeAvailable(from) && isRangeAvailable(end))
        {
            while (from != end)
            {
                if (from->value == x)
                {
                    isFound = true;
                    break;
                }
                from = from->next;
            }
            if (isFound)
            {
                return from;
            }
            else
            {
                throw std::runtime_error("Elements not found");
            }
        }
        else
        {
            throw std::runtime_error("Range is not available");
        }
        }
    void Fill(Node *from, Node *end, const int x)
    {
        Node *start = from;
        // std::cout<<count<<"->"<<count->value<<std::endl;
        if (isRangeAvailable(from) && isRangeAvailable(end))
        {
            while (start != end)
            {
                start->value = x;
                start = start->next;
            }
        }
        else
        {
            throw std::runtime_error("Range is not available");
        }
    }

    void fill_n(Node *from, const int y, const int x)
    {
        Node *start = from;
        if (!isRangeAvailable(from))
        {
            throw std::runtime_error("Beginning iterator is not available");
        }
        else if (y > numberOfNode())
        {
            throw std::runtime_error("End is out of range");
        }
        else
        {
            int upto = 0;
            while (upto < y)
            {
                start->value = x;
                start = start->next;
                upto++;
            }
        }
    }
    void iota(Node *from, Node *end, int x)
    {
        Node *start = from;
        if (!isRangeAvailable(from) || !isRangeAvailable(end))
        {
            throw std::runtime_error("Range is not available");
        }
        else
        {
            while (start != end)
            {
                start->value = x;
                start = start->next;
                x++;
            }
        }
    }
    void reverse()
    {
        Node *start = head;
        Node *from = head;
        Node *stop = tail;
        int number = 0, upto = 0;
        while (from != stop)
        {
            from = from->next;
            number++;
        }
        while (start != stop && upto <= ceil(number / 2))
        {
            int value = start->value;
            start->value = stop->value;
            stop->value = value;
            start = start->next;
            stop = stop->prev;
            upto++;
        }
    }
    void insert_sorted(const int x)
    {
        if (head == nullptr)
        {
            push_back(x);
        }
        else
        {
            Node *tmp = head;
            int totalNode = 0;
            while (tmp != nullptr)
            {
                totalNode++;
                tmp = tmp->next;
            }
            tmp = head;
            if (totalNode == 1)
            {
                push_back(x);
                sortingAscendingOrder(tmp, totalNode);
            }
            else
            {
                sortingAscendingOrder(tmp, totalNode);
                insertion(tmp, x);
            }
        }
    }

    void sortingAscendingOrder(Node *tmp, int totalNode)
    {
        int alreadySorted = 0;
        while (totalNode--)
        {
            while (tmp->next != nullptr)
            {
                if (tmp->value > tmp->next->value)
                {
                    int val = tmp->value;
                    tmp->value = tmp->next->value;
                    tmp->next->value = val;
                    alreadySorted = 1;
                }
                tmp = tmp->next;
            }
            if (alreadySorted != 1)
            {
                tmp = head;
                break;
            }
            tmp = head;
        }
    }

    void insertion(Node *tmp, const int x)
    {
        int hasDone = 0;
        if (x < tmp->value)
        {
            push_front(x);
            hasDone = 1;
        }
        else
        {
            while (tmp != nullptr)
            {
                if (x < tmp->value)
                {
                    Node *sup = tmp->prev;
                    Node *newNode = new Node(x);
                    sup->next = newNode;
                    sup->next->prev = tmp->prev;
                    tmp->prev = sup->next;
                    sup->next->next = tmp;
                    hasDone = 1;
                    break;
                }
                tmp = tmp->next;
            }
        }

        if (hasDone == 0)
        {
            push_back(x);
        }
    }
};

int main()
{
    DoubleLinkedList DoubleLinkedList, AnotherDoubleLinkedList, OtherDoubleLinkedList, insertionSorted;
    for (int i = 1; i <= 10; i++)
    {
        DoubleLinkedList.push_back(i);
    }
    DoubleLinkedList.printList();
    std::cout << std::endl;

    int i = 0;
    Node *a = DoubleLinkedList.head;
    while (i < 5)
    {
        a = a->next;
        i++;
    }
    DoubleLinkedList.remove(a);
    DoubleLinkedList.printList();

    for (int i = 0; i < 4; i++)
    {
        AnotherDoubleLinkedList.push_back(i);
    }

    int j = 0;
    Node *ba = AnotherDoubleLinkedList.head;
    while (j < 3)
    {
        ba = ba->next;
        j++;
    }

    AnotherDoubleLinkedList.insert_before(-90, ba);
    for (int i = 0; i < 9; i++)
    {
        OtherDoubleLinkedList.push_back(i);
    }

    Node *tmp = OtherDoubleLinkedList.head;
    int start = 0, stop = 0;
    while (start < 2)
    {
        tmp = tmp->next;
        start++;
    }
    stop += start;
    Node *st = tmp;
    while (stop < 7)
    {
        st = st->next;
        stop++;
    }
    Node *anS = st;
    while (stop < 8)
    {
        anS = anS->next;
        stop++;
    }
    Node *f = OtherDoubleLinkedList.find(tmp, st, 3);
    // fill method
    OtherDoubleLinkedList.Fill(tmp, st, 5);
    OtherDoubleLinkedList.printList();
    OtherDoubleLinkedList.fill_n(tmp, 7, -4);
    OtherDoubleLinkedList.printList();
    OtherDoubleLinkedList.iota(tmp, st, 99);
    OtherDoubleLinkedList.printList();
    OtherDoubleLinkedList.reverse();
    OtherDoubleLinkedList.printList();
    insertionSorted.push_back(4);
    insertionSorted.push_back(2);
    insertionSorted.push_back(1);
    insertionSorted.push_back(5);
    insertionSorted.push_back(-1);
    insertionSorted.insert_sorted(3);
    insertionSorted.insert_sorted(4);
    insertionSorted.insert_sorted(4);
    insertionSorted.insert_sorted(-4);
    insertionSorted.insert_sorted(100);
    insertionSorted.insert_sorted(2);
    insertionSorted.insert_sorted(69);
    insertionSorted.insert_sorted(6000);
    insertionSorted.insert_sorted(-8);
    insertionSorted.insert_sorted(48);
    insertionSorted.printList();
    return 0;
}