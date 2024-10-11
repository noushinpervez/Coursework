#include<bits/stdc++.h>

using namespace std;

int color[100], dis[100], parent[100], finish[100];
vector<int>adj[100];
int t = 0;

void dfs(int u){
    t = t + 1;
    dis[u] = t;
    color[u] = 1;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(color[v] == 0){
            parent[v] = u;
            cout << u << " -> " << v << " tree edge" << endl;
            dfs(v);
        }
        else if(color[v] == 1){
            cout << u << " -> " << v << " back edge" << endl;
            cout << "Cycle found" << endl;
        }
        else{
            if(dis[u] < dis[v])
                cout << u << " -> " << v << " forward edge" << endl;
            else
                cout << u << " -> " << v << " cross edge" << endl;
        }
    }
    t = t + 1;
    finish[u] = t;
    color[u] = 2;
}

int main(){
    int n, edge, u, v;
    cout << "Enter number of vertex: ";
    cin >> n;
    cout << "Enter number of edge: ";
    cin >> edge;
    for(int i = 0; i < edge; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        color[i] = 0;
        parent[i] = -1;
        dis[i] = 99999;
        finish[i] = 99999;
    }

    int source, destination;
    cout << "Source: ";
    cin >> source;
    cout << "Destination: ";
    cin >> destination;

    dfs(source);
    if(color[destination] != 0)
        cout << "Reachable" << endl;
    else
        cout << "Not reachable" << endl;
}
