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

//끝, 시작
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//시작, 끝
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i , j, x,y, d;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        arr.push({max(x,y),min(x,y)});
    }
    cin>>d;
    int ans=0;
    while(!arr.empty()){
        int e=arr.top().first;
        int s=arr.top().second;
        //cout<<s<<" "<<e<<endl;
        arr.pop();
        if(e-s>d) continue;
        if(pq.empty()){
            pq.push({s,e});
            ans=max(1, ans);
            continue;
        }
        while(!pq.empty() && e>pq.top().first+d){
            pq.pop();
        }
        pq.push({s,e});
        ans=max(ans, (int)pq.size());
    }
    cout<<ans;
}

/*
for(i=1;i<=n;i++){
        
}
*/