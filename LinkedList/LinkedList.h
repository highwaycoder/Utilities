/*
 * LinkedList.h
 *
 *  Created on: Jun 8, 2012
 *      Author: miranda
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace util
{

    typedef unsigned int data_type;
    #define DT_IS_XOR_SAFE 1

    class LinkedList
    {
    private:
        typedef struct Node
        {
            Node* next;
            Node* previous;
            data_type data;
        } Node;
        Node* head;
        unsigned int size;
        Node* fetch_node(unsigned int index);
        void quicksort(unsigned int left, unsigned int right);
        unsigned int quicksort_helper(unsigned int left, unsigned int right,
                unsigned int pivot);
    public:
        LinkedList();
        virtual ~LinkedList();
        data_type get(unsigned int index);
        void put(data_type data);
        void insert(unsigned int index, data_type data);
        void remove(unsigned int index);
        void swap(unsigned int first, unsigned int second);
        void quicksort(void);
        void print(unsigned int index);
        void printAll(void);
        void printAll(unsigned int start_index);
        void printAll(unsigned int start_index, unsigned int end_index);
    };

} /* namespace util */
#endif /* LINKEDLIST_H */
