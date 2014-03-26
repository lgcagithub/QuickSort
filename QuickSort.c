#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QuickSort.h"

int ReadDate(char* filename, int** pArrayOut,int* pNum)
{
    int index = 0;
    FILE* input = fopen(filename,"r");
    if(!input)
    {
        printf("Open %s failed!\n",filename);
        return 0;
    }

    fscanf(input,"%d",pNum);
    if(*pNum <= 0) return 0;

    if(*pArrayOut)
    {
        free(*pArrayOut);
        *pArrayOut = NULL;
    }

    *pArrayOut = (int*)malloc(sizeof(int)*(*pNum));
    while(index < *pNum)
    {
        fscanf(input,"%d",&(*pArrayOut)[index]);
        index++;
    }

    fclose(input);
    return 1;
}

void PrintDate(int* pArray, int num)
{
    int index = 0;
    while(index < num)
    {
        printf("%d ",pArray[index]);
        index++;
    }
    printf("\n");
}

void QuickSort(int* pArray,int num)
{
    int i = 0,j = num-2;
    if(num > 3)
    {
        ThreeSort(&pArray[0],&pArray[num>>1],&pArray[num-1]);
        Swap(&pArray[num>>1],&pArray[num-2]);
        while(1)
        {
            while(pArray[++i] < pArray[num-2]);//!
            while(pArray[--j] > pArray[num-2]);//!
            if(i < j) Swap(&pArray[i],&pArray[j]);
            else
            {
                Swap(&pArray[i],&pArray[num-2]);
                break;
            }
        }
        //!分完区记得要分别对两个分区进行快排！
        QuickSort(pArray,i);//!
        QuickSort(pArray+i+1,num-i);//!
    }
    else
    {
        ThreeSort(&pArray[0],&pArray[1],&pArray[2]);
    }
}

void ThreeSort(int* one,int* two,int* three)
{
    if(*one > *two)
        Swap(one,two);
    if(*one > *three)
        Swap(one,three);
    if(*two > *three)
        Swap(two,three);
}

void Swap(int* v1,int* v2)
{
    int t = *v1;
    *v1 = *v2;
    *v2 = t;
}














