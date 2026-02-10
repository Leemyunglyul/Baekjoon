#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <map>

using namespace std;

long long p[52];
long long anw[52];

struct line{
    double m, c;
};

struct point{
    long long x, y;
};

line make_line(int x, int y){
    point p1, p2;
    p1.x = x;
    p1.y=p[x];
    p2.x = y;
    p2.y=p[y];

    line l;
    double a = (double)(p2.y - p1.y);
    double c = (double)(p2.x - p1.x);
    l.m = a / c;
    l.c = - l.m * p1.x + p1.y;
    return l;
};

double pos(int x, line l){
    return l.m * x + l.c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, i, j, k, x, y;

    cin>>n;

    for(i=1;i<=n;i++){
        cin>>p[i];
    }

    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            line l = make_line(i, j);
            bool valid = true;
            for(k=i+1;k<j;k++){
                if(pos(k, l) <= p[k]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                anw[i]++;
                anw[j]++;
            }
        }
    }

    long long ab = 0;    
    for(i=1;i<=n;i++){
        ab = max(ab, anw[i]);
    }
    cout<<ab<<"\n";
    

    return 0;
}