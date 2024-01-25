#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<set>
#include<algorithm>
//#include<functional>

using namespace std;
vector<char> st;
set<string> s;
set<string>::iterator it;
vector<string> whole;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string word, fake;
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> word;
		for (j = 0; j < word.size(); j++) {
			st.push_back(word[j]);
		}
		sort(st.begin(), st.end());
		for (j = 0, fake=word; j < word.size(); j++) {
			fake[j] = st[j];
		}
		it = s.find(fake);
		if (s.empty() || it == s.end()) {
			s.insert(fake);
			whole.push_back(word);
		}
		st.clear();
	}
	for (i = 0; i < whole.size(); i++) {
		cout << whole[i] << '\n';
	}
}