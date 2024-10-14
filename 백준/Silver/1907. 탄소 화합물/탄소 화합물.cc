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

int arr[3][3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, k, now, w;
    string s;
    cin>>s;
    for(i=0, now=0;i<s.size();i++){
        w=0;
        if(s[i]=='+'||s[i]=='='){
            now++;
            continue;
        }
        if(s[i]>=65 && s[i]<=90){
            if(s[i+1]>=48 && s[i+1]<=57) w=s[i+1]-48;
            else w=1;
            if(s[i]=='C') arr[now][0]+=w;
            else if(s[i]=='H') arr[now][1]+=w;
            else arr[now][2]+=w;
            if(s[i+1]>=48 && s[i+1]<=57)i++;
        }
    }
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            for(k=1;k<=10;k++){
                if(!(i*arr[0][0]+j*arr[1][0]==k*arr[2][0])) continue;
                if(!(i*arr[0][1]+j*arr[1][1]==k*arr[2][1])) continue;
                if(!(i*arr[0][2]+j*arr[1][2]==k*arr[2][2])) continue;
                cout<<i<<" "<<j<<" "<<k;
                return 0;
            }
        }
    }
}