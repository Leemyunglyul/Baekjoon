#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(string X, string Y) {
    int i, j, rem, mem;
    int a1[10]={0};
     int a2[10]={0};
    for(i=0;i<X.size();i++){
        a1[X[i]-48]++;
    }
    for(i=0;i<Y.size();i++){
        a2[Y[i]-48]++;
    }
    string answer = "";
    for(i=9;i>=0;i--){
        if(a1[i]==0 || a2[i]==0) continue;
        if(i==0 && answer==""){
            answer="0";
            break;
        }
        for(j=0;j<min(a1[i], a2[i]);j++){
            answer+=i+48;
        }
    }
    if(answer=="") answer="-1";
    return answer;
}