
#include <iostream>
#include <exception>
using namespace std;

class StackUnderFlowException : public exception{
    public:
        const char* what() const noexcept override{
            return "No item to Pop/No item to View.";
        }
};

template <class T>
class Stack{
    private:
        T elements[100];
        int topIndex;
    public:
        Stack() : topIndex(-1) {}

        void push(T arg){
            if(topIndex == 99){
                cout<<"Stack Full."<<endl;
                return;
            }
            topIndex++;
            elements[topIndex] = arg;
        }

        T pop(){
            if(topIndex == -1){
                throw StackUnderFlowException();
            }
            cout<<"Popped: "<<elements[topIndex]<<endl;
            return elements[topIndex--];
        }

        T top(){
            if(topIndex == -1){
                throw StackUnderFlowException();
            }
            cout<<"Stack Top: "<<elements[topIndex]<<endl;
            return elements[topIndex];
        }
};

int main(){

    Stack<string> stack;
    stack.push("Message");  
    stack.push("Will");     
    stack.push("Come");    
    stack.push("Out");      
    stack.push("Reversed"); 

    try{
        stack.pop(); 
        stack.pop(); 
        stack.pop(); 
        stack.pop();
        stack.top();
        stack.pop();
        stack.pop(); 
        
    }
    catch(StackUnderFlowException& err){
        cout<<err.what()<<endl;
    }

    return 0;
}
