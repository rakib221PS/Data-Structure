#include <stdio.h>

int main(void){
    FILE *f = fopen("data.bin","wb");
        // FILE *f = fopen("data.bin","rb"); 
    for (int i = 0; i < 100; i++)
    {
        fwrite(&i, sizeof(int), 1, f);
    }
            FILE *f = fopen("data.bin","rb"); 
    int a[100];
            fread(&a, sizeof(int), 100, f);
        for (int i = 0; i < 100; i++)
    {
        printf("%d\n",a[i]);
    // }
    fclose(f);
    return 0;
}