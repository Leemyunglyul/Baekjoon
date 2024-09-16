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

int arr[6];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i, x, y;
    cin>>n;
    for(i=0;i<=5;i++) cin>>arr[i];
    cin>>x>>y;
    int sum=0;
    for(i=0;i<=5;i++){
        if(arr[i]%x>0) sum++;
        sum+=arr[i]/x;
    }
    cout<<sum<<endl;
    cout<<n/y<<" "<<n%y;

}
