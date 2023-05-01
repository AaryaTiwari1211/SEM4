#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 5e5 + 5;

struct Edge
{
    int to, next;
};

Edge edges[MAXM];
int head[MAXN], tot = 0;

inline void add_edge(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}

int n, m, r;
bool vis[MAXN];
double p[MAXN], maxp = 0;

void dfs(int u, double prob)
{
    vis[u] = true;
    bool deadend = true;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (!vis[v])
        {
            deadend = false;
            dfs(v, prob / (double)(head[u]));
        }
    }
    if (deadend)
    {
        p[u] += prob;
        maxp = max(maxp, p[u]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    dfs(r, 1.0);

    for (int i = 1; i <= n; i++)
    {
        if (fabs(p[i] - maxp) < 1e-9)
        {
            cout << "You will most likely be stuck on: " << i << endl;
        }
    }

    return 0;
}
