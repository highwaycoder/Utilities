
#include "Stack.h"

int main(void)
{
    util::Stack* testStack = new util::Stack();
    testStack->push(42);
    testStack->push(50);
    testStack->push(99);
    testStack->print();
    testStack->pop();
    testStack->print();
    delete testStack;
    return 0;
}
