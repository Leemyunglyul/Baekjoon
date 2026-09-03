#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 540; // 9시간

int N, M;
int D[36][36];
int PT[36], SV[36];
char TY[36];
int airportIdx;
int minIn[36];        // 각 관광포인트로 들어오는 최소 이동시간
int bitOf[36];        // 관광포인트 -> 비트 인덱스

vector<int> tourist, hotelList, ratioOrder;
bool used[36];
unsigned long long mask;

int bestSat;
vector<int> bestPath, cur_;

// (day, hotel, visitedMask) 지배 판정용
unordered_map<unsigned long long, int> memo[6][36];

// 남은 시간으로 얻을 수 있는 만족도 상한 (분수 배낭 완화)
int boundVal(int day, int elapsed) {
    long long R = (long long)(M - day) * LIMIT + (LIMIT - elapsed);
    long long v = 0;
    for (int p : ratioOrder) {
        if (used[p]) continue;
        long long c = PT[p] + minIn[p];   // 최소한 '이동 + 놀이'는 필요
        if (c <= R) { R -= c; v += SV[p]; }
        else { v += (long long)SV[p] * R / c; break; }
    }
    return (int)v;
}

void dfs(int day, int elapsed, int cur, int curSat) {
    if (curSat + boundVal(day, elapsed) <= bestSat) return;

    if (day == M) {
        // 마지막 날: 공항 복귀로 마감
        if (elapsed + D[cur][airportIdx] <= LIMIT && curSat > bestSat) {
            bestSat = curSat;
            bestPath = cur_;
            bestPath.push_back(airportIdx);
        }
    } else {
        // 오늘 하루를 호텔 입실로 마감 (같은 호텔이면 D=0)
        for (int h : hotelList) {
            if (elapsed + D[cur][h] > LIMIT) continue;

            auto &mp = memo[day + 1][h];
            auto it = mp.find(mask);
            if (it != mp.end() && it->second >= curSat) continue;   // 지배당함
            if (it != mp.end()) it->second = curSat;
            else if (mp.size() < 1000000) mp.emplace(mask, curSat);

            cur_.push_back(h);
            dfs(day + 1, 0, h, curSat);
            cur_.pop_back();
        }
    }

    // 관광포인트 하나 더 들르기 (마지막 날에도 가능)
    for (int p : tourist) {
        if (used[p]) continue;
        int t = elapsed + D[cur][p] + PT[p];
        if (t > LIMIT) continue;

        used[p] = true;  mask |= 1ULL << bitOf[p];
        cur_.push_back(p);
        dfs(day, t, p, curSat + SV[p]);
        cur_.pop_back();
        mask &= ~(1ULL << bitOf[p]);  used[p] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M;
        memset(D, 0, sizeof(D));
        for (int i = 1; i <= N - 1; i++)
            for (int j = i + 1; j <= N; j++) {
                int d; cin >> d;
                D[i][j] = D[j][i] = d;
            }

        tourist.clear(); hotelList.clear();
        airportIdx = -1;
        for (int i = 1; i <= N; i++) {
            string s; cin >> s;
            TY[i] = s[0];
            PT[i] = SV[i] = 0;
            if (TY[i] == 'P') { cin >> PT[i] >> SV[i]; tourist.push_back(i); }
            else if (TY[i] == 'A') airportIdx = i;
            else hotelList.push_back(i);
        }

        for (int i = 1; i <= N; i++) {
            minIn[i] = INT_MAX;
            for (int j = 1; j <= N; j++)
                if (i != j) minIn[i] = min(minIn[i], D[i][j]);
        }
        for (int k = 0; k < (int)tourist.size(); k++) bitOf[tourist[k]] = k;

        ratioOrder = tourist;
        sort(ratioOrder.begin(), ratioOrder.end(), [](int a, int b) {
            long long ca = PT[a] + minIn[a], cb = PT[b] + minIn[b];
            return (long long)SV[a] * cb > (long long)SV[b] * ca;
        });

        for (int d = 0; d < 6; d++)
            for (int h = 0; h < 36; h++) memo[d][h].clear();

        memset(used, 0, sizeof(used));
        mask = 0;
        bestSat = -1;
        bestPath.clear();
        cur_.clear();                 // 출발 공항은 경로에 넣지 않는다

        dfs(1, 0, airportIdx, 0);

        cout << "#" << tc << " ";
        if (bestSat <= 0) {
            cout << 0 << "\n";
        } else {
            cout << bestSat;
            for (int x : bestPath) cout << " " << x;
            cout << "\n";
        }
    }
    return 0;
}