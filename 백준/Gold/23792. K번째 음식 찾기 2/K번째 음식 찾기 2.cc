#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int>& A, vector<int>& B, vector<int>& C, int n, int k, int o, int x, int y, int z)
{
    int l, r;
    l = 0; r = x - 1;
    while (l <= r)
    {
		int m = (l+r)/2;
		int cur = m+1;

        cur += lower_bound(B.begin(), B.begin() + y, A[m]) - B.begin();
        cur += lower_bound(C.begin(), C.begin() + z, A[m]) - C.begin();

        if (cur == k)
        {
            cout << o << ' ' << m + 1 << '\n';
            return 1;
        }

        cur > k ? r = m - 1 : l = m + 1;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	vector <int> A(n), B(n), C(n);
    for (int& i : A) cin >> i;
    for (int& i : B) cin >> i;
    for (int& i : C) cin >> i;
 
    int q; cin >> q;
    for (int x, y, z, k; q--;)
    {
        cin >> x >> y >> z >> k;
        if (solve(A, B, C, n, k, 1, x, y, z));
        else if (solve(B, A, C, n, k, 2, y, x, z));
        else solve(C, A, B, n, k, 3, z, x, y);
    }
	
}