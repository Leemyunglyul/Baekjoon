#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

stack<pair<string, int>> st;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> work;
map<int, string> ff;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    int hour, mint, last, left, i, now;
    string hw;
    for(i=0;i<plans.size();i++){
        hw=plans[i][0];
        string name=plans[i][1];
        hour=(name[0]-48)*10+name[1];
        mint=(name[3]-48)*10+name[4];
        work.push({hour*60+mint, stoi(plans[i][2])});
        ff[hour*60+mint]=hw;
    }
    
    while(!work.empty()){
        int t=work.top().first;//시작시간
        int ll=work.top().second;//소요시간
        hw=ff[t];//과목 이름
        work.pop();
        if(st.empty()){
            now=t;
            st.push({hw, ll});
            continue;
        }
        last=t;
        left=last-now;
        while(!st.empty() && left>0){
            if(st.top().second<=left){
                answer.push_back(st.top().first);
                left-=st.top().second;
                st.pop();
            }
            else{
                int temp=st.top().second-left;
                string temps=st.top().first;
                st.pop();
                st.push({temps, temp});
                break;
            }
        }
        st.push({hw, ll});
        now=last;
    }
    while(!st.empty()){
        answer.push_back(st.top().first);
        st.pop();
    }
    return answer;
}