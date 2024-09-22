#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <cmath>

#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
typedef long long int ll;

using namespace std;

int N, C, NodeNum = 0;
vector<int> v[200001];
int index_tree[200001][2];
ll tree[1000000];
ll depth[200001];

void tree_building(int r){
    index_tree[r][0] = ++NodeNum;
    for(int i:v[r]) if(depth[i] == 0) {
        depth[i] = depth[r] + 1;
        tree_building(i);
    }
    index_tree[r][1] = NodeNum;
}
void update(int d, int l, int r, int x){
    if(x < l || r < x) return ;
    tree[d]++;
    if(l == r) return ;
    update(2*d, l, (l+r)/2, x);
    update(2*d+1, (l+r)/2 + 1, r, x);
}

ll find(int d, int l, int r, int x, int y){
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return tree[d];
    return find(2*d, l, (l+r)/2, x, y) + find(2*d+1, (l+r)/2+1, r, x, y);
}

int main(void){ 
    memset(tree, 0, sizeof(tree));  
    memset(depth, 0,sizeof(depth));
    scanf("%d %d", &N, &C);
    for(int i=0; i<N-1; i++){
        int s,e; scanf("%d %d", &s, &e);
        v[s].push_back(e); v[e].push_back(s);
    }
    int k; scanf("%d", &k); depth[C] = 1;
    tree_building(C); 

    for(int i=0; i<k; i++){
        int a, b; scanf("%d %d", &a, &b);
        if(a==1){
            update(1,1,N,index_tree[b][0]);
        }else{
            printf("%lld\n", find(1, 1, N, index_tree[b][0], index_tree[b][1]) * depth[b]);
        }
    }
    return 0;
}