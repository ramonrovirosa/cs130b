//Problem 2 You are given an array A containing n integers with no duplication. The integers are sorted, but not
//necessarily sequential (or consecutive). You want to ﬁnd out if there exists an index i for which A[i] = i. For example,
//if A = [-17; -3; 1; 4; 6; 20], then A[4] = 4 (assuming 1-based indexing). Give a divide-and-conquer algorithm that runs
//in time O(logn).

IndexEqualsValue(Array[], low, high) {
    //highest value and lowest values in array
    if (high < low)
        return -1 // not found
    midIndex = midValue(low,high);
    //if index is greater than value at position
    //search on the RIGHT side of the array for the value
    if (midIndex > Array[midIndex])
      return IndexEqualsValue(Array, midIndex+1, high)
    //if index is greater than value at position
    //search on the LEFT side of the array for the value
    else if (midIndex < Array[midIndex])
         return IndexEqualsValue(Array, low, midIndex-1)
    else{
       printf("Index matches value for index: %d == value: %d\n",midIndex,Array[midIndex]); // found!
       return;
    }
}