#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

vector <vector<int>> allocation; 
vector <vector<int>> maxv; 
vector <vector<int>> need; 
vector <int> available; 
vector <int> safe_seq;

int n, m; 
vector <int> check; 

void outputvector(vector <vector<int>> x){
    for(int i=0; i<int(x.size()); i++){
        for(int j=0; j<int(x[i].size()); j++){
            cout<<x[i][j]<<" ";
        }
        cout<<'\n';    
    
    }
}

void calcNeedMatrix(){
    
    int temp; 

    for(int i=0; i<n; i++){
        vector <int> tempv;
        for(int j=0; j<m; j++){
            temp = maxv[i][j] - allocation[i][j]; 
            tempv.push_back(temp);
        }
        need.push_back(tempv);
    }
    cout<<"Need matrix\n"; 
    outputvector(need);
}

void checkSafety(){
    //For each process check if number of resources needed is less than the available resources
    cout<<"Here\n";
    int count = 0;
    
    while(count<n){

        //cout<<"In while loop";
        for(int i=0; i<n; i++){
            cout<<i<<" "; 
            while(check[i]==1){
                i++;
            }
            int flag = 0;
            for(int j=0; j<m; j++){
                if(need[i][j]<=available[j]){

                }
                else{
                    flag = 1; 
                    check[i] = 0; 
                }
            }
            if(flag==0){
                cout<<"Process "<<i<<" has enough ";
                for(int k=0; k<m; k++){
                    available[k] += allocation[i][k];
                }
                safe_seq.push_back(i);
                check[i]=1;
                count++; 
            }
        }
        
        

    }
}

int main(){

    //Defining data structures
    int temp; 
    cout<<"Enter number of processes\n";
    cin>>n; 
    cout<<"Enter number of resources \n"; 
    cin>>m; 

    //Input allocation matrix
    cout<<"Enter allocation matrix\n"; 
    for(int i=0; i<n; i++){
        cout<<"For process P"<<i<<'\n';
        vector <int> tempv;
        for(int j=0; j<m; j++){
            //cout<<"Enter resource instances\n";
            cin>>temp;
            tempv.push_back(temp); 
        }
        allocation.push_back(tempv);
    }
    outputvector(allocation);

    //Input max matrix
    cout<<"Enter max matrix\n"; 
    for(int i=0; i<n; i++){
        cout<<"For process P"<<i<<'\n';
        vector <int> tempv;
        for(int j=0; j<m; j++){
            //cout<<"Enter resource instances\n";
            cin>>temp;
            tempv.push_back(temp); 
        }
        maxv.push_back(tempv);
    }
    outputvector(maxv);

    //Input total availability 
    cout<<"Enter available resources\n"; 
    for(int i=0; i<m; i++){
        cin>>temp; 
        available.push_back(temp);
    }

    calcNeedMatrix(); 
    
    //cout<<"check matrix\n";
    for(int i=0; i<n; i++){
        check.push_back(0);
    }
    checkSafety();
    cout<<"Safe sequence\n"; 
    for(int i=0; i<n; i++){
        cout<<safe_seq[i]<<"->"; 
    }








    //Input Allocation, Max, Available
    /*need; 
    need[i][j] = max[i][j] - allocation[i][j]; 
    vector <bool> finish (n,false);
    work = available; 
    for(i in 0 to n){
        for(j 0 to m){
            if(need[i][j]>work){

            }
        }
    } */
    return 0; 
}