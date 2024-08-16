#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

set<int> arr[500010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, q, i, num, j, x, y, z;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        cin>>num;
        for(j=1;j<=num;j++){
            cin>>x;
            arr[i].insert(x);
        }
    }
    for(i=1;i<=q;i++){
        cin>>x;
        if(x==1){
            cin>>y>>z;
            if(arr[z].size()>arr[y].size()) swap(arr[y], arr[z]);

            for(auto i: arr[z]) arr[y].insert(i);

            arr[z].clear();
        }
        else{
            cin>>y;
            cout<<arr[y].size()<<"\n";
        }
    }

    return 0;
}