#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
int infinity = 1e6 + 1;
#define int long long

int32_t main() {
    vector<vector<vector<int>>> database(0, vector<vector<int>>(0, vector<int>(2)));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priority;
    vector<int> used;
    int n = 0;
    int m = 0;
    cin >> n >> m;
    database.resize(n);
    used.resize(n);
    int result = 0;
    used.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int x;
        int y;
        int mass;
        cin >> x >> y >> mass;
        x-=1;
        y-=1;
        vector<int> tmp1(2);
        vector<int> tmp2(2);
        tmp1[0]=x;
        tmp1[1]=mass;
        tmp2[0]=y;
        tmp2[1]=mass;
        database[x].push_back(tmp2);
        database[y].push_back(tmp1);
    }
    priority.push({0, 0});

    while(!priority.empty()) {
        pair<int, int> tmp= priority.top();
        priority.pop();
        int mass=tmp.first;
        int point=tmp.second;
        if(used[point]){
            continue;
        }
        used[point]=1;
        result+=mass;
        for (int j = 0; j < database[point].size(); j++) {
            if(used[database[tmp.second][j][0]]==0){
                priority.push({database[tmp.second][j][1], database[tmp.second][j][0]});
            }
        }
    }
    cout << result;
    return 0;
}
