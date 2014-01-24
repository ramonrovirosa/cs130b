Ramon Rovirosa
CS130B
Program 1

a)
    For the brute force algorithm for comparing the minimum distance between a set of points,
    my algorithm was based on wikipedias description of the closest pair of points problem.

    http://en.wikipedia.org/wiki/Closest_pair_of_points_problem

    Array P[]
    minDist = infinity
    for i = 1 to sizeOfYourArray - 1
        for j = i + 1 to sizeOfYourArray
            let p = P[i], q = P[j]
            if distance(p, q) < minDistance:
                minDistance = distance(p, q)
                closestPair = (p, q)
    return closestPair

    Complexity:
    A simple analysis of the algorithm shows us that this algorithm contains
    a for loop nested inside of another for loop which is Quadratic: O(n^2)

    b)

        For the Divide & Conquer implementation, the first thing I did was sort the numbered pairs,
        that were represented by an Xarray & Y array in order starting from the smallest x value
        until the largest x value. For this I used a quicksort algorithm with time complexity O(n*log(n))

        My algorithm next calls the execution loop:

        ClosestPairDivideConquer(int totalNumberOfPoints, ArrayXY )
            if totalNumberOfPoints <= 3
                ClosestPairBruteForce
            else
                splitArrayInHalf(left,right)

                maxDistanceLeft =ClosestPairDivideConquer(totalNumberOfPoints/2, leftHalf)
                maxDistanceRight=ClosestPairDivideConquer(totalNumberOfPoints/2, rightHalf)

                minimumDistance = minimum(maxDistanceLeft,maxDistanceRight)

                Strip[totalNumberOfPoints]
                j=0
                for i=0:totalNumberOfPoints
                    if absoluteValue(ArrayXY.x - midPoint.x) < minimumDistanced
                        Strip[j] = point[i], j++
                }

                quickSort(strip)

                for i=0; i<j; ++i
                    for  k = i+1; k < j && (strip[k].y - strip[i].y) < minimumDistance; ++k)
                        compare = distance(strip[i],strip[k]);
                        if (  compare < minimumDistance){
                            minimumDistance = distance(strip[i], strip[k]);
                        }
                    }
                }



        The first part of the algorithm involves splitting the array in half, giving you the
        left half and the right half, which takes linear time O(n).

        The next step involves recursively calling the function to find the minimum distance of the
        set of 2,3 points as the original array is split up into smaller arrays.
        The complexity is the same as quicksort, O(n*log(n)).

        Next we have to find any points relative to the midpoint that have a smaller minDistance then
        the left & right points. This involves creating a strip with all the points that touch the midpoint
        and have a smaller distance then the minDistance. This is linear time O(n).

        Next we re-sort the middle strip of elements that we just calculated, using the quicksort algorithm.
        Time complexity is again: O(n*log(n)).

        Finally once we have calculated the xPoints, we next compare the points based on the y cordinates,
        to find all the y cordinates that are less than the minimumDistance. At first look this operation
        seems quadratic but a further analysis shows that this loop runs at most 6 times, making it constant time.

        http://people.csail.mit.edu/indyk/6.838-old/handouts/lec17.pdf
        Slide 7-8.

        Finally the Time analys gives us:

        T(n) = O(n) + O(n*log(n)) + O(n) + O(n*log(n)) + 0(1)
        T(n) = O(n*log(n))

        Complexity: O(n*log(n))



        K Analysis

            Input Size      k           k'
            10              45          11
            300             44850       300
            900             404550      910
            2000            1999000     1837
            20000           199990000   21959




