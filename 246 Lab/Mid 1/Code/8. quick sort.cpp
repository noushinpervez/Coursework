#include<bits/stdc++.h>

using namespace std;

int partition(int A[], int p, int r){
    int pivot = A[r];
    int i = p - 1;

    for(int j = p; j < r; j++){
        if(A[j] <= pivot){
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;

    return (i + 1);
}

void quickSort(int A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main(){
    int A[3];
    cout << "Enter the 3 numbers to sort: ";

    for(int i = 0; i < 3; i++)
        cin >> A[i];

    quickSort(A, 0, 2);
    cout << "After Sorting the 3 numbers: ";

    for(int i = 0; i < 3; i++)
        cout << A[i] << " ";
    cout << endl;
}
