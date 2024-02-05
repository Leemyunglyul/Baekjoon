#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
	
int LCS[1002][1002];
string x, y, result;

string lcs(int i, int j) {
	if (i == 0 || j == 0) return "";
	else if (x[i-1] == y[j-1]) return lcs(i - 1, j - 1) + x[i-1];

	if (LCS[i][j - 1] >= LCS[i - 1][j]) return lcs(i, j - 1);
	else return lcs(i - 1, j);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> y;
	int i, j;
	for (i = 1; i <= x.size(); i++)
	{
		for (j = 1; j <= y.size(); j++)
		{
			if (x[i-1] == y[j-1])
				LCS[i][j] = LCS[i-1][j-1] + 1;
			else
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	cout << LCS[x.size()][y.size()]<<endl;
	cout<< lcs(x.size(), y.size());
	
}