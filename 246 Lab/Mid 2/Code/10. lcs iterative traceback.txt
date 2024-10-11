#include<bits/stdc++.h>

using namespace std;

int dp[100][100];
int tr[100][100];

int sub(string x, string y, int n, int m){
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i - 1] == y[j - 1]){
                tr[i][j] = 1;
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                if(dp[i][j - 1] >= dp[i - 1][j]){
                    tr[i][j] = 2;
                    dp[i][j] = dp[i][j - 1];
                }
                else{
                    tr[i][j] = 3;
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    cout << "DP Table: " << endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++)
            cout << dp[i][j] << " ";

        cout << endl;
    }

    return dp[n][m];
}

void traceback(string x, string y, int n, int m){
    if(n == 0 || m == 0)
        return;

    if(tr[n][m] == 1){
        traceback(x, y, n - 1, m - 1);
        cout << x[n - 1];
    }
    else if(tr[n][m] == 2)
        traceback(x, y, n, m - 1);
    else if(tr[n][m] == 3)
        traceback(x, y, n - 1, m);
}

int main(){
    string x, y;
    cout << "Enter first string: ";
    cin >> x;
    cout << "Enter second string: ";
    cin >> y;

    int n = x.size();
    int m = y.size();

    cout << sub(x, y, n, m) << endl;
    traceback(x, y, n, m);
}
