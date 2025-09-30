/*
Given a binary array arr[] and an integer k, find the maximum length of a subarray 
containing all ones after flipping at most k zeroes to 1's.

Examples: 

Input: arr[] = [1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1], k = 2
Output: 8
Explanation: By flipping the zero at index 1, all the array elements become one.

Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5 
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray 
from index 3 to 7 containing all 1's.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxones(int *arr, int n, int k){
    int oc = 0, zc = 0;
    int max = 0;

    if (n < 1){
        return 0;
    }

    // printf("n = %d\n", n);
    for (int i = 0; i < n; i++){
        int j;
        for (j = i; j < n; j++){
            // printf("arr[%d] = %d\n", j, arr[j]);
            if (arr[j] == 1){
                oc++;            
                // printf("oc = %d\n", oc);
            } else if (zc < k){
                zc++;
                oc++;
                // printf("oc = %d\tzc = %d\n", oc, zc);
            } else {
                // printf("max seq = %d\nrestarting count at %d\n\n", oc, i+1);
                zc = 0;
                oc = 0;
                break;
            }
        }
        if (oc > max){
            // printf("new max seq = %d\nrestarting count at %d\n\n", oc, i+1);
            max = oc;
        }
        if (j == n)
            break;
    }

    return oc;
}


int maxones_better(int *arr, int n, int k){
    int start = 0, end = 0;
    int count = 0;
    int max = 0;
    int seq = 0;

    for (end = 0; end < n; end++){
        // printf("arr[%d] = %d\n", end, arr[end]);
        if (arr[end] == 0){
            count++;
        } 
            
        while (count > k){                
            // printf("too many zeroes\n");
            if (arr[start] == 0){
                count--;                    
            }
            start++;
            // printf("moving starting point at %d\n", start);            
        }
        seq = end - start + 1;
        if (seq > max){
            max = seq;
            // printf("new max seq = %d\n", max);
        }
    }

    return max;
}


void main (){
    int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    int k = 2;
    
    // int arr[] = {1, 0, 0, 1, 0, 1, 0, 1};
    // int k = 2;
    
    // int arr[] = {1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1};
    //   int arr[] = {1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1};

    int n = sizeof(arr)/sizeof(int);
    
    clock_t start = clock();
    printf("%d \n", maxones(arr, n, k));
    clock_t end = clock();
    printf("total elapsed time: %f\n", ((double)(end-start))/CLOCKS_PER_SEC);

    start = clock();
    printf("%d \n", maxones_better(arr, n, k));
    end = clock();
    printf("total elapsed time: %f\n", ((double)(end-start))/CLOCKS_PER_SEC);

    return;
}