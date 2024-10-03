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
#include <unordered_map>
typedef long long ll;

using namespace std;

int tree[310000];
vector<pair<int, int>> arr;
vector<int> v;
map<int, int> tf;

void update(int n, int st, int end, int t){
    if(t<st || t>end) return;
    tree[n]++;
    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t);
    update(n*2+1, mid+1, end, t);
    tree[n]=tree[n*2]+tree[n*2+1];
}

int query(int l, int r, int n, int st, int end){
    if(r<st|| l>end) return 0;
    if(l<=st && end<=r) return tree[n];
    int m =(st+end)/2;
    return query(l, r, n*2, st, m)+query(l, r, n*2+1, m+1, end);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll testn, n, i, j, x, y,m, sum;
    cin>>testn;
    while(testn--){
        cin>>n;
        fill_n(&tree[0], 310000, 0);
        arr.clear();
        v.clear();
        tf.clear();
        for(i=1;i<=n;i++){
            cin>>x>>y;
            v.push_back(-y);
            arr.push_back({x, -y});
        }
        sort(arr.begin(), arr.end());
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(i=0;i<v.size();i++){
            tf[v[i]]=i+1;
        }
        m=v.size();
        for(i=0, sum=0;i<n;i++){
            y=arr[i].second;
            sum+=query(1, tf[y], 1, 1, m);
            update(1, 1, m, tf[y]);
        }
        cout<<sum<<"\n";
    }
   
}
