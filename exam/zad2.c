#include <stdio.h>

int main(void)
{ 
    int average = 0;
    FILE *wor = fopen("workers.txt", "r");
    if (wor == NULL)
    {
        printf("The file does not exist.\n");
    }
    else
    {
        char buf[20];
        int num = 0, total = 0;
        while (fgets(buf, sizeof(buf), wor))
        {
            int salary;
            sscanf(buf, "%*[^0-9]%d", &salary);
            // printf("%s %s - %d",name,surName,salary);
            total += salary;
            num++;
        }
        fclose(wor);
        average = total / num;
        printf("average: %d\n", average);
        FILE *f = fopen("workers.txt", "r");
        if (f == NULL)
        {
            printf("File does not exist");
        }
        else
        {
            char auf[20];
            while (fgets(auf, sizeof(auf), f))
            {
                // printf("%s\n",buf);
                char name[20];
                char surName[20];
                int salary;
                sscanf(auf, "%s %s %d", name, surName, &salary);
                if (salary > average)
                {
                    printf("%s %s\n", name, surName);
                }
            }
        }
    }
    return 0;
}