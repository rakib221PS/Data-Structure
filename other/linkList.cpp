#include <iostream>

class Node
{
public:
    int value;
    Node *Next;
};

void printLinkedList(Node *n)
{
    while (n != NULL)
    {
        std::cout << n->value << std::endl;
        n = n->Next;
    }
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->value = 1;
    head->Next = second;
    second->value = 3;
    second->Next = third;
    third->value = 4;
    third->Next = NULL;
    printLinkedList(head);
    return 0;
}