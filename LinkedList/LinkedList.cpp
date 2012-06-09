/*
 * LinkedList.cpp
 *
 *  Created on: Jun 8, 2012
 *      Author: miranda
 */

#include <cstddef>
#include <cstdio>
#include "LinkedList.h"

namespace util
{

    LinkedList::LinkedList()
    {
        head = NULL;
        size = 0;
    }

    LinkedList::~LinkedList()
    {
        while (size > 0)
            remove(size - 1);
    }

    data_type LinkedList::get(unsigned int index)
    {
        if (size == 0)
            return 0; // empty list
        Node* return_node = fetch_node(index);
        return return_node->data;
    }

    void LinkedList::put(data_type data)
    {
        if (size != 0)
            insert(size - 1, data);
        else
            insert(0, data);
    }

    void LinkedList::insert(unsigned int index, data_type data)
    {
        Node* newNode = new Node;
        Node* insert_place = NULL;
        newNode->data = data;
        if (size == 0)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
        }
        else
        {
            insert_place = fetch_node(index);
            newNode->next = insert_place->next;
            newNode->previous = insert_place;
            insert_place->next->previous = newNode;
            insert_place->next = newNode;
        }
        size++;
    }

    LinkedList::Node* LinkedList::fetch_node(unsigned int index)
    {
        Node* current_node = head;
        if (size <= 1)
            return current_node;
        unsigned int i = 0;
        index %= size;
        if (index < size / 2)
        {
            for (i = 0; i < index; i++)
                current_node = current_node->next;
        }
        else
        {
            for (i = size; i > index; i--)
                current_node = current_node->previous;
        }
        return current_node;
    }

    void LinkedList::remove(unsigned int index)
    {
        if (size == 0)
            return; // do nothing if size is 0
        if (size == 1)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node* to_remove = fetch_node(index);
            // defensive programming against a corrupt list
            if (to_remove->previous != NULL)
                to_remove->previous->next = to_remove->next;
            if (to_remove->next != NULL)
                to_remove->next->previous = to_remove->previous;
            delete to_remove;
        }
        size--;
    }

    void LinkedList::swap(unsigned int first, unsigned int second)
    {
        Node* first_node = fetch_node(first);
        Node* second_node = fetch_node(second);
#if DT_IS_XOR_SAFE == 1
        {
            if (first_node != second_node)
            {
                first_node->data ^= second_node->data;
                second_node->data ^= first_node->data;
                first_node->data ^= second_node->data;
            }
        }
#else
        {
            data_type temp_data = first_node->data;
            first_node->data = second_node->data;
            second_node->data = temp_data;
        }
#endif
    }
    
    unsigned int LinkedList::quicksort_helper(unsigned int left,unsigned int right,unsigned int pivot)
    {
        data_type pivot_value = get(pivot);
        swap(pivot,right);
        unsigned int store = left;
        unsigned int i = 0;
        for(i=left;i<right;i++)
        {
            if(get(i) < pivot_value)
            {
                swap(i,store);
                store++;
            }
        }
        swap(store,right);
        return store;
    }

    void LinkedList::quicksort(unsigned int left, unsigned int right)
    {
        if(left < right)
        {
            unsigned int pivot = size/2;
            unsigned int new_pivot = quicksort_helper(left,right,pivot);
            quicksort(left,new_pivot-1);
            quicksort(new_pivot+1,right);
        }
    }

    void LinkedList::quicksort(void)
    {
        quicksort(0,size-1);
    }
    
    void LinkedList::print(unsigned int index)
    {
        printf("[%d]", get(index));
    }

    void LinkedList::printAll(void)
    {
        // don't print anything if the list is empty
        if (size == 0)
            return;
        printAll(0, size - 1);
    }
    
    void LinkedList::printAll(unsigned int start_index)
    {
        // don't print anything if the list is empty
        if (size == 0)
            return;
        printAll(start_index, size - 1);
    }
    
    void LinkedList::printAll(unsigned int start_index, unsigned int end_index)
    {
        if (start_index < end_index)
        {
            print(start_index);
            printf("->");
            printAll(++start_index);

        }
        else if (start_index > end_index)
        {
            print(start_index);
            printf("<-");
            printAll(--start_index);

        }
        else
        {
            print(start_index);
            putchar('\n');
        }
    }

} /* namespace util */
