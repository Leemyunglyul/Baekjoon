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

long long arr[1010];
long long sum[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, q, i, j, x, a, b, c, d;
    cin>>n>>q;
    for(i=1;i<=n;i++) cin>>arr[i];
    for(i=2, sum[1]=arr[1];i<=n;i++){
        sum[i]=arr[i]+sum[i-1];
    }
    while(q--){
        cin>>x;
        if(x==1){
            cin>>a>>b;
            cout<<sum[b]-sum[a-1]<<"\n";
            //int tmp=arr[a];
            //arr[a]=arr[b];
            //arr[b]=tmp;
            swap(arr[a], arr[b]);
            for(i=2, sum[1]=arr[1];i<=n;i++){
                sum[i]=arr[i]+sum[i-1];
            }
        }
        else{
            cin>>a>>b>>c>>d;
            cout<<sum[b]-sum[a-1]-sum[d]+sum[c-1]<<"\n";
        }
    }
}