#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
using namespace std;

class matrix2
{
    private:
        int **matrix ;
    public:
	    int n , m ;  
        matrix2();
        ~matrix2();
        int** makeMatrix( int **, int , int);
        void maxCheck(int **, int ,int);
        void ans();
};

int main()
{
    matrix2 mat2;
	return 0 ;
}
matrix2::matrix2(){
    srand(time(0));
    cout<< " enter the matrix size: " ;
	cin>> n >> m ;
    matrix = new int *[n];
    for(int i = 0 ; i < n ; i++)
    {
        matrix[i] = new int [m];
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            matrix[i][j]=(rand()%65)*(pow(-1,rand()%2));
        }
    }
    ans();
}
void matrix2 ::ans(){
	matrix = makeMatrix (matrix , n ,m);
	maxCheck(matrix , n , m );
}
int** matrix2:: makeMatrix(int **mat , int n , int m )
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout << matrix[i][j] << "  " ;
        }
        cout << endl ;
    }
    return mat ;
}

void matrix2 :: maxCheck(int **mat , int n , int m)
{
    int sum = 0, maximum = 0, maxi , maxj , maxlen;
    for(int len = 1 ; len <= min(n,m) ; len++)
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                for(int k = 0 ; k < len ; k++)
                {
                    for(int l = 0 ;l < len ; l++)
                    {
                        if( i+len-1 < n && j+len-1 < m)
                        {
							sum += mat[i+k][j+l];
						}
                    }
                }
                if(sum > maximum)
                {
                    maximum = sum;
                    maxi = i;
                    maxj = j ;
                    maxlen = len ;
                }
                sum = 0 ;
            }
        }
    }

    cout << " maximum is : " << maximum << endl ;
    for(int i = maxi; i < maxi + maxlen ; i++ )
    {
        for(int j = maxj ; j < maxj+maxlen ; j++ )
        {
            cout << mat[i][j]<< "  " ;
        }
    }
matrix2::~matrix2()
{
    delete[] matrix;
    delete[] mat;
}