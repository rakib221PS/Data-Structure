#include <iostream>

struct SingleElementsQueue{
    int capacity;
    int elements;
    int first;
    int *singleMem;

    SingleElementsQueue():capacity(1), elements(0), first(0), singleMem(new int[capacity]){}

    SingleElementsQueue push_singleElement(const int x){
        int insertionLocation = (first + capacity) % capacity;
        singleMem[insertionLocation] = x;
        return *this;
    }

    ~SingleElementsQueue(){
        if (elements > 0)
        {
            delete[] singleMem;
        }
    }

};

class XS{
    int capacity;
    int elements;
    int first;
    SingleElementsQueue *mem;

    public:

    XS():capacity(10), elements(0), first(0), mem(new SingleElementsQueue[capacity]){}

    bool isFull(){
        return (capacity == elements);
    }

    void push(const SingleElementsQueue queue){
        if (isFull())
        {
            SingleElementsQueue *tmpMem = new SingleElementsQueue[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                tmpMem[i] = mem[i];
            }
            delete[] mem;
            tmpMem = mem;
            capacity = capacity * 2;
        }
        int insertionLocation = (first + elements) % capacity;
        mem[insertionLocation] = queue;
        elements++;
    }

    bool moreElements(){
        if (elements == 1)
        {
            printElements();
            return false;
        }
        else
        {
            return true;
        }
        
    }

    void printElements(){
        for (int i = 0; i < elements; i++)
        {
            std::cout<<mem[i].singleMem[0]<<std::endl;
        }     
    }

    int sumOfFirstAndSecondElements(){
        return ((mem[0].singleMem[0]) + (mem[1].singleMem[0]));
    }

    ~XS(){
        if (elements > 0)
        {
            delete[] mem;
        }
        
    }
};


int main(){
    XS c;

    for (int i = 2; i < 4; i++)
    {
        SingleElementsQueue singleQu;
        SingleElementsQueue y = singleQu.push_singleElement(i);
        c.push(y);
    }

    if (c.moreElements() == true)
    {
        SingleElementsQueue d;
        int sum = c.sumOfFirstAndSecondElements();
        SingleElementsQueue z = d.push_singleElement(sum);
        c.push(z);
    }

    c.printElements();
    return 0;
}