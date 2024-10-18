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

ll arr[6];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    double x;
    ll n, i, j, y, count, a, b;
    cin>>x;
    count=1000000000;
    y=(ll)(x*count);
    a=__gcd(y,count);
    y=y/a;
    count=count/a;
    for(i=5;i>=1;i--){
        if(count==0) break;
        else if(i==1){
            arr[1]=count;
            break;
        }
        
        arr[i]=(y-count)/(i-1);
        count-=arr[i];
        y-=arr[i]*i;
       // cout<<i<<"th: "<<arr[i]<<endl;
       // cout<<y<<"vs"<<count<<endl;
    }
    for(i=1;i<=5;i++) cout<<arr[i]<<" ";
}