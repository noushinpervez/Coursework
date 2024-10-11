#include<bits/stdc++.h>

using namespace std;

struct activity{
    int st, ft;
}lst[100], tmp;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> lst[i].st;
        cin >> lst[i].ft;
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

    int flag = 0;
    for(int i = 0; i < n; i++){
        if(take[i] == 1)
            flag++;
    }
    cout << flag;
}
