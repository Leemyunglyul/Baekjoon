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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, k, a, b, x, y, w1, w2, op;
    cin>>n>>k;
    for(i=1, a=0, b=0, w1=0, w2=0, op=0;i<=n;i++){
        cin>>x>>y;
        a+=x;
        b+=y;
        if(a>=k){
            cout<<"1";
            return 0;
        }
        else if(b>=k){
            cout<<"-1";
            return 0;
        }
        else if(a+(x/2)>=k && op==0){
            cout<<"1";
            return 0;
        }
        else if(a-b>=50){
            cout<<"1";
            return 0;
        }
        else if(a+x/2-b>=50 && op==0){
            cout<<"1";
            return 0;
        }
    }
    cout<<"0";
    return 0;
}