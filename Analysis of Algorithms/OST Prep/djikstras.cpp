#include<iostream>
using namespace std;

#define INFINITY 999
#define V 4


//INT_MAX

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

void print(int arr[] , int size)
{
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void djikstra(int graph[V][V] , int start)
{
    bool visited[V];
    int distances[V];
    distances[start] = 0;
    for(int i = 0;i<V;i++)
    {
        visited[i]=false;
        if(i!=start)
        {
            distances[i] = INFINITY;
        }
    }
    for(int i = 0;i<V-1;i++)
    {
        int u = minDistance(distances,visited);
        visited[u] = true;
        for(int j = 0;j<V;j++)
        {
            if(!visited[j] && graph[u][j] && distances[u]!=INFINITY && distances[u] + graph[u][j] <= distances[j])
            {
                distances[j] = distances[u] + graph[u][j];
            }
        }
    }
    print(distances , V);
}

int main()
{
    int graph[V][V];
    for(int i = 0;i<V;i++)
    {
        cout<<"Enter row "<<i+1<<" : ";
        for(int j = 0;j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
    djikstra(graph , 2);
}