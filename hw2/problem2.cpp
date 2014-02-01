//Ramon Rovirosa
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