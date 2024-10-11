#include<stdio.h>

void insert(int a[], int heapsize){
    for(int i = heapsize / 2; i >= 0; i--)
        heapify(a, i, heapsize);
}

void heapify(int a[], int i, int heapsize){
    int largest;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if(left <= heapsize && a[left] > a[i])
        largest = left;
    else
        largest = i;
    if(right <= heapsize && a[right] > a[largest])
        largest = right;
    if(largest != i){
        int tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        heapify(a, largest, heapsize);
    }
}

void heapSort(int a[], int heapsize){
    insert(a, heapsize);
    for(int i = heapsize; i > 0; i--){
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        heapsize--;
        heapify(a, 0, heapsize);
    }
}

int main(){
    int size;
    printf("Enter the number of nodes: ");
    scanf("%d", &size);
    int a[size];
    for(int i = 0; i < size; i++){
        printf("Enter a value: ");
        scanf("%d", &a[i]);
    }

    int heapsize = size - 1;
    insert(a, heapsize);
    printf("\nMax heap array: ");
    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);

    heapSort(a, heapsize);
    printf("\nHeap sort array: ");
    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);
}
