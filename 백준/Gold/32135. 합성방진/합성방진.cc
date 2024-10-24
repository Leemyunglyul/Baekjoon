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

bool prime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return false;
    }
    return true;
}

int arr[510];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, k, x,y,s, idx;
    cin>>n;
    s=(n%2==0)?n:n-1;
    while(prime(1+s)) s-=2;
    idx=-1;
    arr[++idx]=s;
    for(i=1;i<=n;i+=2){
        if(i==3) continue;
        arr[++idx]=i;
    }
    arr[++idx]=3;
    arr[++idx]=s-2;
    for(i=2;i<=n;i+=2){
        if(i==s-2 || i==s) continue;
        arr[++idx]=i;
    }
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            cout<<arr[(i+j)%n]<<" ";
        } 
        cout<<"\n";
    }
    
}