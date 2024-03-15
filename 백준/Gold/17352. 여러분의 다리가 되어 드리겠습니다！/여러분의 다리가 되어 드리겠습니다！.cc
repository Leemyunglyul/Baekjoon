#include <iostream>
#include<cmath>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<vector>

using namespace std;

int vertex;
int parent[300100];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
}

void unionn(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> vertex;
    int x, y, i;
    for (i = 1; i <= vertex; i++) {
        parent[i] = i;
    }
    for (i = 1; i <= vertex - 2; i++) {
        cin >> x >> y;
        unionn(x, y);
    }
    for (i = 1; i <= vertex; i++) {
        find(i);
    }
    for (i = 2, x=parent[1]; i <= vertex; i++) {
        if (parent[i] != x) {
            cout << x << " " << parent[i];
            return 0;
        }
    }
}
