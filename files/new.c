#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 10
#define LINESIZE 128
#define SIZE 8

struct mold_data
{

    char mold_type[STRING_SIZE];
    char box_type[STRING_SIZE];
    int box_capacity;
};

struct mold_data array[3];

int main()
{

    FILE *myfile = fopen("patients.txt", "r");
    char  line[100];
    int i = 0;
    while (fgets(line, sizeof(line), myfile))
    {
        char l[40];
        strcpy(l, line);
        sscanf(l, "%s %s %d", array[i].mold_type, array[i].box_type, &array[i].box_capacity);
        i++;
    }
    printf("%s %d",array[1].mold_type,array[1].box_capacity);
    fclose(myfile);
    return 0;
}