#include <iostream>

struct Node
{
    int value;
    Node *next;
    Node(int n) : value(n), next(nullptr)
    {
    }
};

int main()
{
    // first
    Node *head = new Node(1);

    Node *tail = head;

    // second
    tail->next = new Node(2);
    tail = tail->next;

    // third
    tail->next = new Node(3);
    tail = tail->next;

    // fourth
    tail->next = new Node(4);
    tail = tail->next;

    // fifth
    tail->next = new Node(5);
    tail = tail->next;
    return 0;
}
