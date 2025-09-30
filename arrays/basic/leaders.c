/*
Given an array arr[] of size n, the task is to find all the Leaders in the array. An 
element is a Leader if it is greater than or equal to all the elements to its right side.

Note: The rightmost element is always a leader.

Examples:

Input: arr[] = [16, 17, 4, 3, 5, 2]
Output: [17 5 2]
Explanation: 17 is greater than all the elements to its right i.e., [4, 3, 5, 2], 
therefore 17 is a leader. 5 is greater than all the elements to its right i.e., [2], 
therefore 5 is a leader. 2 has no element to its right, therefore 2 is a leader.

Input: arr[] = [1, 2, 3, 4, 5, 2]
Output: [5 2]
Explanation: 5 is greater than all the elements to its right i.e., [2], therefore 5 
is a leader. 2 has no element to its right, therefore 2 is a leader.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void leaders(int* arr, int n){
    int* leads = (int*)malloc(n*sizeof(int));
    int lead = 0;
    int lead_index = 0;

    for (int i = 0; i < n; i++){
        int j = i+1;
        while (j < n){
            if (arr[i] < arr[j]){
                lead = 0;
                break;
            } else {
                j++;
                lead = 1;
            }            
        }
        if (lead){
            leads[lead_index] = arr[i];
            lead_index++;
        }
    }

    for (int i = 0; i < lead_index; i++){
        printf("%d ", leads[i]);
    }
    free(leads);
    return;
}



void leaders2(int* arr, int n){
    int* leads = (int*)malloc(n*sizeof(int));
    int lead_index = 0;

    leads[lead_index] = arr[n-1];

    for (int i = n-2; i >= 0; i--){
        // printf("arr[%d] = %d\tleads[%d] = %d\n", i, arr[i], lead_index, leads[lead_index]);
        if (arr[i] > leads[lead_index]){
            leads[++lead_index] = arr[i];
            // printf("storing %d\n", arr[i]);
        }
    }

    for (int i = lead_index; i >= 0; i--){
        printf("%d ", leads[i]);
    }
    free(leads);
    return;
}



void leaders_better(int* arr, int n){
    int* leads = (int*)malloc(n*sizeof(int));


    free(leads);
    return;
}


int main(){
    clock_t start, end;
    // int arr[] = {16, 17, 4, 3, 5, 2};
    // int arr[] = {1, 2, 3, 4, 5, 2};
    // int arr[] = {1, 4, 6, 11, 14, 16, 19, 23, 27, 30, 32, 36, 40, 42, 47, 51, 54, 56, 61, 64, 68, 71, 75, 78, 80, 84, 86, 90, 93, 97, 100, 103, 106, 108, 111, 115, 119, 122, 124, 126, 130, 133, 136, 139, 141, 145, 147, 151, 154, 157, 160, 163, 165, 168, 172, 174, 179, 183, 185, 188, 192, 195, 199, 201, 205, 208, 211, 213, 217, 221, 225, 227, 230, 234, 238, 241, 245, 247, 252, 256, 260, 263, 266, 269, 273, 275, 278, 281, 285, 289, 291, 295, 298, 301, 305, 308, 312, 315, 319, 323};
    int arr[] = {18, 44, 7, 372, 348, 164, 111, 177, 59, 353, 31, 385, 378, 148, 142, 67, 357, 1, 173, 391, 79, 212, 217, 84, 397, 355, 370, 107, 101, 323, 395, 337, 156, 200, 304, 161, 248, 64, 23, 11, 135, 91, 364, 360, 310, 190, 185, 169, 225, 28, 86, 327, 252, 54, 167, 315, 263, 228, 96, 50, 121, 137, 180, 274, 272, 236, 150, 255, 193, 382, 196, 260, 279, 269, 130, 158, 345, 113, 40, 73, 222, 299, 231, 126, 240, 15, 333, 287, 343, 117, 34, 21, 367, 293, 317, 206, 281, 204, 399, 244};

    int n = sizeof(arr) / sizeof (int);

    start = clock();
    leaders(arr, n);
    end = clock();
    printf("\n\ntotal elapsed time: %f\n\n\n\n", ((double)(end-start))/CLOCKS_PER_SEC);

    start = clock();
    leaders2(arr, n);
    end = clock();
    printf("\n\ntotal elapsed time: %f\n\n\n\n", ((double)(end-start))/CLOCKS_PER_SEC);
    
    return 0;
}
