#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<long long> fact;


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    long long n;
    cin >> n;
    if(n==0){
        cout<<"NO\n";
        return 0;
    }

    fact.push_back(1);
    for (int i = 1; ; ++i) {
        long long next_fact = fact.back() * i;
        if (next_fact > n) { 
            break;
        }
        fact.push_back(next_fact);
    
    }
    
    for (int i = fact.size() - 1; i >= 0; --i) {
        if (n >= fact[i]) {
            n -= fact[i];
        }
    }
    
    if (n == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}