#include <iostream>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
};

struct arrayy {
    int distance;
    char value;
};


string bfs(vector<vector<arrayy>> &arr, int iStart, int jStart, int x, int y) {
    queue<point> pointsQueue;
    point firstPoint;
    firstPoint.x = jStart;
    firstPoint.y = iStart;
    pointsQueue.push(firstPoint);
    while (!pointsQueue.empty()) {
        point first = pointsQueue.front();
        pointsQueue.pop();
        if (arr[first.y][first.x].value == 'T') {
            string route;
            int yLimit = first.y;
            int xLimit = first.x;
            for (int i = 0; i < arr[yLimit][xLimit].distance; i++) {
                if ((first.y - 1 >= 0) && (arr[first.y - 1][first.x].distance == arr[first.y][first.x].distance - 1)) {
                    route.insert(0, "D");
                    first.y = first.y - 1;
                } else {
                    if ((first.x - 1 >= 0) &&
                        (arr[first.y][first.x - 1].distance == arr[first.y][first.x].distance - 1)) {
                        route.insert(0, "R");
                        first.x = first.x - 1;
                    } else {
                        if ((first.x + 1 < x) &&
                            (arr[first.y][first.x + 1].distance == arr[first.y][first.x].distance - 1)) {
                            route.insert(0, "L");
                            first.x = first.x + 1;
                        } else {
                            if ((first.y + 1 < y) &&
                                (arr[first.y + 1][first.x].distance == arr[first.y][first.x].distance - 1)) {
                                route.insert(0, "U");
                                first.y = first.y + 1;
                            }
                        }
                    }
                }
            }
            return route;
        } else {
            if (((first.y + 1 < y) &&
                 ((arr[first.y + 1][first.x].value == '.') || (arr[first.y + 1][first.x].value == 'T'))) &&
                (arr[first.y + 1][first.x].distance == -1)) {
                arr[first.y + 1][first.x].distance = arr[first.y][first.x].distance + 1;
                point tmp;
                tmp.x = first.x;
                tmp.y = first.y + 1;
                pointsQueue.push(tmp);
            }
            if (((first.x - 1 >= 0) &&
                 ((arr[first.y][first.x - 1].value == '.') || (arr[first.y][first.x - 1].value == 'T'))) &&
                (arr[first.y][first.x - 1].distance == -1)) {
                arr[first.y][first.x - 1].distance = arr[first.y][first.x].distance + 1;
                point tmp;
                tmp.x = first.x - 1;
                tmp.y = first.y;
                pointsQueue.push(tmp);
            }
            if (((first.x + 1 < x) &&
                 ((arr[first.y][first.x + 1].value == '.') || (arr[first.y][first.x + 1].value == 'T'))) &&
                (arr[first.y][first.x + 1].distance == -1)) {
                arr[first.y][first.x + 1].distance = arr[first.y][first.x].distance + 1;
                point tmp;
                tmp.x = first.x + 1;
                tmp.y = first.y;
                pointsQueue.push(tmp);
            }
            if (((first.y - 1 >= 0) &&
                 ((arr[first.y - 1][first.x].value == '.') || (arr[first.y - 1][first.x].value == 'T'))) &&
                (arr[first.y - 1][first.x].distance == -1)) {
                arr[first.y - 1][first.x].distance = arr[first.y][first.x].distance + 1;
                point tmp;
                tmp.x = first.x;
                tmp.y = first.y - 1;
                pointsQueue.push(tmp);
            }
        }
    }
    string route = "bad";
    return route;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x;
    int y;
    cin >> x >> y;
    if (x * y < 2) {
        cout << -1;
        return 0;
    }
    vector<vector<arrayy>> arr(x, vector<arrayy>(y));
    int iStart = -1;
    int jStart = -1;
    bool sExists = false;
    bool tExists = false;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            char lol;
            cin >> lol;
            arr[i][j].value = lol;
            if (arr[i][j].value == 'T') {
                tExists = true;
            }
            if (arr[i][j].value == 'S') {
                arr[i][j].distance = 0;
                sExists = true;
                iStart = i;
                jStart = j;
            } else
                arr[i][j].distance = -1;
        }
    }

    if ((sExists) && (tExists)) {
        string route = bfs(arr, iStart, jStart, y, x);
        if(route=="bad"){
            cout << -1;
            return 0;
        }
        cout << route.length() << endl;
        cout << route;
    } else {
        cout << -1;
        return 0;
    }
    return 0;
}

CPerson Vasya(Vasya Poopkin, 11);
CPerson Vasiliy(Vasya);
CPerson Sanek;
sanek


KvMng syka(1, 2, 3);
vivedi(syka);
//x^2 + 2*x + 3
KvMng blyat(x^2 + 2*x + 3);
int k = znach(blyat, 1);
int s = Cho-to