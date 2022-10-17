/*Name:Shashank Patil
  Roll number:27
  PRN NO :202101040077
  Div:A
  Batch:A2

Aim- Design and implement a program for sparse matrix operations of addition, multiplication and
 transpose of the sparse matrix for climate prediction data stored in a 2D array.
*/
#include <iostream>
using namespace std;
#define max 40
class Sparse_matrix
{
    const static int MAX = 40;
    int data[MAX][3];
    int len;

public:
    Sparse_matrix(int r, int c, int l)
    {
        data[0][0] = r;
        data[0][1] = c;
        data[0][2] = l;
        len = 0;
    }
    void insert(int r, int c, int val);
    void display();
    Sparse_matrix transpose();
    void add(Sparse_matrix b);
    void multiply(Sparse_matrix t);
};
void Sparse_matrix ::insert(int r, int c, int val)
{
    if (r > data[0][0] || c > data[0][1])
    {
        cout << "\n\nWrong Entry \n";
    }
    else
    {
        data[len + 1][0] = r;
        data[len + 1][1] = c;
        data[len + 1][2] = val;
        len++;
    }
}
Sparse_matrix Sparse_matrix  ::transpose()
{
    Sparse_matrix t(data[0][1], data[0][0], data[0][2]);
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
void Sparse_matrix ::display()
{
    cout << "\nDimension : " << data[0][0] << "x" << data[0][1];
    cout << "\nSparse Matrix : \nRow\tColumn\tValue\n";
    for (int i = 0; i <= len; i++)
    {
        cout << data[i][0] << "\t " << data[i][1] << "\t" << data[i][2] << endl;
    }
}
void Sparse_matrix ::add(Sparse_matrix b)
{
    Sparse_matrix result(data[0][0], data[0][1], 0);
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
                int addedvalue = data[apos][2] +
                             b.data[bpos][2];
                if (addedvalue != 0)
                {
                    result.insert(data[apos][0],
                                  data[apos][1], addedvalue);
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
void Sparse_matrix ::multiply(Sparse_matrix t)
{
    int sum, tl, t2, t3 = 1;
    Sparse_matrix resultm(data[0][0], t.data[0][0], 0);
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
                    resultm.insert(data[t3][0], t.data[t3][1], sum);
                    t3++;
                }
            }
        }
    }
    resultm.data[0][2] = t3 - 1;
    resultm.display();
}

int main()
{
    int r, c, l, val;
    cout << "\n\t SPARSE MATRIX ";

    cout << "\nEnter number of rows for sparse matrix 1 : ";
    cin >> r;
    cout << "\nEnter number of columns for sparse matrix 1 : ";
    cin >> c;
    cout << "\nEnter number of non zero elements for sparse matrix 1 : ";
    cin >> l;
    Sparse_matrix a(r, c, l);
    for (int i = 0; i < l; i++)
    {
        cout << "\nEnter row no : ";
        cin >> r;
        cout << "\nEnter column no : ";
        cin >> c;
        cout << "\nEnter the value : ";
        cin >> val;
        a.insert(r, c, val);
    }

    cout << "\nSparse Matrix No 1 is : ";
    a.display();

    cout << "\nEnter number of rows for sparse matrix 2 : ";
    cin >> r;
    cout << "\nEnter number of columns for sparse matrix 2 : ";
    cin >> c;
    cout << "\nEnter number of non zero elements for sparse matrix 2 : ";
    cin >> l;
    Sparse_matrix b(r, c, l);
    for (int i = 0; i < l; i++)
    {
        cout << "\nEnter row no : ";
        cin >> r;
        cout << "\nEnter column no : ";
        cin >> c;
        cout << "\nEnter the value : ";
        cin >> val;
        b.insert(r, c, val);
    }

    cout << "\nSparse Matrix Number 2 is : ";
    b.display();

    cout << "\nTranspose of the given matrix is : \n";
    a = a.transpose();
    a.display();
    cout << "\nAddition of the given matrix is : \n";
    a.add(b);
    cout << "\nMultiplication of the given matrix is : \n";
    a.multiply(b);

    return 0;
}
/*    
         SPARSE MATRIX
Enter number of rows for sparse matrix 1 : 4

Enter number of columns for sparse matrix 1 : 4

Enter number of non zero elements for sparse matrix 1 : 4

Enter row no : 1

Enter column no : 2

Enter the value : 10

Enter row no : 1

Enter column no : 3

Enter the value : 12

Enter row no : 2

Enter column no : 3

Enter the value : 14

Enter row no : 1

Enter column no : 1

Enter the value : 15

Sparse Matrix No 1 is :
Dimension : 4x4
Sparse Matrix :
Row     Column  Value
4        4      4
1        2      10
1        3      12
2        3      14
1        1      15

Enter number of rows for sparse matrix 2 : 4

Enter number of columns for sparse matrix 2 : 4

Enter number of non zero elements for sparse matrix 2 : 4

Enter row no : 1

Enter column no : 3

Enter the value : 8

Enter row no : 2

Enter column no : 3

Enter the value : 13

Enter row no : 3

Enter column no : 1

Enter the value : 12

Enter row no : 2

Enter column no : 1

Enter the value : 16

Sparse Matrix Number 2 is :
Dimension : 4x4
Sparse Matrix :
Row     Column  Value
4        4      4
1        3      8
2        3      13
3        1      12
2        1      16

Transpose of the given matrix is :

Dimension : 4x4
Sparse Matrix :
Row     Column  Value
4        4      4
1        1      15
2        1      10
3        1      12
3        2      14

Addition of the given matrix is :

Dimension : 4x4
Sparse Matrix :
Row     Column  Value
4        4      7
1        3      8
1        3      8
2        3      13
2        3      13
3        1      24
2        1      16
3        2      14

Multiplication of the given matrix is :

Dimension : 4x4
Sparse Matrix :
Row     Column  Value
4        4      3
1        3      180
2        3      120
3        1      144

c:\Shashank\Code\C Language\Basics\Cpp>
*/
