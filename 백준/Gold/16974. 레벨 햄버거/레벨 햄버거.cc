#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

long long patty(int n){
    if (n == 0) return 1;
    return (1LL << (n + 1)) - 1;
}

long long burger(int n){
    if (n == 0) return 1;
    return (1LL << (n + 2)) - 3;
}

long long find(int cur, long long left){
    if (cur == 0) return 1; 
    
    long long prev_patty = patty(cur - 1);
    long long prev_burger = burger(cur - 1);
    if (left == 1) return 0;
    else if (left <= 1 + prev_burger) {
        return find(cur - 1, left - 1);
    }
    else if (left == 2 + prev_burger) {
        return prev_patty + 1;
    }
    else { 
        long long remaining_left = left - (2 + prev_burger);
        return prev_patty + 1 + find(cur - 1, remaining_left);
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int n;
    long long x; 
    
    cin>> n >> x;
    cout << find(n, x); 
    
    return 0;
}