Ramon Rovirosa
Problem 4.

Assume n programs of length l1, l2, · · · , ln are to be stored on a tape. Program i is to be
retrieved with frequency fi. If the program are stored in the order of i1, i2, · · · , in,
the expected retrieval time (ERT)

a. Show that storing programs in nondecreasing order of L(i) does not necessarily minimize ERT.

    Given the case where you have n=5 programs of increasing length:

    [f=2.5%,l=1][f=2.5%,l=2][f=2.5%,l=3][f=2.5%,l=4][f=90%,l=5]

    & you try to retrieve the program with length l=5 with f=90% frequency, and
    the other 4 frequencies for the programs add up to 10% (2.5% each)
    the expected retrieval time will be a lost larger than

    the case where you have the n programs sorted in non increasing order and
    choose the largest element length l=5 with 90% frequency, nd
    the other 4 frequencies for the programs add up to 10% (2.5% each)
    in which this would be the most optimal algorithm for minimizing ERT. Since the largest program,
    l=5 would always be chosen always & only first.

    [f=90%,n=1][f=2.5%,n=2][f=2.5%,n=3][f=2.5%,n=4][f=2.5%,n=5] ==> minimum ERT.


b. Show that storing programs in non-increasing order of fi does not necessarily minimize ERT.

    Given the case were you have all your programs retrieved with the same frequency (which is still non-increasing) but increasing length,
    were the largest program is at the end, this strategy would not necessarily minimize ERT.

    * all n programs have same frequency f = 1.
    * increasing length as you go through the tape.
    [f=20%,l=1][f=20%,l=2][f=20%,l=3][f=20%,l=4][f=20%,l=5]

    because the optimal runtime will be the strategy where the largest element is at the beginning of the list will have a more minimal ERT.

    [f=20%,l=5][f=20%,l=4][f=20%,l=3][f=20%,l=2][f=20%,l=1]

c. Show that storing programs in non-increasing order of fi/li does minimize ERT. Note: You can assume that the tape is long enough to hold all the programs.

    Given the greedy solution fi/li is represented by:
    Greedy solution fi/li:i1,i2,i3,...,ia,...,ib,...,in

    -Only differing in one pair of programs at position a & b,

    The retrieval time before & after ia-ib is the same.
    So we consider the retrieval time change between ia-ib
    Given that the ERT is minimized when f(i=a)/l(i=a) <= f(i=b)/l(i=b)

    Lets assume that we now swap the order of a&b and have b going before a:
    fi/li:i1,i2,i3,...,ib,...,ia,...,in
    Thus we now have that the ERT of: f(i=a)/l(i=a)>f(i=b)/l(i=b)
    But we see that the ERT of accessing a increases by l(i=b), & the ERT of accessing b decreases by l(i=a).
    Thus the total ERT between ia-ib is: l(i=b)f(i=b) - l(i=a)f(i=b).
    But this change is an improvement since: f(i=a)/l(i=a)>f(i=b)/l(i=b)
    Thus: l(i=b)f(i=b) - l(i=a)f(i=b) < 0.
    Which means that if two adjacent programs are out of order (b,a) instead of (a,b) based on the algorithm f/a,
    we can improve the ERT by simply swapping them to be in ERT order. 







