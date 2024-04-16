#include <iostream>
#include <map>

using namespace std;

long long sum[200100] = {0};
long long arr[200100] = {0};
map<long long, long long> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, k, i, anw;
    cin >> n >> k;
    s.insert({ 0, 1 });
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = (arr[i] + sum[i - 1])-k;
        if (s.find(sum[i]) != s.end()) {
            s[sum[i]]++;
        }
        else {
            s.insert({ sum[i], 1 });
        }
    }
    map<long long, long long>::iterator it;
    for (it = s.begin(), anw=0; it != s.end(); it++) {
        long long temp = it->second;
        anw += temp*(temp - 1) / 2;
    }
    cout << anw;
    return 0;
}