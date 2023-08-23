// Data Structures and Algorithm
// Lab : Graph Traversal
// Theory: Traversing in graph, BFS Vs DFS

#include <stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

// Breadth-first search traversal logic
void bfs(int v)
{
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] && !visited[i])
        {
            q[++r] = i;
            visited[i] = 1; // Mark the node as visited when adding it to the queue
        }
    }

    if (f <= r)
    {
        bfs(q[f++]);
    }
}

int main()
{
    int v;

    // Enter the number of vertices in the graph
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }

    // Enter the adjacency matrix of the graph
    printf("\n Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Enter the vertex from where we want to traverse
    printf("\n Enter the starting vertex:");
    scanf("%d", &v);

    bfs(v);

    int allNodesReachable = 1; // Assume all nodes are reachable initially

    printf("\n The nodes which are reachable are:\n");
    for (i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            printf("%d\t", i);
        }
        else
        {
            allNodesReachable = 0; // If any node is not reachable, set the flag to 0
        }
    }

    if (allNodesReachable)
    {
        printf("\n Bfs is possible. All nodes are reachable\n");
    }
    else
    {
        printf("\n Bfs is not possible. Not all nodes are reachable\n");
    }

    return 0;
}