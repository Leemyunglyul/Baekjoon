#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, sum, j;
    int big = 0;
    string x;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        sum = 0;
        for (j = 0; j < x.size(); j++) {
            if (x[j] == 'f') {
                if (j + 1 < x.size() && x[j + 1] == 'o') {
                    if (j + 2 < x.size() && x[j + 2] == 'r') {
                        sum++;
                        j++;
                    }
                    j++;
                }
            }
            else if (x[j] == 'w') {
                if (j + 1 < x.size() && x[j + 1] == 'h') {
                    if (j + 2 < x.size() && x[j + 2] == 'i') {
                        if (j + 3 < x.size() && x[j + 3] == 'l') {
                            if (j + 4 < x.size() && x[j + 4] == 'e') {
                                sum++;
                                j++;
                            }
                            j++;
                        }
                        j++;
                    }
                    j++;
                }
               
            }
        }
        big = max(big, sum);
    }
    cout << big;

    return 0;
}