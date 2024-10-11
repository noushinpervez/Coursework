#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000];
int tr[1000][1000];

int lcs(string x, string y, int n, int m){
    if(n == 0 || m == 0)
        return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    if(x[n - 1] == y[m - 1]){
        tr[n][m] = 1;
        return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1);
    }
    else{
        int l1 = lcs(x, y, n - 1, m);
        int l2 = lcs(x, y, n, m - 1);
        if(l1 >= l2){
            tr[n][m] = 2;
            return dp[n][m] = l1;
        }
        else{
            tr[n][m] = 3;
            return dp[n][m] = l2;
        }
    }
}

void traceback(string x, string y, int n, int m){
    if(n == 0 || m == 0)
        return;

    if(tr[n][m] == 1){
        traceback(x, y, n - 1, m - 1);
        cout << x[n - 1];
    }
    else if(tr[n][m] == 2)
        traceback(x, y, n - 1, m);
    else if(tr[n][m] == 3)
        traceback(x, y, n, m - 1);
}

int main(){
    string x, y;
    cout << "Enter first string: ";
    cin >> x;
    cout << "Enter second string: ";
    cin >> y;
    int n = x.size();
    int m = y.size();
    memset(dp, -1, sizeof(dp));

    cout << "LCS length " << lcs(x, y, n, m) << endl;
    traceback(x, y, n, m);
}
