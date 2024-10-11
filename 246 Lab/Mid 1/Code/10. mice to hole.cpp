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
    int n, max = -999999999;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter mice position: ";
    int mice[100], hole[100];

    for(int i = 0; i < n; i++)
        cin >> mice[i];

    cout << "Enter hole position: ";
    for(int i = 0; i < n; i++)
        cin >> hole[i];

    sort(mice, n);
    sort(hole, n);

    for(int i = 0; i < n; i++){
        if(max < abs(mice[i] - hole[i]))
            max = abs(mice[i] - hole[i]);
    }

    cout << max;
}
