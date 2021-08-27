#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <omp.h>

using namespace std;
#define N 3000
#define THREAD_NUMBER 4

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
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
            C[i][j] = 0;
        }
    }



    clock_t start = clock();
    //code
    #pragma omp parallel num_threads(THREAD_NUMBER)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                for(int k = 0; k < N; k++)
                {
                    C[i][j] += A[i][k] * B[j][k];
                }
            }
        }
    }

    clock_t end = clock();
    double total_time = (double)(end - start)/CLOCKS_PER_SEC;




    //create the file and write the result into the file
    FILE *fp = fopen("presult.txt","w");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fprintf(fp,"%d\t",C[i][j]);
        }
        fprintf(fp,"\n");
    }
    //fprintf("The total running time is: ");
    fclose(fp);

    printf("running time is: ");
    printf("%f",total_time);
    return 0;
}