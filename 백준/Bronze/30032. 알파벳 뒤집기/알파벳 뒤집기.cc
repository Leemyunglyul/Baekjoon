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

int arr[47];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, testn, i, j, k;
    cin>>n>>k;
    string s;
    while(n--){
        cin>>s;
        if(k==1){
            for(i=0;i<s.size();i++){
                if(s[i]=='d') s[i]='q';
                else if(s[i]=='b') s[i]='p';
                else if(s[i]=='q') s[i]='d';
                else if(s[i]=='p') s[i]='b';
            }
        }
        else{
            for(i=0;i<s.size();i++){
                if(s[i]=='d') s[i]='b';
                else if(s[i]=='b') s[i]='d';
                else if(s[i]=='q') s[i]='p';
                else if(s[i]=='p') s[i]='q';
            }
        }
        cout<<s<<"\n";
    }
}