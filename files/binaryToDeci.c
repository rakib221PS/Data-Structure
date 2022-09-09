#include <stdio.h>

int main(void){
    int n,i=0;
    printf("Enter decimal value: ");
    int bin[32];
    scanf("%d",&n);
    while(n>0){
        int a = n%2;
        bin[i]=a;
        n=n/2;
        i++;
    }
    for (int  j=i-1; j>=0; j--)
    {
        printf("%d",bin[j]);
    }
    
    return 0;
}