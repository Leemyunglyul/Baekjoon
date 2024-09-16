#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c;
    cin>>a>>b>>c;
    cout<<a+b-c<<endl;
    cout<<stoi(to_string(a)+to_string(b))-c;
}
