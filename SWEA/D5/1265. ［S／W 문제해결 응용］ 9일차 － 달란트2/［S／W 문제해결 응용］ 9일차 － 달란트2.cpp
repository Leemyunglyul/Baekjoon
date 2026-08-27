#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

long long solve(){
    cin>>n>>m;

    long long q, qq, anw, i, j;

    q = n / m;
    qq = n%m;

    anw = 1;

    for(i=1; i<=m; i++){
        if(qq>0){
            anw *= (q+1);
            qq--;
        } else {
            anw *= q;
        }
    }
    return anw;
}

int main(int argc, char** argv)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        cout<< "#" << test_case << " " << solve() << "\n";

	}
	return 0;
}
