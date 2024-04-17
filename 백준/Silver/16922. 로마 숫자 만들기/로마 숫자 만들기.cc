#include <iostream>
#include <cmath>
#include <set>

using namespace std;

set<int> s;
int n;
bool visited[23][10000];

void sch(int idx, int x) {
    if (idx == n) {
        s.insert(x);
        return;
    }
    int i;
    if (!visited[idx + 1][x + 1]) {
        visited[idx + 1][x + 1] = true;
        sch(idx + 1, x + 1);
    }
    if (!visited[idx + 1][x + 5]) {
        visited[idx + 1][x + 5] = true;
        sch(idx + 1, x + 5);
    }
    if (!visited[idx + 1][x + 10]) {
        visited[idx + 1][x + 10] = true;
        sch(idx + 1, x + 10);
    }
    if (!visited[idx + 1][x + 50]) {
        visited[idx + 1][x + 50] = true;
        sch(idx + 1, x + 50);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    fill_n(&visited[0][0], 23 * 10000, false);
    sch(0, 0);
    cout << s.size();

    return 0;
}