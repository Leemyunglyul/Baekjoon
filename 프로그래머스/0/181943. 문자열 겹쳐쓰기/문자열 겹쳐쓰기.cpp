#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    int i;
    for(i=0;i<s;i++) answer+=my_string[i];
    answer+=overwrite_string;
    for(i+=overwrite_string.size();i<my_string.size();i++) answer+=my_string[i];
    return answer;
}