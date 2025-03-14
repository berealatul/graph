#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adjList(n);
        for (auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        return bfs(adjList, source, destination);
    }

    bool bfs(vector<vector<int>> &adjList, int source, int destination)
    {
        queue<int> q;
        vector<bool> visited(adjList.size(), false);

        visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr == destination)
                return true;

            for (auto neighbour : adjList[curr])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return false;
    }
};

// Time Consumed: 40 Minutes