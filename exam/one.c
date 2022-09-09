#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int width, height;
    char color[20];
} figure;

void read(figure *fig,int size);
void print(figure *fig,int size);
figure *maximum(figure *fig,int size);

int main(void){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    figure *f=(figure*)malloc(n*sizeof(figure));
    read(f,n);
    print(f,n);
    figure *max=maximum(f,n);
    printf("%s\n",(max+0)->color);
    printf("%d\n",(max+0)->width);
    printf("%d\n",(max+0)->height);
    return 0;
}

void read(figure *fig,int size){
    for (int i = 0; i < size; i++)
    {
        printf("Enter the width of %d ",i+1);
        scanf("%d",&(fig+i)->width);
                printf("Enter the height of %d ",i+1);
        scanf("%d",&(fig+i)->height);
                printf("Enter the color of %d ",i+1);
        scanf("%s",(fig+i)->color);
        printf("--------------------\n");
    }
    
}


void print(figure *fig,int size){
    for (int i = 0; i < size; i++)
    {
        printf("----------------\n");
        printf("The color of element %d is %s: \n",i+1,(fig+i)->color);
        printf("The width of element %d is %d: \n",i+1,(fig+i)->width);
        printf("The height of element %d is %d: \n",i+1,(fig+i)->height);
        printf("----------------\n");
    }
}

figure *maximum(figure *fig,int size){
    int *max=(int *)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++)
    {
        int allSize = (fig+i)->height+(fig+i)->width;
        max[i]=allSize;
    }
    int maximum=max[0];
    for (int i = 0; i < size; i++)
    {
        if (max[i]>maximum)
        {
            maximum=max[i];
        }  
    }
    figure *ma=(figure *)malloc(1*sizeof(figure));
    int most=0;
    for (int i = 0; i < size; i++)
    {
        if (most == 1)
        {
            break;
        }
        
        if (((fig+i)->height+(fig+i)->width)==maximum)
        {
            strcpy(ma->color,(fig+i)->color);
            ma->height=(fig+i)->height;
            ma->width=(fig+i)->width;
            most = 1;
        }
    }
    return ma;
}