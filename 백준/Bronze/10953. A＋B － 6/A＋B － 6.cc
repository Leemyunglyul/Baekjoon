#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        cout<<(s[0]-48)+(s[2]-48)<<"\n";
    }
}