#include<bits/stdc++.h>

using namespace std;

struct node{
    int nd, weight;
}tmp;

typedef pair<int, int>pi;

vector<node>adj[100];
int dis[100], par[100];
priority_queue<pi, vector<pi>, greater<pi>>q;

void path(int target, int par[]){
    stack<int>st;

    st.push(target);

    while(par[target] != -1){
        target = par[target];
        st.push(target);
    }

    while(!st.empty()){
        if(st.size() == 1)
            cout << st.top() << " ";
        else
            cout << st.top() << " -> ";

        st.pop();
    }
}

void dijkstra(){
    while(!q.empty()){
        int u = q.top().second;
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            node t = adj[u][i];
            int v = t.nd;
            int w = t.weight;

            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                par[v] = u;

                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main(){
    int n, edge, u, v, w;
    cout << "Enter number of vertex: ";
    cin >> n;
    cout << "Enter number of edge: ";
    cin >> edge;

    for(int i = 0; i < edge; i++){
        cin >> u >> v >> w;
        tmp.nd = v;
        tmp.weight = w;
        adj[u].push_back(tmp);
    }

    for(int i = 0; i < n; i++){
        dis[i] = 99999;
        par[i] = -1;
    }

    int src;
    cout << "Enter source: ";
    cin >> src;

    dis[src] = 0;
    q.push(make_pair(dis[src], src));

    dijkstra();

    printf("Vertex Distance from Source:\n");
    for(int i = 1; i < n; i++){
        path(i, par);
        cout << dis[i] << endl;
    }
}
