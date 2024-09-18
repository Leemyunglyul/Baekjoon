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

set<long long> v;
queue<pair<int, long long>> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long a,b, n, x;
    cin>>a>>b;
    q.push({0, a});
    v.insert(a);
    while(!q.empty()){
        n=q.front().first;
        x=q.front().second;
        q.pop();

        if(x==b) break;

        if(v.find(2*x)==v.end() && 2*x<=b){
            v.insert(2*x);
            q.push({n+1, 2*x});
        }
        if(v.find(10*x+1)==v.end() && 10*x+1<=b ){
            v.insert(10*x+1);
            q.push({n+1, 10*x+1});
        }
        //cout<<x<<endl;
    }
    if(x==b) cout<<n+1  ;
    else cout<<"-1";
    
}
