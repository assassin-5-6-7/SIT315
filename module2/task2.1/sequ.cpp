#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

#define N  1000

//create three matrix, first two is the input and the thrid one is used for saving result
int A[N][N];
int B[N][N];
int C[N][N];






int main()
{
    //initiate the matrix, input as random numbers, output as 0s;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            A[i][j] = rand();
            B[i][j] = rand();
            C[i][j] = 0;
        }
    }


    //matrix calculation progress
    //count time using ctime
    clock_t start = clock();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                C[i][k] += A[i][k] * B[j][k];
            }
        }
    }
    clock_t end = clock();
    double total_time = (double)(end - start);

    //create the file and write the result into the file
    FILE *fp = fopen("result.txt","w");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fprintf(fp,"%d",C[i][j]);
        }
        fprintf(fp,"\n");
    }
    fprintf("The total running time is: ",total_time);
    fclose(fp);







    return 0;

}