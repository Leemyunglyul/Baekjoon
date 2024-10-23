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

    string a, b;
    int n, k, s, e, t1, t2, sum;
    cin>>a>>b>>n>>k;
    s=stoi(a.substr(0,2))*60+stoi(a.substr(3,2));
    e=stoi(b.substr(0,2))*60+stoi(b.substr(3,2))-1;
    int q=(e-s)/k;
    if((n+1)%q==0) cout<<(n+1)/q-1<<"\n";
    else cout<<(n+1)/q<<"\n";
    if((n+1)%q==0){
        s+=q*k;
    }
    else s+=((n+1)%q)*k;
    if(s/60<10) cout<<"0";
    cout<<to_string(s/60);
    cout<<":";
    if(s%60<10) cout<<"0";
    cout<<to_string(s%60);
}