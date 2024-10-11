#include<bits/stdc++.h>

using namespace std;

int dp[100][100];
int tr[100][100];

int knapsack(int weight[], int val[], int cap, int n){
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 0; i <= cap; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= cap; j++){
            if(weight[i] <= j){
                if(val[i] + dp[i - 1][j - weight[i]] > dp[i - 1][j]){
                    tr[i][j] = 1;
                    dp[i][j] = val[i] + dp[i - 1][j - weight[i]];
                }
                else{
                    tr[i][j] = 2;
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else{
                tr[i][j] = 2;
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "DP Table: " << endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= cap; j++)
            cout << dp[i][j] << " ";

        cout << endl;
    }

    return dp[n][cap];
}

void traceback(int weight[], int val[], int cap, int n){
    if(n == 0 || cap == 0)
        return;

    if(tr[n][cap] == 1){
        traceback(weight, val, cap - weight[n], n - 1);
        cout << weight[n] << "\t" << val[n] << endl;
    }
    else if(tr[n][cap] == 2)
        traceback(weight, val, cap, n - 1);
}

int main(){
    int n, cap;
    cout << "Enter the number of product: ";
    cin >> n;
    cout << "Enter the capacity of knapsack: ";
    cin >> cap;

    int weight[100], val[100];
    cout << "Enter weight of products: ";
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter val of products: ";
    for(int i = 0; i < n; i++)
        cin >> val[i];

    cout << knapsack(weight, val, cap, n) << endl;
    traceback(weight, val, cap, n);
}
