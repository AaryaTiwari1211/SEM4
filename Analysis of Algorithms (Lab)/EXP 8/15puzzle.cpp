#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 4;
const int N2 = 16;
const int LIMIT = 100;

int MDT[N2][N2];

struct Puzzle {
    int f, g, h;
    int state[N2];

    bool operator < (const Puzzle &p) const {
        return f > p.f;
    }
};

int get_distance(int s[N2]) {
    int distance = 0;
    for (int i = 0; i < N2; i++) {
        if (s[i] == N2-1) continue;
        distance += MDT[i][s[i]];
    }
    return distance;
}

void init() {
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
            MDT[i][j] = abs(i/N - j/N) + abs(i%N - j%N);
        }
    }
}

bool is_goal(int s[N2]) {
    for (int i = 0; i < N2; i++) {
        if (s[i] != i) return false;
    }
    return true;
}

int astar(int s[N2]) {
    priority_queue<Puzzle> open;
    Puzzle p;
    for (int i = 0; i < N2; i++) {
        p.state[i] = s[i];
    }
    p.g = 0;
    p.h = get_distance(p.state);
    p.f = p.g + p.h;
    open.push(p);

    while (!open.empty()) {
        Puzzle p = open.top();
        open.pop();

        if (is_goal(p.state)) return p.g;

        int zero_pos;
        for (int i = 0; i < N2; i++) {
            if (p.state[i] == 0) {
                zero_pos = i;
                break;
            }
        }

        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};
        for (int dir = 0; dir < 4; dir++) {
            int new_x = zero_pos % N + dx[dir];
            int new_y = zero_pos / N + dy[dir];
            int new_pos = new_y * N + new_x;
            if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;

            Puzzle pp = p;
            pp.h -= MDT[new_pos][p.state[new_pos]];
            pp.h += MDT[zero_pos][p.state[new_pos]];
            swap(pp.state[zero_pos], pp.state[new_pos]);
            pp.g++;
            pp.f = pp.g + pp.h;
            if (pp.f <= LIMIT) open.push(pp);
        }
    }
    return -1;
}

int main() {
    init();
    int s[N2];
    for (int i = 0; i < N2; i++) {
        cin >> s[i];
    }
    int ans = astar(s);
    cout << ans << endl;
    return 0;
}
