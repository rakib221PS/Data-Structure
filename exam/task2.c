#include <stdio.h>

int main(void)
{ 
    int max = 0,B=0,n=0;
    // open file
    FILE *grade = fopen("students.txt", "r");
    if (grade == NULL)
    {
        printf("The file does not exist.\n");
    }
    else
    {
        // set character length
        char buf[20];
        int num = 0, total = 0;
        // check line exits
        while (fgets(buf, sizeof(buf), grade))
        {
            int grade;
            // this regex for taking integer
            sscanf(buf, "%*[^0-9]%d", &grade);
            n++;
            // take second grade
            if (n == 1)
            {
                B = grade;
            }
            // take highest grade
            if (grade>max)
            {
                max = grade;
            }
        }
        // close file
        fclose(grade);
        printf("maximum: %d\n", max);
        // open file again
        FILE *f = fopen("students.txt", "r");
        if (f == NULL)
        {
            printf("File not exist");
        }
        else
        {
            char auf[20];
            // check line and put it in auf
            while (fgets(auf, sizeof(auf), f))
            {
                char name[20];
                char surName[20];
                int grade;
                // take name, surName and grade
                sscanf(auf, "%s %s %d", name, surName, &grade);
                if (grade < B )
                {
                    printf("%s %s %d\n", name, surName, grade);
                }
            }
        }
    }
    return 0;
}