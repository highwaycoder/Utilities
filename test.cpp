#include <cstdio>
#include "LinkedList.h"

int main(void)
{
    printf("Creating new list called testList...");
    util::LinkedList* testList = new util::LinkedList;
    printf("Success\n");

    printf("testList.get(0)...%d\n",testList->get(0));

    printf("testList.put(42)...");
    testList->put(42);
    printf("Done\n");
    testList->printAll();

    printf("testList.get(0)...%d\n",testList->get(0));


    printf("testList.put(5)...");
    testList->put(5);
    printf("Done\n");
    testList->printAll();
    printf("testList.put(12)...");
    testList->put(12);
    printf("Done\n");
    testList->printAll();
    printf("testList.insert(1,6)...");
    testList->insert(1,6);
    printf("%d\n",testList->get(2));
    testList->printAll();

    printf("Printing list before sort...\n");
    testList->printAll();

    printf("Sorting...");
    testList->quicksort();
    printf("Done\n");

    printf("Printing list after sort...\n");
    testList->printAll();

    printf("testList.remove(3)...");
    testList->remove(3);
    printf("Done\n");
    testList->printAll();

    printf("testList.insert(50,22)...");
    testList->insert(50,22);
    printf("Done\n");
    testList->printAll();

    printf("testList.remove(50)...");
    testList->remove(50);
    printf("Done\n");
    testList->printAll();

    printf("Cleaning up list...");
    delete testList;
    printf("Done\n");
    return 0;
}
