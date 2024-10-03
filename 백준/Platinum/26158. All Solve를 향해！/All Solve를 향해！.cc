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

int arr[500100];
int tree[2000100];

void init(int n, int st, int end, int k){
    if(st==end){
        if(st<=k) tree[n]=arr[st];
        return;
    }
    int mid=(st+end)/2;
    init(n*2, st, mid, k);
    init(n*2+1, mid+1, end,k);
    tree[n]=max(tree[n*2],tree[n*2+1]);
}   

void update(int n, int st, int end, int t, int diff){
    if(t<st || t>end) return;
    if(st==end){
        tree[n]=diff;
        return;
    }
    int mid=(st+end)/2;
    update(n*2, st, mid, t, diff);
    update(n*2+1, mid+1, end, t, diff);
    tree[n]=max(tree[n*2],tree[n*2+1]);
}

int sum(int n, int st, int end, int l, int r, int diff){
    if(r<st || l>end || tree[n]<=diff) return 0;
    if(st==end) return st;
    int mid=(st+end)/2;
    if(tree[n*2]>diff) return sum(n*2, st, mid, l, r, diff);
    else return sum(n*2+1, mid+1, end, l, r, diff);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, j,k, a, b,c, day,p, lim;
    cin>>n>>k;
    for(i=1 ;i<=n;i++){
        cin>>arr[i];
    }
    init(1, 1, n, k);
    day=0;p=k;
    while(tree[1]>0){
        day++;
       // cout<<"\n"<<day<<"th"<<endl;
        i=sum(1, 1, n, 1, p, 0);
        //cout<<arr[i]<<" ";
        update(1, 1, n, i, 0);
        p++;
        if(p>=n+1) p=n;
        else update(1, 1, n, p, arr[p]);
        while(1){
            i=sum(1, 1, n, 1, p, arr[i]);
            if(i==0) break;
            update(1, 1, n, i, 0);
           // cout<<arr[i]<<" ";
            p++;
            if(p>=n+1) continue;
            else update(1, 1, n, p, arr[p]);
        }
        
    }
    cout<<day;
   
}
