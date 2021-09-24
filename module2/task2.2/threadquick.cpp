#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <pthread.h>

using namespace std;

#define N 110000

#define THREAD_NUMBER 8

//define a mutex lock
pthread_mutex_t mutexa;
//

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


int countb = 0;
int p_lenth = N/THREAD_NUMBER;
void* newfunc(void *arg)
{
    pthread_mutex_lock(&mutexa);
    quick_sort(arr,0,p_lenth+countb*p_lenth-1);
    /*
    printf("%d",countb);
    printf(":::::::::::");
    for(int i = 0; i<N; i++)
    {
        printf("%d\t",arr[i]);
    }*/
    countb++;
    pthread_mutex_unlock(&mutexa);

    return 0;
}




int main()
{
    printf("program strats");

    for(int i = 0; i < N; i++)
    {
        arr[i] = rand()%10;
    }

    pthread_t threads[THREAD_NUMBER];

    //test


    pthread_mutex_init(&mutexa,0);

    
    clock_t start = clock();
    
    for (long i = 0; i < THREAD_NUMBER; i++)
    {
        pthread_create(&threads[i], NULL, newfunc, (void*)i);
    }
    for (long i = 0; i < THREAD_NUMBER; i++)
    {
        pthread_join(threads[i], NULL);
    }    

    clock_t end = clock();    
    double total_time = (end - start)/CLOCKS_PER_SEC;



    pthread_mutex_destroy(&mutexa);



    printf("running time is: ");
    printf("%f",total_time);

    return 0;



}