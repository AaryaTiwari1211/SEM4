#include<iostream>
using namespace std;

#define INFINITY 999
#define V 9

int minDistance(int distances[V] , bool visited[V])
{
    int min = INFINITY;        // Initalizes the minimum value to infinity
    int min_index;             // Initializes Minimum Index
    for(int i = 0;i<V;i++)
    {
        if(!visited[i] && min>distances[i])
        {
            min = distances[i];
            min_index = i;
        }
    }
    return min_index;
}

void print(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void djikstra(int graph[V][V] , int start)
{
    int distances[V];
    bool visited[V];
    distances[start] = 0;
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        if(i!=start)
        {
            distances[i] = INFINITY;
        }
    }
    
    for(int i=0;i<V-1;i++)
    {
        int u = minDistance(distances,visited);
        visited[u]=true; // Visited set to true
        for(int j=0;j<V;j++)
        {
            if(!visited[j] && graph[u][j] && distances[u] != INFINITY && distances[u] + graph[u][j] <= distances[j])
            {
                distances[j] = distances[u] + graph[u][j];
            }
        }
    }
    print(distances , V);
}

int main()
{
    int graph[V][V] = { 
                            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                    };
    djikstra(graph,0);
    return 0;
}

