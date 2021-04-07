#include <vector>
#include <queue>
#include <iostream>

int INF = 1e9;

struct Edge {
    int to;
    int flow;
    int maxFlow;
};

bool bfs(std::vector<std::vector<Edge>>& G, std::vector<int>& dist, int& s, int& t) {
    dist.assign(dist.size(), INF);
    std::queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (Edge& e : G[v]) {
            if (dist[e.to] == INF && e.flow < e.maxFlow) {
                q.push(e.to);
                dist[e.to] = dist[v] + 1;
            }
        }
    }
    return dist[t] != INF;
}

int dfs(std::vector<std::vector<Edge>>& G, std::vector<int>& dist, int t, int flow, int v) {
    if (flow == 0) {
        return 0;
    }
    if (v == t){
        return flow;
    }
    for (Edge& e : G[v]) {
        if (dist[e.to] != dist[v] + 1) {
            continue;
        }
        int res = dfs(G, dist, t, std::min(flow, e.maxFlow - e.flow), e.to);
        if (res > 0) {
            e.flow += res;
            for (Edge& w : G[e.to]) {
                if (w.to == v) {
                    w.flow -= res;
                    break;
                }
            }
            return res;
        }
    }
    return 0;
}

int dinic(std::vector<std::vector<Edge>>& G, int s, int t) {
    std::vector<int> dist(G.size(), INF);
    int res = 0;
    while (bfs(G, dist, s, t)) {
        res += dfs(G, dist, t, INF, s);
    }
    return res;
}

int32_t main() {
    int n;
    int m;
    int k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<Edge>> graph(n + m + 366 );
    for (int i = 1; i <= n; i++) {
        graph[0].push_back({i, 0, 1});
        graph[i].push_back({0, 1, 1});
    }
    int from, to;
    for (int i = 0; i < k; i++) {
        std::cin >> from >> to;
        graph[from].push_back({n + to, 0, 1});
        graph[n + to].push_back({from, 1, 1});
    }
    for (int i = n + 1; i <= n + m; i++) {
        graph[i].push_back({n + m + 1, 0, 1});
        graph[n + m + 1].push_back({i, 1, 1});
    }
    std::cout << dinic(graph, 0, n + m + 1) << std::endl;
}