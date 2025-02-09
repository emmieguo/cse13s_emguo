# Design Doc hw3

# str_suffix
Since this function returns either true or false, we should use strcmp to compare needle and then the char that is composed of the last few characters of haystack which is determined by the length of needle. Pseudocode to get that char is:

haystack + (strlen(haystack) - strlen(needle))

Then from this, if the to chars are the same, strcmp of the two would be zero. So, if the strcmp is zero, return true. Else, return false.

# dot_product
This function returns the dot product of two matrices. In C, these matrices are defined as arrays. To do this, we should sum the products of the pairs in the array. These pairs are defined as elements in the array with the same position in their respected array. Pseudocode for this function would be:

while(int i = 0; i < len; i++)

{

    product = a[i] + b[i];
    sum = sum + product;

}

return sum;

# reduce
Reduce is similar to map but instead of int (*funk)(int), we are given int (*f)(int,int). This means that we will return the inital with two function parameters. You need to iterate through all values in the list. You can do this by:

for(int i = 0; i < length; i++)

  {

    initial = f(initial, nums[i]);

  }

  return(initial);

# maximum_with_reduce
This function returns the maximum function of the list in one line. How this is achieved is by the use of a helper function. This helper function will find the max of the current two values from the list. How this is possible is from calling reduce since this function iterates through the whole list. How you can return the max is:

return reduce(nums, length, helper_function, nums[0]);

In which the helper_function compare if either initial or nums[i] is greater and return the greater value.

# sum_positive_with_reduce
Very simmilar to the last function where we would need both the use of a helper function and reduce to complete. Since we need to return the sum of all the positive numbers in the list, we must compare two elements at a time (using the reduce function). This comparison will be done in the helper function because sum_positive_with_reduce should only be one line. This is possible by:

return reduce(nums, length, helper_function, nums[0]);

In which the helper_function will compare to see if initial and nums[i] are greater than zero. The positive values will be summed and returned.