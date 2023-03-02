#include <stdio.h>

#define N 5
#define M 6

void matrixArrayOfArrays(int n, int m){
    float** ptr = (float*)malloc(m*sizeof(float*));
    for(int i = 0; i < m; i++){
        ptr[i] = (float*)malloc(n*sizeof(float));
    }
    int current = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ptr[i][j] = ++current;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%f", ptr[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    for(int i = 0; i < m; i++){
        free(ptr[i]);
    }
    free(ptr);
}

void matrixOneBigArray(int n, int m){
    float** ptr = (float*)malloc(m*sizeof(float*));
    float big = (float)malloc(n*m*sizeof(float));

}

int main(int argc, char** argv){
    matrixArrayOfArrays(N,M);
    matrixOneBigArray(N,M);
    return 0;
}