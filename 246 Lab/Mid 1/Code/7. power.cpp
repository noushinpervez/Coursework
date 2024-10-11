#include<bits/stdc++.h>

using namespace std;

int power(int x, int y){
    if(y == 0)
        return 1;
    else if(y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}

int main(){
    int x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << power(x, y);
}
