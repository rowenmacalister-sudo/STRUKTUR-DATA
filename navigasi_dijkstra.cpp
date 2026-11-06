#include <iostream>
#include <vector>
#include <climits>
#include <cctype>
#include <algorithm>
using namespace std;

const int N = 6;
const int INF = INT_MAX;
int graph[N][N];

void addEdge(char a, char b, int w) {
    int x = a - 'A';
    int y = b - 'A';
    graph[x][y] = w;
    graph[y][x] = w;
}

void dijkstra(int src, int dist[], int parent[]) {
    bool visited[N] = {false};

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < N; count++) {
        int u = -1;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        if (dist[u] == INF) break;

        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

void printRoute(int parent[], int tujuan) {
    vector<int> path;
    for (int x = tujuan; x != -1; x = parent[x]) {
        path.push_back(x);
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < (int)path.size(); i++) {
        cout << char('A' + path[i]);
        if (i != (int)path.size() - 1) cout << " -> ";
    }
}

int main() {
    addEdge('A', 'B', 4);
    addEdge('A', 'C', 2);
    addEdge('B', 'C', 1);
    addEdge('B', 'D', 5);
    addEdge('B', 'E', 3);
    addEdge('C', 'D', 8);
    addEdge('C', 'E', 6);
    addEdge('D', 'E', 2);
    addEdge('D', 'F', 4);
    addEdge('E', 'F', 3);

    int dist[N], parent[N];

    dijkstra(0, dist, parent);
    cout << "=== Rute terpendek dari A ===" << endl;
    for (int i = 1; i < N; i++) {
        cout << "A ke " << char('A' + i) << " : ";
        printRoute(parent, i);
        cout << " (total " << dist[i] << " km)" << endl;
    }

    char asal, tujuan;
    cout << endl << "=== Rekomendasi Rute ===" << endl;
    cout << "Lokasi asal   (A-F): ";
    cin >> asal;
    cout << "Lokasi tujuan (A-F): ";
    cin >> tujuan;
    asal = toupper(asal);
    tujuan = toupper(tujuan);

    if (asal < 'A' || asal > 'F' || tujuan < 'A' || tujuan > 'F') {
        cout << "Lokasi harus A-F" << endl;
        return 0;
    }

    dijkstra(asal - 'A', dist, parent);
    cout << "Rute tercepat: ";
    printRoute(parent, tujuan - 'A');
    cout << endl << "Total jarak  : " << dist[tujuan - 'A'] << " km" << endl;

    return 0;
}
