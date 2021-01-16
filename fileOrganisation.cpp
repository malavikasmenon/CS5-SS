//Single Level File Organisation
#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

vector <string> dir;

bool searchFile(string s){
    auto it = find(dir.begin(), dir.end(), s);
    if(it!=dir.end()){
        return true;
    }
    else 
        return false; 
}

createFile(){
    string fname;
    cout<<"Enter the name of the file:"; 
    cin>>fname; 
    bool flag = searchFile(fname); 
    while(flag==true){
        cout<<"File Name Already Exists. Enter New File Name"; 
        cin>>fname;
        flag = searchFile(fname); 
    }
    cout<<"File "<<fname<<" created.\n";
    dir.push_back(fname); 
}

deleteFile(){
    string s;
    cout<<"Enter name of file to be deleted\n";
    cin>>s; 
    auto it = find(dir.begin(), dir.end(), s); 
    if(it!=dir.end()){
        dir.erase(it);
        cout<<"File has been deleted \n";
    }
    else{
        cout<<"File does not exist\n"; 
    }
}




display(){
    cout<<"Here's the list of files in the directory\n"; 
    int n = dir.size(); 
    for(auto i = dir.begin(); i<dir.end(); i++){
        cout<<*i<<'\n';
    }
}

int main(){

    int ch = 0;
    string key;
    do{
        cout<<"Choose your preferred option\n"; 
        cout<<"1. Create A File\n";
        cout<<"2. Delete A File \n";
        cout<<"3. Search for a file \n";
        cout<<"4. Display the list of all files\n";
        cout<<"5. Exit\n";
        cin>>ch; 
        switch(ch){
            case 1: createFile();
                    break; 
            case 2: deleteFile();
                    break;
            case 3: cout<<"Enter file name to be searched\n";
                    cin>>key;
                    if(searchFile(key)==true){
                        cout<<"File Exists\n";
                    }
                    else{
                        cout<<"File does not exist \n"; 
                    }
                    break;
            case 4: display(); 
                    break;
            default: cout<<"Invalid Option\n";
        }
    } while(ch<5); 
    
    return 0;
}