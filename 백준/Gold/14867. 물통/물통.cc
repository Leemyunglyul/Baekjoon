#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

set<pair<int, int>> visited;
queue<tuple<int, int, int>> q;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int a, b, x, y, t1, t2;
    cin>>a>>b>>x>>y;
    q.push({0, 0, 0});
    visited.insert({0, 0});
    while(!q.empty()){
        int num=get<0>(q.front());
        int s1=get<1>(q.front());
        int s2=get<2>(q.front());
        q.pop();

        if(s1==x && s2==y){
            cout<<num;
            return 0;
        }

        if(visited.find({s1, 0})==visited.end()){
            visited.insert({s1, 0});
            q.push({num+1, s1, 0});
        }
        if(visited.find({0, s2})==visited.end()){
            visited.insert({0, s2});
            q.push({num+1, 0, s2});
        }
        if(visited.find({a,s2})==visited.end()){
            visited.insert({a, s2});
            q.push({num+1, a, s2});
        }
        if(visited.find({s1, b})==visited.end()){
            visited.insert({s1, b});
            q.push({num+1, s1, b});
        }
        //b를 a로
        if(s1+s2>a){
            t1=a;
            t2=s2-(a-s1);
        }
        else{
            t1=s1+s2;
            t2=0;
        }
        if(visited.find({t1, t2})==visited.end()){
            visited.insert({t1, t2});
            q.push({num+1, t1, t2});
        }
        //a를 b로
        if(s1+s2>b){
            t1=s1-(b-s2);
            t2=b;
        }
        else{
            t1=0;
            t2=s1+s2;
        }
        if(visited.find({t1, t2})==visited.end()){
            visited.insert({t1, t2});
            q.push({num+1, t1, t2});
        }
    }

    cout<<"-1";

    return 0;
}