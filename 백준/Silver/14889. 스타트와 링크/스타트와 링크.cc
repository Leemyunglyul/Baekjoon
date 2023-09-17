#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int team[21][21];
int Team[21];
int NotTeam[21];
int score[21] = {0};
int Notscore[21] = { 0 };
int n;
int Min = 50000;

void bruteback(int x)
{
	int i, j, con;
	int number;
	if (x == n/2)
	{
		for (j = 0; j < n; j++)
		{
			Notscore[j] = 0;
			NotTeam[j] = 0;
		}
		for (j = 0; j < n/2; j++)
			Notscore[Team[j]] =1;
		i = 0;
		for (j = 0; j < n; j++)
			if (Notscore[j] == 0)
				NotTeam[i++] = j;
		
		number = 0;
		for (i = 0; i < n/2; i++) {
				for (j = 0; j < i; j++)
					number += team[NotTeam[i]][NotTeam[j]] + team[NotTeam[j]][NotTeam[i]];
		}
		/*printf("\n스타트팀 : ");
		for (j = 0; j < n/2; j++)
			printf("%d", Team[j]);
		printf("\n상대팀 : ");
		for (j = 0; j < n / 2; j++)
			printf("%d", NotTeam[j]);
		printf("\n%d %d\n", number, score[x - 1]);*/
		if (number <= score[x - 1])
			number = score[x - 1] - number;
		else
			number -= score[x - 1];
		if (number < Min)
			Min = number;
		
		return;
	}
	if (x == 0){
		for (i = 0; i < n/2; i++) {
			Team[x] = i;
			bruteback(x + 1);
		}
	}
	else {
		for (i = Team[x-1]+1; i < n/2+x; i++){
			
			score[x] = score[x - 1];
			Team[x] = i;
			for (j = 0; j < x; j++)
				score[x] += team[Team[x]][Team[j]] + team[Team[j]][Team[x]];
			bruteback(x + 1);
		}
	}
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++)
			cin >> team[i][j];
	bruteback(0);
	cout << Min;
	return 0;
}