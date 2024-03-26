#include <stdio.h>
#define mod 1000000007

typedef struct {
	long long array[2][2];
} Matrix;

Matrix matrix_multiply_modular (Matrix A, Matrix B);
Matrix matrix_power_modular (Matrix Base, long long power);

int main() {
	
	long long N;
	scanf("%lld", &N);
	
	if (N % 2) {
		printf("0");
	}
	else {
		Matrix Base = { {{0,1},{-1,4}} };
		Matrix Answer = { {{1,0},{3,0}} };
		
		Base = matrix_power_modular (Base, N/2);
		Answer = matrix_multiply_modular (Base, Answer);
		
		printf("%lld", Answer.array[0][0]);
	}
	return 0;
}

Matrix matrix_multiply_modular (Matrix A, Matrix B) {
	Matrix result = { {{0}} };
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < 2; j++) {
				long long temp = (A.array[i][k] * B.array[k][j] + mod) % mod;
				result.array[i][j] = (result.array[i][j] + temp) % mod;
			}
		}
	}
	return result;
}

Matrix matrix_power_modular (Matrix Base, long long power) {
	Matrix result = { {{1,0},{0,1}} };
	while(power) {
		if (power % 2) {
			result = matrix_multiply_modular (result, Base);
		}
		Base = matrix_multiply_modular (Base, Base);
		power /= 2;
	}
	return result;
}