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

    int x, y;
    cin>>x>>y;
    double tmp=(double)x*(100-y)/100;
    if(tmp>=100) cout<<"0";
    else cout<<"1";
}

/*
for(i=1;i<=n;i++){
        
}
*/