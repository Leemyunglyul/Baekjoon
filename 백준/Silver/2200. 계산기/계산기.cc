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

    long long n, i, j, x, y, sum;

    cin>>n;

    for(i=n, sum=2*(n-1)+1; i>=0; i--) {
        cin>>x;

        if(i==0){
            if(x>0)sum += to_string(x).length()+1;
            cout<<sum+1;
            break;
        } 

        if(i<n &&x>0) sum+=to_string(x).length() + 1;
    }

    return 0;
}