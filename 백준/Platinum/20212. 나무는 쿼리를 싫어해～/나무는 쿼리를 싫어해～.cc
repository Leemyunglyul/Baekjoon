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
typedef long long ll;

using namespace std;

vector<tuple<ll, ll, ll>> ad;
vector<tuple<ll, ll, ll, ll>> print;
vector<ll> area;
map<ll, ll> tf;
ll tree[810000];
ll lazy[810000];
ll add[210000];
ll tot[810000];
vector<pair<ll, ll>> con;

void init(int n, int st, int end){
    if(st==end){
        tot[n]=add[st];
        return;
    }
    int mid=(st+end)/2;
    init(n*2, st, mid);
    init(n*2+1, mid+1, end);
    tot[n]=tot[n*2]+tot[n*2+1];
}   
void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] +=tot[node]*lazy[node];
        if(start!=end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right, long long diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        lazy[node]+=diff;
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
long long query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    long long lsum = query(node*2, start, (start+end)/2, left, right);
    long long rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n, i, j, s, e,m, x, a, b, c,d;
    cin>>n;
    for(i=1, ad.push_back({0,0,0});i<=n;i++){
        cin>>a>>b>>c>>d;
        b--;
        area.push_back(b);
        area.push_back(c);
        if(a==1)  ad.push_back({b, c, d});
        else  print.push_back({d, i, b, c});
    }
    //coordinate compression
    sort(print.begin(), print.end());
    area.push_back(0);
    area.push_back(1);
    area.push_back(1000000000);
    sort(area.begin(), area.end());
    area.erase(unique(area.begin(), area.end()), area.end());
    n=area.size()-1;
    //cout<<n<<"//\n";
    for(i=1;i<=n;i++){
        tf.insert({area[i], i});
        add[i]=area[i]-area[i-1];
    } 
    init(1, 1, n);
    //offline query
    for(i=0, x=1;i<print.size();i++){
        b=get<0>(print[i]);
        a=get<1>(print[i]);
        c=get<2>(print[i]);
        d=get<3>(print[i]);
        for(;x<=b;x++){
            update_range(1, 1, n, tf[get<0>(ad[x])]+1, tf[get<1>(ad[x])], get<2>(ad[x]));
        }
        con.push_back({a,query(1, 1, n, tf[c]+1, tf[d])});
    }
    sort(con.begin(), con.end());
    for(i=0;i<con.size();i++) cout<<con[i].second<<"\n";

}
