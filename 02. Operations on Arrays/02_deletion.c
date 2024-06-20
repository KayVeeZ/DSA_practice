#include<stdio.h>
void display(int arr[], int n){
    // code for traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void indDeletion(int arr[], int size, int index){
    //  code for deletion
     
     for (int i = index; i < size - 1; i++)
     {
        arr[i] = arr[i+1];
     }
}

int main(){ 
    
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3;
    display(arr,size);
    indDeletion(arr, size, index);
    
    size -= 1;
    printf("Element has been deleted! Look!!!\n");
    display(arr,size);
    return 0;
}