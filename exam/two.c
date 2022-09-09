#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *digits(char tab[]);

int main(void){
    char str[200];
    printf("Enter string max range 200: ");
    scanf("%s",str);
    char *dg=digits(str);
    printf("%s",dg);
}

char *digits(char tab[]){
    int len = strlen(tab);
    char *dig=(char *)malloc(len*sizeof(char));
    int j=0;
    for (size_t i = 0; i < len; i++)
    {
        if (!(tab[i]>97&&tab[i]<123))
        {
            dig[j]=tab[i];
            j++;
        }
    }
    dig[j]='\0';
    return dig;
    
}