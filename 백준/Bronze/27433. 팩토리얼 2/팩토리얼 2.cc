#include <iostream>
using namespace std;

int main()
{
    int n, i;
    cin>>n;
    long long int x=1;
    for(i=1;i<=n;i++)
        x*=i;
    cout << x;
}