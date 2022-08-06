#include <iostream>
using namespace std;

// stack using array
class Stack{
    int size,top,*arr;
    public:
    Stack(int s){
        size = s;
        arr = new int[size];
        top = -1;
    }
    ~Stack(){
        delete []arr;
    }
    void push(int val){
        if(top == (size-1)){
            cout<<"Over Flow"<<endl;
            return;
        }
        arr[++top] = val;
    }
    int pop(){
        if(top == -1){
            cout<<"Under Flow"<<endl;
            return 0;
        }
        return arr[top--];
    }
    int peek(){
        if(top==-1){
            cout<<"Under Flow"<<endl;
            return 0;
        }
        return arr[top];
    }
   

};

int main(int argc, char const *argv[])
{
    Stack s1(5),s2(10);
    s1.push(20);
    s1.push(40);
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    
    return 0;
}
