#include <iostream>
using namespace std;

char* subStr(char *str,int start , int stop){
    int size = stop-start +1;
    char *sub = new char[size];
    // cout<<"In fun---->"<<str<<endl;
    
    if(stop<=0 || start <0){
        return NULL;
    }

    int index = 0;
    for (int i=start; i<stop; i++){
        // cout<<*(str+i);
        sub[index] =  *(str+i);
        index++;
    }
    cout<<endl;
    // cout<<"The Sub string ----->"<<sub<<endl;
    return sub;

}

int main(){
    // string name;
    char name[100],*p;
    cout<<"enter name"<<endl;
    cin.get(name,100);

    // getline(cin,name);

    // cout<<name<<endl;
    // cout<<name[3]<<endl;

    p  = subStr(name,2,5);

    cout<<"Printing in Main "<<endl;
    if(p == NULL){
        cout<<"NULL"<<endl;
    }
    else{
        while (*p != '\0'){
        cout<<*p;
        p++;
    }

    }
    
    cout<<endl;

   

    return 0;
}