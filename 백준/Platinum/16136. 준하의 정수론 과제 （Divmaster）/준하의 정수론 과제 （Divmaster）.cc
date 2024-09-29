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

int arr[100100];
int tree[100100];
int check[1001000];

long long init(int node, int st, int end){
    if(st==end) return tree[node]=arr[st];
    int mid=(st+end)/2;
    return tree[node]=init(node*2, st, mid)+init(node*2+1, mid+1, end);
}
void update(int n, int st, int end, int l, int r){
    if(r<st || l>end) return;
    if(st==end){
        tree[n]=check[tree[n]];
       // cout<<st<<"->"<<tree[n]<<endl;
        return;
    }
    int mid=(st+end)/2;
    update(n*2, st, mid, l, r);
    update(n*2+1, mid+1, end, l, r);
    tree[n]=tree[n*2]+tree[n*2+1];
}
int sum(int l, int r, int node, int st, int end){
    if(l<=st && end<=r) return tree[node];
    if(r<st || end<l) return 0;
    int m =(st+end)/2;
    return sum(l, r, node*2, st, m)+sum(l, r, node*2+1, m+1, end);
}

int gg(int a, int b){
    int count=0;
    while(a%b==0){
        count++;
        a=a/b;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j, x,m, a,b, c;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>arr[i];
    init(1, 1, n);
    for(i=2, check[1]=1;i<=1000000;i++){
        if(check[i]>0) continue;
        check[i]=2;
        for(j=i+i;j<=1000000;j+=i){
            if(check[j]==0) check[j]=gg(j, i)+1;
            else check[j]=check[j]*(gg(j, i)+1);
        }
    }
    while(m--){
        cin>>a>>b>>c;
        if(a==1) update(1, 1, n, b, c);
        else cout<<sum(b, c, 1, 1, n)<<"\n";
    }
    
}