#include <iostream>
int main() {
    long long n, i, k, x;
    std::cin>>n>>k;
    for(i=1, x=1;i<=n;i++) x=x*i%k;
    std::cout<<x;
}