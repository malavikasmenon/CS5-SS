/*
Algorithm 
1. Initialise - state to thinking, semaphore to 0 
2. Print Menu 
3. Ask which philosopher
4. If to start eating, change state to hungry. check if neighbours are eating. if not - change state to eating. then put down fork and change back to thinking 
5. If to stop eating, change state to thinking. test for neighbours 

*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

enum{THINKING, HUNGRY, EATING} state[5]; 
int sem[5]; 

void initialise(){
    for(int i=0; i<5; i++){
        sem[i] = 0;
        state[i] = THINKING;
    }
}

void test(int x){
    if(state[x]==HUNGRY && sem[(x+1)%5]==0 && sem[(x+4)%5]==0){
        sem[x]=1;
        state[x]=EATING;
    }
}

void pickup(int x){
    cout<<"Picking up fork\n";
    state[x] = HUNGRY; 
    test(x); 
    if(sem[x]==1){
        cout<<"Philosopher "<<x+1<<" is eating\n";
    }
    else{
        cout<<"Philosopher can't eat right now\n"; 
    }
}

void putdown(int x){
    //cout<<"Putting down\n";
    if(state[x]!=EATING){
        cout<<"Operation not possible. Philosopher is not eating right now\n";
        return; 
    }
    state[x]=THINKING;
    sem[x]=0; 
    test((x+1)%5);
    test((x+4)%5);
    cout<<"Philosopher "<<x+1<<" has stopped eating\n"; 
}

int main(){

    int ch, ph;
    initialise();
    do{
        cout<<"Menu\n";
        cout<<"1. Start eating \n";
        cout<<"2. Stop eating \n";
        cout<<"3. Exit\n";
        cout<<"Enter choice\n";
        cin>>ch;
        if(ch==3){
            exit(0);
        }
        cout<<"Which philosopher do you want to interact with?\n";
        cin>>ph;
        switch (ch)
        {
            case 1: 
                pickup(ph-1);
                break;
            case 2: 
                putdown(ph-1);
                break;
            default:
                break;
        }
    }while(ch<3);
    return 0;
}