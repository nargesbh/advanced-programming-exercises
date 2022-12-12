#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

void makeCombiUtil(vector<vector<int> >& ans, 
	vector<int>& tmp, int n, int left, int k) 
{ 
	if (k == 0) { 
		ans.push_back(tmp); 
		return; 
	}  
	for (int i = left; i <= n; ++i) 
	{ 
		tmp.push_back(i); 
		makeCombiUtil(ans, tmp, n, i + 1, k - 1); 
		tmp.pop_back(); 
	} 
} 
vector<vector<int> > makeCombi(int n, int k) 
{ 
	vector<vector<int> > ans; 
	vector<int> tmp; 
	makeCombiUtil(ans, tmp, n, 1, k); 
	return ans; 
} 
bool check(vector<int> form ,int n){
    int row_1;
    int row_2;
    int column_1;
    int column_2;
    for (int i=0 ; i < form.size()-1 ; i++){
        row_1 = form[i] / n;
        if( form[i] <= n){row_1 = 0;}
        column_1 = ( form[i] % n) - 1 ;
        if(column_1 == -1){column_1 += n;}
        for (int j=i + 1; j< form.size() ; j++){
            row_2 = form[j] / n;
            if( form[j] <= n){row_2 = 0;}
            column_2 = (form[j] % n) - 1;
            if(column_2 == -1){column_2 += n;}
            if( row_2 == row_1 - 2 && column_2 == column_1 - 1 ){
                return false;
            }
            if ( row_2 == row_1 - 2 && column_2 == column_1 + 1){
                return false;
            }
            if (row_2 == row_1 + 2 && column_2 == column_1 - 1){
                return false;
            }
            if (row_2 == row_1 + 2 && column_2 == column_1 + 1){
                return false;
            }
            if (row_2 == row_1 - 1 && column_2 == column_1 + 2){
                return false;
            }
            if (row_2 == row_1 - 1 && column_2 == column_1 - 2){
                return false;
            }
            if (row_2 == row_1 + 1 && column_2 == column_1 - 2){
                return false;
            }            
            if (row_2 == row_1 + 1 && column_2 == column_1 + 2){
                return false;
            }
        }
    }
    return true;
} 
int main() 
{  
	int n ;
    cout << "enter n :";
    cin >> n; 
    cout<<"your n*n board is :"<<endl;
    int board=1;
    for(int row=0 ; row < n ; row++){
        for(int column =0 ; column < n ; column++){
            cout<<board<<" ";
            board++;
        }
        cout<<endl;
    }
	vector<vector<int> > ans = makeCombi(n*n , n); 
    cout <<"The valid positions are :"<<endl;
	for (int i = 0; i < ans.size(); i++) { 
        if( check (ans[i] , n ) == true){
            for (int j = 0; j < ans[i].size(); j++) { 
			    cout << ans[i][j] << " "; 
		    } 
            cout << endl;
        }
	} 
	return 0; 
} 
