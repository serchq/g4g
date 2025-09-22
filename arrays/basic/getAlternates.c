/*
Given an array arr[], the task is to print every alternate element of the array starting from the first element.

Examples:

Input: arr[] = [10, 20, 30, 40, 50]
Output: 10 30 50
Explanation: Print the first element (10), skip the second element (20), print the third element (30), skip the fourth element(40) and print the fifth element(50).

Input: arr[] = [-5, 1, 4, 2, 12]
Output: -5 4 12
*/


void getalternates(int *arr, int n){
    for (int i = 0; i < n; i++){
        if (i%2 == 0){
           printf("%d ", arr[i]); 
        }
    }
    printf("\n");

    return;
}




int main(){
    int arr[] = {10, 20, 30, 40, 50};


    int n = sizeof(arr)/sizeof(int); 

    getalternates(arr, n);
}
