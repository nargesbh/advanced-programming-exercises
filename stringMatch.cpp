#include<iostream>
using namespace std;
bool check(string a , string b){
    int la=a.length();
    int lb=b.length();
    int check=false;
    for(int i=0 ; i< la - lb +1; i++){
        if (a.substr(i , lb)==b){check=true;}
    }
    return check;
}


int main(){
    string a;
    string b;
    cout<<"enter a:";
    getline(cin ,a) ;
    cout<<"enter b:";
    getline(cin , b);
    string help=b;
    int i=0;
    bool check2=check(a,b);
    for(int j=0 ; j<a.length() ; j++ ){
        check2=check(a , b);
        if (check2==true){i++ ; b=b+help;}
        else if (check2==false){break;}
    }
    if(i==0){cout<<"couldn't find 'b' in 'a' "<<endl; }
    else if (i!=0){cout<<"i :"<<i<<endl;}
    return 0 ;
}