/*
 * Stack.cpp
 *
 *  Created on: Jun 9, 2012
 *      Author: miranda
 */
#include <cstdio>
#include "Stack.h"

namespace util
{
    Stack::Stack()
    {
        
    }
    
    Stack::~Stack()
    {
        while(depth > 0) pop();
    }

    void Stack::push(data_type data)
    {
        Node* new_node = new Node;
        new_node->data = data;
        if(depth != 0)
            new_node->down = top;
        else
            new_node->down = 0;
        top = new_node;
        depth++;
    }

    Stack::data_type Stack::pop(void)
    {
        if(depth == 0) return 0;
        data_type data = top->data;
        Node* to_delete = top;
        if(depth != 1)
            top = top->down;
        delete to_delete;
        depth--;
        return data;
    }

    void Stack::print(void)
    {
        unsigned int i = depth;
        Node* current = top;
        while(i > 0)
        {
            printf("#%d: %d\n",i,current->data);
            current = current->down;
            i--;
        }
    }

} /* namespace util */
