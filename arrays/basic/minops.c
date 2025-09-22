/*
Minimum increment by k operations to make all equal
Last Updated : 11 Oct, 2024
You are given an array of n-elements, you have to find the number of operations needed 
to make all elements of array equal. Where a single operation can increment an element 
by k. If it is not possible to make all elements equal print -1.

Example : 

Input : arr[] = {4, 7, 19, 16},  k = 3
Output : 10

Input : arr[] = {4, 4, 4, 4}, k = 3
Output : 0

Input : arr[] = {4, 2, 6, 8}, k = 3
Output : -1
*/

#include <stdio.h>
#include <stdlib.h>


int minops(int *arr, int n, int k){
    int max = arr[0];
    int temp = 0;
    int op = 0;

    for (int i = 1; i < n; i++){
        if (arr[i] >= max){            
            temp = max;
            max = arr[i];
        }
        if (max == temp){
            continue;
        }
        else if ((max - temp)%k){
            return -1;
        }
    }

    for (int i = 0; i < n; i++){
        // printf("max = %d\t arr[%d] = %d\tk = %d\n", max, i, arr[i], k);
        op += ((max - arr[i])/k);
        // printf("op = %d\n", op);
    }

    return op;
}



void main (){
    // int arr[] = {4, 7, 19, 16};
    // int arr[] = {4, 4, 4, 4};
    // int k = 3;
    int arr[] = { 21, 33, 9, 45, 63};
    int k = 6;

    int n = sizeof(arr)/sizeof(int);


    printf("%d \n", minops(arr, n, k));

    return;
}