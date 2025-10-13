#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<string> words;
vector<bool> visited;
int min_len = 1e9;

int get_overlap_len(const string& s1, const string& s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int max_overlap = 0;

    for (int l = min(len1, len2); l > 0; --l) {
        if (s1.substr(len1 - l) == s2.substr(0, l)) {
            max_overlap = l;
            break;
        }
    }
    return max_overlap;
}

void find_shortest(int count, const string& current_str) {
    if (count == n) {
        int current_len = current_str.length();
        if (current_len < min_len) {
            min_len = current_len;
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;

            int overlap = get_overlap_len(current_str, words[i]);
            string next_str = current_str + words[i].substr(overlap);
            
            find_shortest(count + 1, next_str);

            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    words.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    for (int i = 0; i < n; ++i) {
        visited[i] = true;
        find_shortest(1, words[i]);
        visited[i] = false;
    }

    cout << min_len << endl;

    return 0;
}