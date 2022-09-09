// clear up redundancies in Your code -- add a method empty() which returns true if elements is equal to 0. Use it in pop and top.
#include <iostream>
#include <stdexcept> // allows us to use the standard exceptions defined by C++

class Stack
{
    int mem[100];
    int elements;
    // bool checkTop = true;
    // bool checkPush = true;
    // bool checkPop = true;

public:
    Stack() : elements(0) {}
    bool empty(){
        if (elements == 0)
        {
            return true;
        }
        return false;    
    }

    int top()
    {
        if (empty())
        {
            throw std::runtime_error("top() called on an empty stack");
        }

        return mem[elements - 1];
    }

    void pop()
    {
        if (empty())
        {
            throw std::runtime_error("pop() called on an empty stack");
        }

        elements--;
    }

    // still unsafe
    void push(int x)
    {
        if (elements >= 100)
        {
            throw std::runtime_error("push() is not possible for lacking of space");
        }

        mem[elements] = x;
        elements++;
    }
};

int main()
{
    Stack s;
    s.push(1);
    std::cout << s.top();
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // std::cout << s.top() << std::endl;
    // s.pop();
    // std::cout << s.top() << std::endl;
    // s.push(4);
    // std::cout << s.top() << std::endl;
    // s.pop();
    // std::cout << s.top() << std::endl;
}
