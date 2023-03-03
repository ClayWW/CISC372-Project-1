#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 6

void matrixArrayOfArrays(int n, int m){
    float** ptr = malloc(m*sizeof(float*)); //pointer array of length m meaning there are m many pointers
    for(int i = 0; i < m; i++){
        ptr[i] = malloc(n*sizeof(float)); //for each element in pointer array, create an array of length n
    }
    float current = 0; //current value in full array
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ptr[i][j] = ++current; //go one by one through the first array (1,2,3,4) then to the next array (5,6,7,8)
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%f", ptr[i][j]);    //print them out in 2d form
            printf("\t");
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < m; i++){ //free every pointer in ptr array
        free(ptr[i]);
    }
    free(ptr); //free the ptr array's pointer
}

void matrixOneBigArray(int n, int m){
    float** ptr = malloc(m*sizeof(float*));
    float* big = malloc(n*m*sizeof(float));
    for(int i = 0; i < n*m; i++){
        if(i%n == 0){
            ptr[i] = (float*)malloc(n*sizeof(float));
        }
    }
    float current = 0;
    for(int i = 0; i < n*m; i++){
        big[i] = ++current;
    }
    /*
    for(int i = 0; i < n*m; i++){
        printf("%f", big[i]);
        printf("\t");
        if((int)big[i]%n == 0 && i > 0){
            printf("\n");
        }
    }
    */
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            printf("%f",big[(i*n)+j]);
            printf("\t");
        }
        printf("\n");
    }

    printf("\n");
    
    for(int i = 0; i<m; i++){ //free error here
        free(ptr[i]);
        printf("free works %d",i);
    }
    
    free(ptr);
    free(big);

}

int main(int argc, char** argv){
    matrixArrayOfArrays(N,M);
    matrixOneBigArray(N,M);
    return 0;
}