#include <stdio.h>

int main(void){
    FILE *wo;
    wo=fopen("word.txt","w");
    //char name[10];
    for(int i=0;i<5;i++){
        char name[10];
        printf("Enter word %d: ",i);
        scanf("%s",name);
        fputs(name,wo);
    }
    fclose(wo);
    return 0;
}
