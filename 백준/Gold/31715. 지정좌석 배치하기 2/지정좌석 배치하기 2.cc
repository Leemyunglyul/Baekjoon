#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define div 1000000007

using namespace std;

vector<long long> arr[1010];
long long list[1010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, m, d, i, j, sum, s, x, k;
    cin >> n >> m >> d;
    for (i = 1, sum = 1; i <= m; i++) {
        sum = (sum * i) % div;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> x;
            arr[i].push_back(x+d*(i-1));
        }
        sort(arr[i].begin(), arr[i].begin() + m);
        if (i == 1) continue;
        fill_n(&list[0], 1010, 0);
        
        for (j = 0, k=0; j < m; j++) {
            while (k<m-1 && arr[i - 1][k] < arr[i][j]) k++;
            if (arr[i - 1][k] >= arr[i][j]) list[j] = k;
            else list[j] = k + 1;
           //cout<<arr[i-1][k]<<"vs"<<arr[i][j]<<"==" << list[j] << " \n";
        }
        //cout << endl;
        //cout << "/////" << endl;
        for (j = 0, s = 0; j < m; j++) {
            if (list[j] <= j) {
                s = 0;
                break;
            }
            if (j == 0) {
                s = list[j];
            }
            else {
                s = s * (list[j] - j) % div;
            }
        }
        sum =(sum * s)% div;
    }
    cout << sum;

    return 0;
}