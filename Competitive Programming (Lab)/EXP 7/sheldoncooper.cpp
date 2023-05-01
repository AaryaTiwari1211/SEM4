#include <bits/stdc++.h>

using namespace std;

vector<int> adj[999];

bool vis[999];

void dfs(int s)

{
    vis[s] = true;
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (vis[adj[s][i]] == false)
            dfs(adj[s][i]);
    }
}

int main()

{

    int t;
    cin >> t;

    while (t--)

    {

        int a, b, x, y;
        cin >> a >> b;

        int count = 0;

        for (int i = 1; i <= b; i++)

        {

            cin >> x >> y;

            adj[x].push_back(y);

            adj[y].push_back(x);
        }

        for (int i = 1; i <= a; i++)

        {

            if (vis[i] == false)

            {

                dfs(vis[i]);

                count++;
            }
        }

        cout << (count - 1) << endl;
    }
}