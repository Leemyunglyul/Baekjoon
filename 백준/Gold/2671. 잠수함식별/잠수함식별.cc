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

    string x;

    cin>>x;
    if(checkPattern(x)) {
        cout << "SUBMARINE\n";
    } else {
        cout << "NOISE\n";
    }
    
    return 0;
}