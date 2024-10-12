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
#include <climits>
#include <unordered_map>
typedef long long ll;

using namespace std;

ll arr[1001010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll sum=0;
    ll n, i, j, a, b,m,x, c;
    cin>>n>>b>>c;
    if(b<c){
        for(i=1;i<=n;i++){
            cin>>arr[i];
            sum+=b*arr[i];
        }
        cout<<sum;
        return 0;
    }
    for(i=1;i<=n;i++){
        cin>>arr[i];
        sum+=c*arr[i];
    }
    for(i=1;i<=n;i++){
        if(arr[i]<=arr[i+1]){
            if(arr[i+1]<=arr[i+2]){
                arr[i+1]-=arr[i];
                arr[i+2]-=arr[i];
                sum+=(b-c)*arr[i];
                arr[i]=0;
            }
            else{
                x=arr[i+1]-arr[i+2];
                arr[i+1]-=x;
                arr[i]-=x;
                sum+=x*(b-c);
                if(arr[i]>0)i--;
            }
        }
        else{
            x=arr[i]-arr[i+1];
            arr[i]-=x;
            sum+=(b-c)*x;
            i--;
        }
    }
    
    cout<<sum;
}