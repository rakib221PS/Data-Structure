#include <iostream>
#include <math.h>
#include <stdexcept>
#include <string>

class Calculator
{
    int number;
    int elements;
    int capacity;

    int *mem;

public:
    Calculator() : capacity(10),
                   mem(new int[capacity]),
                   elements(0)
    {
    }

    bool isFull()
    {
        return (capacity == elements);
    }

    bool isEmpty()
    {
        return (elements == 0);
    }

    void push(int x)
    {
        if (isFull())
        {
            int *tmp = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                tmp[i] = mem[i];
            }
            delete[] mem;
            capacity *= 2;
            mem = tmp;
        }
        mem[elements++] = x;
    }

    int top()
    {
        if (isEmpty())
        {
            throw std::runtime_error("top() called empty stack! underflow!");
        }
        return mem[elements - 1];
    }

    void pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("pop() called empty stack! underflow!");
        }
        elements--;
    }

    void print()
    {
        for (int i = 0; i < elements; i++)
        {
            std::cout << mem[i] << " ";
        }
    }

    int sum()
    {
        int number1 = top();
        pop();
        int number2 = top();
        pop();
        int result = number1 + number2;
        push(result);
        return result;
    }

    int minus()
    {
        int number1 = top();
        pop();
        int number2 = top();
        pop();
        int result = number1 - number2;
        push(result);
        return result;
    }

    int multiply()
    {
        int number1 = top();
        pop();
        int number2 = top();
        pop();
        int result = number1 * number2;
        push(result);
        return result;
    }

    int squareRoot()
    {
        int result = sqrt(top());
        pop();
        push(result);
        return result;
    }

    int exponential()
    {
        int number1 = top();
        pop();
        int number2 = top();
        pop();
        int result = pow(number2, number1);
        push(result);
        return result;
    }
    ~Calculator()
    {
        delete[] mem;
    }
};

int evaluate(std::string xs)
{
    Calculator calculator;

    for (int i = 0; i < xs.size(); i++)
    {
        int finalResult = 0;
        if (xs[i] == ' ')
        {
            continue;
        }
        else if (isdigit(xs[i]))
        {
            calculator.push(xs[i] - '0');
        }
        else
        {
            if (xs[i] == '+')
            {
                finalResult = calculator.sum();
            }
            else if (xs[i] == '-')
            {
                finalResult = calculator.minus();
            }
            else if (xs[i] == '*')
            {
                finalResult = calculator.multiply();
            }
            else if (xs[i] == 's')
            {
                finalResult += calculator.squareRoot();
            }
            else if (xs[i] == 'e')
            {
                finalResult = calculator.exponential();
            }
            else
            {
                continue;
            }
        }
    }
    return calculator.top();
}

int main()
{
    std::cout << evaluate("5 5 +") << std::endl;
    std::cout << evaluate("5 4 *") << std::endl;
    std::cout << evaluate("5 2 3 + *") << std::endl;
    std::cout << evaluate("5 2 + 3 *") << std::endl;
    std::cout << evaluate("1 2 3 4 + + +") << std::endl;
    std::cout << evaluate("1 2 + 3 + 4 +") << std::endl;
    std::cout << evaluate("8 2 e") << std::endl;
    std::cout << evaluate("8 2 * s") << std::endl;
    std::cout << evaluate("7 8 + s") << std::endl;
    return 0;
}