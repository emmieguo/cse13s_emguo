# hw2 Design doc

# next_collatz_number
In this function, I will have two if statements that will determine if the current number is even or odd. After each conditional the number will either be halfed or x3 + 1. Return the next collatz number.

# count_collatz_steps
This function will first return 0 if the input is 1. If now, create a while loop that makes sure it will repeat until the number has reached 1. In this while loop, I will call next_collatz_number and concatenate the value associated with the count. Return the count.

# maximum
This function will iterate through the array and compare the first element with the second, the largest one will be taken and from this point, the largest will be compared to the next one. Return the largest value.

# sum_positive
This function will iterate throught the given array. I will use a while loop to go through every element in the array and if the element is greater than 0, that current number will be added to the total sum. Return the total sum.

# count_negative
Like sum_positive, this function will iterate through the given array using a while loop that has the bounds of len. In the while loop, I will check if the current element is less than 0. If it is, one will be added to the count. Return count.