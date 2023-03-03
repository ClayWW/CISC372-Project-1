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
            ptr[i] = big+(i*n);
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

    free(ptr);
    free(big);

}

int main(int argc, char** argv){
    matrixArrayOfArrays(N,M);
    matrixOneBigArray(N,M);
    return 0;
}

/*
5a) Creating an array of arrays does not require one chunk of continuous memory which is a pro but because of this accessing and allocation time will not be as quick which is a con.
An array of arrays is dynamically allocated memory, allowing for quick changes to the arrays in use such as deleting or adding any elements. 
Creating one large array including pointers is easily traversed, but such an array needs to exist in one continuous chunk of memory which is a con. One large array
is also statically allocated memory making it much more difficult to make changes to the array. An array of arrays is also easier to set up (or at least something I 
am more accustomed to) as it allows us to locate and place our pointers in the proper location using only a for loop while a large array requires a more intricate process 
to lay down pointers.


5b) If I was in a situation where my memory was beginning to get a little too crowded, using an array of arrays would be a better approach because
the memory that the array of arrays is using can be dispersed into wherever it fits, it is significantly more manageable to introduce when memory is getting close to
capacity. But if I was in a situation where the time to access certain memory is what I am concerned with, then the one big array approach would be better. Because both
strategies have their own pros and cons, it really comes down to what the user is concerned about whether that be memory size, memory location, accessing speed, the ease at
which changes can be made to the array, etc. 

*/