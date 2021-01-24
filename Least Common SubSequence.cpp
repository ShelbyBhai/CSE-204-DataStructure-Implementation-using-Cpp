#include<bits/stdc++.h>
using namespace std;
char **LcsLength(string X,string Y)
{
    int m = X.length();
    int n = Y.length();
    int c[m+1][n+1];
    char **b = new char*[m+1];
    for(int i = 0; i < m+1; i++)
    {
        b[i] = new char[n+1];
    }
    for(int i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for(int i = 0; i <=n; i++)
    {
        c[0][i] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            if(X[i-1] == Y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D';
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'T';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';
            }
        }
    }
    return b;
}
void PrintLCS(char **b, string X, int i, int j)
{
    if(i == 0 || j == 0)
    {
        return;
    }
    if(b[i][j] == 'D')
    {
        PrintLCS(b,X,i-1,j-1);
        cout << X[i-1];
    }
    else if(b[i][j] == 'T')
    {
        PrintLCS(b,X,i-1,j);
    }
    else
    {
        PrintLCS(b,X,i,j-1);
    }
}
int main()
{
    string x,y;
    cin >> x >> y;
    int m = x.length();
    int n = y.length();
    char **b = new char*[m+1];
    for(int i = 0; i < m+1; i++)
    {
        b[i] = new char[n+1];
    }
    b = LcsLength(x,y);
    PrintLCS(b,x,m,n);
}
