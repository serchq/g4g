/*
Given an array arr[] of size n-1 with distinct integers in the range of [1, n]. 
This array represents a permutation of the integers from 1 to n with one element missing. 
Find the missing element in the array.

Examples: 

Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: Here the size of the array is 4, so the range will be [1, 5]. 
The missing number between 1 to 5 is 4
*/

#include <stdio.h>
#include <stdlib.h>


int missing(int *arr, int n){
    int *temp = (int*)calloc((n+1), sizeof(int));
    
    for (int i = 0; i < n; i++){
        temp[arr[i]-1]++;
        printf("arr[%d] = %d\n", i, arr[i]);
        for (int j = 0; j < n+1; j++){
            printf("%d ", temp[j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n+1; i++){
        if (temp[i] == 0){
            return i+1;
        }
    }
}



void main (){
    int arr[] = {8, 2, 4, 5, 3, 7, 1};
    // int arr[] = {1, 2, 3, 5};
    int n = sizeof(arr)/sizeof(int);


    printf("%d \n", missing(arr, n));

    return;
}