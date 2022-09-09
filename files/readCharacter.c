#include <stdio.h>

int main(void)
{
    char c;
    char name[10];
    printf("Enter file name: ");
    scanf("%s", name);
    FILE *f = fopen(name, "r");
    if (f == NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        while (c != EOF)
        {
            c = fgetc(f);
            printf("%c", c);
        }
    }
    return 0;
}