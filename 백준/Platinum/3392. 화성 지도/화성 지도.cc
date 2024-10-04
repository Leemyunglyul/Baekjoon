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

int tree[121000];
int cnt[121000];
vector<tuple<int, int, int, bool>> arr;

void update(int n, int st, int end, int l, int r, int d){
    if(r<st || l>end) return;

    if(l<=st && end<=r){
        cnt[n]+=d;
    }
    else{
        int mid=(st+end)/2;
        update(n*2, st, mid, l, r, d);
        update(n*2+1, mid+1, end, l, r, d);
    }
    
    if(cnt[n]>0){
        tree[n]=end-st+1;
    }
    else{
        if(st==end) tree[n]=0;
        else tree[n]=tree[n*2]+tree[n*2+1];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, i, j, x1, y1, y2, x2, m, sum;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x1>>y1>>x2>>y2;
        arr.push_back({x1, y1+1, y2+1, true});
        arr.push_back({x2, y1+1, y2+1, false});
    }
    sort(arr.begin(), arr.end());
    for(i=0, sum=0;i<arr.size();i++){
        if(i>0) sum+=(get<0>(arr[i])-get<0>(arr[i-1]))*tree[1];
        m=get<3>(arr[i])?1:-1;
        update(1, 1, 30001, get<1>(arr[i]),get<2>(arr[i])-1, m);
    }
    cout<<sum;
}
