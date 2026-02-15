#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>
#include <regex>

using namespace std;

regex slump_re("^([DE]F+)+G$");

bool isSlump(const string& s) {
    return regex_match(s, slump_re);
}

bool isSlimp(string s) {
    if (s.length() < 2) return false;

    if (s == "AH") return true;

    if (s.front() == 'A' && s.back() == 'C') {
        if (s[1] == 'B') {
            return isSlimp(s.substr(2, s.length() - 3));
        }
        else {
            return isSlump(s.substr(1, s.length() - 2));
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    string s;
    cin >> q;
    cout<<"SLURPYS OUTPUT\n";
    while (q--) {
        cin >> s;
        bool found = false;
        for (int i = 2; i < s.length(); i++) {
            string part1 = s.substr(0, i);
            string part2 = s.substr(i);
            
            if (isSlimp(part1) && isSlump(part2)) {
                found = true;
                break;
            }
        }

        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
    cout<<"END OF OUTPUT\n";
    
    return 0;
}