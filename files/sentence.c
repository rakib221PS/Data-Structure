#include <stdio.h>

int main(void){
    FILE *fp;
    fp=fopen("sentence.txt","w");
    for(int i=0;i<5;i++){
        char sen[10];
        printf("Enter sentence %d: ",i);
        scanf("%s",sen);
        fprintf(fp,"%s\n",sen);
    }
    fclose(fp);
    return 0;
}
