#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    int i;
    for(i=0;i<queries.size();i++){
        int temp=arr[queries[i][0]];
        arr[queries[i][0]]=arr[queries[i][1]];
        arr[queries[i][1]]=temp;
    }
    answer=arr;
    return answer;
}