#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;
int dist[20][20];
bool visited[20];

int tsp(int curr, int visited_count)
{
    if (visited_count == n)
    { // Base case: all cities have been visited
        return dist[curr][0];
    }

    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int new_dist = dist[curr][i] + tsp(i, visited_count + 1);
            ans = min(ans, new_dist);
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    cout << "Minimum distance for TSP is: " << tsp(0, 1) << endl;
    return 0;
}