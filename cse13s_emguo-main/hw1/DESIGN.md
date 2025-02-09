# Design Doc

area_of_disk: Since the formula for the area of a disk is A = Pi * r2, I will be coding Pi, M_PI in C, multiplied by the argument radius * radius.

area_of_ring: The area of a ring would be the area of the entire disk, minus the area of the inner disk, the hole. Use the same logic from area_of_disk function.

bigger_minus_smaller: Use an if statement to compare these arguments. If a is less than b, return b - a. If b is less than a, return a - b.

value_in_range: Use an if statement. If specific value is less than upper bound AND greater than lower bound, return True; otherwise, return False.

caat.c: Read user input through a while loop. Check if each char is aeiouAEIOU (use OR). IF it is, putchar() it twice. If not, putchar() it once and go to the next.