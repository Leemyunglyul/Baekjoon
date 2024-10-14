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

    int n, i, j, s1, s2,idx;
    string s;
    getline(cin, s);
    s1=0;
    idx=0;
    while(idx<s.size() && s[idx]!='-'){
        s1++;
        idx++;
    }
    s2=s.size()-1-idx;
    if(s1>1 && s1<=8 && s2>=1 && s2<=24) cout<<"YES";
    else cout<<"NO";
}