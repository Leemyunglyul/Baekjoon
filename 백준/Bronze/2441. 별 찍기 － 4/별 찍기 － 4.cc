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

int arr[5100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            cout<<" ";
        }
        for(j=i;j<=n;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}