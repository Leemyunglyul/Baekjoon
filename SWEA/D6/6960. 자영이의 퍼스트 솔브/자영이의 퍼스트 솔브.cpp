#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> arr[1010];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> aw;

int solve(){
    while (!aw.empty()) aw.pop();
    int n, i, j, x, y;

    cin>> n;

    int time = 0;
    int anw = 0;

    for(i=1;i<=n;i++){
        cin>>arr[i].first >> arr[i].second;

        pq.push({arr[i].second, arr[i].first});
    }

    while(!pq.empty()){

        
        int t = pq.top().second;
        int due = pq.top().first;

        pq.pop();

        if(time + t <= due){
            anw++;
            time += t;
            aw.push(t);
        } else{
            if(!aw.empty() && aw.top()>t && time - aw.top() + t <= due){
                time = time - aw.top() + t;
                aw.pop();
                aw.push(t);
                
            }
        }
    }

    return anw;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout <<"#"<<test_case << " "<< solve()<<"\n";

	}
	return 0;
}