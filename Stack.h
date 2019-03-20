#ifndef __STACK_H
#define __STACK_H

#include "Const.h"

#include <iostream>
#include <cstring>

class Stack  {
private:
    itemType* stack;
    int p;
public:
    Stack(int max = 100)
    {  stack = new itemType[max];  p = 0;  }
    ~Stack()
    {  delete [] stack;       }
    void push(itemType v)
    {  stack[p++] = v;     }
    itemType pop()
    {  return stack[--p];  }
    int empty()
    { return (!p);         }
    void display(std::string t)
    {
        std::cout << "\n" << t << "\t";
        for (int i = 0; i < p; i++)
        {
            std::cout << stack[i]->info << " ";
        }
    }
};

#endif
