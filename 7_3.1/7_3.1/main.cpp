#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

bool IsNegativeElement(int** a, int n, int i);
int Sum(int** a, int n, int i);

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            a[i][j] = Low + rand() % (High-Low+1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
void Element(int** a, int n)
{
    bool flag = true;
    for (int k = 0; k < n; k++)
    {
        flag = true;
        for (int i = 0; i < n; i++)
            if (a[k][i] != a[i][k])
            {
                flag = false;
                break;
            }
        if (flag)
            cout << k;
    }
}

void PrintSecondTask(int** a, int n)
{
  for (int i=0; i<n; i++)
  {
      bool isNegativeElement  = IsNegativeElement(a, n, i);
    if (isNegativeElement)
    {
        cout << "2. Row " << i + 1 << "; Sum: " << Sum(a, n, i) << endl;
        
    }
      
  }
}

bool IsNegativeElement(int** a, int n, int i)
{
    for (int j=0; j<n; j++)
    {
        if ( a[i][j] < 0 )
        {
            return true;
            
        }
        
    }
    return false;
}

int Sum(int** a, int n, int i)
{
    int S=0;
  //  for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                S += a[i][j];
            }
    return S;
}

int main() {
    srand((unsigned)time(NULL));
    int Low = -10;
    int High = 10;
    int n, i;
    cout << "n = "; cin >> n;
    int **a = new int*[n];
    for (int i=0; i<n; i++)
        a[i] = new int[n];
    Create(a, n, Low, High);
    Print(a, n);
    Element(a, n);
    cout << "1. k = " << i + 1 << endl;
    //cout << "1. element = " << Element(a, n) << endl;
    PrintSecondTask(a, n);
    cout << "2. Row " << i + 1 << "; Sum: " << Sum(a, n, i) << endl;
//    cout << "2. sum = " << Sum(a, n, i) << endl;
    for (int i=0; i<n; i++)
        delete [] a[i];
    delete [] a;
    return 0;
    
}


