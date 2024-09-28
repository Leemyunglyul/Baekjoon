#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <climits>

using namespace std;

int arr[250100];
double tree[1010000];
double lazy[1010000];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = (double)arr[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] = (end-start+1)*lazy[node];
        if (start != end) {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right, double diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        tree[node] = (end-start+1)*diff;
        if (start != end) {
            lazy[node*2] = diff;
            lazy[node*2+1] = diff;
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

double query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    double lsum = query(node*2, start, (start+end)/2, left, right);
    double rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j, m, x,r, a, b, c;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>arr[i];
    init(1, 1,n );
    string s;
    while(m--){
        cin>>s;
        if(s=="get"){
            cin>>a;
            cout << fixed;
            cout.precision(12);
            cout<<query(1, 1, n, a, a)<<"\n";
        }
        else{
            cin>>a>>b;
            double sum=query(1, 1, n, a, b)/(b-a+1);
            update_range(1, 1, n, a, b, sum);

        }
    }
    
}