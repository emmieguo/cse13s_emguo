# Hw4 Design doc
Thoughts going into this assignment: "what am i looking at?"

# stack_push
This function prompts us to add a new node at the front of the stack. Return false if we are unable to do. To do this, we have to understand what the push function wants. In class, the professor demonstrates how a push should look like. We need to create a new node. If the new node is NULL, aka the memory allocation failed, this should return false. If allocation is successful. After this, we should make the current front as next and the new node as front. Then, return true.

    Node new = calloc()
    if node == null --> return false{
        new->item;
        new->item = s->top;
        s->top=new;
        return true;
    }

# stack_pop
This function asks to pop the stack and put the result into the output pointer. To do this, the stack cannot be empty. First check this case. After this, how would you remove a node? Simple! use free(). But before that, we must set our new top. To do this, we can create a pointer that would allow us to store the current top while we move next to top. Then we would simply free the pointer that was connected to the node we wanted to pop.

    Node* pointer = s-> top;
	s -> top = s-> top -> next;
	free(pointer);

# stack_empty
We want to return true if the stack is empty. How we can do this is by comparing the top value to null. This will simply check if there is a node in the stack.
    
    return s -> top == NULL;

# stack_delete
We want to free all of the memory used by this stack, including its linked list. To do this, we should construct a while loop that will continue to free() the memory and linked lists in the stack until it is empty. After this, we set the pointer to null.

    while(stack != NULL){
        set top to next;
        free(top);
    }
    *s = NULL;

# stack_compute_step
This function is on the longer side. For this, we are given NUMBER, ADD, SUBTRACT, MULTIPLY, DIVIDE which is defined in stack_calculator.h. The argument "item" is one of these types. We must first check to see what the item.type is and then we will know what to do and what to return.
For NUMBER, we are expected to push item into the stack. For this, we can simply call the stack_push function: stack_push(s,item);
For ADD, we want to add two pops of our stack together and then push. Call stack_pop twice and then add these two values together
For SUBTRACT, MULTIPLY, DIVIDE, these are all similar to ADD. They will follow a similar structure:

    stack_pop(s,first);
    stack_pop(s,second);
    pushee = first +, -, * or / second;
    stack_push(s,pushee);
