#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    int answer = 0;
    int left = 1;
    int right = distance;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int prev = 0;
        int removed = 0;

        for (int rock : rocks) {
            if (rock - prev < mid) {
                removed++;
            } else {
                prev = rock;
            }
        }

        if (removed <= n) {
            // 최소 간격 mid를 만들 수 있음
            answer = mid;
            left = mid + 1;
        } else {
            // 너무 많은 바위를 제거해야 함
            right = mid - 1;
        }
    }

    return answer;
}