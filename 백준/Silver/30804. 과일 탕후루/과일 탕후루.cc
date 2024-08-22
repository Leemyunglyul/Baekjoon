#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <queue>
#include <tuple>
#include <deque>

using namespace std;

int arr[200100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, front, back, color;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    int anw=0;
    int sum=0;
    for(i=1, color=0, front=0, back=0;i<=n;i++){
        if(color==0){
            sum++;
            color=1;
            front=i;
            continue;
        }
        if(color==1){
            if(arr[front]!=arr[i]){
                color++;
                back=i;
                sum++;
            }
            else{
                front=i;
                sum++;
            }
            continue;
        }
        if(color==2 && (arr[front]!=arr[i] && arr[back]!=arr[i])){
            anw=max(sum, anw);
            sum=i-front;
            front=back;
            back=i;
        }
        else if(arr[front]==arr[i]){
            front=back;
            back=i;
            sum++;
        }
        else if(arr[back]==arr[i]){
            back=i;
            sum++;
        }

    }
    cout<<max(sum, anw);

    return 0;
}