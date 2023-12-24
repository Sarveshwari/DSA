#include<iostream>
using namespace std;

class Stack{

    public: 
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;

    }

    void push(int ele)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=ele;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }

    }

    void pop()
    {
        if(top>=0)
        {
            top--;
        }
        else{
            cout<<"Stack empty"<<endl;
        }

    }

    int peek(){
        return arr[top];
    }

    bool isempty()
    {
        if(top<0)
        {
            return true;
        }
        else{
            return false;
        }
    }

};


int main()
{
    Stack st(5);

    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);

    cout<<st.peek()<<endl;

    st.pop();

    cout<<st.peek()<<endl;

   return 0;
}
