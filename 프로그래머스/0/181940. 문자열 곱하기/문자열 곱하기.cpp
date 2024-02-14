#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int k) {
    string answer = "";
    int i;
    for(i=0;i<k;i++) answer+=my_string;
    return answer;
}