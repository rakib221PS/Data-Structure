#include <stdio.h>

int main(void)
{
    // char array
    char arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    // open binary file in binary mode
    FILE *f = fopen("binary.bin", "wb");
    // write all value of arr array in binary file as binary mode
    fwrite(arr, sizeof(char), 10, f);
    // close file
    fclose(f);
    char brr[10];
    // open file again
    FILE *p = fopen("binary.bin", "rb");
    if (p == NULL)
    {
        printf("File does not exits\n");
    }
    else
    {
        // read value from binary file
        fread(brr, sizeof(char), 10, f);
        for (int i = 0; i < 10; i++)
        {
            // right shift bitwise operator to change oldest bit to zero and put them into new array c
            int c = arr[i] >> 1;
            brr[i] = c;
        }
    }
    // close file
    fclose(p);
    // open file again
    FILE *mf = fopen("newBinary.bin", "wb");
    // write change value into new binary file
    fwrite(brr, sizeof(char), 10, mf);
    fclose(mf);
    return 0;
}