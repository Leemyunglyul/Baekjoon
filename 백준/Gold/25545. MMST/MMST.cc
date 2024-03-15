#include <iostream>
#include<cmath>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<vector>

using namespace std;
int vertex, edge;
vector<tuple<int, int, int, int>> e;
bool visited[500100];
int minp[200100];
int maxp[200100];
vector<int> print;

int minfind(int x) {
    if (x == minp[x]) return x;
    else return minp[x] = minfind(minp[x]);
}

int maxfind(int x) {
    if (x == maxp[x]) return x;
    else return maxp[x] = maxfind(maxp[x]);
}

bool minparent(int x, int y) {
    x = minfind(x);
    y = minfind(y);
    return x == y;
}

bool maxparent(int x, int y) {
    x = maxfind(x);
    y = maxfind(y);
    return x == y;
}

void minunion(int x, int y) {
    x = minfind(x);
    y = minfind(y);
    minp[x] = y;
}

void maxunion(int x, int y) {
    x = maxfind(x);
    y = maxfind(y);
    maxp[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, x, y, d, yes, temp;

    cin >> vertex >> edge;
    for (i = 0; i < edge; i++) {
        cin >> x >> y >> d;
        e.push_back({ d, x, y, i });
    }
    if (edge == vertex-1) {
        cout << "NO";
        return 0;
    }
    for (i = 1; i <= vertex; i++) {
        minp[i] = i;
        maxp[i] = i;
    }
    //Min st
    sort(e.begin(), e.end());
    fill_n(&visited[0], 500100, false);
    for (i = 0; i < e.size(); i++) {
        int x = get<1>(e[i]);
        int y = get<2>(e[i]);
        if (!minparent(x, y)) {
            minunion(x, y);
            visited[i] = true;
        }
    }
    //MMST
    for (i = 0, yes = 0; i < e.size(); i++) {
        x = get<1>(e[i]);
        y = get<2>(e[i]);
        temp = get<3>(e[i]);
        if (yes==0 && !visited[i]) {
            yes = 1;
            maxunion(x, y);
            print.push_back(temp+1);
            for (j = 0; j < i; j++) {
                x = get<1>(e[j]);
                y = get<2>(e[j]);
                temp = get<3>(e[j]);
                if (!maxparent(x, y)) {
                    maxunion(x, y);
                    print.push_back(temp+1);
                }
            }
        }
        else if (yes == 1) {
            if (!maxparent(x, y)) {
                maxunion(x, y);
                print.push_back(temp + 1);
            }
        }
    }
    sort(print.begin(), print.end());
    cout << "YES\n";
    for (i = 0; i < print.size(); i++) {
        cout << print[i] << " ";
    }
}
