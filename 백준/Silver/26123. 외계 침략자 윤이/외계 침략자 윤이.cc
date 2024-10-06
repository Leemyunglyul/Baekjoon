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

priority_queue<pair<int, int>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, m, x, i, sum, a, b;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>x;
        pq.push({x, 1});
    }
    for(i=1, sum=0;i<=m;i++){
        a=pq.top().first;
        b=pq.top().second;
        pq.pop();
        while(!pq.empty() && a==pq.top().first){
            b+=pq.top().second;
            pq.pop();
        }
        pq.push({a-1, b});
        sum+=b;

        if(pq.empty() || pq.top().first==0) break;
    }
    
    cout<<sum;
}
