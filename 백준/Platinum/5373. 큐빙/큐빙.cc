#include <iostream>
#include<cmath>

using namespace std;

//위, 아래, 앞, 뒤, 왼, 오
//흰, 노,   빨, 오, 초, 파
char color[7] = { ' ', 'w', 'y','r','o','g', 'b' };
int cube[30];
int cub[28][7];
int tem[28][7]= {
    {0, 0, 0, 0, 0, 0, 0},
        //위, 아래, 앞, 뒤, 왼, 오
    { 0, 1, 0, 0, 4, 5, 0 }, //1-1
    { 0, 1, 0, 0, 4, 0, 0 }, //1-2
    { 0, 1, 0, 0, 4, 0, 6 }, //1-3
    { 0, 1, 0, 0, 0, 5, 0 }, //1-4
    { 0, 1, 0, 0, 0, 0, 0 }, //
    { 0, 1, 0, 0, 0, 0, 6 }, //1-6
    { 0, 1, 0, 3, 0, 5, 0 }, //1-7
    { 0, 1, 0, 3, 0, 0, 0 },
    { 0, 1, 0, 3, 0, 0, 6 }, //1-9
        //위, 아래, 앞, 뒤, 왼, 오
    { 0, 0, 0, 0, 4, 5, 0 }, //2-1
    { 0, 0, 0, 0, 4, 0, 0 },
    { 0, 0, 0, 0, 4, 0, 6 }, //2-3
    { 0, 0, 0, 0, 4, 5, 0 }, //2-4
    { 0, 0, 0, 0, 0, 0, 0 }, //중심
    { 0, 0, 0, 0, 0, 0, 6 },
    { 0, 0, 0, 3, 0, 5, 0 },
    { 0, 0, 0, 3, 0, 0, 0 },
    { 0, 0, 0, 3, 0, 0, 6 }, //2-9
        //위, 아래, 앞, 뒤, 왼, 오
    { 0, 0, 2, 0, 4, 5, 0 }, //3-1
    { 0, 0, 2, 0, 4, 0, 0 },
    { 0, 0, 2, 0, 4, 0, 6 }, //2-3
    { 0, 0, 2, 0, 0, 5, 0 }, //3-4
    { 0, 0, 2, 0, 0, 0, 0 }, //중심
    { 0, 0, 2, 0, 0, 0, 6 }, //3-6
    { 0, 0, 2, 3, 0, 5, 0 },
    { 0, 0, 2, 3, 0, 0, 0 },
    { 0, 0, 2, 3, 0, 0, 6 }, //3-9
};

void cub_rot(int num, int side ,int clock) {
    int temp[7], i;
    for (i = 1; i <= 6; i++) {
        temp[i] = cub[num][i];
    }
    //위, 아래, 앞, 뒤, 왼, 오
    if ((side == 1 && clock==1) || (side == 2 && clock == -1)) {//위시계=아래반시계 
        cub[num][1] = temp[1]; cub[num][2] = temp[2];
        cub[num][5] = temp[3]; cub[num][6] = temp[4];
        cub[num][4] = temp[5]; cub[num][3] = temp[6];
    }
    else if ((side == 1 && clock == -1) || (side == 2 && clock == 1)) {//위시계=아래반시계 
        cub[num][1] = temp[1]; cub[num][2] = temp[2];
        cub[num][5] = temp[4]; cub[num][6] = temp[3];
        cub[num][4] = temp[6]; cub[num][3] = temp[5];
    }
    else if ((side == 3 && clock == 1) || (side == 4 && clock == -1)) {//3시계=4반시계 
        cub[num][3] = temp[3]; cub[num][4] = temp[4];
        cub[num][1] = temp[5]; cub[num][2] = temp[6];
        cub[num][5] = temp[2]; cub[num][6] = temp[1];
    }
    else if ((side == 3 && clock == -1) || (side == 4 && clock == 1)) {//위시계=아래반시계 
        cub[num][3] = temp[3]; cub[num][4] = temp[4];
        cub[num][1] = temp[6]; cub[num][2] = temp[5];
        cub[num][5] = temp[1]; cub[num][6] = temp[2];
    }
    else if ((side == 5 && clock == 1) || (side == 6 && clock == -1)) {//3시계=4반시계 
        cub[num][5] = temp[5]; cub[num][6] = temp[6];
        cub[num][3] = temp[1]; cub[num][4] = temp[2];
        cub[num][1] = temp[4]; cub[num][2] = temp[3];
    }
    else if ((side == 5 && clock == -1) || (side == 6 && clock == 1)) {//3시계=4반시계 
        cub[num][5] = temp[5]; cub[num][6] = temp[6];
        cub[num][3] = temp[2]; cub[num][4] = temp[1];
        cub[num][1] = temp[3]; cub[num][2] = temp[4];
    }
}

