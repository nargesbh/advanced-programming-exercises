#include <iostream>
#include<cmath>
using namespace std;
string binary_maker(int n){
    string answer;
    // array to store binary number 
    int binaryNum[32]; 
    // counter for binary array 
    int i = 0; 
    while (n > 0) {  
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for (int j = i - 1; j >= 0; j--) {
        if(binaryNum[j] == 0){ answer+= "0";}
        else if (binaryNum[j] == 1){ answer += "1";}
    }
    return answer;
}
void unrank(int n){
    string n_binary = binary_maker(n);
    cout<<n_binary<<endl;
    int length = n_binary.length();
    int counter =1 ;
    for(int i = length-1 ; i>-1 ; i--){
        if (n_binary[i] != *"0"){
            cout<<counter << " ";
            counter++;
        }
        else if(n_binary[i] == *"0" ){counter++;}
    }
}
void ranking(int n){
    int binary_array[n];
    int a[n];
    int count=0;
    int answer=0;
    int help_dec=n-1;
    cout<<"Enter the subset divided by space , enter -1 when you're done ."<<endl;
    for (int i=0 ; i<n ; i++){
        int k;
        cin>>k;
        if(k==-1){break;}
        a[i]=k;
        count++;
    }
    for (int i=0 ; i<= n ; i++){
        binary_array[i]=0;
    }
    for (int k=0 ; k<=count ; k++){
        binary_array[n-a[k]]=1;
    }
    for(int i=0 ; i<=n ; i++){
        answer+=pow(2,help_dec) * binary_array[i];
        help_dec--;
    }
    cout<<answer;
}
int main(){
    int n;
    cout << "Enter n:";
    cin >> n;
    int job;
    cout << "if you want to rank enter 1 and if you want to unrank enter 2 :";
    cin >>job;
    if(job==1){ranking(n);}
    else if(job==2){unrank(n);}
    return 0;
}