#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int arr[100100];
set<int> list;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, i, j;
    cin>>n>>k;
    for(i=1;i<=n;i++){ 
        cin>>arr[i];
        list.insert(arr[i]);
    }
    for(i=1;i<=n;i++){ 
        if(list.find(arr[i]-1)==list.end()){
            pq.push({1, arr[i]-1});
        }
        if(list.find(arr[i]+1)==list.end()){
            pq.push({1, arr[i]+1});
        }
    }
    long long sum=0;
    while(list.size()<n+k){
        while(list.find(pq.top().second)!=list.end()) pq.pop();

        int num=pq.top().first;
        int pos=pq.top().second;
        pq.pop();
        list.insert(pos);
        sum+=num;

        if(list.find(pos-1)==list.end()){
            pq.push({num+1, pos-1});
        }
        if(list.find(pos+1)==list.end()){
            pq.push({num+1, pos+1});
        }
    }
    cout<<sum;
}

/*
for(i=1;i<=n;i++){
        
}
*/