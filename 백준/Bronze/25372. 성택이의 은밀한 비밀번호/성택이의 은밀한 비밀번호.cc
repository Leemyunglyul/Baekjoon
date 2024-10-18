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

    int n;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        if(s.size()>=6 && s.size()<=9) cout<<"yes\n";
        else cout<<"no\n";
    }
}