#include <string>
#include <vector>

using namespace std;

int arr[510][510]={0};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int i, j;
    for(i=0, arr[0][0]=triangle[0][0];i<triangle.size()-1;i++){
        for(j=0;j<triangle[i].size();j++){
            arr[i+1][j]=max( arr[i+1][j],arr[i][j]+triangle[i+1][j]);
            arr[i+1][j+1]=max( arr[i+1][j+1],arr[i][j]+triangle[i+1][j+1]);
        }
    }
    for(i=0;i<triangle[triangle.size()-1].size();i++){
        answer=max(answer, arr[triangle.size()-1][i]);
    }
    return answer;
}