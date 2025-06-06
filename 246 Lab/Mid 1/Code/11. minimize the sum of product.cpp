#include<bits/stdc++.h>

using namespace std;

int sort(int x[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(x[i] > x[j]){
                int tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
        }
    }
}

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int a[100], b[100];
    int ans = 0;
    cout << "Enter array 1: ";

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter array 2: ";
    for(int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, n);
    sort(b, n);

    for(int i = 0; i < n; i++)
        ans += a[i] * b[n - i - 1];

    cout << "Minimum sum is " << ans;
}
