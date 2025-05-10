#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>

using namespace std;

queue<tuple<int, int, int>> q;

long long arr[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    fill_n(&arr[0], 1000001, 987654321);

    long long n, i, x, q1, q2, q3, y;
    cin>> n;
    q.push({1, 1, 1});
    arr[1]=true;
    if(n==0){
        cout<<"0 0";
        return 0;
    }

    x = 987654321;
    y = 987654321;

    while(!q.empty()){
        q1 = get<0>(q.front());
        q2 = get<1>(q.front());
        q3 = get<2>(q.front());

        //cout<<q1<<" "<<q2<<" "<<q3<<"\n";

        q.pop();

        if(q1 == n){
            if(q2<=x){
                if(q3<=y){
                    x = q2;
                    y = q3;
                }
            }
            continue;
        }
        
        if(q1+1 <= n && arr[q1+1]>=q2+1){
            q.push({q1+1, q2+1, q3+1});
            arr[q1+1]=min(q2+1, arr[q1+1]);
        }
        if(q1*3 <= n && arr[q1*3]>=q2+1){
            q.push({q1*3, q2+1, q3+3});
            arr[q1*3]=min(q2+1, arr[q1*3]);
        }
        if(q1*q1 <= n && arr[q1*q1]>=q2+1){
            q.push({q1*q1, q2+1, q3+5});
            arr[q1*q1]=min(q2+1, arr[q1*q1]);
        }
    }
    cout<< x <<" "<<y;
}