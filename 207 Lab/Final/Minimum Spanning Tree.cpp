#include<iostream>

using namespace std;

int min_Key(int key[], bool visited[])
{
    int min = 999, min_index;

    for (int v = 0; v < 6; v++) {
        if (visited[v] == false && key[v] < min)
        {
            min = key[v];
			min_index = v;
        }
    }
    return min_index;
}

int print_MST(int parent[], int cost[6][6])
{
    int minCost = 0;
	cout <<"Edge \tWeight\n";
    for(int i = 1; i < 6; i++)
    {
		cout << parent[i] << " - " << i << " \t" << cost[i][parent[i]] << " \n";
		minCost += cost[i][parent[i]];
    }
	cout << "Total cost is " << minCost;
}

void find_MST(int cost[6][6])
{
    int parent[6], key[6];
    bool visited[6];

    for(int i = 0; i < 6; i++) {
        key[i] = 999;
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int x = 0; x < 5; x++)
    {
        int u = min_Key(key, visited);
        visited[u] = true;

        for (int v = 0; v < 6; v++)
        {
            if(cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }
	print_MST(parent, cost);
}

int main()
{
    int cost[6][6] = {{0, 4, 0, 0, 0, 2},
                      {4, 0, 6, 0, 0, 3},
                      {0, 6, 0, 3, 0, 1},
                      {0, 0, 3, 0, 2, 0},
                      {0, 0, 0, 2, 0, 4},
                      {2, 3, 1, 0, 4, 0}
                      };
	find_MST(cost);

    return 0;
}
