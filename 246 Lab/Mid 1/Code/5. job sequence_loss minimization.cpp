#include<bits/stdc++.h>

using namespace std;

struct job{
    int no;
    double time, loss, lt;
}job[100], temp;

int main(){
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        job[i].no = i + 1;
        cout << "Enter time: ";
        cin >> job[i].time;
        cout << "Enter loss: ";
        cin >> job[i].loss;
        job[i].lt = job[i].loss / job[i].time;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(job[i].lt < job[j].lt){
                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
        cout << job[i].no << " ";
}
