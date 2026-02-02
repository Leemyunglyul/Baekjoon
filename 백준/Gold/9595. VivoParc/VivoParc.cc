#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>

using namespace std;

vector<int> graph[110];
int color[110];
int n;

bool isSafe(int u, int c) {
    for (int v : graph[u]) {
        if (color[v] == c) return false;
    }
    return true;
}

bool solve(int u) {
    if (u > n) return true; 

    for (int c = 1; c <= 4; c++) { 
        if (isSafe(u, c)) {
            color[u] = c;
            if (solve(u + 1)) return true; 
            color[u] = 0;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    string line;
    
    while (cin >> line) {
        size_t pos = line.find('-');
        if (pos != string::npos) {
            int a = stoi(line.substr(0, pos));
            int b = stoi(line.substr(pos + 1));
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    if(solve(1)) {
        for(int i=1;i<=n;i++) {
            cout << i << " " << color[i] << "\n";
        }
    }
    

    return 0;
}