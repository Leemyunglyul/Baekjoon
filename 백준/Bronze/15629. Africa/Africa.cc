#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

vector<string> trip;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, sum, j;
	string input;
	cin >> n;
	for (i = 0, sum=0; i < n; i++) {
		cin >> input;
		trip.push_back(input);
	}
	for (i = 0; i < n; i++) {
		if (trip[i] == "botswana" || trip[i] == "south-africa");
		else if (trip[i] == "tanzania" || trip[i] == "kenya" || trip[i] == "ethiopia") {
			sum += 50;
		}
		else if (trip[i] == "namibia") {
			for (j = 0; j < i; j++) {
				if (trip[j] == "south-africa") {
					sum -= 100;
				}
			}
			sum += 140;
		}
		else if (trip[i] == "zimbabwe") {
			if (i < n - 1 && trip[i + 1] == "zambia") {
				sum += 50;
				i++;
			}
			else sum += 30;
		}
		else if (trip[i] == "zambia") {
			if (i < n - 1 && trip[i + 1] == "zimbabwe") {
				sum += 50;
				i++;
			}
			else sum += 50;
		}
	}
	cout << sum;
}