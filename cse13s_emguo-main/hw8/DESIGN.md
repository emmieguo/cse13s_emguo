# Design Doc Homework 8

# What we know about a customer
Every customer in our database has an email address (a string), a name (a string), a shoe size (an integer) and a favorite food (a string).
How should we keep this information? How do you store structured information like this in C, usually?
Create a struct called customer and add the elements for email_address, name, shoe_size, and favorite food.

    typedef struct Customer {
      char *email_address;
      char *name;
      int shoe_size;
      char *favorie_food
      struct Customer *next;
    } Customer;

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



# the main interaction loop
When the program loads up, it will read customers.tsv and store all the customers in the hash table. Then, it will repeatedly prompt the user for a command. The commands you should support are as follows. --> for this, we would use scanf() in order to read the tab separated values

# add
if the user types add, the program will additionally prompt the user for an email address, a display name, a shoe size, and a favorite food. This user (with their associated data) will then be added to the hash table. If that email address is already present in the hash table, then replace the data that was already in the hash table with the new entry.

    Customer *add_customer_to_list(char *email_address, char *name, int shoe_size, char *favorite_food, Customer *bucket) {
      Customer* new_customer;

      new_customer = calloc(1, sizeof(FriendNode));
      new_customer->email_address = strdup(email_address);
      new_customer->name = strdup(name);
      new_customer->fav_food = strdup(favorite_food);
      new_customer->shoe_size = 20;
      new_customer->next = bucket;

      return new_customer;
    }


    void add_customer_to_table(char *email_address, char *name, int shoe_size, char *favorite_food, CustomerTable *table) {
      unsigned long hashvalue = hash(name);
      size_t which_bucket = hashvalue % table->num_buckets;

      Customer *linkedlist = table->buckets[which_bucket];
      table->buckets[which_bucket] = add_customer_to_list(email_address, name, shoe_size, favorite_food, linkedlist);
      return;
    }

# lookup
prompt the user for an email address, then go find that entry in the hash table! If the specified customer is not found (nobody has that email address) then display a nice message that the customer was not found. Then display all the information we have about that user in a nicely formatted way.

We would want to use fgets() to get the string which is the email address.

    Customer *lookup(char *email_address){
      int index = fgets();
      if(hash_table[index] != NULL){
        return hash_table[index];
      }
      printf("customer was not found");
      return NULL;
    }

# delete
prompt the user for an email address, then go find that entry in the hash table (and delete it from the linked list in the bucket). Again, if the specified customer is not found (nobody has that email address) then display a nice message that the customer was not found.

    void delete(char *email_address, Customer *linkedlist) {
      if (!linkedlist) {
        print("email doesnt exist");
      } else if (!strcmp(email_address, linkedlist->email_address)) {
        Customer *next = linkedlist->next;
        free(linkedlist->email_address);
        free(linkedlist);
      }
    }

# list
display every user in the database, in whatever order is convenient. Format each user the same way we do in lookup.
Is display the same as print?
if so, print the users in the database. "list" them out

# save
write the current state of the database back to customers.tsv
What does it mean by write the current state of the database back to customers.tsv?
We can use fgets(), strtok(), calloc(), malloc(), and perhaps override the information on the tsv file with the information in the hash table

# quit
clean up all of our memory and exit the program.
free all memory that was allocated using calloc and malloc.

