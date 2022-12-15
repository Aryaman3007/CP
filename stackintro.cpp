#include<bits/stdc++.h>
using namespace std;

//Stack implementation
class Stack{

    public:
    int top;
    int size;
    int *arr;

    Stack(int size){
        this->top=-1;
        this->size=size;
        arr=new int[size];
    }

    void push(int d){
        if(size-top>1){
            top++;
            arr[top]=d;
        }
        else{
            cout<<"Stack Overflow\n";
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow\n";
        }
    }

    void peek(){
        if(top>=0){
            cout<<arr[top]<<endl;
        }
        else{
            cout<<"Stack Underflow\n";
        }
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    /*Using stl

    Stack<int> s;
    s.push(2);
    s.push(4);
    s.pop();
    cout<<"Print the top element : "<<s.top()<<endl;
    if(s.empty()){
        cout<<"Stack is empty\n";
    }
    else{
        cout<<"Stack is not empty\n";
    }
    cout<<s.size();*/

    Stack st(5);
    st.push(5);
    st.push(15);
    st.push(25);
    st.push(29);
    st.push(35);
    st.push(55);
    st.peek();

    st.pop();
    st.peek();

    st.pop();
    st.peek();
    
    if(st.isempty()){
        cout<<"Stack is empty\n";
    }
    else{
        cout<<"Stack is not empty\n";
    }

    st.pop();

    return 0;

}