void rot(int side, int clock) {
    int i, temp[10], now, j;
    if (side == 1) {
        for (i = 1; i <= 9; i++) {
            temp[i] = cube[i];
            cub_rot(cube[i], side, clock);
        }
        if (clock == 1) {
            cube[1] = temp[7]; cube[3] = temp[1]; cube[7] = temp[9]; cube[9] = temp[3];
            cube[2] = temp[4]; cube[4] = temp[8]; cube[8] = temp[6]; cube[6] = temp[2];
            
        }
        else {
            cube[1] = temp[3]; cube[3] = temp[9]; cube[7] = temp[1]; cube[9] = temp[7];
            cube[2] = temp[6]; cube[6] = temp[8]; cube[8] = temp[4]; cube[4] = temp[2];
        }
    }
    else if (side == 2) {
        for (i = 1; i <= 9; i++) {
            temp[i] = cube[i+18];
            cub_rot(cube[i + 18], side, clock);
        }
        if (clock == 1) {
            cube[19] = temp[3]; cube[21] = temp[9]; cube[25] = temp[1]; cube[27] = temp[7];
            cube[20] = temp[6]; cube[22] = temp[2]; cube[26] = temp[4]; cube[24] = temp[8];
        }
        else {
            cube[19] = temp[7]; cube[21] = temp[1]; cube[25] = temp[9]; cube[27] = temp[3];
            cube[20] = temp[4]; cube[22] = temp[8]; cube[26] = temp[6]; cube[24] = temp[2];
        }
    }
    else if (side == 3) {
        for (j = 0, now = 1; j <= 18; j += 9) {
            for (i = 7; i <= 9; i ++) {
                temp[now++] = cube[i + j];
                cub_rot(cube[i + j], side, clock);
            }
        }
        if (clock == 1) {
            cube[7] = temp[7]; cube[9] = temp[1]; cube[27] = temp[3]; cube[25] = temp[9];
            cube[8] = temp[4]; cube[18] = temp[2]; cube[26] = temp[6]; cube[16] = temp[8];

        }
        else {
            cube[7] = temp[3]; cube[25] = temp[1]; cube[27] = temp[7]; cube[9] = temp[9];
            cube[8] = temp[6]; cube[18] = temp[8]; cube[26] = temp[4]; cube[16] = temp[2];
        }
    }
    else if (side == 4) {
        for (j = 0, now = 1; j <= 18; j += 9) {
            for (i = 1; i <= 3; i++) {
                temp[now++] = cube[i + j];
                cub_rot(cube[i + j], side, clock);
            }
        }
        if (clock == 1) {
            cube[1] = temp[3]; cube[19] = temp[1]; cube[21] = temp[7]; cube[3] = temp[9];
            cube[2] = temp[6]; cube[12] = temp[8]; cube[20] = temp[4]; cube[10] = temp[2];
        }
        else {
            cube[1] = temp[7]; cube[19] = temp[9]; cube[21] = temp[3]; cube[3] = temp[1];
            cube[2] = temp[4]; cube[12] = temp[2]; cube[20] = temp[6]; cube[10] = temp[8];
        }
    }
    else if (side == 5) {
        for (j=0, now=1; j<=18; j+=9) {
            for (i = 1; i <= 9; i += 3) {
                temp[now++] = cube[i + j];
                cub_rot(cube[i + j], side, clock);
            }
        }//1,4,7,10,16,19, 22, 25
        if (clock == 1) {
            cube[1] = temp[7]; cube[7] = temp[1]; cube[25] = temp[3]; cube[19] = temp[9];
            cube[4] = temp[4]; cube[16] = temp[2]; cube[22] = temp[6]; cube[10] = temp[8];

        }
        else {
            cube[1] = temp[3]; cube[7] = temp[9]; cube[25] = temp[7]; cube[19] = temp[1];
            cube[4] = temp[6]; cube[16] = temp[8]; cube[22] = temp[4]; cube[10] = temp[2];
        }
    }
    else if (side == 6) {
        for (j = 0, now = 1; j <= 18; j += 9) {
            for (i = 3; i <= 9; i += 3) {
                temp[now++] = cube[i + j];
                cub_rot(cube[i+j], side, clock);
            }
        }
        if (clock == 1) {
            cube[3] = temp[3]; cube[21] = temp[1]; cube[27] = temp[7]; cube[9] = temp[9];
            cube[6] = temp[6]; cube[18] = temp[8]; cube[24] = temp[4]; cube[12] = temp[2];
        }
        else {
            cube[3] = temp[7]; cube[9] = temp[1]; cube[27] = temp[3]; cube[21] = temp[9];
            cube[6] = temp[4]; cube[18] = temp[2]; cube[24] = temp[6]; cube[12] = temp[8];
        }
    }
}

void print() {
    int i, j;
    for (i = 1; i <= 9; i++) {
        cout << color[cub[cube[i]][1]];
        if (i%3==0) cout << "\n";
    }
    //cout << endl;
    /*for (i = 1; i <= 9; i++) {
        cout << cube[i];
        if (i % 3 == 0) cout << "\n";
    }*/
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, testn, n, s, d;
    string x;
    cin >> testn;
    while (testn--) {
        for (i = 1; i <= 27; i++) cube[i] = i;
        for (i = 1; i <= 27; i++) {
            for (j = 1; j <= 6; j++) {
                cub[i][j] = tem[i][j];
            }
        }
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> x;
            if (x[0] == 'U') s = 1;
            else if (x[0] == 'D') s = 2;
            else if (x[0] == 'F') s = 3;
            else if (x[0] == 'B') s = 4;
            else if (x[0] == 'L') s = 5;
            else if (x[0] == 'R') s = 6;
            if (x[1] == '+') d = 1;
            else d = -1;
            rot(s, d);
            //cout << i << "번재 "<< x<<"\n";
            //print();
            //cout << endl;
        }
        print();
    }
    

}
