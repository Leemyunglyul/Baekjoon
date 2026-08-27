#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
vector<int> W;      // 1-indexed, W[1..N]
vector<int> S;      // 덩어리 크기들
vector<int> nextBad; // nextBad[i] = i번째 블록부터 봤을 때, W값이 X보다 큰 가장 앞쪽 위치 (없으면 N+1)

// 주어진 X(허용 가능한 최대 Wear Level)에 대해
// 모든 덩어리를 순서대로, 겹치지 않게 배치할 수 있는지 판별
bool check(int X) {
    // nextBad 배열 갱신 (뒤에서부터)
    nextBad.assign(N + 2, N + 1);
    for (int i = N; i >= 1; i--) {
        if (W[i] > X) nextBad[i] = i;
        else nextBad[i] = nextBad[i + 1];
    }

    int pos = 1; // 현재 배치 가능한 가장 왼쪽 시작 후보 위치 (1-indexed)

    for (int idx = 0; idx < K; idx++) {
        int sz = S[idx];
        bool found = false;

        // pos부터 시작해서, 길이가 sz인 구간에 W>X인 블록이 없는
        // 가장 왼쪽 시작점을 찾는다.
        while (pos + sz - 1 <= N) {
            int b = nextBad[pos]; // pos 이후 첫 '나쁜' 블록의 위치

            if (b >= pos + sz) {
                // [pos, pos+sz-1] 구간에 나쁜 블록이 없음 -> 배치 가능
                found = true;
                break;
            } else {
                // 구간 안에 나쁜 블록(b)이 존재
                // pos부터 b까지의 어떤 시작점도 이 나쁜 블록을 포함하므로 스킵
                pos = b + 1;
            }
        }

        if (!found) return false; // 이 덩어리를 배치할 곳이 없음

        pos = pos + sz; // 이번 덩어리를 [pos, pos+sz-1]에 배치했다고 가정하고 다음 시작 위치로 이동
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> K;

        W.assign(N + 1, 0);
        int maxW = 1;
        for (int i = 1; i <= N; i++) {
            cin >> W[i];
            maxW = max(maxW, W[i]);
        }

        S.assign(K, 0);
        for (int i = 0; i < K; i++) {
            cin >> S[i];
        }

        // 이분 탐색: 정답 X (최대 Wear Level의 최솟값)
        int lo = 1, hi = maxW; // 어떤 X든 maxW 이상이면 반드시 배치 가능 (전체가 유효 블록이므로)
        int answer = hi;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                answer = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}