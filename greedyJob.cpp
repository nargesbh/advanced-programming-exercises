#include <iostream>
using namespace std;
class job
{
    private:
        int **jobs , rows , **result;
    public:
        job();
        ~job();
        void bestWay();
};
job :: job()
{
    cout << "enter the number of the jobs : " ;
    cin >> rows;
    cout<<endl;
    jobs = new int* [rows];
    for (int row=0 ; row<rows ; row++){
        jobs[row] = new int [2];
    }
    for(int row=0 ; row < rows ; row++){
        cout << "enter s and f of job number "<< row <<" :" ;
        for(int col =0 ; col < 2 ; col++)
            cin >> jobs[row][col];
        cout << endl;
    }
    cout << "jobs you entered are :"<<endl;
    for(int row=0 ; row<rows ; row++){
        for(int col=0 ; col<2 ; col++){
            cout<< jobs[row][col] << " ";
        }
        cout <<endl;
    }
}
void job :: bestWay(){
    int least = jobs[0][1] - jobs[0][0];
    result = new int* [rows];
    for (int row=0 ; row<rows ; row++){
        result[row] = new int [2];
    }
    int fillArray=0;
    int leastIndex=0;
    bool check =true;
    int l=0;
    while( l < rows ){
    for(int i=0 ; i<rows ; i++){
        if((jobs[i][1] - jobs[i][0] <= least) && 1<=jobs[i][1] && jobs[i][1]<=24 && 1<=jobs[i][0] && jobs[i][0]<=24 ){
            leastIndex = i;
            least =jobs[i][1] - jobs[i][0];
        }
    }
    l++;
    result[fillArray][0] = jobs[leastIndex][0];
    result[fillArray][1] = jobs[leastIndex][1];
    fillArray++;
    delete jobs[leastIndex];
    least=25;
    }
    cout<<"the best way is :"<<endl;
    cout << result[0][0] <<" "<<result[0][1] << endl;
    for (int j=1 ; j<rows ; j++){
        for(int k=0 ; k<j ; k++ ){
            if((result[j][0] > result[k][0] && result[j][0] < result[k][1]) || (result[j][1] > result[k][0] && result[j][1] < result[k][1]) ){
                check = false;
            }
        }
        if(check){
            cout << result[j][0] <<" "<<result[j][1] << endl;
        }
        check=true;
    }

}
int main(){
    job bestWayJob;
    bestWayJob.bestWay();
    return 0;
}
job :: ~job(){
    for (int row=0 ; row<rows ; row++){
        delete[] result[row];
    }
    for (int row=0 ; row<rows ; row++){
        delete [] jobs[row];
    }
    delete[] jobs;
    delete[] result;
}
