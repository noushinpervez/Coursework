#include<bits/stdc++.h>

using namespace std;

struct activity{
    int st, ft;
}lst[100], tmp;

int main(){
    int n, s, f;
    cout << "Enter the number of activity: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter start time: ";
        cin >> s;
        cout << "Enter finish time: ";
        cin >> f;
        lst[i].st = s;
        lst[i].ft = f;
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(lst[i].ft > lst[j].ft){
                tmp = lst[i];
                lst[i] = lst[j];
                lst[j] = tmp;
            }
        }
    }

    int take[100];
    int flag = 0;

    for(int i = 0; i < n; i++)
        take[i] = 0;

    for(int i = 0; i < n; i++){
        if(take[i] != -1){
            take[i] = 1;
            for(int j = i + 1; j < n; j++){
                if(lst[i].ft > lst[j].st)
                    take[j] = -1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(take[i] == 1)
            flag++;
    }

    cout << endl;
    cout << "Activity taken: " << flag << endl;
}
