#include <iostream>

class Stack
{
    int mem[100];
    int elements;

public:
    Stack() : elements(0) {}

    void push(int x)
    {
        mem[elements] = x;
        elements++;
    }

    int top()
    {
        return mem[elements - 1];
    }

    void pop()
    {
        elements--;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.push(4);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
}
