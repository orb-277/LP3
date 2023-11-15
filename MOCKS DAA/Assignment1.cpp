#include <bits/stdc++.h>
using namespace std;

int fibrec(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return fibrec(n - 1) + fibrec(n - 2);
	}
}

int fibdp(int n) {
	int x0 = 0;
	int x1 = 1;
	if (n <= 1) {
		return n;
	}
	for (int i = 2; i <= n; ++i)
	{
		int temp = x1;
		x1 = x1 + x0;
		x0 = temp;
	}
	return x1;
}



int main() {
	cout << fibrec(5) << endl;
	cout << fibdp(1) << endl;
	return 0;
}