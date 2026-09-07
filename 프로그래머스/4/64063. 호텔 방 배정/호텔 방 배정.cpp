#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> parent;

long long find(long long x) {
    auto it = parent.find(x);
    if (it == parent.end()) {
        parent[x] = x;
        return x;
    }
    if (it->second == x) return x;
    return it->second = find(it->second);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    answer.reserve(room_number.size());

    for (long long want : room_number) {
        long long assigned = find(want);
        answer.push_back(assigned);
        parent[assigned] = assigned + 1; 
    }

    return answer;
}