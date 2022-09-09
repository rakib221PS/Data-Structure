#include <iostream>
#include <stdexcept>

class Stack
{
    public:
    int capacityRow, capacityColumn;
    int elements;
    int **mem;

public:
    Stack() : capacityRow(3),
              capacityColumn(2),
              elements(0),
              mem(new int *[capacityRow])
    {
        for (int i = 0; i < capacityRow; i++)
        {
            mem[i] = new int[capacityColumn];
        }
        
    }

    bool empty()
    {
        return (elements == 0);
    }

    int *top()
    {
        if (empty())
            throw std::runtime_error("top() called empty stack! Underflow!");
        int *topPair = new int[2];
        topPair[0] = mem[elements-1][0];
        topPair[1] = mem[elements-1][1];
        return topPair;
    }
    void push(const int x, const int y)
    {
        if (capacityRow == elements)
        {
            int **newMem = new int *[capacityRow * 2];
            for (int i = 0; i < capacityRow * 2; i++)
            {
                newMem[i] = new int [capacityColumn];
            }
            
            for (int i = 0; i < capacityRow; i++)
            {
                for (int j = 0; j < capacityColumn; j++)
                {
                    newMem[i][j] = mem[i][j];
                }
                 
            }
            for (int i = 0; i < capacityRow; i++)
            {
                delete[] mem[i];
            }
            delete[] mem;
            for (int i = 0; i < capacityRow * 2; i++)
            {
                mem[i] = newMem[i];
            }
            
            capacityRow *= 2;
        }
        mem[elements][0] = x;
        mem[elements][1] = y;
        elements++;
    }
    void pop()
    {
        if (empty())
            throw std::runtime_error("Pop() called empty stack! Underflow!");
        elements--;
    }

    ~Stack()
    {
        for (int i = 0; i < capacityRow; i++)
        {
            delete [] mem[i];
        }
        delete [] mem;  
    }
};

int fun(const int x, const int y){
    int sum = 0;
    Stack fu;
    fu.push(x, y);
    while (!fu.empty())
    {
        if (fu.top()[0] == 0 || fu.top()[1] == 0)
        {
            sum += 1;
        }
        else
        {
            fu.push(x-1, y);
            fu.push(x, y-1);
        }
        fu.pop();
    }
    return sum;
}

int main()
{
	std::cout << fun(0, 0) << std::endl;
	std::cout << fun(0, 1) << std::endl;
	std::cout << fun(1, 0) << std::endl;
	std::cout << fun(1, 1) << std::endl;
	std::cout << fun(3, 4) << std::endl;
	std::cout << fun(2, 6) << std::endl;
	std::cout << fun(8, 7) << std::endl;
	std::cout << fun(8, 10) << std::endl;
	std::cout << fun(12, 14) << std::endl;  
    return 0;
}