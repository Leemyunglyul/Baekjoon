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
#include <unordered_map>
typedef long long ll;

using namespace std;

int arr[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, i;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++) arr[s[i]-97]++;
    for(i=0;i<26;i++) cout<<arr[i]<<" ";
}
