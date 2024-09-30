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

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long sum, i,j, n, x,  count, now;
    cin>>n;
    for(i=1, sum=0, count=0, now=0;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>x;
            if(x==0) continue;
            pq.push(x);
            sum+=x;
        }
    }
    sum=(sum+1)/2;
    while(!pq.empty()){
        ++count;
        now+=pq.size();
        if(now>=sum){
            cout<<count;
            return 0;
        }
        while(!pq.empty() && count==pq.top()) pq.pop();
    }
    cout<<count;
}
