//partA
//Merge arrays & then bubble sort
joinArrays(ArrayOfArrays) {
                int totalSize=0;
                for(int i=0;i<ArrayOfArrays.size;i++){
                         totalSize+=ArrayOfArrays[i].size;
                }
                int arraysMerged[totalSize]={};
                for(int i=0;i<ArrayOfArrays.size;i++){
                         arraysMerged.append(ArraysOfArrays[i]);
                }

                int size = arraysMerged.length;
                int temp = 0;
                int middle=size/2;
                int median;

                for(int i=0; i < size; i++){
                        for(int j=1; j < (size-i); j++){

                                if(arraysMerged[j-1] > arraysMerged[j]){
                                        //swap the elements!
                                        temp = intArray[j-1];
                                        arraysMerged[j-1] = arraysMerged[j];
                                        arraysMerged[j] = temp;
                                }

                        }
                }
                return arraysMerged;
}
Complexity: O(n^2)

//Part B
main(ArrayOfArrays){
    int totalSize=0;
    for(int i=0;i<ArrayOfArrays.size;i++){
             totalSize+=ArrayOfArrays[i].size;
    }
    int arraysMerged[totalSize]={};
    for(int i=0;i<ArrayOfArrays.size;i++){
             arraysMerged.append(ArraysOfArrays[i]);
    }
    mergeSort(arraysMerged);
}
static void mergeSort(int[] A) {
        if (A.length > 1) {
            int q = A.length/2;

            int[] leftArray = Arrays.copyOfRange(A, 0, q);
            int[] rightArray = Arrays.copyOfRange(A,q,A.length);

            mergeSort(leftArray);
            mergeSort(rightArray);

            merge(A,leftArray,rightArray);
        }
    }

static void merge(int[] a, int[] l, int[] r) {
    int totElem = l.length + r.length;
    //int[] a = new int[totElem];
    int i,li,ri;
    i = li = ri = 0;
    while ( i < totElem) {
        if ((li < l.length) && (ri<r.length)) {
            if (l[li] < r[ri]) {
                a[i] = l[li];
                i++;
                li++;
            }
            else {
                a[i] = r[ri];
                i++;
                ri++;
            }
        }
        else {
            if (li >= l.length) {
                while (ri < r.length) {
                    a[i] = r[ri];
                    i++;
                    ri++;
                }
            }
            if (ri >= r.length) {
                while (li < l.length) {
                    a[i] = l[li];
                    li++;
                    i++;
                }
            }
        }
    }
    //return a;

}

Complexity: O(n*log(n)*k)