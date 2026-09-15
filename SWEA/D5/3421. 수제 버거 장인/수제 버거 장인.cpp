#include <iostream>
#include <set>
#include <bitset>
using namespace std;

typedef long long ll;

set<pair<ll, ll> > s;

int n, m;

ll ans = 0;

void tsp(int pre, ll sum){

    if(pre == n+1){
        ans++;
        //cout<<"sum : " << bitset<16>(sum) << "\n";
        return;
    }

    bool flag = true;

    for(int i=1; i<pre; i++){
        
        if(!(sum & (1LL << i))) continue;
        if(s.find({i, pre}) != s.end()){
            flag = false;
            break;
        }
    }

    if(flag) tsp(pre+1, sum | (1LL << pre));


    tsp(pre+1, sum);


}

void solve(){
    cin >> n >> m;

    int i, j, x, y;

    for(i=0; i<m; i++){
        cin >> x >> y;
        s.insert({x, y});
        s.insert({y, x});
    }

    tsp(1, 0);
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

        cout << "#" << test_case << " ";
        solve();
        cout << ans << "\n";
        ans = 0;
        s.clear();

	}
	return 0;
}