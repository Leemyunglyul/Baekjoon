#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

long long arr[110000];
long long tree[410000];
vector<tuple<int, int, int, int>> query;
vector<pair<int, int>> tf;
long long print[100100];

long long init(int n, int st, int end){
    if(st==end) return tree[n]=arr[st];
    int mid=(st+end)/2;
    return tree[n]=init(n*2, st, mid)+init(n*2+1, mid+1, end);
}

void update(int n, int st, int end, int t, long long d){

    if(t<st || t>end) return;
    tree[n]+=d;

    if(st==end) return;
    int mid=(st+end)/2;
    update(n*2, st, mid, t, d);
    update(n*2+1, mid+1, end, t, d);
}

long long q(int n, int st, int end, int l, int r){
    if(l<=st && end<=r) return tree[n];
    if(r<st || l>end) return 0;

    int mid=(st+end)/2;
    return q(n*2, st, mid, l, r)+q(n*2+1, mid+1, end, l, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, x, i, j, a, b, c, d, k,num;
    cin>> n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    init(1, 1, n);
    tf.push_back({0, 0});
    cin>>k;
    for(i=1, num=0;i<=k;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            tf.push_back({b, arr[b]});
            update(1, 1, n, b, c-arr[b]);
            arr[b]=c;
        }
        else{
            cin>>b>>c>>d;
            query.push_back({b,++num, c, d});
        }
    }
    int now=tf.size()-1;
    sort(query.begin(), query.end());
    for(i=query.size()-1;i>=0;i--){
        int nn=get<1>(query[i]);
        int idx=get<0>(query[i]);
        int l=get<2>(query[i]);
        int r=get<3>(query[i]);
        
        while(idx!=now){
            b=tf[now].first;
            c=tf[now].second;
            update(1, 1, n, b, c-arr[b]);
            arr[b]=c;
            now--;
        }
        print[nn]=q(1, 1, n, l, r);
    }
    for(i=1;i<=num;i++) cout<<print[i]<<"\n";
}