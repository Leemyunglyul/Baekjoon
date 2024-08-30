#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <iomanip>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    double a, b;
    cin>>a>>b;
    double c=299792458.0;
    cout<<fixed<<setprecision(10)<<(a+b)/(1+a*b/c/c);
}