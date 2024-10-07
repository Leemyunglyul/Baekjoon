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
#include <unordered_map>
typedef long long ll;

using namespace std;

int arr[10010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n, m, i, sum, c;
    for(i=3,arr[1]=1,sum=0;i<=10000;i++){
        if(i%2==0 || i%5==0) continue;
        m=0;
        c=1;
        sum=0;
        while(1){
            c=c%i;
            sum+=c;
            c*=10;
            m++;
            if(sum%i==0) break;
        }
        arr[i]=m;
    }
    while(1){
        cin>>n;
        if(cin.eof()) break;
        cout<<arr[n]<<"\n";
    }
}
