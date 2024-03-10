#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>


using namespace std;

int red[4][4] = { 0 };
int blue[4][6] = { 0 };
int green[6][4] = { 0 };
int score = 0;

//1 x y 2 x y , x y+1 3 x y , x+1 y
void add_blue(int block, int x, int y) {
    int r, c, i, j, r2, c2;
    if (block == 1) {
        r = x;
        c = 0;
        while (c < 5 && blue[r][c + 1] == 0) c++;
        blue[r][c] = 1;
    }
    else if (block == 2) {
        r = x; c = 1;
        while (c < 5 && blue[r][c + 1] == 0) c++;
        blue[r][c] = 1;
        blue[r][c-1] = 1;
    }
    else if (block == 3) {
        r = x; c = 0;
        r2 = x+1; c2 = 0;
        while (c < 5 && blue[r][c + 1] == 0) c++;
        while (c2 < 5 && blue[r2][c2 + 1] == 0) c2++;
        c = min(c, c2);
        blue[r][c] = 1;
        blue[r2][c] = 1;
    }
}

void add_green(int block, int x, int y) {
    int r, c, i, j, r2, c2;
    if (block == 1) {
        r = 0;
        c = y;
        while (r < 5 && green[r+1][c] == 0) r++;
        green[r][c] = 1;
    }
    else if (block == 2) {
        r = 0; c = y;
        r2 = 0; c2 = y+1;
        while (r < 5 && green[r + 1][c] == 0) r++;
        while (r2 < 5 && green[r2 + 1][c2] == 0) r2++;
        r = min(r, r2);
        green[r][c] = 1;
        green[r][c2] = 1;
    }
    else if (block == 3) {
        r = 1; c = y;
        while (r < 5 && green[r + 1][c] == 0) r++;
        green[r][c] = 1;
        green[r-1][c] = 1;
    }
}

void g_blue() {
    int temp[4][6] = { 0 };
    int i, j, now;
    for (i = 5, now=5; i >= 0; i--) {
        for (j = 0; j <= 3; j++) {
            if (blue[j][i] > 0) break;
        }
        if (j <= 3) {
            for (j = 0; j <= 3; j++) {
                temp[j][now] = blue[j][i];
            }
            now--;
        }
    }
    for (i = 5; i >= 0; i--) {
        for (j = 0; j <= 3; j++) {
            blue[j][i] = temp[j][i];
        }
    }
}

void g_green() {
    int temp[6][4] = { 0 };
    int i, j, now;
    for (i = 5, now = 5; i >= 0; i--) {
        for (j = 0; j <= 3; j++) {
            if (green[i][j] > 0) break;
        }
        if (j <= 3) {
            for (j = 0; j <= 3; j++) {
                temp[now][j] = green[i][j];
            }
            now--;
        }
    }
    for (i = 5; i >= 0; i--) {
        for (j = 0; j <= 3; j++) {
            green[i][j] = temp[i][j];
        }
    }
}

void del_blue() {
    int i, j;
    for (i = 0; i <= 5; i++) {
        for (j = 0; j <= 3; j++) {
            if (blue[j][i] == 0) break;
        }
        if (j == 4) {
            score++;
            for (j = 0; j <= 3; j++) {
                blue[j][i] = 0;
            }
        }
    }
}

void del_green() {
    int i, j;
    for (i = 0; i <= 5; i++) {
        for (j = 0; j <= 3; j++) {
            if (green[i][j] == 0) break;
        }
        if (j == 4) {
            score++;
            for (j = 0; j <= 3; j++) {
                green[i][j] = 0;
            }
        }
    }
}

void del_blue01() {
    int del, i, j;
    for (i = 0, del = 0; i <= 1; i++) {
        for (j = 0; j <= 3; j++) {
            if (blue[j][i] > 0) {
                del++;
                break;
            }
        }
    }
    if (del == 0) return;
    for (i = 5; i >=2; i--) {
        for (j = 0; j <= 3; j++) {
            if (blue[j][i] > 0) {
                break;
            }
        }
        if (j == 4) continue;
        else {
            del--;
            for (j = 0; j <= 3; j++) {
                blue[j][i] = 0;
            }
        }
        if (del == 0) break;
    }
}

void del_green01() {
    int del, i, j;
    for (i = 0, del = 0; i <= 1; i++) {
        for (j = 0; j <= 3; j++) {
            if (green[i][j] > 0) {
                del++;
                break;
            }
        }
    }
    if (del == 0) return;
    for (i = 5; i >= 2; i--) {
        for (j = 0; j <= 3; j++) {
            if (green[i][j] > 0) {
                break;
            }
        }
        if (j == 4) continue;
        else {
            del--;
            for (j = 0; j <= 3; j++) {
                green[i][j] = 0;
            }
        }
        if (del == 0) break;
    }
}

int count() {
    int i, j, sum;
    for (i = 0 , sum=0 ; i <= 5; i++) {
        for (j = 0; j <= 3; j++) {
            if (blue[j][i] > 0) sum++;
            if (green[i][j] > 0) sum++;
        }
    }
    return sum;
}

void print() {
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 5; j++) {
            cout << blue[i][j] << " ";
        }cout << "\n";
    }
    cout << "\n";
}

void print2() {
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 3; j++) {
            cout << green[i][j] << " ";
        }cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j, x, y, t;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >>t>> x >> y;
       // cout << "/////////////\n";
        add_blue(t, x, y);
       // cout << "더했을때\n";
      //  print();

        del_blue();
       // cout << "꽉차\n";
      //  print();

        g_blue();
       // cout << "중력\n";
       // print();

        del_blue01();
       // cout << "영역전개\n";
       // print();

        g_blue();
       // cout << "중력\n";
       // print();

        add_green(t, x, y);
       // cout << "더했을때\n";
//print2();
        del_green();
        //cout << "꽉차\n";
       // print2();
        g_green();
        //cout << "중력\n";
        //print2();
        del_green01();
        //cout << "영역전개\n";
       // print2();
        g_green();
       // cout << "중력\n";
        //print2();
    }
    cout << score << "\n" << count();
}
