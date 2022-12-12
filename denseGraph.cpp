#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class graph
{
    private:
        int n,m;
        vector<vector<int>> G;
        vector<int> array;
        bool ansCheck=false;
    public:
        graph();
        void allPossibleSubset();
        bool checkConnectivity(vector<vector<int>> a);
        bool checkdense(vector<vector<int>> set);
};
graph :: graph()
{
    cout << "enter the number of vertices : ";
    cin >> n;
    cout << "enter the number of edges : ";
    cin >> m;
    for(int i=0 ; i<m ; i++){
        G.push_back({0,0});
    }
    for(int i=0 ; i<m ; i++){
        cout <<"enter two vertices that are connected : ";
        cin >> G[i][0] >> G[i][1] ;
    }
    for(int i=0;i<m;i++){
		array.push_back(i+1);
    }
    
}
void graph ::allPossibleSubset( )
{
	vector<vector<int>> subsetMake;
	int  count = pow(2,m);
    bool check = false;
	// vector<vector<int>> G = {{1,2} , {3,4} , {5,6}};
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i & (1 << j)) > 0){
				// cout << array[j] << " ";
                check = true;
				subsetMake.push_back(G[ array[j] - 1]);
				}
		}
        if (check)
        {
            cout << " subgraph :"<<endl;
            for (int i = 0; i < subsetMake.size(); i++) { // printing the 2D vector.
                for (int j = 0; j < subsetMake[i].size(); j++)
                    cout << subsetMake[i][j] << " ";
                    cout << endl;
            }
            cout << "connectivity : "<< checkConnectivity(subsetMake)<<endl;
            cout << "check dense :" << checkdense(subsetMake)<<endl;
            cout << "-----------------------"<<endl;
        if(checkConnectivity(subsetMake) && checkdense(subsetMake)){
            ansCheck = true;
            cout << " a valid subgraph :"<< endl;
            for (int i = 0; i < subsetMake.size(); i++) { // printing the 2D vector.
                for (int j = 0; j < subsetMake[i].size(); j++)
                    cout << subsetMake[i][j] << " ";
                    cout << endl;
            }
            cout << "-------------------";
        }
        }
		subsetMake.clear();
	}
    if(!ansCheck){
        cout << "none of the subgraphs are valid"<<endl;
    }
}
bool graph ::checkConnectivity(vector<vector<int>> a)
{
//     cout << "subgraph :"<<endl;
//         for (int i = 0; i < a.size(); i++) { // printing the 2D vector.
//       for (int j = 0; j < a[i].size(); j++)
//       cout << a[i][j] << " ";
//       cout << endl;
//    }
    vector<bool> check_connectivity;
    vector<int> connected_vertices;
    int help = a[0][0];
    int stop_loop = m;
    bool ans = true;
    connected_vertices.push_back(a[0][0]);
    for(int i=0 ; i<n ; i++){
        check_connectivity.push_back(false);
    }
    check_connectivity[a[0][0]-1] = true;
    for(int i = 1 ; i < a.size() ; i++){
        if(a[i][0] == help){
            connected_vertices.push_back(a[i][1]);
        }
    }
    for(int i =0 ; i < connected_vertices.size() ; i++){
        stop_loop -- ;
        if (stop_loop < 0 ){break;}
        for(int j=0 ; j < a.size() ; j++){
            if( connected_vertices[i] = a[j][0]){
                connected_vertices.push_back(a[j][1]);
            }
        }
    }
    for(int k=0 ; k<connected_vertices.size() ; k++){
        check_connectivity[connected_vertices[k]-1] = true;
    }
    for(int k=0 ; k<check_connectivity.size() ; k++){
        if(check_connectivity[k] == false){
            // cout << "check connectivity = 0 "<<endl;
            return 0;
        }
    }
    // cout <<"check connectivity = 1"<<endl;
    return 1;
}
bool graph ::checkdense(vector<vector<int>> set)
{
//         cout << "subgraph :"<<endl;
//         for (int i = 0; i < set.size(); i++) { // printing the 2D vector.
//       for (int j = 0; j < set[i].size(); j++)
//       cout << set[i][j] << " ";
//       cout << endl;
//    }
   int q = set . size();
   vector<int> help ;
   for(int i=0 ; i < set.size() ; i++){
       for(int j=0 ; j<2 ; j++){
           if( (find(help.begin(), help.end(), set[i][j]) != help.end()) == false){
               help . push_back(set[i][j]);
           }
       }
   }
    int p = help.size();
    if( q / ((p*(p-1))/2) > 0.75 ){
        // cout << "DENSE =1"<<endl;
        return 1;
    }
    // cout << "DENSE =0 "<<endl;
    return 0;
}
int main (){
    graph denseGraph;
    denseGraph.allPossibleSubset();
    return 0;
}