#include <iostream>
#include <vector>

using namespace std;

long long segt[410000];

long long init(int node, int st, int end){
    if(st == end) return segt[node] = 1;
    int mid = (st + end) / 2;
    return segt[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int n, int st, int end, int t){
    if(t < st || t > end) return; 
    segt[n]--;

    if(st == end) return;
    int mid = (st + end) / 2;
    update(n * 2, st, mid, t);
    update(n * 2 + 1, mid + 1, end, t);
}

long long find(int n, int st, int end, int x){
    if(st == end) return st;

    int mid = (st + end) / 2;
    if(segt[n * 2] >= x) return find(n * 2, st, mid, x);
    else return find(n * 2 + 1, mid + 1, end, x - segt[n * 2]);
}

vector<long long> print;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, k;
    cin >> n >> k;
    
    init(1, 1, n);
    
    long long t = k;
    for(long long i = 1; i <= n; i++){
        long long x = find(1, 1, n, t);
        update(1, 1, n, x);
        print.push_back(x);
        if(segt[1] > 0) {
            t = (t + k - 1) % segt[1];
            if(t == 0) t = segt[1]; 
        }
    }
    cout << "<";
    for(long long i = 0; i < print.size(); i++){
        if(i < n - 1) cout << print[i] << ", ";
        else cout << print[i] << ">";
    }
    cout << "\n";

    return 0;
}
