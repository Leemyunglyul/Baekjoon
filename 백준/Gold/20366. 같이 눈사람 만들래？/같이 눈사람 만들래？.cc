#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

int arr[610];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, k, s1, s2, sum1, sum2;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int anw = abs(arr[1]+arr[n]-arr[2]-arr[n-1]);
    for (i = 1; i <= n; i++) {
        for (j = n; j >=i+3; j--) {
            sum1 = arr[i] + arr[j];
            s1 = i + 1; s2 = j - 1;
            while (s1 < s2) {
                sum2 = arr[s1] + arr[s2];
                anw = min(abs(sum1-sum2), anw);
                if (sum1 == sum2){
                    cout<<"0";return 0;
                }
                else if (sum1 > sum2) {
                    s1++;
                }
                else s2--;

            }
        }
    }
    cout << anw;
}