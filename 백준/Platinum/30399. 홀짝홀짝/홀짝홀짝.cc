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

int tree[800100][2];
bool lazy[800100]={false};
vector<tuple<int, int, int>> q;
vector<int> area;
set<int> s;
map<int, int> tf;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node][0] = area[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
    }
}
void update_lazy(int node, int start, int end) {
    if (lazy[node]) {
        swap(tree[node][0], tree[node][1]);
        if (start != end) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = false;
    }
}
void update_range(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        lazy[node]=!lazy[node];
        update_lazy(node, start, end);
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right);
    update_range(node*2+1, (start+end)/2+1, end, left, right);
    tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
    tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
}
pair<int, int> query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return {0, 0};
    }
    if (left <= start && end <= right) {
        return {tree[node][0],tree[node][1]};
    }
    pair<int, int> lsum = query(node*2, start, (start+end)/2, left, right);
    pair<int, int> rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return {lsum.first + rsum.first,lsum.second + rsum.second};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, i, j, a, b, c, d;
    cin>>n>>m;
    area.push_back(0);
    area.push_back(1);
    area.push_back(n);
    s.insert(0);
    s.insert(1);
    s.insert(n);
    for(i=1 ;i<=m;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            if(d%2==0) continue;
            b--;
            q.push_back({a, b, c});
            if(s.find(b)==s.end()){
                area.push_back(b);
                s.insert(b);
            }
            if(s.find(c)==s.end()){
                area.push_back(c);
                s.insert(c);
            }
        }
        else{
            cin>>b>>c;
            b--;
            q.push_back({a, b, c});
            
            if(s.find(b)==s.end()){
                area.push_back(b);
                s.insert(b);
            }
            if(s.find(c)==s.end()){
                area.push_back(c);
                s.insert(c);
            }
        }
    }
    sort(area.begin(),area.end());
    s.clear();
    for(i=area.size()-1;i>=1;i--){
        tf.insert({area[i], i});
        area[i]=area[i]-area[i-1];
    }
    n=area.size()-1;
    init(1, 1 , n);
    for(i=0;i<q.size();i++){
        a=get<0>(q[i]);
        b=get<1>(q[i]);
        c=get<2>(q[i]);
        if(a==1){
            update_range(1, 1, n, tf[b]+1, tf[c]);
        }
        else{
            pair<int, int> p=query(1, 1, n, tf[b]+1, tf[c]);
            cout<<p.second<<" "<<p.first<<"\n";
        }
    }
}
