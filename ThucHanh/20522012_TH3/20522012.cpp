#include <iostream> 
#define MAX 100
using namespace std;
void Nhap(int& n, int a[], int b[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
}
void Xuat(int n, int a[][MAX])
{
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int fn(int n, int a[], int b[])
{
    int dp[MAX][MAX];
    for (int i = 0; i < n + 2; i++)
        for (int j = 0; j < n + 2; j++)
            dp[i][j] = 1e5;
    
    dp[1][1] = 0;
    for (int i = 2; i <= n + 1; i++)
        for (int j = (i + 1) / 2; j >= 1; j--)
            dp[i][j] = min(dp[i - 1][j - 1] + a[i-2], dp[i - 1][j] + b[i-2]);
    Xuat(n, dp);
    return dp[n + 1][n / 2 + 1];
}
int main()
{ 
    int n;
    int chinh[MAX], phu[MAX];
    Nhap(n, chinh, phu);
    int res = fn(n, chinh, phu);
    cout << res;
    return 0;
}