#include <iostream>
#include<cmath>
#include<map>
#include<queue>
#include<vector>

using namespace std;

int parent[100100];
int lim[100100], n;
int alc[100100] = { 0 };


int find(int x) {
    if (lim[x]>alc[x] || x==n ) return x;
    else return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q, i, x, y, z, j, k, end;
    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> x;
        parent[i] = i + 1;
        lim[i] = x;
    }
    for (i = 0; i < q; i++) {
        cin >> x;
        if (x == 1) {
            cin >> x >> k;
            for (j = find(x); j <= n;) {
                if (j == n && k > lim[j] - alc[j]) {
                    k = lim[j] - alc[j];
                }

                if (k > lim[j] - alc[j]) {
                    k -= lim[j] - alc[j];
                    alc[j] = lim[j];
                }
                else {
                    alc[j] += k;
                    break;
                }
                j = parent[j];
            }
        }
        else {
            cin >> x;
            cout << alc[x] << "\n";
        }
        //for (j = 1; j <= n; j++) {
           // cout << j << "//" << parent[j] << endl;
        //}
        
    }
    
    
}
