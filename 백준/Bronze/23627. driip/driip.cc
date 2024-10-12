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

    string s;
    cin>>s;
    int n, i, j;
    if(s.size()<5){
        cout<<"not cute";
        return 0;
    }
    bool anw=true;
    n=s.size();
    if(s[n-1]!='p' || s[n-2]!='i' || s[n-3]!='i'|| s[n-4]!='r'|| s[n-5]!='d') anw=false;
    if(anw) cout<<"cute";
    else cout<<"not cute";
}