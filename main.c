#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pArray = NULL;
    int num = 0;

    if(ReadDate("input.txt",&pArray,&num))
    {
        PrintDate(pArray,num);
        QuickSort(pArray,num);
        PrintDate(pArray,num);
    }

    return 0;
}
