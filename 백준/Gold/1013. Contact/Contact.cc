#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>
#include <regex>

using namespace std;

bool checkPattern(string s) {
    regex re("(100+1+|01)+");
    return regex_match(s, re);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string x;

    cin>>n;
    while(n--){
        cin>>x;
        cout << (checkPattern(x) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}