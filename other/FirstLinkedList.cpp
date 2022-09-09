#include <iostream>

struct Node
{
    int value;
    Node *next;
};

int main()
{
    Node *head = new Node;
    head->value = 1;
    head->next = new Node;
    head->next->value = 2;
    head->next->next = new Node;
    head->next->next->value = 3;
    head->next->next->next = nullptr;
    return 0;
}
