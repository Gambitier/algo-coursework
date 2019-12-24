#include <iostream>
#include <vector>
using namespace std;

long long int assign(int n, vector<vector<int>> preference)
{
    int mx = 1 << n;
    int i, j;
    int s;
    vector<long long int> dp(mx, 0);
    dp[mx - 1] = 1;
    for (int mask = mx - 1; mask >= 0; mask--)
    {
        j = mask;
        s = 0;
        while (j)
        {
            s += (j & 1);
            j /= 2;
        }
        for (i = 0; i < n; i++)
        {
            if (preference[s][i] && !(mask & (1 << i)))
            {
                dp[mask] += dp[mask | (1 << i)];
            }
        }
    }
    return dp[0];
}

int main()
{
    int i, n, j;
    cout << "How many students are there ? " << endl;
    cin >> n;
    vector<vector<int>> preference(n + 1, vector<int>(n, 0));
    cout << endl
         << "Enter the preferences of each of "<< n 
         << " students for " << n << " subjects" << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> preference[i][j];
        }
    }

    cout << endl
         << "Total number of assignments that can be prepared are " << endl;

    cout << assign(n, preference) << endl;
    return 0;
}