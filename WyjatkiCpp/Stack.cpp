#include "Stack.h"

Stack::Stack(): top(-1), maxStackSize(0) { }

Stack::Stack(int max): top(-1), maxStackSize(max){ }

void Stack::push(int newItem){
    if(top < maxStackSize - 1){
            dfs.push_back(newItem);
            top++;
    }
    else{
       throw StackFullException("Cannot push element: ", newItem, maxStackSize);
    }
}

int Stack::pop(){
    int p;
    if(top >= 0){
        p = dfs[top];
        dfs.pop_back();
        top--;
        return p;
    }
    else{
        throw StackEmptyException("Stack is empty!");
    }
}

int Stack::getSize(){
    return maxStackSize;
}