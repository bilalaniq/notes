// -------------------------------------two crystal ball problem----------------------------------
/*
You are given a building with 𝑁 floors and two crystal balls. The objective is to determine the highest floor from which you can
drop a ball without breaking it, using the minimum number of drops in the worst-case scenario.


Key Constraints:
You have 2 balls.
You have N floors.
A ball will break if dropped from a certain floor, and if it does not break, it can be reused.
You want to find the highest floor from which the ball can be dropped without breaking it, with a minimum number of drops.



let discous our opsions
linear search
binary search

if we generalize our problem what is our problem
lets say that we have an 100 story building and from each floor we drop the 2 crystl balls but we need to find the the lowest floor at
which the two crystal balls break
so we can reprensent the whole building with an array
and each floor by an bool false if no crystal ball break otherwise true

building [f,f,f,f................f,t,t,t,t....]
                                  ^
                                  |
                             so we have to find where is this mid point from where the crystal ball breaks
                             in the best optimized way possible

now you have understand the problem now lets see how can we solve this
now we have only learned about linear search binary search

--------------------------------Linear search
so we have to iterating over the array to find at which index there is true but what if the crystal balls break at the 100th floor we than
need to traverse through all the array that will cause the time complexity of this algoritham to be big-O(n) or linear
which is not good

-------------------------------binary search
as we know that binary search only work on sorted array but we are smart and know that this array is sorted
building [0,0,0,0,................0,1,1,1,1....]

now we can simply go to the middle and just see if it is true or 1 if yes than that mean that one of the crystal has broke but
we have two crystal ball how to see that
lets take an example we have 10 floors

building [0,0,0,1,1,1,1,1,1,1];
                  ^
                  |
            this is the middle of the array and it is 1 if it is 1 than that mean that one crystall ball has broke so we will
            have to cheak if that if the other crystal ball has not broken before so we also need to linearlly transverse over all the
            floors to see where was the fist floor that cause the balls to break

Binary search works best on sorted data and is ideal for scenarios where you only have one ball. However, with
two balls, you cannot perform a simple binary search because if the first ball breaks at a mid-point, you'd have no way of
determining which floor is the exact threshold. You'd need to perform a linear search on the lower floors after the first
ball breaks, which may lead to more drops than necessary.

building [0,0,0,1,1,1,1,1,1,1];
         ^       ^
         |       |
         |_______|
             |
         you need to perform the linear search here when using binary search which will cause the time complexity to become
         big-O(1/2n)
         where the constants are ignored which cause the algoritham to have time complexity of big-O(n)
         which is not good


so lets talk about the best approch to overcome this problem in the most optimized way

---------------------------------------The Optimized Approach (Best Search)----------------------
The optimized approach to solve this problem would be to jump in a way that we have to jump some porsion on n floors
we have to jump by some fundamantal different unit of floors

in binary search we jump by half of the array but in this case we have to jump by some different unit of floors

so here it what i proopose that we jump by an propsion of sqrt(n) floors

so that mean that we would have to jump sqrt(n) floors until it breaks
and if it breaks we would have to jump sqrt(n) floors back to the last good point and see within those sqrt(n) floors where the
crystal ball breaks



building [0,0,0,1,1,1,1,1,1,1];
         ^    ^^    ^
         |    ||    |
         |____||____|
            |     |
      sqrt(n)    sqrt(n)

so we have to jump sqrt(n) floors and if it breaks we have to jump sqrt(n) floors back and see where the crystal ball breaks
this is the most optimized way to solve this problem

so when we find where the ball breaks we can simply jump by sqrt(n) floor and see where the crystal ball breaks
this will cause the time complexity of this algoritham to be big-O(sqrt(n))

because we have to do an sqrt(n) jumps of the board and than jump back sqrt(n) floors back to the last point

so sqrt(n) + sqrt(n) = 2sqrt(n) = sqrt(n)
which is the time complexity of this algoritham becaue the constants are ignored



 which is the most optimized way to solve this problem

*/
// lets solve this problem in c++

#include <iostream>

int function(int *arr, int n)
{
    int jump = sqrt(n);

    int i = jump;
    for (; i < n; i += jump)
    {
        if (arr[i])
        {
            break;
        }
    }

    i -= jump;
    for (int j = 0; j < jump && i < n; j++, i++)
    {
        if(arr[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    const int n = 20;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        if (i < 10)
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = 1;
        }
    }

    std::cout << function(arr, n) << std::endl;  //this will print 10

    return 0;
}

/*
 Jump Search (also known as Square Root Search) and is a hybrid approach that effectively combines both linear search and optimization
via jumping (sqrt(n) increments). It is neither purely linear nor binary search, but rather an efficient compromise, and it's one of 
the best ways to solve the two crystal balls problem with O(√n) complexity.
*/