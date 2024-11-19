//Theory of stacks

/*
->Stack is a linear data structure based on LIFO(Last In First Out) principle in which the insertion of a new element and 
    removal of an existing element takes place at the same end represented as the top of the stack.
->The order may be LIFO(Last In First Out) or FILO(First In Last Out). 
->LIFO implies that the element that is inserted last, comes out first and FILO implies that the element that is inserted first, comes out last.

->Representation of Stack Data Structure:
https://media.geeksforgeeks.org/wp-content/uploads/20240606180735/Stack-representation-in-Data-Structures-(1).webp

->Types of Stack
    Fixed Size Stack : As the name suggests, a fixed size stack has a fixed size and cannot grow or shrink dynamically. 
    Dynamic Size Stack : A dynamic size stack can grow or shrink dynamically.This type of stack is implemented using 
    a linked list, as it allows for easy resizing of the stack.

->Basic Operations on Stack Data Structure:
In order to make manipulations in a stack, there are certain operations provided to us.
    push() to insert an element into the stack
    pop() to remove an element from the stack
    top() Returns the top element of the stack.
    isEmpty() returns true if stack is empty else false.
    isFull() returns true if the stack is full else false.

->Application of Stacks in DSA
    Converting infix to postfix expressions.
    Undo/Redo button/operation in word processors.
    Syntaxes in languages are parsed using stacks.
    It is used in many virtual machines like JVM.
    Forward-backward surfing in the browser.
    History of visited websites.
    Message logs and all messages you get are arranged in a stack.
    Call logs, E-mails, Google photos’ any gallery, YouTube downloads, Notifications ( latest appears first ).
    Scratch card’s earned after Google pay transaction. 
    Used in IDEs to check for proper parentheses matching

->Aplications of Stack in real life
    A stack of books on a bookshelf
    A stack of folders in an office
    A stack of paper cups at a water cooler
    A stack of chairs at an outdoor concert
    A stack of papers on a desk 


->Array representation of stack
    Advantages of Array Implementation:
    Easy to implement.
    Memory is saved as pointers are not involved.

    Disadvantages of Array Implementation:
    It is not dynamic i.e., it doesn’t grow and shrink depending on needs at runtime. 
    The total size of the stack must be defined beforehand.

*/