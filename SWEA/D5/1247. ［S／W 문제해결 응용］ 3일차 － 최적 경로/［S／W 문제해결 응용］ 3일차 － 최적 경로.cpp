#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n;

int arr[12][2];
int dist[12][12];
int cost[12][1<<12];

void calculate_distances() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]);
        }
    }
}

int tsp(int pos, int visited) {
    if (visited == (1 << n -1) - 1) {
        return dist[pos][n - 1]; // 마지막 도시에서 끝점으로 이동
    }

    if (cost[pos][visited] != -1) {
        return cost[pos][visited];
    }

    int ret = 1e9;
    for (int next = 0; next < n - 1; next++) {
        if (!(visited & (1 << next))) {
            ret = min(ret, tsp(next, visited | (1 << next)) + dist[pos][next]);
        }
    }

    return cost[pos][visited] = ret;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;

        n += 2; // 시작점과 끝점을 포함하여 n+2개의 도시로 처리

        // DP 테이블을 -1로 초기화 (미방문 상태 표시)

        fill_n(&cost[0][0], sizeof(cost) / sizeof(int), -1);

        // 0부터 n+1까지 정확히 n+2개 입력
        for (int i = 0; i < n; i++) {
            if(i==1){
                cin >> arr[n-1][0] >> arr[n-1][1]; // 끝점 좌표 입력
                continue;
            }
            else if(i==0){
                cin >> arr[0][0] >> arr[0][1]; // 시작점 좌표 입력
                continue;
            }
            else{
                cin >> arr[i-1][0] >> arr[i-1][1];
            }
        }

        calculate_distances();
        
        // 0번 도시에서 시작, 0번 도시 방문 처리(1 << 0 = 1)
        cout << "#" << test_case << " " << tsp(0, 1) << "\n";
    }

    return 0;
}