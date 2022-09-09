#include <stdio.h>

int main(void)
{
    char s[100];
    FILE *f = fopen("patients.txt", "r");
    while ((fgets(s, 100, f)))
    {
        char nu[10];
        char su[10];
        int n;
        sscanf(s, "%s %s %d",nu, su, &n);
        if ((nu[0] == 'A' || nu[0] == 'E' || nu[0] == 'I' || nu[0] == 'O' || nu[0] == 'U' || nu[0] == 'a' || nu[0] == 'e' || nu[0] == 'i' || nu[0] == 'o' || nu[0] == 'u') && n>75)
        {
            printf("This patient has Vowel in his name and age over 75: %s ", s);
            printf("%d",n);
        }
    }
    return 0;
}