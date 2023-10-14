#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;


int main() {
	int x, y, z;
	double w;
	cin >> x >> y >> z;
	w = sqrt((double)(x * x) / (y * y + z * z));
	y =(int)floor(w * y);
	z = (int)floor(w * z);
	cout << y << " " << z;
}