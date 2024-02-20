#include <string>
#include <vector>
#include<map>
#include<algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> ssort; 
map<int, int> hash;
long long int sum[2510]={0};

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    int i, j;
    for(i=0;i<data.size();i++){
        ssort.push_back({{data[i][col-1],-data[i][0]},i});
    }
    sort(ssort.begin(), ssort.end());
    for(i=row_begin;i<=row_end;i++){
        int temp=ssort[i-1].second;
        for(j=0;j<data[temp].size();j++){
            sum[i]+=(data[temp][j]%i);
        }
    }
    for(i=row_begin+1, answer=sum[i-1];i<=row_end;i++){
        answer=answer^sum[i];
    }
    return answer;
}