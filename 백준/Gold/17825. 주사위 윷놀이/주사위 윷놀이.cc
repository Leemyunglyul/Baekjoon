#include <iostream>

using namespace std;

int outside[22] = 
{ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 
22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0 };
int inside1[5] = { 10, 13, 16, 19, 25 };
int inside2[4] = { 20, 22, 24, 25 };
int inside3[5] = { 30, 28, 27, 26, 25 };
int inside4[5] = { 25, 30, 35, 40, 0 };

int pos[5][2] = {0};
int dice[11];
int anw = 0;

int move(int num, int d) {
    int area = pos[num][0];
    int p = pos[num][1];
    if (area == 0) {
        if (p+d==5 || p + d == 10|| p + d == 15) {
            area = (p + d) / 5;
            p = 0;
        }
        else if (p + d >= 20) {
            area = 4;
            p = p + d - 20 + 3;
        }
        else p = min(21, p + d);
    }
    else if (area == 1 || area==3) {
        if (p + d >= 4) {
            area = 4;
            p = p + d - 4;
        }
        else p = p + d;
    }
    else if (area == 2) {
        if (p + d >= 3) {
            area = 4;
            p = p + d - 3;
        }
        else p = p + d;
    }
    else if (area == 4) {
        p = min(4, p + d);
    }
    if ((area == 4 && p == 4) || (area == 0 && p == 21)) {
        pos[num][0] =4;
        pos[num][1] =4;
        return 0;
    }
    for (int i = 1; i <= 4; i++) {
        if (i == num) continue;
        if (pos[i][0] == area && pos[i][1] == p) return -1;
    }
    pos[num][0]=area;
    pos[num][1] = p;
    if (area == 0) return outside[p];
    else if (area == 1) return inside1[p];
    else if (area == 2) return inside2[p];
    else if (area == 3) return inside3[p];
    else if (area == 4) return inside4[p];
}

void dfs(int tryn, int sum) {
    if (tryn == 11) {
        anw = max(anw, sum);
       // if(sum>210) cout << sum << endl;
        return;
    }

    int i, score;
    if (tryn == 1) {
        score=move(1, dice[tryn]);
        dfs(2, score);
        return;
    }
    for (i = 1; i <= 4; i++) {
        int pre_area = pos[i][0];
        int pre_pos=pos[i][1];
        int result = move(i, dice[tryn]);
        if (result == -1) continue;

        dfs(tryn + 1, sum + result);

        pos[i][0] = pre_area;
        pos[i][1] = pre_pos;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int i;
    for (i = 1; i <= 10; i++) cin >> dice[i];
    dfs(1, 0);
    cout << anw;
}
