#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int larr[n1],rarr[n2];
    for(int i=0;i<n1;i++){
        larr[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        rarr[i] = arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(larr[i] <= rarr[j]){
            arr[k] = larr[i];
            i++;
        }
        else{
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = larr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n - 1);
    printf("sorted array is:\n");
    printArray(arr,n);

    return 0;
}