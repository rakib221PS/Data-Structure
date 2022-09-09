// this header for isupper function
#include <ctype.h>
#include <stdio.h>
// for malloc
#include <stdlib.h>
// for string
#include <string.h>
// * means returning pointer
char *alternative(char *c)
{
    int n = 0;
    int k = 0;
    // '\0' indicates null. our string is null terminated
    while (c[k] != '\0')
    {
        if (isupper(c[k]))
        {
            n++;
        }
        k++;
    }
    char *d = (char *)malloc(n * sizeof(char));
    int j = 0, i = 0;
    while (c[j] != '\0')
    {
        if (isupper(c[j]))
        {
            d[i++] = c[j];
        }
        j++;
    }

    return d;
}

int main()
{
    char *name = "heDlEDDDbaLLssLLkk";
    // assigning pointer to pointer
    char *a = alternative(name);
    for (int i = 0; a[i] != '\0'; i++)
    {
        printf("%c", a[i]);
    }

    return 0;
}