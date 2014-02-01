//Ramon Rovirosa
//problem 3
//N intervals on the X axis.else

Greedy strategy interval selection technique:

1. their starting x locations (smaller ones first)

    No. Will not generate optimal results.

    Given the (x_start, x_end) list:
    { (0,100), (10,20), (30,40) , (70,90)  }

    1. XXXXXXXXXXXXXXXXXXXXXXXXXX
    2. XXX 3. XXXXX 4.XXXX 5.XXXX

    This strategy of selecting intervals would return 1 (the first) interval that overlaps
    all the other intervals, when we know that the optimal result would involve returning
    the 3 intervals: (10,20), (30,40) , (70,90)



2. their end x locations (smaller ones first)

    Yes, will generate optimal results.

    If you have 1 interval that overlaps 2 intervals in the same region it will pick the
    two intervals since they the 1st of two interval will finish before the one overlapping interval.


3. their lengths (shorter ones first).

    No. Will not generate the optimal results.

    Given the (x_start, x_end) list:
    { (0,50), (45,55), (50,100)  }

    1.XXXXXXXXX  2.XXXXXXXXX
            3.XXXXX

    This algorithm would pick the interval (45,55) first and return 1 total interval,
    were the optimal solution would be to pick the two largest intervals first instead of the
    3rd smallest one.

    So in the case were a smaller interval overlaps two larger intervals, then this algorithm would not be optimal.

4. the number of other intervals that they overlap with (fewer overlaps first)

    Yes, will generate optimal results.

    Because, intervals with less overlaps will naturally be picked before intervals that overlap them.