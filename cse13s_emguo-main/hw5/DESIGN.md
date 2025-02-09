# homework 5: graphs, queues, stacks and search Design Doc

# enqueue_path
For the function we will push a stack. We need to append values to the stack throught the heap and set the top to current.

    q -> items[q-> val] = n;
    q -> val ++;

# dequeue_path
For the function we will pop a stack. In order to do this, we need to free/dequeue all elements on the heap/in the stack. Use a for loop to free the nodes just like the last homework assignment and then point the the stack to NULL.

    LLPath *next = (*path)-> next;
    free(*path);
    *path = next;
    returnval = (*path) -> val;

# graph_find_path_bfs
For this function, we will need to perform breadth first search. Use enqueue and dequeue to do the search. Breadth first search is conducted using last in first out order. We need to check if the node on the list was previously visited. If it was not then we would call enqueue to push the stack. If it was visited, we would need to use dequeue to free it.



# graph_find_path_dfs
For this function, we will need to perform depth first search. Use enqueue and dequeue to do the search. Depth first search is conducted using last in first out order. Very similar to bfs, just in a different order.

# implementing stack behavior for Paths
LLPath is our queue/stack. We need to search and determine the shortest/quickest path to get from point a to point b. This will require us to enqueue while the node in the LLPath has not been visited and dequeue when it has been visited. Then, we need to check each vertex for adjacency. 