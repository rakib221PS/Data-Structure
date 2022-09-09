#include <stdio.h>

int main(void){
    FILE *f=fopen("binarayData.bin","wb");
    for(int i = 0;i<=100;i++){
        fwrite(&i,sizeof(char),1,f);
    }
    fclose(f);
    FILE *p=fopen("binarayData.bin","rb");
    char j;
    for(int i=0;i<=100;i++){
        int a = fread(&j,sizeof(char),1,f);
        // if (j == 1)
        // {
            printf("%d ",a);
        // }  
    }
    return 0;
}
