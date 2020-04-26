#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    
    ifstream read("/Users/christine/Desktop/HW/106學年度/下學期/HW1/input.txt", ios::in);
    
    int cases;
    read >> cases;
    for(int cnt=0; cnt < cases; cnt++){
        int N=0, M=0;
        read >> N >> M;
        //cout << "N=" << N << "\nM=" << M << endl;
        vector<int> group(N+1);//group number to which each person belongs
        for(int i=1; i<N+1; i++){//initialize group number as oneself for each person
            group[i] = i;
            //cout << "group["<<i<<"]:"<<group[i]<<", ";
        }
        //cout << endl;
        
        vector<int> groupCnt(N+1);//how many friends in a group
        for(int i=1; i<N+1; i++){//initialize groupCnt 0
            groupCnt[i] = 0;
            //cout << "groupCnt["<<i<<"]:"<<groupCnt[i]<<", ";
        }
        //cout << endl;
        
        for(int n=0; n<M; n++){//read M pairs
            int num1=0, num2=0;
            read >> num1 >> num2;//read 2 person and shift the bigger group to the smaller group
            //cout << "num1="<<num1<<", num2="<<num2<<endl;
            if(group[num1] < group[num2]){
                //cout << "group["<<num1<<"]:"<<group[num1]<<" < group["<<num2<<"]:"<<group[num2]<<endl;
                
                //find all members in the bigger group
                for(int j=1; j<N+1 ; j++){
                    //cout <<"j="<<j<<endl;
                    if(j == num2)   continue;//skip the one mentioned above
                    if(group[j] == group[num2]){
                        //cout << "group["<<j<<"]:"<<group[j]<<" = group["<<num2<<"]:"<<group[num2]<<endl;
                        group[j] = group[num1];//shift to the smaller group
                        //cout << "NEW group["<<j<<"]:"<<group[j]<<endl;
                    }
                }
                group[num2] = group[num1];
                //cout << "NEW group["<<num2<<"]:"<<group[num2]<<endl;
            }
            else if(group[num2] < group[num1]){//the other way round
                //cout << "group["<<num2<<"]:"<<group[num2]<<" < group["<<num1<<"]:"<<group[num1]<<endl;
                for(int j=1; j<N+1; j++){
                    if(j == num1)   continue;
                    if(group[j] == group[num1]){
                        //cout << "group["<<j<<"]:"<<group[j]<<" = group["<<num1<<"]:"<<group[num1]<<endl;
                        group[j] = group[num2];
                        //cout << "NEW group["<<j<<"]:"<<group[j]<<endl;
                    }
                }
                group[num1] = group[num2];
                //cout << "NEW group["<<num1<<"]:"<<group[num1]<<endl;
            }
            
        }
        for(int i=1; i<N+1; i++){//initialize group number as oneself for each person
           
            cout << group[i]<<", ";
        }
        cout <<endl;
        //calculate size of group
        int lcc=0;
        for(int i=1; i<N+1; i++){
            for(int j=1; j<N+1; j++){
                if(group[j] == i){
                    //cout << "group["<<j<<"]="<<i<<endl;
                    groupCnt[i]++;
                    //cout << "groupCnt["<<i<<"]:"<<groupCnt[i]<<endl;
                }
            }
        }
        //find LCC
        for(int i=1; i<N+1; i++){
            if(groupCnt[i] > lcc){
                lcc = groupCnt[i];
            }
        }
        cout << lcc << endl;
    }
    
    system("pause");
    return 0;
    
}
