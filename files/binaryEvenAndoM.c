#include <stdio.h>

int main(void)
{
    FILE *f = fopen("binarayData.bin", "wb");
    char num[100];
    for (int i = 0; i <= 100; i++)
    {
        num[i] = i;
    }
    fwrite(num, sizeof(char), 100, f);
    fclose(f);
    FILE *p = fopen("binarayData.bin", "rb");
    char a[100];
    fread(a, sizeof(char), 100, p);
    for (int i = 0; i < 100; i++)
    {

        // printf("%d ", a[i]);
        if ((a[i] & 1) == 1)
        {
            printf("%d ", a[i]);
        }
    }
    fclose(p);
    return 0;
}