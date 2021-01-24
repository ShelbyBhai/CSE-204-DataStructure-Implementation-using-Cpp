#include<bits/stdc++.h>
using namespace std;
int** MatrixChainOrder(int p[],int k)
{
    cout << "Entered here" << endl;
    int n = k-1;
    int j = 0;
    int m[n+1][n+1];
    int **s = new int*[n];
    for(int i = 0; i < n; i++)
    {
        s[i] = new int[n+1];
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0 ; j <= n; j++)
        {
            m[i][j] = -1;
        }
    }
    for(int i = 0; i <= n-1; i++)
    {
        for(int j = 0 ; j <= n; j++)
        {
            s[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    int q = 0;
    for(int l = 2; l <= n; l++)
    {
        for(int i = 1; i <= n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = 100000000;
            for(int k = i; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]= q;
                    s[i][j] = k;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    return s;
}
int** MatrixChainOrderZero(int p[], int k)
{
    int plength = k;
    int n = plength - 1;
    int j = 0;
    int m[n][n];
    int **s = new int*[n-1];
    for(int i = 0; i < n-1; i++)
    {
        s[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            m[i][j] = -1;
        }
    }
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            s[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }
    int q = 0;
    for(int l = 2; l <= n; l++)
    {
        for(int i = 0; i <= n-l; i++)
        {
            j = i+l-1;
            m[i][j] = 100000000;
            for(int k = i; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(q<m[i][j])
                {
                    m[i][j]= q;
                    s[i][j] = k+1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 1; j < n; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    return s;
}
void PrintOptimalParenthesis(int **s,int i,int j,char A[])
{
    if(i == j)
    {
        cout << A[i-1] << " ";
    }
    else
    {
        cout << "(";
        PrintOptimalParenthesis(s,i,s[i][j],A);
        PrintOptimalParenthesis(s,(s[i][j])+1,j,A);
        cout << ")";
    }
}
int main()
{
    int n;
    cin >> n;
    char Mat[n];
    int row[n],cols[n];
    for(int i = 0; i < n; i++)
    {
        cin >> Mat[i] >> row[i] >> cols[i];
    }
    int p[n+1];
    for(int i = 0; i < n; i++)
    {
        p[i] = row[i];
    }
    p[n] = cols[n-1];
    int k = sizeof(p)/sizeof(p[0]);
    cout << k << endl;
    int **s =  MatrixChainOrder(p,k);
    cout << endl;
    PrintOptimalParenthesis(s,1,n,Mat);
}
