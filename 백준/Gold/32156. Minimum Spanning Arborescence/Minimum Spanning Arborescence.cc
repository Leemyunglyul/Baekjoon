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

int edge[510000];
priority_queue<pair<long long, long long>> pq;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n, m, r, i, j, a,b , c, sum, num;
    cin>>n>>m>>r;
    for(i=0, sum=0, num=0;i<m;i++){
        cin>>a>>b>>c;
        if(b!=r){
            sum+=c;
            pq.push({c, b});
            edge[b]++;
            num++;
        } 
    }
    while(!pq.empty()){
        i=pq.top().second;
        long long cost=pq.top().first;
        pq.pop();
        if(edge[i]>1){
            num--;
            sum-=cost;
            edge[i]--;
        }
    }
    if(num==n-1) cout<<sum;
    else cout<<"-1"; 

}

