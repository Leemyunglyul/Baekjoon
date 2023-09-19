#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int i, j, n, bnum, pre;
	string input, memory, bomb;
	cin >> input;
	cin >> bomb;
	for (i = 0; i < input.size(); i++)
	{
		j = 0;
		if (input[i] == bomb[bomb.size() - 1])
		{
			//cout << "들어갔따" << memory.size()<<endl;
			n = memory.size();
			if (n == 0 && bomb.size() == 1)
				continue;
			else if (n == 0 && bomb.size() != 1);
			else {
				for (j = bomb.size() - 2; j >= 0; j--, n--)
					if (memory[n - 1] != bomb[j])
						break;
				if (j == -1)
					memory = memory.erase(memory.size() - bomb.size() + 1, memory.size());
				else
					j = 0;
			}
		}
		if(j==0)
			memory += input[i];
		//cout << memory << endl;
	}
	if (memory.size() == 0)
		cout << "FRULA";
	else
		cout << memory;
	return 0;
}