#include <iostream>
#include <limits>
using namespace std;
class dp
{
    private:
        int s , n;
        float* coinNumber;
        int* answer;
        int* coinsArray;
    public :
        dp(int n1);
        ~dp();
        void leastNumCoin();
        void coins();
};
int main()
{
    int n;
    cout << "Enter the number of coins' values :";
    cin >> n;
    dp dpValue(n);
    dpValue.leastNumCoin();
    dpValue.coins();
    return 0;
}
dp :: dp(int n1)
{
    n=n1;
    cout << "Enter s :";
    cin>>s;
    // cout << "Enter the number of coins' values :";
    // cin >> n;
    cout << "s+1 :" << s+1 <<endl;
    coinsArray = new int [n];
    coinNumber = new float [s+1];
    answer = new int [s+1];
    for(int i=0 ; i<n ; i++){
        cout <<"enter the value of the coin number "<<i+1<<" : ";
        cin>>coinsArray[i];
    }
    for(int i=0 ; i<=s ; i++){
        answer[i] = -1; 
    }
    coinNumber[0] = 0;
    for(int i=1 ; i<=s ; i++){
        coinNumber[i] = numeric_limits<float>::infinity();
    }
}

void dp ::leastNumCoin()
{
    for(int j=0 ; j<n ; j++){//coins array
        for(int i=1 ; i<=s ; i++){//coins number
            if(coinsArray[j] <= i){
                if(coinNumber[i] > min(coinNumber[i] , coinNumber[i - coinsArray[j]] + 1)){
                    answer[i] = j;
                }
                coinNumber[i] = min(coinNumber[i] , (coinNumber[i - coinsArray[j]]) + 1 );
            }
        }
    }
    cout << "least number of coins you need is : "<< coinNumber[n] << endl;

}

void dp :: coins()
{
    int check = s;
    cout << "the coins you need are :";
    while(s > 0){
        cout << coinsArray[answer[s]]<<" ";
        s = s - coinsArray[answer[s]] ;
    }
}
dp :: ~dp()
{
    delete[] coinsArray;
    delete[] coinNumber;
    delete[] answer;
}
