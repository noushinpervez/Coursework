#include<bits/stdc++.h>

using namespace std;

int dp[100];

int fibo(int n){
    if(n < 2)
        return n;

    if(dp[n] != -1)
        return dp[n];
    else
        return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main(){
    int n;
    cout << "Enter a number to find sum of Fibonacci series: ";
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << fibo(n);
}
