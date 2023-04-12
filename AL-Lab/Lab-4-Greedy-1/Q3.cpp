// Topological Sorting
#include <bits/stdc++.h>
using namespace std;

#define MAX 100

void topologicalSort(int n, int graph[MAX][MAX])
{
    int inDegree[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                inDegree[j]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    vector<int> result;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0)
            {
                if (--inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        count++;
    }

    if (count != n)
    {
        cout << "The graph contains a cycle.\n";
        return;
    }

    cout << "Topological Sorting of the graph: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    int graph[MAX][MAX];
    memset(graph, 0, sizeof(graph));

    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }

    topologicalSort(n, graph);

    return 0;
}