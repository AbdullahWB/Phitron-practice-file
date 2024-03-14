---------------------------------------- demo 1 ----------------------------



#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, m;
int di, dj;
char MX[N][N];
bool VIS[N][N];
pair<int, int> parent[N][N];
vector<pair<int, int>> DIR = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && !VIS[i][j]);
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    VIS[si][sj] = true;
    parent[si][sj] = {-1, -1}; // Initialize parent of source to (-1, -1)
    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int pi = par.first;
        int pj = par.second;
        if (pi == di && pj == dj) {
            return; // Exit the BFS loop when destination is reached
        }
        for (int i = 0; i < 4; i++) {
            int ci = pi + DIR[i].first;
            int cj = pj + DIR[i].second;
            if (valid(ci, cj)) {
                q.push({ci, cj});
                VIS[ci][cj] = true;
                parent[ci][cj] = {pi, pj};
            }
        }
    }
}

int main() {
    memset(parent, -1, sizeof(parent));
    cin >> n >> m;
    int si = -1, sj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MX[i][j];
            if (MX[i][j] == 'R') {
                si = i;
                sj = j;
            }
            if (MX[i][j] == 'D') {
                di = i;
                dj = j;
            }
            if (MX[i][j] == '#') {
                VIS[i][j] = true;
            }
        }
    }

    bfs(si, sj);

    pair<int, int> des = {di, dj}; // Destination coordinates
    pair<int, int> src = {-1, -1}; // Start with an invalid source
    if (parent[di][dj] != make_pair(-1, -1)) { // If destination is reachable
        src = parent[di][dj]; // Update the source coordinates
    }

    while (des != src) { // Trace back from destination to source
        MX[des.first][des.second] = 'X'; // Mark the path with 'X'
        des = parent[des.first][des.second];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << MX[i][j];
        }
        cout << endl;
    }

    return 0;
}




---------------------------------------- demo 2 -----------------------------


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



