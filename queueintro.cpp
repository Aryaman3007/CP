#include<bits/stdc++.h>
using namespace std;

class Queue {
    int qfront;
    int rear;
    int size;
    int *arr;

public:

    Queue() {
        // Implement the Constructor    
        size=100001;
        qfront=0;
        rear=0;
        arr=new int[size];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size){
            cout<<"Queue Overflow\n";
        }
        else{
            arr[rear]=data;
            rear++;
        }        
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear==qfront){
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(rear==qfront){
            return -1;
        }
        return arr[qfront];
    }
};