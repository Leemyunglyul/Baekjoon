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

    string s;
    int n, i, sum;
    cin>>s;
    for(i=0, sum=0;i<s.size();i++){
        if(s[i]<=92){
            while((i+sum)%4!=0) sum++;
        }
    }
    cout<<sum;

}