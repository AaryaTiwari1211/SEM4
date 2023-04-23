#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int dist[N][N];
int n;
int ans = INT_MAX;
vector<int> path, shortest_path;

void tsp(int mask, int curr, int cost) {
    if (mask == (1 << n) - 1) {
        if (dist[curr][0] != -1) {
            cost += dist[curr][0];
            if (cost < ans) {
                ans = cost;
                shortest_path = path;
                shortest_path.push_back(0);
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0 && dist[curr][i] != -1) {
            path.push_back(i);
            tsp(mask | (1 << i), i, cost + dist[curr][i]);
            path.pop_back();
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    tsp(1, 0, 0);
    cout << ans << endl;
    for (int i : shortest_path) {
        cout << i << " ";
    }
    return 0;
}
