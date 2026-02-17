#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>
#include <regex>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, maxB, minW;
    string s;
    
    cin >> N >> maxB >> minW >> s;

    int start = 0, curB = 0, curW = 0, maxLen = 0;

    for (int end = 0; end < N; end++) {
        if (s[end] == 'B') curB++;
        else curW++;

        while (curB > maxB) {
            if (s[start] == 'B') curB--;
            else curW--;
            start++;
        }

        if (curW >= minW) {
            maxLen = max(maxLen, end - start + 1);
        }
    }

    cout << maxLen << "\n";

    return 0;
}