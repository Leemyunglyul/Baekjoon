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
    
    int n, testn;
    cin>>testn;
    while(testn--){
        cin>>n;
        if(n<=3 || n==6) cout<<0;
        else if(n==4) cout<<2;
        else cout<<1;
        cout<<"\n";
    }
    
}
