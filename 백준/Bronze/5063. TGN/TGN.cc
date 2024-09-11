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

    int n, x, y, z;
    cin>>n;
    while(n--){
        cin>>x>>y>>z;
        if(x<y-z) cout<<"advertise\n";
        else if(x==y-z) cout<<"does not matter\n";
        else cout<<"do not advertise\n";
    }
}

/*
for(i=1;i<=n;i++){
        
}
*/