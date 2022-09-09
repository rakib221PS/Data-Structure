#include <stdio.h>

int main(void)
{
    FILE *f = fopen("text.txt", "r");
    char c;
    while (c != EOF)
    {
        c = fgetc(f);
        {
            {
                {
                    {
                        {
                            {
                                {
                                    printf("%c ---",c);
                                }
                            }
                        }
                        printf("hi everyone\n");
                    }
                }
            }
        }
    }
    return 0;
}