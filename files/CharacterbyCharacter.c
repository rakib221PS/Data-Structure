#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("file.txt","w");
    for(int i = 0;i<=5;i++){
        char c;
        printf("Enter %d ",i);
        scanf("%c",&c);
        fflush(stdin);
        fputc(c,fp);
    }
    fclose(fp);
    return 0;
}
