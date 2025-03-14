#include <stdio.h>
#include <stdbool.h>

bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source, int destination)
{
    int **adjList = (int **)malloc(n * sizeof(int *));
    int *adjSize = (int *)calloc(n, sizeof(int));

    // keep count of corresponding node's neighbour
    for (int i = 0; i < n; i++)
    {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    // allocate relevent memory for each edge
    for (int i = 0; i < edgesSize; i++)
        adjList[i] = (int *)malloc(adjSize[i] * sizeof(int));

    // array contains value where current node neighbour will be stores
    int *index = (int *)calloc(n, sizeof(int));

    // store neighbours of respective edges
    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u][index[u]++] = v;
        adjList[v][index[v]++] = u;
    }

    free(index);

    // bfs to detect path
    bool *visited = (bool *)calloc(n, sizeof(bool));
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0;
    int back = 0;

    queue[back++] = source;
    visited[source] = true;

    bool status = false;

    while (front < back)
    {
        int curr = queue[front++];
        if (curr == destination)
        {
            status = true;
            break;
        }

        for (int i = 0; i < adjSize[curr]; i++)
        {
            if (!visited[adjList[curr][i]])
            {
                visited[adjList[curr][i]] = true;
                queue[back++] = adjList[curr][i];
            }
        }
    }

    // free memory
    free(visited);
    free(queue);
    free(adjSize);
    for (int i = 0; i < n; i++)
        free(adjList[i]);
    free(adjList);

    return status;
}