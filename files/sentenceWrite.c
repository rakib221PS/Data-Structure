#include <stdio.h>

int main(void){
    char name[100];
    FILE *f=fopen("hello.txt","w");
    for (int i = 0; i < 3; i++)
    {
        printf("Enter sentence 1: ");
        scanf("%s",name);
        fflush(stdin);
        fprintf(f, "%s",name);
        fputc('\n',f);
    }
    
    return 0;
}