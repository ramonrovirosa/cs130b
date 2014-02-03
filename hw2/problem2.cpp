//problem 2
//matching dance couples

struct Dancer
{
    string gender;
    int height;
};

struct Pair{
    Dancer male;
    Dancer female;
};

Pair *danceCouples(Dancer dancers[]){

    //first sort all dancers based on height;
    //shortest to tallest;
    Dancer *sortedDancers=quickSort(dancers,height);

    Dancer maleDancers[];
    Dancer femaleDancers[];

    int j=0;
    int k=0;
    int l=0;

    for(i:0=>sortedDancers.length){
        if(sortedDancers[i].gender == "Male")
            maleDancers[j++] = sortedDancers[i];
        else
            femaleDancers[k++] = sortedDancers[i];
    }

    Pair matchedCouples[];

    //find the max, weather the max is males or females.
    int max = (j>k)?j:k;

    j=0;
    k=0;
    while(max>j || max>k){
        if( femaleDancers[k].height <= maleDancers[j].height + 3){
          matchedCouples[l].male = maleDancers[j++];
          matchedCouples[l++].female = femaleDancers[k++];
        }
        else if(femaleDancers[k].height > maleDancers[j].height )
            j++; //move on to next male
        else
            k++; //no match move on to next female

    }

    return matchedCouples;

}

//Complexity
Quicksort: O(n*log(n))
Split array into male & female: O(n)
Pair  dance couples: O(n)

Overall Complexity:
T(n) = O(n*log(n)) + O(n) + O(n)

Complexity: O(n*log(n))


Optimal Solution: Yes

The algorithm involves first sorting the men & women by height shortest to tallest.
Then the idea is to match the couples beginning with the two shortest in the group and moving
along to the tallest pairs.

By sorting the couples first & then matching them in order, we find that all couples within the expected
range are matched. This gives us an optimal number of pair matches between couples.