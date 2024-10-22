#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<a+b+c+d+e+f-min(min(a,b),min(c,d))-min(e,f);
}