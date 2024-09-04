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

int arr[1001000];
int pr[1001000];
vector<long long> prime;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long i,j, s, e;
    cin>>s>>e;
    for(i=2;i<=1000000;i++){
        if(arr[i]>0) continue;
        prime.push_back(i);
        for(j=i*2;j<=1000000;j+=i){
            arr[j]=1;
        }
    }
    for(i=0;i<prime.size();i++){
        long long x=prime[i]*prime[i];
        if(x>e) break;
        long long y=s/x;
        if(s%x>0) y++;
        y=x*y;
        //cout<<x<<"->";
        for(j=y;j<=e;j+=x){
            pr[j-s]=1;
           //cout<<j<<" ";
        }
       // cout<<endl;
    }
    int sum=0;
    for(i=0;i<=e-s;i++){
        if(pr[i]==0) sum++;
    }
    cout<<sum;
    
}

/*
for(i=1;i<=n;i++){
        
}
*/