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

int arr[110000];
int tree[430000];
vector<tuple<int, int, int>> query;
vector<int> edge[110000];
int print[51000];

void update(int n, int st, int end, int t){
    if(t<st || t>end) return;
    tree[n]++;
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

    int i, j, x, y,m, n, k;
    for(i=2;i<=100000;i++){
        if(arr[i]>0) continue;
        arr[i]=i;
        for(j=i+i;j<=100000;j+=i){
            arr[j]=i;
        }
    }
    for(i=2;i<=100000;i++){
        edge[arr[i]].push_back(i);
    }
    cin>>m;
    for(i=1;i<=m;i++){
        cin>>x>>y;
        query.push_back({y, x, i});
    }
    sort(query.begin(), query.end());
    for(k=2;k<=get<0>(query[0]);k++){
        for(j=0;j<edge[k].size();j++){
            update(1, 1, 100000, edge[k][j]);
        }
    }
    for(i=0;i<query.size();i++){
        int b=get<0>(query[i]);
        int a=get<1>(query[i]);
        if(i>=1 && get<0>(query[i-1])!=b){
            for(k=get<0>(query[i-1])+1;k<=b;k++){
                for(j=0;j<edge[k].size();j++){
                    update(1, 1, 100000, edge[k][j]);
                }
            }
        }
        print[get<2>(query[i])]=sum(2, a, 1, 1, 100000);
    }
    for(i=1;i<=m;i++) cout<<print[i]<<"\n";
}
