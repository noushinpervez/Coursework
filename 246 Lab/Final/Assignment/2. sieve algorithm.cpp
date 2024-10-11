#include<bits/stdc++.h>

using namespace std;

// initially all the numbers are unmarked
vector<int>prime(100000, 0); // creating a vector of size 100000 with all values as 0

void seive(int n){
    for(int i = 2; i <= n; i++){
        if(prime[i] == 0){
            for(int j = i * i; j <= n; j += i)
                prime[j] = 1; // mark the multiples of numbers
        }
    }

    // print the unmarked numbers
    for(int i = 2; i <= n; i++){
        if(prime[i] == 0)
            cout << i << " ";
    }
}

int main(){
    int n; // print all primes smaller than or equal to n
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime numbers from 1 to " << n << ": " << endl;
    seive(n);
}
