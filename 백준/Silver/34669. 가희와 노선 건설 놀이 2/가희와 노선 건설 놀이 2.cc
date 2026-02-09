#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x, y;

    cin>>n;

    while(n--){
        cin>>x>>y;
        cout<<x*y<<" "<<x/y<<"\n";
    }

    return 0;
}