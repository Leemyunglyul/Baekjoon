#include <iostream>
#include <fstream>
//#include <string>
//#include <vector>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
long long int arr[100002];
stack <pair<int,int>> s;
long long int w = 0;

int main()
{
	int n, i;
	long long temp;
	//ifstream infile;
	//ofstream outfile;
	//infile.open("input.txt");
	//outfile.open("output.txt");
	while (1)
	{
		w = 0;
		//infile >> n;
		cin >> n;
		if (n == 0)
			return 0;
		for (i = 0; i < n; i++)
		{
			//infile >> arr[i];
			temp = i;
			cin >> arr[i];
			while (!s.empty() && arr[i] < arr[s.top().first])
			{
				temp = s.top().second;
				w = max(w, (i - temp) * arr[s.top().first]);
				s.pop();
			}
			if (!s.empty() && arr[i] == arr[s.top().first])
				continue;
			
			s.push({ i, temp });
		}
		while (!s.empty())
		{
			w = max(w, (long long)arr[s.top().first] * (n - s.top().second));
			s.pop();
		}
		//outfile << w <<endl;
		cout << w << endl;
	}
	//infile.close();
	//outfile.close();
	return 0;
}