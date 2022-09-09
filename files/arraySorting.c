#include <stdio.h>
#include <stdlib.h>

typedef int (*order)(int, int); // porzadek to nazwa typu

int ascending_order(int, int);
int descending_order(int, int);

void sort(int *tab, int size, int(ptr)(int, int)); // wsk okresla rodzaj sortowania
void print(int *tab, int size);
void read(int *tab, int size);

order choose(char option)
{
    switch (option)
    {
    case '<':
        return ascending_order;
    case '>':
        return descending_order;
    }
}

int main()
{
    printf("\n\n\n");
    printf("\t\t\t\t\t***************\n");
    printf("\t\t\t\t\t* Sorted list *\n");
    printf("\t\t\t\t\t***************\n");
    printf("\n\n");

    int size;
    char option;

    printf("\n\tChoose the sort type ( '<' or '>' ):\t");
    scanf("%c", &option);

    printf("\n\tEnter the size of the positive integer array to sort:\t");
    scanf("%d", &size);
    int *tab = (int *)malloc(size * sizeof(int));

    printf("\n\tEnter a positive integer:\n");
    read(tab, size);
    printf("\n\tArray before sorting:\t");
    print(tab, size);

    sort(tab, size, choose(option));
    printf("\n\tArray after sorting:\t");
    print(tab, size);
    printf("\n\n");

    return 0;
}
int descending_order(int a, int b)
{
    return a >= b ? 1 : 0;
}
int ascending_order(int a, int b)
{
    return a <= b ? 1 : 0;
}

void sort(int *tab, int size, int(ptr)(int, int))
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (!ptr(tab[j], tab[j + 1]))
            {
                int pom = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = pom;
            }
}
void print(int *tab, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", *tab++);
}

void read(int *tab, int size)
{
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", tab++);
}
