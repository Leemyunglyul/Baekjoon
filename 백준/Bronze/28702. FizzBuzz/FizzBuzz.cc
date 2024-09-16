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

int check(string x){
    if(x=="FizzBuzz" || x=="Fizz" || x=="Buzz") return 0;
    else return stoi(x);
}

string tf(int x){
    if(x%3==0 && x%5==0) return "FizzBuzz";
    else if(x%3==0) return "Fizz";
    else if(x%5==0) return "Buzz";
    else return to_string(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string x, y, z;
    cin>>x>>y>>z; 
    int a=check(x);
    if(a!=0){
        cout<<tf(a+3);
        return 0;
    }
    a=check(y);
    if(a!=0){
        cout<<tf(a+2);
        return 0;
    }
    a=check(z);
    if(a!=0){
        cout<<tf(a+1);
        return 0;
    }
}
