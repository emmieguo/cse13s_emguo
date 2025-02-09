#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct CustomerNode {
  char *email;
  char *name;   // the key
  int shoe_size; // values
  char *fav_food;  // values
  struct CustomerNode *next;
} CustomerNode;

typedef struct CustomerTable {
  // the actual buckets
  // an array of linked lists.
  CustomerNode **buckets;
  // num_buckets
  size_t num_buckets;
} CustomerTable;


// Thank you Dan Bernstein.
unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
    str++;
  }
  return hash;
}

CustomerNode *add_customer_to_list(char *email, char *name, int shoe_size, char *food, CustomerNode *bucket) {
  CustomerNode* new_customer;

  new_customer = calloc(1, sizeof(CustomerNode));
  new_customer->email = strdup(email);
  new_customer->name = strdup(name);
  new_customer->fav_food = strdup(food);
  new_customer->shoe_size = shoe_size;
  new_customer->next = bucket;

  return new_customer;
}

void add_customer_to_table(char *email, char *name, int shoe_size, char *food, CustomerTable *table) {
  //printf("%s\t%s\t%d\t%s\n", email, name, shoe_size, food);
  unsigned long hashvalue = hash(email);
  size_t which_bucket = hashvalue % table->num_buckets;
  CustomerNode *cusussy = table->buckets[which_bucket];

  while(cusussy){
    if(strcmp(email, cusussy->email) == 0){
      free(cusussy->name);
      //free(cusussy->shoe_size);
      free(cusussy->fav_food);
      cusussy->name = strdup(name);
      cusussy->fav_food = strdup(food);
      //cusussy->shoe_size = strdup(shoe_size);
      return;
    }
    cusussy = cusussy->next;
  }

  CustomerNode *linkedlist = table->buckets[which_bucket];
  table->buckets[which_bucket] = add_customer_to_list(email, name, shoe_size, food, linkedlist);
  return;
}

CustomerTable *build_customer_table(size_t num_buckets) {
  CustomerTable* output = calloc(1, sizeof(CustomerTable));
  output->num_buckets = num_buckets;

  // allocate space for num_buckets FriendNode pointers.
  // THEY ARE ALREADY NULL POINTERS.
  output->buckets = calloc(num_buckets, sizeof(CustomerNode *));

  return output;
}

CustomerNode* delete_customer_from_list(char *email, CustomerNode *linkedlist) {
  if (!linkedlist) {
    return NULL;
  } else if (!strcmp(email, linkedlist->name)) {
    // match!!

    // need to free this node!
    CustomerNode *next = linkedlist->next;
    // now delete this node.
    free(linkedlist->email);
    free(linkedlist->name);
    free(linkedlist->fav_food);
    free(linkedlist);
    return next;
  } else {
    // recursive case!!
    linkedlist->next = delete_customer_from_list(email, linkedlist->next);
    return linkedlist;
  }
}




void delete_table(CustomerTable *table) {
  // for each bucket, delete everything in that bucket
  for (size_t i=0; i < table->num_buckets; i++) {
    CustomerNode *here = table->buckets[i];
    while(here) {
      free(here->name);
      free(here->fav_food);
      free(here->email);
      CustomerNode *freethis = here;
      here = here->next;
      free(freethis);
    }
  }
  free(table->buckets);
  free(table);
}


int main(void) {
  CustomerTable* table = build_customer_table(4);

  FILE *infile = fopen("customers.tsv", "r");
  char buffer[81*4];
  while(fgets(buffer, 81 * 4, infile) != NULL) {
    add_customer_to_table(strtok(buffer, "\t"), strtok(NULL, "\t"), atoi(strtok(NULL, "\t")), strtok(NULL, "\n" ), table);

  }
  fclose(infile);

  while(true){
    char command[81];
    printf("Enter a command: ");
    scanf("%s", command);

    char email[81];
    char name[81];
    int shoe_size;
    char food[81];

    char temp0;
    char temp1;
    char temp2;

    if(strcmp(command, "add") == 0){
      printf("Enter email: ");
      scanf("%c",&temp0); // temp statement to clear buffer
	    scanf("%[^\n]",email);
      printf("Enter name: ");
	    scanf("%c",&temp1); // temp statement to clear buffer
	    scanf("%[^\n]",name);
      printf("Enter shoe size: ");
	    scanf("%d",&shoe_size);
      printf("Enter favorite food: ");
      scanf("%c",&temp2); // temp statement to clear buffer
	    scanf("%[^\n]",food);
      add_customer_to_table(email, name, shoe_size, food, table);
    }

    if(strcmp(command, "lookup") == 0){
      printf("Enter an email: ");
      scanf("%s", email);
      unsigned long hashbrown = hash(email);
      size_t bucketmhm = hashbrown % table->num_buckets;
      CustomerNode *cusussy = table->buckets[bucketmhm];

      while(cusussy){
        if(strcmp(email, cusussy->email) == 0){
          printf("Email: %s,\tName: %s,\tShoe Size: %d,\tFavorite Food: %s\n", cusussy->email, cusussy->name, cusussy->shoe_size, cusussy->fav_food);
          break;
        }
        cusussy = cusussy->next;
      }
    }

    if(strcmp(command, "delete") == 0){
      printf("Enter an email: ");
      scanf("%s", email);
      unsigned long hashbrown = hash(email);
      size_t bucketmhm = hashbrown % table->num_buckets;
      CustomerNode *cusussy = table->buckets[bucketmhm];
      CustomerNode *temp = NULL;
      bool yes = false;
      while(cusussy){
        if(strcmp(email, cusussy->email) == 0){
          yes = true;
          if(temp == NULL){
            table->buckets[bucketmhm] = cusussy->next;
          }
          else{
            temp->next = cusussy->next;
          }
          free(cusussy);        
        }
        temp = cusussy;
        cusussy = cusussy->next;
      }
      if(yes){
        printf("Deleted!\n");
      }
      else{
        printf("No user was found.\n");
      }
    }

    if(strcmp(command, "list") == 0){
      for(size_t i = 0; i < table->num_buckets; i++){
        CustomerNode *cusussy = table->buckets[i];
        while(cusussy){
        printf("Email: %s,\tName: %s,\tShoe Size: %d,\tFavorite Food: %s\n", cusussy->email, cusussy->name, cusussy->shoe_size, cusussy->fav_food);
        cusussy = cusussy->next;
        }
      }
    }

    if(strcmp(command, "save") == 0){
      FILE *infile = fopen("customers.tsv", "w");
      for(size_t i = 0; i < table->num_buckets; i++){
        CustomerNode *cusussy = table->buckets[i];
        while(cusussy){
        fprintf(infile, "%s\t%s\t%d\t%s\n", cusussy->email, cusussy->name, cusussy->shoe_size, cusussy->fav_food);
        cusussy = cusussy->next;
        }
      }
      fclose(infile);
    }

    if(strcmp(command, "quit") == 0){
      delete_table(table);
      printf("Exiting program\n");
      exit(0);
    }

  }
  return 0;
}

