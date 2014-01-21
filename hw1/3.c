//part A
//Buble sort
medianUnsortedA(intArray) {

                int size = intArray.length;
                int temp = 0;
                int middle=size/2;
                int median;

                for(int i=0; i < size; i++){
                        for(int j=1; j < (size-i); j++){

                                if(intArray[j-1] > intArray[j]){
                                        //swap the elements!
                                        temp = intArray[j-1];
                                        intArray[j-1] = intArray[j];
                                        intArray[j] = temp;
                                }

                        }
                }
                median = intArray[middle];
                return median;

}

Complexity: O(n^2)

//part B
//Quicksort

medianUnsortedB(Array, left, right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      int middle= Array.length/2;

      /* partition */
      while (i <= j) {
            while (Array[i] < pivot)
                  i++;
            while (Array[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = Array[i];
                  Array[i] = Array[j];
                  Array[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            medianUnsortedB(Array, left, j);
      if (i < right)
            medianUnsortedB(Array, i, right);

      median = intArray[middle];
      return median;
}

Complexity:
O(n*log(n))~average case
O(n^2)~worst case
