#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &cols, vector<bool> &nd, vector<bool> &rd, int row) {
	if (row == cols.size()) {
		for (int i = 0; i < cols.size(); ++i)
		{
			cout << cols[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < cols.size(); ++i)
	{
		if (cols[i] == -1 && !nd[i + row] && !rd[row - i + cols.size() - 1]) {
			cols[i] = row;
			nd[i + row] = true;
			rd[row - i + cols.size() - 1] = true;
			solve(cols, nd, rd, row + 1);
			cols[i] = -1;
			nd[i + row] = false;
			rd[row - i + cols.size() - 1] = false;
		}

	}
}

int main() {

	cout << "Enter board size" << endl;
	int n;
	cin >> n;
	vector<int> cols(n, -1);
	vector<bool> nd(2 * n - 1, false);
	vector<bool> rd(2 * n - 1, false);

	solve(cols, nd, rd, 0);

	return 0;
}