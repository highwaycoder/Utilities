/*
 * Stack.h
 *
 *  Created on: Jun 9, 2012
 *      Author: miranda
 */

#ifndef STACK_H
#define STACK_H

namespace util
{

    class Stack
    {
    private:
        typedef unsigned int data_type;
        typedef struct Node
        {
            Node* down;
            data_type data;
        } Node;
        Node* top;
        unsigned int depth;
    public:
        Stack();
        virtual ~Stack();
        void push(data_type data);
        data_type pop(void);
        void print();
    };

}
 /* namespace util */
#endif /* STACK_H */
