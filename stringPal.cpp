#include<iostream>
#include<string.h>
#include<bits/stdc++.h> 
using namespace std;
string find_pal(string a){
    string pal;
    int counter=0;
    for(int i=0 ; i<a.length()-1 ;i++){
        //cout<<"i:"<<i<<endl;
        for(int j=i+1 ; j<a.length()-1 ;j++){
          //cout<<"j :"<<j<<endl;
            string first=a.substr(i,j-i);
            string second=a.substr(j+1,j-i);
            reverse(second.begin(),second.end());
            string first2=a.substr(i,j);
            string second2=a.substr(j,(j-i));
            reverse(second2.begin(),second2.end());
            if (first==second){
                if (counter==0){
                    pal=a.substr(i,j+(j-i)+1);
                    counter+=1;
                }
                else if(counter>0){
                    int sec_pal=(a.substr(i,j+(j-i))).length();
                    if(pal.length()<sec_pal){
                        pal=a.substr(i,j+(j-i));
                    }
                }
            }
            else if (first2==second2){
                cout<<"1"<<endl;
                if (counter==0){
                    cout<<"2"<<endl;
                    pal=a.substr(i,2*(j-i));
                    counter+=1;
                }
                else if(counter>0){
                    int sec_pal=(a.substr(i,(j-i)+1)).length();
                    if(pal.length()<sec_pal){
                        pal=a.substr(i,(j-i)+1);
                    }
                }
            } 
        }
    }
    return pal;
}
int main(){
    string a;
    cout<<"Enter your string :";
    getline(cin , a);
    string k = find_pal(a);
    cout<<"The longest palindrome is :"<<k<<endl;
    return 0;
 }
 /////////////////////////////////////////////////////////////

 //instead of using reverse(second.begin(),second.end()) we could also do this :
 //string second2;
 //for (int k =second.length()-1 ; k>0 ; k--){
 //    second2=second2+second[k];
 //}
 //second=second2;

 /////////////////////////////////////////////////////////