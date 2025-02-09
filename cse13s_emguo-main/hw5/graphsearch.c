#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphsearch.h"

// dealing with sets of integers. We wrote these in class.
LLint *add_to_set(LLint *set, int val) {
  LLint *newfront = calloc(1, sizeof(LLint));
  newfront->val = val;
  newfront->next = set;

  return newfront;
}

bool set_contains(LLint *set, int val) {
  if (set == NULL) {
    return false;
  } else if (set->val == val) {
    return true;
  } else {
    return set_contains(set->next, val);
  }
}

// Linked lists of paths. You'll need to implement these.

// Returns the new front of the queue, for a queue of Path structs.
// Usually this will be the old front of the queue, but if q is NULL, then it
// will allocate a new linked list node and return that.
LLPath *enqueue_path(LLPath *q, Path path) {
  // YOUR CODE HERE
  LLPath *new = (LLPath *)calloc(1, sizeof(LLPath));
  if(q == NULL){
    new->val = path;
    new->next = q;
    return new;
  }
  else if(q != NULL){
    LLPath *temp = q;
    while(temp->next){
      temp = temp->next;
    }
    new -> val = path;
    temp -> next = new;
    return q;
  }
  return q;
}

bool dequeue_path(LLPath **q, Path *ret) {
  if (!(*q) || !q){
  	return false;
  }
  *ret = (*q)->val;
  LLPath *freethis = *q;
  *q = (*q)->next;
  free(freethis);
  return true;
}

void byebyegraph(Graph **g, int vertices){
  for (int i=0; i < vertices; i++) {
    free((*g)->matrix[i]);
  }
  free((*g)->matrix);
  free(*g);
}

// We wrote these in class.
// This will create an adjacency matrix in which its n x n.
// No links yet but sets up the space to add the edges
Graph *graph_create(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  g->matrix = (int **)calloc(vertices, sizeof(int*));
  for (int i=0; i < vertices; i++) {
    g->matrix[i] = (int *)calloc(vertices, sizeof(int));
  }
  return g;
}

// This function would connect the nodes
void graph_add_edge(Graph *g, int i, int j) {
  // 1 being there is a connection and 0 meaning there is no connection
  g->matrix[i][j] = 1;
}

bool graph_has_edge(Graph *g, int i, int j) {
  return g->matrix[i][j];
}

// Convenience method for you -- returns a new Path where you have added another
// vertex along the path.
Path path_extend(Path path, int new_vertex) {
  Path out;
  out.steps = path.steps;

  for (int i=0; i < path.steps; i++) {
    out.vertices_visited[i] = path.vertices_visited[i];
  }
  out.vertices_visited[path.steps] = new_vertex;
  out.steps += 1;
  return out;
}

// Print out a path nicely for the user.
void print_path(Path path) {
  if (path.steps == 0) {
    puts("(empty path)");
  }
  for (int i=0; i < path.steps; i++) {
    printf("%s%d",
        (i == 0) ? "" : " -> ",
        path.vertices_visited[i]);
  }
  puts("");
}

// Breadth-first search!
Path graph_find_path_bfs(Graph *g, int i, int j){
  // create vistes and to visit
  LLint *visited = NULL;
  LLPath *to_visit = NULL;

  // create a path of int i and add it to to_visit
  Path start = {1, {i}};
  to_visit = enqueue_path(to_visit, start);


  // while loop to contest all children
  // while there are still more items in to_visit
  // initialize current
  while(to_visit){
    Path current;
    dequeue_path(&to_visit, &current);
    
    int current_val = (&current)->vertices_visited[((&current)->steps)-1];

    // this is what is currently being explored

    // if we are at the end, return the shortest path
    if(current_val == j){
      while(visited){
        LLint *mommy = visited;
        visited = visited->next;
        free(mommy);
      }
      while(to_visit){
        Path daddy;
        dequeue_path(&to_visit, &daddy);
      }
      return current;
    }

    // add what is being explored to visited
    visited = add_to_set(visited, current_val);
    

    // find all children and path_extend them to the current path they are in in the LLPath to_visit
    for(int a = 0; a < g->vertices; a++){
      if(graph_has_edge(g, current_val, a)){
        if(!set_contains(visited, a)){
          to_visit = enqueue_path(to_visit, path_extend(current, a));
        }
      }
    }
  }

  while(visited){
    LLint *mommy = visited;
    visited = visited->next;
    free(mommy);
  }
  Path empty = {0, {0}};
  return empty;
}

//create helper function for dfs
LLPath *enqueue_stack(LLPath *q, Path path){
  LLPath *new = (LLPath *)calloc(1, sizeof(LLPath));
  new->next = q;
  new->val = path;
  return new;
}

// dont use enqueue_path
// can keep dequeue_path
// Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
  LLint *visited = NULL;
  LLPath *to_visit = NULL;

  Path start = {1, {i}};
  to_visit = enqueue_stack(to_visit, start);

  while(to_visit){
    Path current;
    dequeue_path(&to_visit, &current);
    
    int current_val = (&current)->vertices_visited[((&current)->steps)-1];

    if(current_val == j){
      while(visited){
        LLint *mommy = visited;
        visited = visited->next;
        free(mommy);
      }
      while(to_visit){
        Path daddy;
        dequeue_path(&to_visit, &daddy);
      }
      return current;
    }

    visited = add_to_set(visited, current_val);

    for(int a = 0; a < g->vertices; a++){
      if(graph_has_edge(g, current_val, a)){
        if(!set_contains(visited, a)){
          to_visit = enqueue_stack(to_visit, path_extend(current, a));
        }
      }
    }
  }
  while(visited){
    LLint *mommy = visited;
    visited = visited->next;
    free(mommy);
  }
  Path empty = {0, {0}};
  return empty;
}
