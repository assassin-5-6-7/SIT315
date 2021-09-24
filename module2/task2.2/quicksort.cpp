#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

#define N 200000

int arr[N];

void swap(int* a, int* b)
{
    int i = *a;
    *a = *b;
    *b = i;
}

//function to find the pivot number index
int partition(int array[], int left, int right)
{
    int pivot = array[right];
    int leftindex = left;
    int rightindex = right-1;
    while(true)
    {
        while(leftindex < right & array[leftindex] <= pivot)
        {
            leftindex++;
        }
        while(rightindex > left & array[rightindex] > pivot)
        {
            rightindex--;
        }
        if(leftindex >= rightindex)
        {
            break;
        }
        //swap(array,leftindex,rightindex);
        swap(&array[leftindex],&array[rightindex]);

    }
    //swap(array,leftindex,right);
    swap(&array[leftindex],&array[right]);
    return leftindex;

}

//function of quick_sort
void quick_sort(int array[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int partindex = partition(array, left, right);
    quick_sort(array, left, partindex-1);
    quick_sort(array, partindex+1, right);
}






int main()
{
    printf("program strats");

    for(int i = 0; i < N; i++)
    {
        arr[i] = rand()%10;
    }

    clock_t start = clock();
    quick_sort(arr,0,N-1);
    clock_t end = clock();
    double total_time = (end - start)/CLOCKS_PER_SEC;


    /*
    for(int i = 0; i<N; i++)
    {
        printf("%d\t",arr[i]);
    }*/
    printf("running time is: ");
    printf("%lf",total_time);

}