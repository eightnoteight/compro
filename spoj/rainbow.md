#3724. Rainbow Ride
-----------------------------------------------------------------------------

## methods of solving
- Depth-First Search
- Union-Find

## Union - Find method
1. union the family members pair if any of the pair likes the other,
2. accumulate the weights of all children and store in the root
3. add roots into a set
4. prepare a list containing the weights of roots from the rootset
5. now add as many elements as you can from the list
    >> complexity
    1. linear
    2. k * n
    3. k * n
    4. n
    5. n