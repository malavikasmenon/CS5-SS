/*
Algorithm 
1. Enter buffer size 
2. Initialise empty = buffer_size, full = 0 and mutex = 1
3. Print Menu 
4. If produce -> check if buffer is full. If not full, make mutex 0, add an item, increment full, decrement empty and make mutex 1
5. If consumer -> check if buffer is empty. If not, make mutex 0, consume an item, decrement full, increment empty and make mutex 1
6. Maintain count and produce total count for consumed and produced items 

*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

int buffer_size, full, empty, prod_count, consumer_count, mutex, x; 

int wait(int &s){
    s--;
    return s;
}

int signal(int &s){
    s++;
    return s;
}

void produce(){
    //cout<<"Producing\n";
    if(full==buffer_size){
        cout<<"Buffer is full. Can't Produce\n";
        return;
    }
    else{
        wait(empty);
        wait(mutex);
        prod_count++;
        x++; 
        cout<<"Produced item "<<x<<'\n';
        signal(mutex);
        signal(full); 
    }
    
}

void consume(){
    cout<<"Consuming\n";
    if(empty==buffer_size){
        cout<<"Buffer is empty. Can't consume\n";
    }
    else{
        wait(full);
        wait(mutex);
        consumer_count++;
        cout<<"Consumed item "<<x<<'\n';
        x--;
        signal(mutex);
        signal(empty); 
    }
}

int main(){

    int ch;
    cout<<"Enter buffer size\n"; 
    cin>>buffer_size; 

    //Initialisation
    full = 0; 
    empty = buffer_size; 
    mutex = 1; 
    x = 0; 

    do {
        cout<<"Menu\n";
        cout<<"1. Produce an Item\n";
        cout<<"2. Consume an Item\n"; 
        cout<<"3. Exit\n";
        cout<<"Enter choice\n";
        cin>>ch; 
        switch (ch)
        {
            case 1: produce();
                break;
            
            case 2: consume();
                break;

            default:
                break;
        }

    } while(ch<3);
    cout<<"Current empty slots: "<<empty<<'\n';
    cout<<"Current occupied slots: "<<full<<'\n';
    cout<<"Producer count: "<<prod_count<<'\n';
    cout<<"Consumer count: "<<consumer_count<<'\n'; 
    return 0; 
}