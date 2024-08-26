#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i;
    string s, x;
    bool anw=true;
    cin>>n;
    getline(cin, x);
    while(n--){
        getline(cin, x);
        if(x=="Never gonna give you up" || x=="Never gonna let you down" || x=="Never gonna run around and desert you"
        || x=="Never gonna make you cry" || x=="Never gonna say goodbye" || x=="Never gonna tell a lie and hurt you"
        || x=="Never gonna stop");
        else anw=false;
    }
    if(anw) cout<<"No";
    else cout<<"Yes";
}