#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int topsort(vector<vector<int>> &array, vector<int> &topsortArray, vector<bool> &black, vector<int> &vertex, int peak,
            int k) {
    vertex[peak] = k;
    for (int i = 0; i < array[peak].size(); i++) {
        if (vertex[array[peak][i]] == 0) {
            int check = topsort(array, topsortArray, black, vertex, array[peak][i], k);
            if (check == -1) {
                return -1;
            }
        } else {
            if (!black[array[peak][i]])
                return -1;
        }
    }
    topsortArray.push_back(peak);
    black[peak] = true;
    return 0;
}

int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<vector<int>> array(n, vector<int>());
    vector<int> topsortArray;
    vector<bool> black(n);
    int k = 0;

    for (int i = 0; i < m; i++) {
        int first;
        int second;
        cin >> first >> second;
        array[first - 1].push_back(second - 1);
    }

    vector<int> vertex(n);
    for (int i = 0; i < n; i++) {
        vertex[i] = 0;
        black[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (vertex[i] == 0)
            int tmp = topsort(array, topsortArray, black, vertex, i, ++k);
    }
    reverse(topsortArray.begin(), topsortArray.end());
    bool ans = true;
    for (int i = 0; i < n - 1; i++) {
        bool tmpAns = false;
        for (int j = 0; j < array[topsortArray[i]].size(); j++) {
            if (array[topsortArray[i]][j] == topsortArray[i + 1])
                tmpAns = true;
        }
        if (!tmpAns)
            ans = false;
    }

    vector<string> stackNames;
    char tmpChar[6];
    tmpChar[0] = 's';
    tmpChar[1] = 't';
    tmpChar[2] = 'a';
    tmpChar[3] = 'c';
    tmpChar[4] = 'k';
    tmpChar[5] = 0 + '0';
    string tmpString = tmpChar;
    stackNames.push_back(tmpChar);
    cout << stackNames[0];
    return 0;
}