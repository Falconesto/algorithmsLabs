#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
using namespace std;

struct edge {
    int first;
    int second;
    int edgeMass;
};

const int infinity = 1e9;

int32_t main() {
    vector<edge> edges;
    int n;
    std::cin >> n;
    int mass[1000];
    int parents[1000];
    for (int i = 0 ; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int a = i;
            int b = j;
            int c=0;
            std::cin >> c;
            if (c != (int)1e9){
                edges.push_back({a, b, c});
            }
        }
        parents[i] = -1;
    }
    int x=0;

    for(int i = 0 ; i < n ; i ++) {
        x = -1;
        for(int j = 0 ; j < edges.size() ; j ++)
            if(mass[edges[j].first] < infinity)
                if (mass[edges[j].second] > mass[edges[j].first] + edges[j].edgeMass) {
                    mass[edges[j].second] = max(-infinity, mass[edges[j].first] + edges[j].edgeMass);
                    parents[edges[j].second] = edges[j].first;
                    x = edges[j].second;
                }
    }
    if (x != -1) {
        std::cout << "YES" << std::endl;
        int y = x;
        for (int i = 0; i < n; ++i) {
            y = parents[y];
        }
        std::vector<int> path;
        for (int cur = y; ; cur = parents[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1) {
                break;
            }
        }
        reverse (path.begin(), path.end());
        std:: cout << path.size() << std::endl;
        for (int i : path) {
            std::cout << i + 1 << ' ';
        }
    }
    else {
        std::cout << "NO" <<  std::endl;
    }
    return 0;
}