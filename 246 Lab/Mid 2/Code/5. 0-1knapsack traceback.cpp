#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000];
int tr[1000][1000];

int knapsack(int weight[], int val[], int cap, int n){
    if(n == 0 || cap == 0)
        return 0;

    if(dp[n][cap] != -1)
        return dp[n][cap];

    if(weight[n] <= cap){
        int l1 = val[n] + knapsack(weight, val, cap - weight[n], n - 1);
        int l2 = knapsack(weight, val, cap, n - 1);
        if(l1 >= l2){
            tr[n][cap] = 1;
            return dp[n][cap] = l1;
        }
        else{
            tr[n][cap] = 0;
            return dp[n][cap] = l2;
        }
    }
    else{
        tr[n][cap] = 0;
        return dp[n][cap] = knapsack(weight, val, cap, n - 1);
    }
}

void traceback(int weight[], int val[], int cap, int n){
    if(n == 0 || cap == 0)
        return;

    if(tr[n][cap] == 1){
        cout << n << " " << weight[n] << " " << val[n] << endl;
        traceback(weight, val, cap - weight[n], n - 1);
    }
    else
        traceback(weight, val, cap, n - 1);
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

    memset(dp, -1, sizeof(dp));

    cout << "Maximum Profit: " << knapsack(weight, val, cap, n) << endl;
    cout << "Products taken: ";
    traceback(weight, val, cap, n);
}
