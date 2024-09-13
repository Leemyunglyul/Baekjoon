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
    cin>>x>>y;
    cout<<abs((y-1)/4-(x-1)/4)+abs((x-1)%4-(y-1)%4);

}

/*
for(i=1;i<=n;i++){
        
}
*/