/*
Check if an Array is Sorted
Last Updated : 15 Jul, 2025
Given an array arr[], check if it is sorted in ascending order or not. Equal 
values are allowed in an array and two consecutive equal values are considered 
sorted.

Examples: 

Input: arr[] = [10, 20, 30, 40, 50]
Output: true
Explanation: The given array is sorted.

Input: arr[] = [90, 80, 100, 70, 40, 30]
Output: false
Explanation: The given array is not sorted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


bool checkIfSorted(int *arr, int n){
    bool sorted;

    for (int i = 0; i < n-1; i++){
        if (arr[i] <= arr[i+1]){
            sorted = true;
        } else {
            sorted = false;
            break;
        }
    }

    return sorted;
}


int main(){
    clock_t start, end;
    // int arr[] = {10, 20, 30, 40, 50};
    int arr[] = {10, 20, 30, 30, 50};
    // int arr[] = {90, 80, 100, 70, 40, 30};

    int n = sizeof(arr)/sizeof(int);


    start = clock();
    printf("%s\n", checkIfSorted(arr, n) ? "true" : "false");
    end = clock();
    printf("\n\ntotal elapsed time: %f\n\n\n\n", ((double)(end-start))/CLOCKS_PER_SEC);
}