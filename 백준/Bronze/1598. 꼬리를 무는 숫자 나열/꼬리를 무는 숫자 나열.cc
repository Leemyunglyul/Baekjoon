#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x, y;
    cin>>x>>y;
    cout<<abs((y-1)/4-(x-1)/4)+abs((x-1)%4-(y-1)%4);

}