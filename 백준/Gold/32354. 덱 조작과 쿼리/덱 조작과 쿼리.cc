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

stack<long long> mem;
vector<pair<int, int>> query;
vector<int> edge[500010];
long long print[500010];

void dfs(int now, long long sum){
    long long a, b, c;
    a=query[now].first;
    b=query[now].second;
    if(a==1){
        mem.push(b);
        sum+=b;
    } 
    else if(a==2){
        c=mem.top();
        mem.pop();
        sum-=c;
    }
    else if(a==4) print[now]=sum;
    for(int i=0;i<edge[now].size();i++){
        dfs(edge[now][i], sum);
    }
    if(a==1)mem.pop();
    else if(a==2)mem.push(c);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, i, j, x, a, b, c;
    cin>>n;
    string s;
    fill_n(&print[0], 500001, -1);
    query.push_back({0, 0});
    for(i=1;i<=n;i++){
        cin>>s;
        if(s=="push"){
            cin>>x;
            query.push_back({1, x});
        } 
        else if(s=="pop"){
            query.push_back({2, 0});
        }
        else if(s=="restore"){
            cin>>x;
            edge[x].push_back(i);
            query.push_back({3, 0});
            continue;
        }
        else query.push_back({4, 0});
        edge[i-1].push_back(i);
    }
    dfs(0, 0);
    for(i=1;i<=n;i++){
        if(print[i]>=0) cout<<print[i]<<"\n";
    }
}
