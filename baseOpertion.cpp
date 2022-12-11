#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
string find_base(int a,int n){
    vector<char> base={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','N','O','P','Q','R','S',
                        'T','U','V','W','X','Y','Z'};
    vector<int> integer={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
    string answer;
    vector<char>::const_iterator begin = base.begin();
	vector<char>::const_iterator last = base.begin() + n;
	vector<char> new_base(begin, last);
    vector<int>::const_iterator begin = integer.begin();
	vector<int>::const_iterator last = integer.begin() + n;
	vector<int> new_int(begin, last);
    int quotient=1;
    int remainder;
    while (quotient!=0){
        quotient=a/n;
        remainder=a-(quotient*n);
        a=quotient;
        for (int i=0; i<n ; i++){
            if (new_int[i]==remainder){
                answer = new_base[i] + answer;
            }
        }
    }
    return answer;
}
string get_string(char x){
    string s(1,x);
    return s;
}
int find_dec(string a , int n , vector<string> hex , vector<int> dec){
    int answer;
    int e=1;
    int len= a.length();
    for (int i=0 ; i<len ; i++){
        for(int j=0 ; j<n ; j++){
            if (get_string(a[i])==hex[j]){
                for(int k=0 ; k<len-i-1 ; k++){e*=n;}
                answer+=(dec[j] * e );
                e=1;
            }
        }
    }
    return answer;
}
string sum(string a , string b , vector<string> hex , vector<int> dec){
    string answer;
    int counter=0;
    int counter2=0;
    int len;
    int len_a = a.length() -1;
    int len_b = b.length() -1;
    if (len_a>len_b){
        len=len_a;
        for(int i=0 ; i<(len_a - len_b) ; i++){
            b ="0" + b;
        }
    }
    else if (len_b>len_a){
        len=len_b;
        for(int i=0 ; i<(len_b - len_a) ; i++){
            a ="0" + a;
        }
    }
    else if (len_a == len_b){
        len=len_a;
    }
    while (len > -1){
        string stack_a=get_string(a[len]);
        string stack_b=get_string(b[len]);
        for (int j =0 ; j < 16 ; j++){
            if ( hex[j] == stack_a || hex[j]==stack_b){
                counter+=dec[j];
                counter2+=1;
                if (counter2==2){
                    counter2=0;
                    if (counter<16){
                        for(int k=0 ; k<16 ; k++){
                            if (dec[k]==counter){
                                answer=hex[k]+answer;
                                counter=0;
                                len-=1;
                            }
                        }
                    }
                    else if (counter>=16){
                        int m=counter - ((counter/16)*16);
                        for (int k=0 ; k<16 ; k++){
                            if (dec[k]==m){
                                answer=hex[k]+answer;
                                counter=1;
                                len-=1;
                            }
                        }
                    }
                }
            } 
        }
    } 
    if (counter!=0){
        for (int k=0 ; k<16 ; k++){
            if (dec[k]==counter){
                answer=hex[k]+answer;}}}
    return answer;
}
string substraction(string a , string b , vector<string> hex , vector<int> dec){
    string answer;
    int len;
    int len_a = a.length() -1;
    int len_b = b.length() -1;
    int counter_a;
    int counter_b;
    if (len_a>len_b){
        len=len_a;
        for(int i=0 ; i<(len_a - len_b) ; i++){
            b ="0" + b;
        }
    }
    else if (len_b>len_a){
        len=len_b;
        for(int i=0 ; i<(len_b - len_a) ; i++){
            a ="0" + a;
        }
    }
    else if (len_a == len_b){
        len=len_a;
    }
    while(len>-1){
        string stack_a=get_string(a[len]);
        string stack_b=get_string(b[len]);
        for(int i=0 ; i<16 ; i++){
            if (hex[i]==stack_a){
                counter_a+= dec[i];
            }
            if(hex[i]==stack_b){
                counter_b+=dec[i];  
            }
        }
        if (counter_a>=counter_b){

            counter_a-=counter_b;
            for( int j=0 ; j<16 ; j++){
                if (dec[j]==counter_a){
                    answer=hex[j]+answer;
                    counter_a=0;
                    counter_b=0;
                    len-=1;
                }
            }
        }
        else if(counter_a<counter_b){
            counter_a+=16;
            counter_a-=counter_b;
            for(int k=0 ; k<16 ; k++){
                if (dec[k]==counter_a){
                    answer=hex[k]+answer;
                    counter_a=-1;
                    counter_b=0;
                    len-=1;
                }
            }
        }

    }
    return answer;

}
string multiplication(string a , string b , vector<string> hex , vector<int> dec){
    string answer;
    int len;
    int stk;
    string main_stack;
    string help_stack;
    int counter_a;
    int counter_b;
    int carry;
    int remain;
    int cnt;
    int len_a = a.length() -1;
    int len_b = b.length() -1;
    for(int i=len_b ; i>-1 ; i-=1){//harkat roo adad paini
        for (int j=len_a ; j >-1; j--){//harkar roo adad balai
        string stack_a=get_string(a[j]);
        string stack_b=get_string(b[i]);
        for(int i=0 ; i<16 ; i++){
            if (hex[i]==stack_a){
                counter_a= dec[i];
            }
            if(hex[i]==stack_b){
                counter_b=dec[i];  
            }
        }
        stk=counter_a*counter_b+carry;
        if (stk<16){
            for (int k=0 ; k<16 ; k++){
                if (dec[k]==stk){
                    main_stack=hex[k]+main_stack;
                    carry=0;
                }
            }
        }
        else if (stk>=16){
            remain=stk -(16*(stk/16));
            carry=stk/16;
            for (int k=0 ; k<16 ; k++){
                if (dec[k]==remain){
                    main_stack=hex[k]+main_stack;
                }
            }

        }
        }
    if(carry!=0){
    for(int i =0 ; i<16 ; i++){
        if (dec[i]==carry){
            main_stack=hex[i]+main_stack;
            carry=0;
        }
    }
    }
        cnt+=1;
        if(cnt>1){
            main_stack=main_stack+"0";
            help_stack=sum(help_stack,main_stack,hex,dec);
            cnt=1;
            main_stack="";
        }
        else if (cnt <= 1){
            help_stack=main_stack;
            main_stack="";
        }

    }
 return help_stack;


}
string division(string a , string b,int base , vector<string> hex , vector<int> dec){
    string answer;
    string i="0";
    cout<<"dec a:"<<find_dec(a , base,hex,dec)<<endl;
    cout<<"dec b :"<<find_dec(b , base,hex,dec)<<endl;
    while(find_dec(a,base,hex,dec)>=find_dec(b,base,hex,dec)){
        a=substraction(a , b , hex , dec);
        i=sum(i,"1",hex,dec);
    }
    return i;

}
int main(){
    int a;
    int b ;
    int base;
    int c;
    string a2;
    string b2;
    cout<<"Enter a :";
    cin>>a;
    cout<<"Enter b :";
    cin>>b;
    cout<<"Enter their base :";
    cin>>base;
    cout<<"if you want to find sum press '1' , if you want to find substraction press '2' , if you want to find multiplication press '3' , if you want to find devision press '4' "<<endl;
    cin>>c;
    a2=find_base(a,base);
    b2=find_base(b,base);
    vector<string> base2={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J","K","L","N","O","P","Q","R","S",
                        "T","U","V","W","X","Y","Z"};
    vector<int> integer={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
    string answer;
    vector<string>::const_iterator begin = base2.begin();
	vector<string>::const_iterator last = base2.begin() + base;
	vector<string> hex(begin, last);
    vector<int>::const_iterator begin = integer.begin();
	vector<int>::const_iterator last = integer.begin() + base;
	vector<int> dec(begin, last);
    if(c==1){
        string answer=sum(a2 , b2 , hex , dec);
        cout<<answer<<endl;
    }
    else if (c==2){
        string answer=substraction(a2 , b2 , hex , dec);
        cout<<answer<<endl;
    }
    else if (c==3){
        string answer=multiplication(a2 , b2 , hex , dec);
        cout<<answer<<endl;
    }
    else if (c==4){
        string answer=division(a2 , b2 , base , hex , dec);
        cout<<answer<<endl;
    }
    return 0;
}