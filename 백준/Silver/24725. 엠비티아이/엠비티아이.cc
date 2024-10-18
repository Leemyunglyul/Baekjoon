#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>  // for transform

using namespace std;

string arr[210];
int sum=0;

unordered_map<string, int> mbti_map = {
    {"ENFP", 1}, {"ENFJ", 2}, {"ENTP", 3}, {"ENTJ", 4},
    {"ESTP", 5}, {"ESFP", 6}, {"ESFJ", 7}, {"ESTJ", 8},
    {"INFP", 9}, {"INFJ", 10}, {"INTP", 11}, {"INTJ", 12},
    {"ISTP", 13}, {"ISTJ", 14}, {"ISFJ", 15}, {"ISFP", 16}
};

void update(string x) {
    // 문자열을 대문자로 변환

    if (mbti_map.find(x) != mbti_map.end()) {
        sum++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, i, j;
    string ss;
    cin >> n >> m;
    
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j < m; j++) {
            if (!(arr[i][j] == 'I' || arr[i][j] == 'E')) continue;

            // 아래부터 문자열 덧셈을 한 번에 하지 않고, 차례대로 처리
            if (i + 3 <= n) {
                ss = "";
                ss += arr[i][j];
                ss += arr[i + 1][j];
                ss += arr[i + 2][j];
                ss += arr[i + 3][j];
                update(ss);
            }
            if (j + 3 < m) {
                ss = "";
                ss += arr[i][j];
                ss += arr[i][j + 1];
                ss += arr[i][j + 2];
                ss += arr[i][j + 3];
                update(ss);
            }
            if (i - 3 >= 1) {
                ss = "";
                ss += arr[i][j];
                ss += arr[i - 1][j];
                ss += arr[i - 2][j];
                ss += arr[i - 3][j];
                update(ss);
            }
            if (j - 3 >= 0) {
                ss = "";
                ss += arr[i][j];
                ss += arr[i][j - 1];
                ss += arr[i][j - 2];
                ss += arr[i][j - 3];
                update(ss);
            }
            if (i + 3 <= n && j + 3 < m) {
                ss = "";
                ss += arr[i][j];
                ss += arr[i + 1][j + 1];
                ss += arr[i + 2][j + 2];
                ss += arr[i + 3][j + 3];
                update(ss);
            }
            if (i + 3 <= n && j - 3 >= 0) {
                ss = "";
                ss += arr[i][j];
                ss += arr[i + 1][j - 1];
                ss += arr[i + 2][j - 2];
                ss += arr[i + 3][j - 3];
                update(ss);
            }
            if (i - 3 >= 1 && j + 3 < m) {
                ss = "";
                ss += arr[i][j];
                ss += arr[i - 1][j + 1];
                ss += arr[i - 2][j + 2];
                ss += arr[i - 3][j + 3];
                update(ss);
            }
            if (i - 3 >= 1 && j - 3 >= 0) {
                ss = "";
                ss += arr[i][j];
                ss += arr[i - 1][j - 1];
                ss += arr[i - 2][j - 2];
                ss += arr[i - 3][j - 3];
                update(ss);
            }
        }
    }

    cout << sum;

    return 0;
}
