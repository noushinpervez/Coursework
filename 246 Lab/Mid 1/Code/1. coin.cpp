#include<iostream>

using namespace std;

struct coin{
    int coinvalue;
}lst[100];

int main(){
    int n, m;
    cout << "Enter an amount to change: ";
    cin >> m;
    cout << "Enter the number of coins: ";
    cin >> n;
    int a, flag = 0;
    int ans[100];
    cout << "Enter coin values: ";

    for(int i = 0; i < n; i++){
        cin >> a;
        lst[i].coinvalue = a;
    }

    for(int i = n - 1; i >= 0; i--){
        while(m > 0 && m >= lst[i].coinvalue){
            m = m - lst[i].coinvalue;
            ans[flag] = lst[i].coinvalue;
            flag++;
        }
        if(m == 0)
            break;
    }
    cout << "Coin needed: ";

    for(int i = 0; i < flag; i++)
        cout << ans[i] << " ";

    cout << endl;
    cout << "Total coin: " << flag << endl;
}
