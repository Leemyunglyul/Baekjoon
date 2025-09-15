#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, w, l;
    cin >> n >> w >> l;

    queue<int> wait;
    for (int i = 0; i < n; i++) {
        int truck;
        cin >> truck;
        wait.push(truck);
    }

    queue<int> bridge;
    for (int i = 0; i < w; i++) {
        bridge.push(0);
    }
    
    int time = 0;
    int curr_weight = 0;

    while (!wait.empty() || curr_weight > 0) {
        time++;
        
        int exit_truck = bridge.front();
        bridge.pop();
        curr_weight -= exit_truck;

        if (!wait.empty()) {
            int next_truck = wait.front();
            if (curr_weight + next_truck <= l) {
                curr_weight += next_truck;
                bridge.push(next_truck);
                wait.pop();
            } else {
                bridge.push(0);
            }
        } else {
            bridge.push(0);
        }
    }

    cout << time;

    return 0;
}