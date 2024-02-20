#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> list;

vector<string> solution(vector<string> players, vector<string> callings) {
    //vector<string> answer;
    int i, j, temp;
    string x1, x2;
    for(i=0;i<players.size();i++){
        list.insert({players[i], i});
    }
    for(i=0;i<callings.size();i++){
        x1=callings[i];
        x2=players[list[callings[i]]-1];
        list[x1]--;
        list[x2]++;
        players[list[x1]]=x1;
        players[list[x2]]=x2;
    }
    return players;
}