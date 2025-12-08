#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

string common[50][50];

void solve(){
    string x, y;

    cin>>x>>y;

    int n= x.size();
    int m = y.size();

    int i, j;

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                common[i][j] = common[i-1][j-1] + x[i-1];
            }
            else{
                if(common[i-1][j].size() > common[i][j-1].size()){
                    common[i][j] = common[i-1][j];
                }
                else{
                    common[i][j] = common[i][j-1];
                }
            }
        }
    }

    cout << common[n][m] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    solve();

    return 0;
}


