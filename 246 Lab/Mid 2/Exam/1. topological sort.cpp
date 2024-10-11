#include<bits/stdc++.h>

using namespace std;

int dis[100], col[100], par[100], fin[100];
vector<int>adj[100];
vector<int>result;
int t = 0;

int dfs(int u){
    int flag = 0;
    t = t + 1;
    dis[u] = t;
    col[u] = 1;

    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];

        if(col[v] == 0){
            par[v] = u;
            dfs(v);
        }
        else if(col[v] == 1){
            flag = 1;
            cout << "Cycle Found" << endl;
            return flag;
        }
    }

    t = t + 1;
    fin[u] = t;
    col[u] = 2;

    result.push_back(u);
}

int main(){
    int n, edge, u, v;
    cin >> n;
    cin >> edge;

    for(int i = 0; i < edge; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 0; i < n; i++){
        col[i] = 0;
        dis[i] = 99999;
        fin[i] = 99999;
        par[i] = -1;
    }

    for(int i = 0; i < adj[u].size(); i++){
        if(col[i] == 0){
            if(dfs(i) == 1){
                dfs(i);
                break;
            }
            else{
                reverse(result.begin(), result.end());

                for(int i = 0; i < result.size(); i++)
                    cout << result[i] << " ";
            }
        }
    }
}
