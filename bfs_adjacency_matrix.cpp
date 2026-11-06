#include <iostream>
#include <queue>
#include <cctype>
using namespace std;

const int N = 6;
int adj[N][N];

void bfs(int start) {
    bool visited[N] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "Urutan BFS: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << char('A' + u) << " ";

        for (int v = 0; v < N; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    int m;
    cout << "Jumlah edge: ";
    cin >> m;

    cout << "Masukkan edge (contoh: A B)" << endl;
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b;
        a = toupper(a);
        b = toupper(b);

        int x = a - 'A';
        int y = b - 'A';

        if (x < 0 || x >= N || y < 0 || y >= N) {
            cout << "Vertex harus A-F, edge ini diabaikan" << endl;
            i--;
            continue;
        }
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    char s;
    cout << "Vertex awal: ";
    cin >> s;
    s = toupper(s);

    if (s < 'A' || s > 'F') {
        cout << "Vertex awal tidak valid" << endl;
        return 0;
    }

    bfs(s - 'A');
    return 0;
}
