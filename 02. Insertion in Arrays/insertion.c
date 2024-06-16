#include<stdio.h>
void display(int arr[], int n){
    // code for traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int indInsertion(int arr[], int size, int element, int capacity, int index){
    //  code for insertion
     if(size >= capacity){
        return -1;
     }
     for (int i = size-1; i >= index; i--)
     {
        arr[i+1] = arr[i];
     }
     arr[index] = element;
     return 1;

}

int main(){
    // change capacity to test errors
    int capacity = 100; 
    
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3;
    display(arr,size);
    int result = indInsertion(arr, size, element, capacity, index);
    
    if (result == 1){
        size += 1;
        printf("Element has been inserted! Look!!!\n");
        display(arr,size);
        return 0;
    }
    
    else{
        printf("Insertion failed!");
    }
}