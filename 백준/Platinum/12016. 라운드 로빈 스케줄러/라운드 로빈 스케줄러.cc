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

using namespace std;

long long arr[110000];
int tree[430000];
vector<pair<long long, long long>> query;
long long print[110000];

void init(int n, int st, int end){
    if(st==end){
        tree[n]=1;
        return;
    }
    int mid=(st+end)/2;
    init(n*2, st, mid);
    init(n*2+1, mid+1, end);
    tree[n]=tree[n*2]+tree[n*2+1];
}   

void update(int n, int st, int end, int t){
    if(t<st || t>end) return;
    tree[n]--;
    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t);
    update(n*2+1, mid+1, end, t);
    tree[n]=tree[n*2]+tree[n*2+1];
}

int sum(int l, int r, int n, int st, int end){
    if(r<st|| l>end) return 0;
    if(l<=st && end<=r) return tree[n];
    int m =(st+end)/2;
    return sum(l, r, n*2, st, m)+sum(l, r, n*2+1, m+1, end);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long i, j, x, y,m, n, k, ss, pre, a, b, now;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        query.push_back({x, i});
    }
    sort(query.begin(), query.end());
    init(1, 1, n);
    for(i=0, ss=(query[0].first-1)*n, now=0;i<n;i++){
        a=query[i].first;
        b=query[i].second;
        print[b]=ss+now+sum(1, b, 1, 1, n);
        //cout<<b<<": "<<sum(1, b, 1, 1, n)<<"+"<<ss<<"//"<<print[b ]<<endl;
        if(i<n-1){
            if(query[i+1].first!=a){
                ss+=tree[1]+now;
                now=0;
                update(1, 1, n, b);
                ss+=(query[i+1].first-1-a)*tree[1];
            } 
            else{
                now++;
                update(1, 1, n, b);
            } 
        }
        
        
    }
    for(i=1;i<=n;i++) cout<<print[i]<<"\n";
}
