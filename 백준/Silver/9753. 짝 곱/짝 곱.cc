#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100100];
vector<int> prime;
vector<long long> anw;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int i, j,tc, x, y;
    
    for(i=2;i<=100050;i++){
        if(arr[i]==1) continue;
        prime.push_back(i);
        for(j=i+i;j<=100050;j+=i){
            arr[j]=1;
        }
    }
    for(i=0;i<prime.size();i++){
        for(j=i+1;j<prime.size();j++){
            x=prime[i];
            y=prime[j];
            if((long long)x*y>100001) break;
            anw.push_back((long long)x*y);
        }
    }
    sort(anw.begin(), anw.end());
   
    cin>>tc;
    while(tc--){
        cin>>x; 
        auto it = lower_bound(anw.begin(), anw.end(), (long long)x);
        cout<<*it<<'\n';
    }
}