#include <bits/stdc++.h>
using namespace std;

bool canFinish(int n, vector<vector<int>> &pre)
{
    vector<int> adj[n];
    for (auto &it : pre)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto &it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto &it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return (topo.size() == n);
}

int main()
{
    int n=2;
    vector<vector<int>> v = {{1,0}};
    canFinish(n,v);
}