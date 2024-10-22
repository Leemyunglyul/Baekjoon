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

    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<a+b+c+d+e+f-min(min(a,b),min(c,d))-min(e,f);
}