#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
using ppi = pair<ll, ll>;


ppi pos(ll x, int h){
    if(h==1){
        ppi arr[4] = {{1, 1}, {1, 2}, {2, 2}, {2, 1}}; 
        return arr[x-1];
    }
    ll s = 1LL << (h - 1);
    ll s_sq = s * s;  

    if(x <= s_sq) { 
        ppi p = pos(x, h - 1);
        return {p.second, p.first}; 
    } 
    else if(x <= 2 * s_sq) {
        ppi p = pos(x - s_sq, h - 1);
        return {p.first, p.second + s};
    } 
    else if(x <= 3 * s_sq) { 
        ppi p = pos(x - 2 * s_sq, h - 1);
        return {p.first + s, p.second + s};
    } 
    else {
        ppi p = pos(x - 3 * s_sq, h - 1);
        return {(2 * s) + 1 - p.second, s + 1 - p.first}; 
    }
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int testn;
    int h;
    ll x1, x2; 

    cin >> testn;
    while(testn--){
        cin >> h >> x1 >> x2;

        ppi p1 = pos(x1, h);
        ppi p2 = pos(x2, h);

        double unit_dist = distance(p1.first, p1.second, p2.first, p2.second);
        double real_dist = unit_dist * 10.0;
        
        cout << (ll)round(real_dist) << "\n";
    }

    return 0;
}