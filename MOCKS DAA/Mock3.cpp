/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int knapSackRec(int i, int W, vector<int> wt, vector<int> val, vector<vector<int>> &dp) {
	if (i >= wt.size() || W <= 0) {
		return 0;
	}
	if (dp[i][W] != -1) {
		return dp[i][W];
	}
	if (W >= wt[i]) {

		dp[i][W] = max(knapSackRec(i + 1, W, wt, val, dp), knapSackRec(i + 1, W - wt[i], wt, val, dp) + val[i]);
		return dp[i][W];

	}
	else {
		dp[i][W] = knapSackRec(i + 1, W, wt, val, dp);
		return dp[i][W];
	}

}

int knapSacktab(int i, int W, vector<int> wt, vector<int> val, vector<vector<int>> &dp) {
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp.size(); j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= wt.size(); i++) {
		for (int w = 1; w <= W; w++) {
			if (wt[i - 1] <= w) {
				dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
			} else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	return dp[wt.size()][W];


}

int main() {
	cout << "No. of items:" << endl;
	int n; // Number of items
	cin >> n;


	cout << "Max wt" << endl;
	int W; // Maximum weight capacity of the knapsack
	cin >> W;

	vector<int> wt(n, 0);
	vector<int> val(n, 0);

	for (int i = 0; i < n; i++) {
		cout << "Enter val" << endl;
		cin >> val[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> wt[i];
	}


	vector<vector<int>> dp(n + 1, vector<int> (W + 1, -1));

	cout << knapSacktab(0, W, wt, val, dp);
}