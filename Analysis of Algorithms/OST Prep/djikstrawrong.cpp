#include<iostream>
#define v 5
#define max 999
using namespace std;
bool visited[v]; // track of visited node

int minDistance(int distance[v], bool visited[v])
{
    int min = max;
    int minIndex;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && min > distance[i])
        {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijikstras(int graph[v][v], int source)
{

    int dist[v];    // this has shortest dist from start to each node

    // initializing all distances to infinity except the start node
    for (int i = 0; i < v; i++)
    {
        dist[i] = max;
        visited[i] = false;
    }
    dist[source] = 0;

    for (int j = 0; j < v; j++)
    {
        int minDist = minDistance(dist, visited);
        // mark the selected vertex as visited
        visited[minDist] = true;

        // updating the distance of cost matrix
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && graph[minDist][i] && dist[minDist] != max && dist[minDist] + graph[minDist][i] <= dist[v])
            {
                dist[i] = dist[minDist] + graph[minDist][i];
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << i << " " << dist[i] << " " << endl;
    }
}

int main()
{
    int cost[v][v];
    cout << "Enter cost matrix : \n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> cost[i][j];
        }
    }
    int source;
    cout << "enter the source ";
    cin >> source;
    dijikstras(cost, source);
}