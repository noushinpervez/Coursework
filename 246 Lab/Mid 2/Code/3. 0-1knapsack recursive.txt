#include<bits/stdc++.h>

using namespace std;

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int knapsack(int weight[], int val[], int cap, int n){
    if(n == 0 || cap == 0)
        return 0;

    if(weight[n] <= cap)
        return max(val[n] + knapsack(weight, val, cap - weight[n], n - 1), knapsack(weight, val, cap, n - 1));
    else
        return knapsack(weight, val, cap, n - 1);
}

int main(){
    int n, cap;
    cout << "Enter the number of product: ";
    cin >> n;

    int weight[100], val[100];
    cout << "Enter weight & value of products: ";
    for(int i = 1; i <= n; i++)
        cin >> weight[i] >> val[i];

    cout << "Enter the capacity of knapsack: ";
    cin >> cap;

    cout << "Maximum Profit: " << knapsack(weight, val, cap, n);
}
