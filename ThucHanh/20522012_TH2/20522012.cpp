#include <iostream>

using namespace std;
#define MAX 100
void Nhap(char person[], int bottle[], int cur_bottle[], int& n, int& m, int& k)
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> person[i];

    for (int i = 0; i < m; i++)
    {
        cin >> bottle[i];
        if (bottle[i] == k)
            cur_bottle[i] = -1;
        else
            cur_bottle[i] = k;
    }         
}

int FindMinIdx(int a[], int m) 
{
    int min, pos;
    for (int i = 0; i < m; i++)
        if (a[i] != -1)
        {
            min = a[i];
            pos = i;
            break;
        }

    for (int i = 1; i < m; i++)
    {
        if (a[i] == -1)
            continue;
        else
            if (min >= a[i])
            {
                min = a[i];
                pos = i;
            }
    }
    return pos;
}

int FindMaxIdx_(int a[], int b[], int m) 
{
    int max, min, pos;
    for (int i = 0; i < m; i++)
        if (a[i] != -1)
        {
            max = a[i];
            min = b[i];
            pos = i;
            break;
        }
    for (int i = 1; i < m; i++)
    {
        if (a[i] == -1)
            continue;
        else
            if (max <= a[i])
                if (max == a[i])
                {
                    if (min >= b[i])
                    {
                        max = a[i];
                        min = b[i];
                        pos = i;
                    }
                }
                else
                {
                    max = a[i];
                    min = b[i];
                    pos = i;
                }
    }
    return pos;
}

void Xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Process(char person[], int bottle[], int cur_bottle[], int res[], int& n, int& m, int& k)
{
    for (int i = 0; i < n; i++)
    {
        if (person[i] == 'E')
        {
            int pos = FindMinIdx(bottle, m);
            res[i] = pos + 1;
            cur_bottle[pos] -= 1;
            if (cur_bottle[pos] == 0)
            {
                cur_bottle[pos] = -1;
                bottle[pos] = -1;
            }
        }
        else
        {
            int pos = FindMaxIdx_(cur_bottle, bottle, m);
            res[i] = pos + 1;
            cur_bottle[pos] -= 1;
            if (cur_bottle[pos] == 0)
            {
                cur_bottle[pos] = -1;
                bottle[pos] = -1;
            }
        }
        
    }
}
int main()
{
    int n, m, k;
    char person[MAX];
    int bottle[MAX];
    int cur_bottle[MAX];
    int res[MAX];

    Nhap(person, bottle, cur_bottle, n, m, k);
    Process(person, bottle, cur_bottle, res, n, m, k);
    Xuat(res, n);
}

