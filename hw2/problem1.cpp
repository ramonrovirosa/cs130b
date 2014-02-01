//problem 1
//Coin Change


//returns array: number_of[quarters,dimes,nickes,pennies]
int* coinChange(int change){
    //Quarter == $25
    //Dimes   == $10
    //Nickels == $5
    //Pennies == $1

    int numberCoins[4];


    while(change >= 25){
        numberCoins[0]++;
        change-=25;
    }
    while(change >= 10){
        numberCoins[1]++;
        change-=10;
    }
    while(change >= 5){
        numberCoins[2]++;
        change-=5;
    }
    while(change >= 1){
        numberCoins[0]++;
        change-=25;
    }
    return numberCoins;
}

The greedy algorithm for the coin change problem first gives the max number
of quarters possible, then the max number of dimes possible, and then the
max number of nickels and then pennies.

Since it is always true that if you have one coin of higher value e.g. a
quarter you need more than one coins of lower values, e.g. 2 dimes + 1 nickel to
make the same amount of change. The greedy algorithms makes sure that there are no
more than the necessary number of coins, and is therefore optimal. 

