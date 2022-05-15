#include <iostream>

using namespace std;

const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;

int a[maxn], dp[maxn][maxn], s[maxn][maxn];

void solve(int l, int r)
{
    if (s[l][r])
    {
        cout << "(A" << s[l][r] << " * ";
        solve(l, s[l][r]);
        solve(s[l][r] + 1, r);
        cout << ")";
    }
}

int main()
{
    int N;

    cout << "Number of matrices: ";
    cin >> N;

    if (1 >= N || N > 256)
    {
        std::cout << "Incorrect value: " << N << "\n";
        system("pause");
        return 0;
    }

    cout << "Dimensional matrices: ";
    for (int i = 1; i <= N; ++i)
        cin >> a[i];

    for (int l = 2; l < N; ++l)
    {
        for (int i = 1; i + l <= N; ++i)
        {
            int j = i + l - 1;
            dp[i][j] = dp[i + 1][j] + a[i] * a[i + 1] * a[j + 1];
            s[i][j] = i;
            for (int k = i + 1; k < j; ++k)
            {
                int x = dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
                if (dp[i][j] > x)
                {
                    dp[i][j] = x;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "The smallest number multiplications to calculate the product of matrices:\n"
         << dp[1][N - 1] << "\n";

    cout << "Optimal arrangement of brackets in the expression:\n";
    solve(1, N - 1);
    cout << "\n";

    system("pause");

    return 0;
}
