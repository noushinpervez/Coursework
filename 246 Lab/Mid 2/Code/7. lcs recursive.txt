#include<bits/stdc++.h>

using namespace std;

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int lcs(string x, string y, int n, int m){
    if(n == 0 || m == 0)
        return 0;

    if(x[n - 1] == y[m - 1])
        return 1 + lcs(x, y, n - 1, m - 1);
    else
        return max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}

int main(){
    string x, y;
    cout << "Enter first string: ";
    cin >> x;
    cout << "Enter second string: ";
    cin >> y;
    int n = x.size();
    int m = y.size();

    cout << "LCS length " << lcs(x, y, n, m);
}
