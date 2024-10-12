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

vector<tuple<int, int, int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, a, b, c, k;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a>>b>>c;
        int x=c/b;
        int y=c%b;
        arr.push_back({-x, -y, b, a});
    }
    sort(arr.begin(), arr.end());
    for(i=0;i<k;i++){
        cout<<get<3>(arr[i])<<"\n";
    }

}