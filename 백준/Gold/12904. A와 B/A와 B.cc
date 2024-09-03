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

    string x,y;
    int len, i, j;
    cin>>x>>y;
    len=y.size();
    while(x.size()<len){
        if(y[len-1]=='A') len--;
        else{
            len--;
            reverse(y.begin(), y.begin()+len);
        }
    }
    bool anw=true;
    for(i=0;i<x.size();i++){
        if(x[i]!=y[i]){
            cout<<"0";
            return 0;
        }
    }
    cout<<"1";
}