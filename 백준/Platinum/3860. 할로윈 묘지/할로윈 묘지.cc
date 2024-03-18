#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include<climits>
#include<queue>

using namespace std;

int land[40][40];
int dp[40][40];
vector<tuple<int, int, int, int, int>> edge;
vector<tuple<int, int, int, int, int>> temp;
int col, row, gn;


void print() {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void add_edge() {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (land[i][j] !=0 || (i==row-1 && j==col-1)) continue;
            if (i > 0) {
                if (land[i - 1][j] == -1);
                else {
                    edge.push_back({ i, j, i - 1, j, 1 });
                }
            }
            if (j > 0) {
                if (land[i][j-1] == -1);
                else {
                    edge.push_back({ i, j, i, j-1, 1 });
                }
            }
            if (i < row - 1) {
                if (land[i + 1][j] == -1);
                else {
                    edge.push_back({ i, j, i + 1, j, 1 });
                }
            }
            if (j <col-1) {
                if (land[i][j + 1] == -1);
                else {
                    edge.push_back({ i, j, i, j + 1, 1 });
                }
            }
        }
    }
}

void path() {
    int i, j, k, r1, c1, r2, c2, dd;
    
    //int temp[40][40];
    /*for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            temp[i][j]=dp[i][j];
        }
    }*/
   
    for (i = 0; i < edge.size(); i++) {
        r1 = get<0>(edge[i]);
        c1= get<1>(edge[i]);
        r2=  get<2>(edge[i]);
        c2 = get<3>(edge[i]);
        dd= get<4>(edge[i]);
        if (dp[r1][c1] == INT_MAX) continue;

        dp[r2][c2] = min(dp[r2][c2], dp[r1][c1] + dd);
    }
    /*for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            dp[i][j] = temp[i][j];
        }
    }*/
}

bool neg_cycle() {
    int i, j;
    int temp[40][40];
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            temp[i][j] = dp[i][j];
        }
    }
    path();
    //print();
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (dp[i][j] != temp[i][j]) return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, r, c, hole, r2, c2, tt;
    while (1) {
        cin >> col >> row;
        if (col == 0 && row == 0) return 0;
        cin >> gn;
        fill_n(&dp[0][0], 40 * 40, INT_MAX);
        fill_n(&land[0][0], 40 * 40, 0);
        for (i = 0; i < gn; i++) {
            cin >> c >> r;
            land[r][c] = -1;
        }
        
        cin >> hole;
        for (i = 0; i < hole; i++) {
            cin >> c >> r >> c2 >> r2 >> tt;
            temp.push_back({ r,c, r2, c2, tt });
            land[r][c] = 1;
        }
        add_edge();
        while (!temp.empty()) {
            edge.push_back(temp.back());
            temp.pop_back();
        }
        dp[0][0] = 0;
       // print();
        for (i = 1; i <= row * col - gn; i++) {
            path();
          //  print();
        }
        if (neg_cycle()) {
            cout << "Never";
        }
        else if (dp[row - 1][col - 1] == INT_MAX) cout << "Impossible";
        else cout << dp[row - 1][col - 1];
        cout << "\n";
       //print();
        edge.clear();
    }
}
