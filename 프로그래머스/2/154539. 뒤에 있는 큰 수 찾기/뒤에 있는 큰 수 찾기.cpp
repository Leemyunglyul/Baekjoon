#include <string>
#include <vector>
#include<stack>


using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int i;
    for(i=0;i<numbers.size();i++) answer.push_back(0);
    stack<pair<int, int>> st;
    for(i=0;i<numbers.size();i++){
        while(!st.empty() &&st.top().first<numbers[i]){
            answer[st.top().second]=numbers[i];
            st.pop();
        }
         st.push({numbers[i], i});
    }
    while(!st.empty()){
         answer[st.top().second]=-1;
        st.pop();
    }
    return answer;
}