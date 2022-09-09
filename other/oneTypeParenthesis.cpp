#include <iostream>
#include <string>

class Stack
{
    std::string parenthesis;
    char *character = new char[10];
    int elements;

public:
    Stack() : parenthesis(""), elements(-1) {}

    void push(std::string x)
    {
        parenthesis = parenthesis + x;
    }
    void printParenthesis()
    {
        std::cout << parenthesis;
    }
    bool isEmpty()
    {
        return elements == -1;
    }
    bool isBalanced()
    {
        int size = parenthesis.size();
        for (int i = 0; i < size; i++)
        {
            if (parenthesis[i] == '(' || parenthesis[i] == '{' || parenthesis[i] == '[')
            {
                elements++;
                character[elements] = parenthesis[i];
            }
            else
            {
                if (parenthesis[i] == ')')
                {
                    if (character[elements] == '(')
                    {
                        elements--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (parenthesis[i] == '}')
                {
                    if (character[elements] == '{')
                    {
                        elements--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if (character[elements] == '[')
                    {
                        elements--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Stack()
    {
        if (!isEmpty())
        {
            delete[] character;
        }
    }
};

int main()
{
    Stack s;
    std::string parenthesis;
    std::cout << "Enter parenthesis: " << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << "s.parenthesis[" << i << "]: ";
        std::cin >> parenthesis;
        s.push(parenthesis);
    }
    s.printParenthesis();
    std::cout << std::endl;
    if (s.isBalanced() == true)
    {
        std::cout << "The string is balanced" << std::endl;
    }
    else
    {
        std::cout << "The string is imbalance" << std::endl;
    }
    return 0;
}
