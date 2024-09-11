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

int arr[110][10010];
int list[110][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, t, i, j, x, y ;
    cin>>n>>t;
    for(i=1;i<=n;i++){
        cin>>list[i][0]>>list[i][1];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=t;j++){
            //cout<<i<<"=="<<j<<endl;
            arr[i][j]=arr[i-1][j];
            if(list[i][0]<=j){
                arr[i][j]=max(arr[i-1][j-list[i][0]]+list[i][1], arr[i][j]);
            }
        }
    }
    cout<<arr[n][t];
}

/*
for(i=1;i<=n;i++){
        
}
*/