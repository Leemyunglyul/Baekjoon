#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
    int n = cookie.size();
    int answer = 0;

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + cookie[i];
    }

    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int total = prefix[r + 1] - prefix[l];

            if (total % 2 != 0) {
                continue;
            }

            int half = total / 2;

            int target = prefix[l] + half;

            auto it = lower_bound(
                prefix.begin() + l + 1,
                prefix.begin() + r + 1,
                target
            );

            if (it != prefix.begin() + r + 1 && *it == target) {
                answer = max(answer, half);
            }
        }
    }

    return answer;
}