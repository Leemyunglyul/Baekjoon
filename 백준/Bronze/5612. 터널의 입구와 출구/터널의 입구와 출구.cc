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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, sum, x, y, anw;
    cin>>n>>sum;
    anw=sum;
    while(n--){
        cin>>x>>y;
        sum+=(x-y);
        if(sum<0) anw=0;
        else if(anw>0) anw=max(anw, sum);
    }
    cout<<anw;
}