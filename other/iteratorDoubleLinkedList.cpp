#include <iostream>

struct Node
{
    int value;
    Node *next;
    Node *prev;

    explicit Node(int v) : value(v),
                           next(nullptr),
                           prev(nullptr)
    {
    }
};

class DoubleLinkedList
{
    Node *head;
    Node *tail;

public:
    DoubleLinkedList() : head(nullptr),
                         tail(nullptr)
    {
    }

    Node *begin()
    {
        return head;
    }

    Node *end()
    {
        return tail;
    }

    bool empty()
    {
        return head == nullptr;
    }

    void clear()
    {
        while (head != nullptr){
            Node *tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }

    Node *remove(Node *link)
    {
        while (link != nullptr)
        {
            Node *delTmp = link;
            link = link->next;
            delete delTmp;
        }
        return link;
    }
    ~DoubleLinkedList()
    {
        clear();
    }
};

int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    for (int i = 2; i <= 6; i++)
    {
        Node *tmp = new Node(i);
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
    Node *head2 = head;
    while (head2 != nullptr)
    {
        std::cout<<head2->value<<std::endl;
        head2 = head2->next;
    }
    DoubleLinkedList DoubleL;
    // before entering to remove method tail point to a memory which is not null. But after entering this method tail automatically point to nullptr. And after completing this method all operations this point to none. why??? I want to make tail that it will point to nullptr. without passing tail as parameter in remove it is not possible to work with tail->next and tail->prev inside remove method;
    // And If I let tail without pointing to nothing, will it ok?
    // head = DoubleL.remove(head);
    // while (head != nullptr){
    //     std::cout<<head->value<<std::endl;
    //     head = head->next;
    // }
    return 0;
}