#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, H, W;
int grid[3010][3010];
int prefix_sum[3010][3010];

bool solve(int mid) {
    int threshold = (H * W) / 2;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            int val = (grid[i][j] > mid) ? 1 : 0;
            prefix_sum[i][j] = val + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }

    for (int i = H; i <= R; ++i) {
        for (int j = W; j <= C; ++j) {
            int count_greater = prefix_sum[i][j] 
                              - prefix_sum[i-H][j] 
                              - prefix_sum[i][j-W] 
                              + prefix_sum[i-H][j-W];
            if (count_greater <= threshold) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> R >> C >> H >> W;

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> grid[i][j];
        }
    }

    int lo = 1, hi = R * C;
    int ans = hi;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (solve(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}