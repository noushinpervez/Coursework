#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000];
int tr[1000][1000];

int subset(int arr[], int sum, int n){
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 0; i <= sum; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i] <= j){
                if(dp[i - 1][j - arr[i]] > dp[i - 1][j]){
                    tr[i][j] = 1;
                    dp[i][j] = dp[i - 1][j - arr[i]];
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
        for(int j = 0; j <= sum; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[n][sum];
}

void traceback(int arr[], int sum, int n){
    if(n <= 0 || sum == 0)
        return;

    if(tr[n][sum] == 1){
        traceback(arr, sum - arr[n], n - 1);
        cout << arr[n] << " ";
    }
    else if(tr[n][sum] == 2)
        traceback(arr, sum, n - 1);
}

int main(){
    int n, sum;
    cout << "Enter the number of product: ";
    cin >> n;

    int arr[100];
    cout << "Enter array: ";
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    cout << "Enter the sum: ";
    cin >> sum;

    if(subset(arr, sum, n)){
        cout << "Possible" << endl;
        traceback(arr, sum, n);
    }
    else
        cout << "Not Possible";
}
