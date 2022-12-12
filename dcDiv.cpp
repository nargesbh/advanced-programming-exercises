#include <iostream>
#include <bits/stdc++.h> 
#include <math.h>
#include <string>
using namespace std;
string division(int *a ,int b ,int m_counter)
{   
    int stack = 0;
    int ten_pow = 0;
    string ans;
    int check_finish = m_counter;
    while(check_finish > 0){
        while(ten_pow < m_counter ){
            int m = ten_pow;
            for(int i=0 ; i<=ten_pow ; i++){
                stack += a[i] * pow( 10 , m);
                m--;
            }
            if(stack >= b){
                int new1 = stack - ( (stack / b) * b );
                int findNumDigits = (to_string(new1)) . length();
                for(int j=0 ; j < (ten_pow + 1) - findNumDigits ; j++ ){
                    a[j] = 0;
                }
                int n = findNumDigits -1;
                for(int k = (ten_pow + 1) - findNumDigits ; k < ten_pow+1 ; k++){
                    a[k] = new1 / (pow (10 , n));
                    new1 = new1 - (a[k] * (pow (10 , n)));
                    n--;
                }
                break;
            }
            stack =0;
            ten_pow++;
        }
        ans = ans + to_string(stack / b) ;
        stack = 0;
        check_finish -= (ten_pow+1) ;     

    }
    return ans;

}
int main(){
    int* m;
    int* n;
    int m_counter;
    int n_counter;
    cout << "how many digits does m have ?";
    cin >> m_counter;
    m = new int[m_counter];
    cout <<"enter m's digits devided by enter :"<<endl;
    for(int i=0 ; i<m_counter ; i++){
        cin >> m[i];
    }
    cout << "how many digits does n have ?";
    cin >> n_counter;
    n = new int[n_counter];
    cout <<"enter n's digits devided by enter :"<<endl;
    for(int i=0 ; i<n_counter ; i++){
        cin >> n[i];
    }
    int n_int = 0;
    for(int i=0 ; i<n_counter ; i++){
        n_int= n_int + (n[i] * ( pow(10,n_counter - i - 1)));
    }
    cout <<"the answer is :" <<division(m ,n_int , m_counter)<<endl;
    return 0;
}