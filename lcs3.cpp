#include <iostream>
#include <cstdlib>
#include<string.h> 
using namespace std;
class LCS
{
        private:
        int n,m ,k;//toole a va b va G
        char* A ;//array A
        char* B ;//arry B
        char* G;
        char* D;//zir majmooe B
        char* S;//javabe nahai
        int* C;//counter(shomarande binary)
    public:
        LCS();
        ~LCS();
        int find_lcs() ;
        void print_lcs(int) ;
} ;
LCS :: LCS()
{
    cout << "enter the length of the first sequence : ";
    cin >> n;
    cout << "enter the length of the second sequence : ";
    cin >> m;
    cout << "enter the length of the third sequence :";
    cin >> k;
    A = new char [n+1];
    B = new char [m+1];
    G = new char [k+1];
    D = new char [m+1];
    S = new char [m+1];
    C = new int [m+1];
    for (int i=0 ; i<=m ; i++){
        D[i] = 0;
        C[i] = 0;
    }
    cout << "enter the first sequence :";
    cin >> A;
    cout << "enter the second sequence :";
    cin >> B;
    cout <<"enter the third sequence :";
    cin >> G;
    cout << A << endl;
    cout << B << endl;
    cout << G << endl;
}
int LCS :: find_lcs()
{
    int i,j,num,f; //i harpat A , j harkat D , num andaze D , f harkat roo G
    int p = m-1 ; int max =0 ;
    while( p>=0 ){
        num=0;
        for(int i=0 ; B[i] != 0 ; i++)
            if(C[i] == 1){
                D[num] = B[i];
                num ++;
            }
        D[num] =0;
        i=0 ; j=0;f=0;
        if(num > max){
            while((D[j] != 0) && (A[i]!= 0) && (G[f] !=0) ){
                if(A[i] == D[j] && G[f] == D[j]){
                    j++;
                    if( j==num){
                        strcpy(S,D);
                        max = num ;
                        break;
                    }
                }
                if (A[i] != D[j]) { i++;}
                if (G[f] != D[j]) {f++;}
            }
        }
        C[m-1] =C[m-1]+1;//dorost kardane shomarande jadid
        p=m-1;
        while((p>=0) && (C[p]==2)){
            C[p]=0 ; p--;
            if(p>=0) C[p] = C[p]+1;
        }
    }
    return max ;
}
void LCS :: print_lcs(int m){
    for (int i=0 ; i<=m ; i++)
        cout << S[i] ;
    cout << endl ;
}
int main (void){
    LCS lcc;
    int lt = lcc.find_lcs() ;
    cout <<"the length of LCS :" << lt << endl ;
    cout <<"the LCS :" ;
    lcc.print_lcs(lt);
    return 0;
}
LCS :: ~LCS(){
    delete[] A;
    delete[] B;
    delete[] G;
    delete[] D;
    delete[] S;
    delete[] C;
}