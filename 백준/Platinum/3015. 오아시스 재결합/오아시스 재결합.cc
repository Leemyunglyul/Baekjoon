#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

stack<pair<int, int>> st;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int i, n, x, a, b, tmp;
	long long anw = 0;
	cin>>n;

	for(i=1; i<=n; i++){
		cin>>x;
		bool flag = false;

		while(!st.empty()){
			a = st.top().first;
			b = st.top().second;

			if(a<x){
				anw+=b;
				st.pop();
			} else if(a == x){
				anw+=b;
				st.pop();
				if(!st.empty()){
					anw++;
				}
				st.push({x, b+1});
				flag = true;
				break;
			}
			else{
				anw++;
				st.push({x, 1});
				flag = true;
				break;
			}
		}		
		if(!flag) st.push({x, 1});
	}

	cout << anw;

	return 0;

}