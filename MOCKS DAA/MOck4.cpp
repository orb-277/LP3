#include <iostream>

using namespace std;

const int N = 4;
int position[N];

// Check if a position is safe
bool isSafe(int queen_number, int col_position)
{
	// Check each queen before this one
	for (int i = 0; i < queen_number; i++)
	{
		// Get another queen's row_position
		int other_col_pos = position[i];

		// Now check if they're in the same row or diagonals
		if (other_col_pos == col_position || // Same row
			other_col_pos == col_position - (queen_number - i) || // Same diagonal
			other_col_pos == col_position + (queen_number - i))   // Same diagonal
			return false;
	}
	return true;
}

// Recursively generate a tuple like [0 0 0 0], then [0 0 0 1] then etc...
void solve(int k)
{
	if (k == N) // We placed N-1 queens (0 included), problem solved!
	{
		// Solution found!
		cout << "Solution: " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << position[i] << ' ';
        }
        cout << endl;
        
		for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
            {
                if(j != position[i])
                    cout << "X ";
                else
                    cout << "Q ";
            }
            cout << endl;
        }    
			
		cout << endl;
	}
	else
	{
		for (int i = 0; i < N; i++) // Generate ALL combinations
		{
			// Before putting a queen (the k-th queen) into a row, test it for safeness
			if (isSafe(k, i))
			{
				position[k] = i;
				
				solve(k + 1);
			}
		}
	}
}

int main()
{
	solve(0);

	return 0;
}