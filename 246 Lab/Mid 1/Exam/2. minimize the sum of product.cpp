#include<bits/stdc++.h>

using namespace std;

int sorting(int x[], int n){
    int tmp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(x[i] > x[j]){
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
}

int main(){
    int n, tmp1, tmp2;
    cin >> n;
    int a[100], b[100];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    sorting(a, n);
    sorting(b, n);

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans += a[i] * b[n - i - 1];

    cout << ans;
}
