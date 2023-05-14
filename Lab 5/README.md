# DSA-In-Class-Lab-5

Question 1:

  * Compare the time taken for recursive vs. non-recursive algorithms of quick sort.


Question 2:
  
  * The median of a set of integers is the midpoint value of the data set for which an equal number
    of integers are less than and greater than the value. To find the median, you must first sort your
    set of integers in non-decreasing order, then:
    
      * If your set contains an odd number of elements, the median is the middle element of
        the sorted sample. In the sorted set {1, 2, 3}, 2 is the median.
      * If your set contains an even number of elements, the median is the average of the two
        middle elements of the sorted sample. In the sorted set {1, 2, 3, 4}, (2+3)/2=2.5 is the
      median.
      
  * Given an input stream of n integers, perform the following task for each ith integer:
      * Add the ith integer to a running list of integers.
      * Find the median of the updated list (i.e., for the first element through the ith element).
      * Print the updated median on a new line. The printed value must be a double-precision
        number scaled to 1 decimal place (i.e., 12.3 format).

  * Example:
      * Input: a = [7, 3,5, 2]
      * Output:
                7.0, 
                5.0, 
                5.0, 
                4.0
