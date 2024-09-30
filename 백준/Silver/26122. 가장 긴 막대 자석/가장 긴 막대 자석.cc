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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int i, j,n, n1, n2, anw;
    string s;
    cin>>n>>s;
    for(i=0, n1=0, n2=0, anw=0;i<n;i++){
        if(i>=1 && s[i-1]!=s[i]){
            if(s[i]=='N') n1=0;
            else n2=0;
        }
        if(s[i]=='N'){
            n1++;   
        }
        else{
            n2++;
        }
        anw=max(anw, 2*min(n1, n2));
    }
    cout<<anw;
}
