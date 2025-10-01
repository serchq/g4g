/*
Given a sorted array arr[] of size n, the goal is to rearrange the array so 
that all distinct elements appear at the beginning in sorted order. Additionally, 
return the length of this distinct sorted subarray.

Note: The elements after the distinct ones can be in any order and hold any value, 
as they don't affect the result.

Examples: 

Input: arr[] = [2, 2, 2, 2, 2]
Output: [2]
Explanation: All the elements are 2, So only keep one instance of 2.

Input: arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]
Output: [1, 2, 3, 4, 5]

Input: arr[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation : No change as all elements are distinct.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int removeDuplicates2(int *arr, int n){      
    int k = 1;

    if (n <= 1)
        return k;

    for (int i = 1; i < n; i++){
        if (arr[i] != arr[i - 1]){
            arr[k++] = arr[i];
        }    
    }

    return k;
}



int *removeDuplicates(int *arr, int n, int *k){      
    int *result = (int*)malloc(n*sizeof(arr));
    
    if (n <= 1)
        return arr[0];

    result[0] = arr[0];    
    for (int i = 1; i < n; i++){
        if (arr[i] != result[*k]){
            result[++(*k)] = arr[i];
        }    
    }

    (*k)++;
    return result;
}


int main(){
    clock_t start, end;
    // int arr[] = {2, 2, 2, 2, 2};
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    // int arr[] = {1, 2, 3};

    int n = sizeof(arr) / sizeof (int);

    int k;

    start = clock();
    int *result = removeDuplicates(arr, n, &k);

    printf("[ ");
    for (int i = 0; i < k; i++){
        printf("%d ", result[i]);
    }
    printf("]\n");
    
    end = clock();
    printf("\n\ntotal elapsed time: %f\n\n\n\n", ((double)(end-start))/CLOCKS_PER_SEC);

    start = clock();
    k = removeDuplicates2(arr, n);

    printf("[ ");
    for (int i = 0; i < k; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
    
    end = clock();
    printf("\n\ntotal elapsed time: %f\n\n\n\n", ((double)(end-start))/CLOCKS_PER_SEC);
    
    return 0;
}