#include <iostream>
using namespace std;
#define max 20
class sparse_matrix
{
    const static int MAX = 20;
    int data[MAX][3];
    int len;

public:
    sparse_matrix(int r, int c, int l)
    {
        data[0][0] = r;
        data[0][1] = c;
        data[0][2] = l;
        len = 0;
    }
    void insert(int r, int c, int val);
    void display();
    sparse_matrix transpose();
    void add(sparse_matrix b);
    void multiply(sparse_matrix t);
};
void sparse_matrix ::insert(int r, int c, int val)
{
    if (r > data[0][0] || c > data[0][1])
    {
        cout << "\n\nWrong Entry -_- \n";
    }
    else
    {
        data[len + 1][0] = r;
        data[len + 1][1] = c;
        data[len + 1][2] = val;
        len++;
    }
}
sparse_matrix sparse_matrix ::transpose()
{
    sparse_matrix t(data[0][1], data[0][0], data[0][2]);
    if (len > 0)
    {
        for (int i = 0; i < data[0][1]; i++)
        {
            for (int j = 1; j <= len; j++)
            {
                if (data[j][1] == i)
                {
                    t.len++;
                    t.data[t.len][0] = data[j][1];
                    t.data[t.len][1] = data[j][0];
                    t.data[t.len][2] = data[j][2];
                }
            }
        }
    }
    return t;
}
void sparse_matrix ::display()
{
    cout << "\nDimension : " << data[0][0] << "x" << data[0][1];
    cout << "\nSparse Matrix : \nRow\tColumn\tValue\n";
    for (int i = 0; i <= len; i++)
    {
        cout << data[i][0] << "\t " << data[i][1] << "\t" << data[i][2] << endl;
    }
}
void sparse_matrix ::add(sparse_matrix b)
{
    sparse_matrix result(data[0][0], data[0][1], 0);
    if (data[0][0] != b.data[0][0] || data[0][1] != b.data[0][1])
    {
        cout << "\n\nMatrix cannot be added\n";
    }
    else
    {
        int apos = 1, bpos = 1;
        while (apos <= len && bpos <= b.len)
        {
            if (data[apos][0] > b.data[bpos][0] ||
                data[apos][0] == b.data[bpos][0] &&
                    data[apos][1] > b.data[bpos][1])
            {
                result.insert(b.data[bpos][0],
                              b.data[bpos][1], b.data[bpos][2]);
                bpos++;
            }
            else if (data[apos][0] < b.data[bpos][0] ||
                     data[apos][0] == b.data[bpos][0] &&
                         data[apos][1] < b.data[bpos][1])
            {
                result.insert(b.data[apos][0],
                              b.data[apos][1], b.data[apos][2]);
                apos++;
            }
            else
            {
                int addedl = data[apos][2] +
                             b.data[bpos][2];
                if (addedl != 0)
                {
                    result.insert(data[apos][0],
                                  data[apos][1], addedl);
                    apos++;
                    bpos++;
                }
            }
        }
        while (apos <= len)
        {
            result.insert(data[apos][0], data[apos][1],
                          data[apos][2]);
            apos++;
        }
        while (bpos <= b.len)
        {
            result.insert(b.data[apos][0], b.data[apos][1],
                          b.data[apos][2]);
            bpos++;
        }
        result.data[0][2] = result.len;
        result.display();
    }
}
void sparse_matrix ::multiply(sparse_matrix t)
{
    int sum, tl, t2, t3 = 1;
    sparse_matrix mresult(data[0][0], t.data[0][0], 0);
    for (int i = 0; i < data[0][0]; i++)
    {
        for (int j = 0; j < t.data[0][1]; j++)
        {
            sum = 0;
            tl = 1;
            t2 = 1;
            int flag1 = 0, flag2 = 0;
            while (tl <= data[0][2])
            {
                if (data[tl][0] == i)
                {
                    flag1 = 1;
                    break;
                }
                tl++;
            }
            while (t2 <= t.data[0][2])
            {
                if (t.data[t2][0] == j)
                {
                    flag2 = 1;
                    break;
                }
                t2++;
            }
            if (flag1 == 1 && flag2 == 1)
            {
                while (data[tl][0] == i &&
                       t.data[t2][0] == j)
                {
                    if (data[tl][1] ==
                        t.data[t2][1])
                    {
                        sum = sum + data[tl][2] * t.data[t2][2];
                        tl++;
                        t2++;
                    }
                    else if (data[tl][1] <
                             t.data[t2][1])
                    {
                        tl++;
                    }
                    else
                    {
                        t2++;
                    }
                }
                if (sum > 0)
                {
                    mresult.insert(data[t3][0], t.data[t3][1], sum);
                    t3++;
                }
            }
        }
    }
    mresult.data[0][2] = t3 - 1;
    mresult.display();
}

int main()
{
    int r, c, l, val;
    cout << "\n\t SPARSE Matrix ";

    cout << "\nEnter no of rows for sparse matrix 1 : ";
    cin >> r;
    cout << "\nEnter no of columns for sparse matrix 1 : ";
    cin >> c;
    cout << "\nEnter no of non zero elements for sparse matrix 1 : ";
    cin >> l;
    sparse_matrix a(r, c, l);
    for (int i = 0; i < l; i++)
    {
        cout << "\nEnter row no : ";
        cin >> r;
        cout << "\nEnter column no : ";
        cin >> c;
        cout << "\nEnter your value for the entered location : ";
        cin >> val;
        a.insert(r, c, val);
    }

    cout << "\nSparse Matrix No 1 is : ";
    a.display();

    cout << "***************************";
    cout << "\nEnter no of rows for sparse matrix 2 : ";
    cin >> r;
    cout << "\nEnter no of columns for sparse matrix 2 : ";
    cin >> c;
    cout << "\nEnter no of non zero elements for sparse matrix 2 : ";
    cin >> l;
    sparse_matrix b(r, c, l);
    for (int i = 0; i < l; i++)
    {
        cout << "\nEnter row no : ";
        cin >> r;
        cout << "\nEnter column no : ";
        cin >> c;
        cout << "\nEnter your value for the entered location : ";
        cin >> val;
        b.insert(r, c, val);
    }

    cout << "\nSparse Matrix No 2 is : ";
    b.display();

    cout << "\nTranspose of the matrix1 is : \n";
    a = a.transpose();
    a.display();
    cout << "\nAddition of the matrix is : \n";
    a.add(b);
    return 0;
}