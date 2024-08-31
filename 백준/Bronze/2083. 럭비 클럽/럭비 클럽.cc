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

    string s;
    int x, y;
    while(1){
        cin>>s>>x>>y;
        if(s=="#" && x==0 && y==0) return 0;
        if(x>17||y>=80){
            cout<<s<<" "<<"Senior\n";
        }
        else cout<<s<<" "<<"Junior\n";
    }
}