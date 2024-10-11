#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, edge, u, v;
    cout << "Enter number of vertex: ";
    cin >> n;
    int matrix[n][n];
    cout << "Enter number of edge: ";
    cin >> edge;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            matrix[i][j] = 0;
    }

    for(int i = 0; i < edge; i++){
        cin >> u >> v;
        matrix[u][v] = matrix[u][v] + 1;
        matrix[v][u] = matrix[v][u] + 1;
    }

    int flag = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] > 1){
                flag = 0;
                break;
            }
        }
    }

    if(flag == 0)
        cout << "Multi graph";
    else
        cout << "Simple graph";
}
