#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

map<string, int> listn;

int solution(vector<string> friends, vector<string> gifts) {
    int giftn[52][52]={0};
    int num[52]={0};
    int i, j, sum;
    int answer = 0;
    for(i=0;i<friends.size();i++){
        listn.insert({friends[i], i});
    }
    string f1, f2;
    for(i=0;i<gifts.size();i++){
        for(j=0, f1="", f2="";j<gifts[i].size();j++){
            if(gifts[i][j]==' ') break;
            f1+=gifts[i][j];
        }
        for(j++;j<gifts[i].size();j++){
            f2+=gifts[i][j];
        }
        num[listn[f1]]++;
        num[listn[f2]]--;
        giftn[listn[f1]][listn[f2]]++;
    }
    for(i=0;i<friends.size();i++){
        sum=0;
        for(j=0;j<friends.size();j++){
            if(i==j) continue;
            if(giftn[i][j]>giftn[j][i]) sum++;
            else if(giftn[i][j]==giftn[j][i]){
                if(num[i]>num[j]) sum++;
            }
            else continue;
        }
        answer=max(answer, sum);
    }
    return answer;
}