#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
pair<int, int> parent[1005][1005];
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int ci, int cj) {
    return (ci >= 0 && ci < n && cj >= 0 && cj < m && a[ci][cj] != '#' && parent[ci][cj] == make_pair(-1, -1));
}

void bfs(int si, int sj, int di, int dj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    parent[si][sj] = {-2, -2};
    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        if (par.first == di && par.second == dj)
            return; 

        for (int i = 0; i < 4; i++) {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj)) {
                q.push({ci, cj});
                parent[ci][cj] = par;
            }
        }
    }
}

void markShortestPath(int si, int sj, int di, int dj) {
    pair<int, int> curr = {di, dj};
    while (curr != make_pair(si, sj)) {
        if (a[curr.first][curr.second] != 'D' && a[curr.first][curr.second] != 'R') {
            a[curr.first][curr.second] = 'X';
        }
        curr = parent[curr.first][curr.second];
    }
}

int main() {
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'R') {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'D') {
                di = i;
                dj = j;
            }
            parent[i][j] = {-1, -1}; 
        }
    }

    bfs(si, sj, di, dj);

    if (parent[di][dj] != make_pair(-1, -1)) {
        markShortestPath(si, sj, di, dj);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}