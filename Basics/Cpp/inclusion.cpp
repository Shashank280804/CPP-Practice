#include <iostream>
using namespace std;

int intersection(int a[], int b[], int c[], int n1, int n2, int n3)
{
    int i, j, k, m = 0, s[100];
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                for (k = 0; k < n3; k++)
                {
                    if (c[k] == b[j])
                    {
                        s[m] = c[k];
                        m++;
                        break;
                    }
                }
            }
        }
    }
    cout << "\nRoll no. of the students who know all three languages:\n";
    for (i = 0; i < m; i++)
    {
        cout << "\t" << s[i] << "\t";
    }
    cout << "\nTotal students: " << m;
    return m;
}
int intersection2(int a[], int b[], int n1, int n2)
{
    int i, j, k, m = 0, s[100];
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                s[m] = b[j];
                m++;
                break;
            }
        }
    }
    cout << "\nRoll no.:\n";
    for (i = 0; i < m; i++)
    {
        cout << "\t" << s[i] << "\t";
    }
    cout << "\nTotal: " << m;
    return m;
}
int main()
{
    int n1, n2, n3, g[15], f[15], j[15], i, m, k, x, y, z, u;
    cout << "\nINCLUSION & EXCLUSION PRINCIPLE\n";
    cout << "\n**************************************\n";
    cout << "Enter no. of students who play cricket:\n";
    cin >> n1;
    cout << "Enter Roll no.:\n";
    for (i = 0; i < n1; i++)
    {
        cin >> g[i];
    }
    cout << "Enter no. of students who play basketball:\n";
    cin >> n2;
    cout << "Enter Roll no.:\n";
    for (i = 0; i < n2; i++)
    {
        cin >> f[i];
    }
    cout << "Enter no. of students who play football:\n";
    cin >> n3;
    cout << "Enter Roll no.:\n";
    for (i = 0; i < n3; i++)
    {
        cin >> j[i];
    }
    k = intersection(g, f, j, n1, n2, n3);
    cout << "\nStudents who knows German & French are:\n";
    y = intersection2(g, f, n1, n2);
    cout << "\nStudents who knows German & Japanese are:\n";
    z = intersection2(g, j, n1, n3);
    cout << "\nStudents who knows French & Japanese are:\n";
    x = intersection2(f, j, n2, n3);
    u = n1 + n2 + n3 + k - x - y - z;
    cout << "\nThe total students are: " << u;
}
