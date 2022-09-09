#include <iostream>
#include <stdexcept>

class UndoRedo
{
    int capacity;
    int redoCapacity;
    int elements;
    int redoElements;
    std::string *currentAllStrings;
    std::string *redoStrings;

public:
    UndoRedo() : capacity(10),
                 redoCapacity(10),
                 elements(0),
                 redoElements(0),
                 currentAllStrings(new std::string[capacity]),
                 redoStrings(new std::string[capacity])
    {
    }

    bool empty()
    {
        return (elements == 0);
    }

    bool redoEmpty()
    {
        return (redoElements == 0);
    }

    std::string top()
    {
        if (empty())
            throw std::runtime_error("top() called empty stack! Underflow!");
        return currentAllStrings[elements - 1];
    }
    void write(std::string x)
    {
        if (capacity == elements)
        {
            std::string *newCurrentAllStrings = new std::string[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newCurrentAllStrings[i] = currentAllStrings[i];
            }
            delete[] currentAllStrings;
            currentAllStrings = newCurrentAllStrings;
            capacity *= 2;
        }

        currentAllStrings[elements++] = x;
    }

    void redoPush(std::string x)
    {
        if (redoCapacity == redoElements)
        {
            std::string *newRedoStrings = new std::string[redoCapacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newRedoStrings[i] = redoStrings[i];
            }
            delete[] redoStrings;
            redoStrings = newRedoStrings;
            redoCapacity *= 2;
        }

        redoStrings[redoElements++] = x;
    }

    std::string undo()
    {
        if (empty())
        {
            throw std::runtime_error("undo() called empty memory! Underflow!");
        }
        std::string un = currentAllStrings[elements - 1];
        redoPush(un);
        elements--;
        return un;
    }

    std::string redo()
    {
        if (redoEmpty())
        {
            throw std::runtime_error("redo() called empty memory! Underflow!");
        }
        std::string run = redoStrings[redoElements - 1];
        redoElements--;
        write(run);
        return run;
    }
    void pop()
    {
        if (empty())
            throw std::runtime_error("Pop() called empty stack! Underflow!");
        elements--;
    }

    ~UndoRedo()
    {
        delete[] currentAllStrings;
    }
};

int main()
{
    UndoRedo buf;
    buf.write("a");
    buf.write("b");
    buf.write("c");
    buf.write("d");
    std::cout << "undoing: " << buf.undo() << std::endl;
    std::cout << "undoing: " << buf.undo() << std::endl;
    std::cout << "redoing: " << buf.redo() << std::endl;
    std::cout << "undoing: " << buf.undo() << std::endl;
    buf.write("e");
    std::cout << "undoing: " << buf.undo() << std::endl;
    std::cout << "redoing: " << buf.redo() << std::endl;
    std::cout << "redoing: " << buf.redo() << std::endl;
    std::cout << "redoing: " << buf.redo() << std::endl;
    return 0;
}