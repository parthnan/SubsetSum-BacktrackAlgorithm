# SubsetSum-BacktrackAlgorithm
Solving the popular NP problem, The Subset Sum Problem, with a Amortized O(n) algorithm based on Recursive Backtracking. Literally takes 0.01sec to find sums 10000+ terms long!

The Algorithm stood second fastest in the organized Intra-University competition, and needs no extra storage space/buffers. Lost only to a Randomized Dynamic programming algorithm, which has a small chance of giving an invalid answer.

# Problem Statement and algorithm
Problem Statement : From a set of N numbers from 1 to 1,000,000, find a subset that sums up to a random number X (1,000,000 < X < N×1,000,000).
Algorithm : We think of the N numbers sorted in descending order as a1,a2,a3,....an. Then, we do a Depth First Search on the following tree, looking for the set of a's that sum upto X. The DFS is then optimized using the mathematical properties a1>a2...>an.

![alt text](https://raw.githubusercontent.com/parthnan/SubsetSum-BacktrackAlgorithm/master/general.png)

# Results and Analysis
An Example run is as below, Number of terms to find N=10 and 100, takes zero time.

![alt text](https://raw.githubusercontent.com/parthnan/SubsetSum-BacktrackAlgorithm/master/test.png)

Number of terms to find N=10,000,000?? Now that's something! Takes under 3 seconds :

![alt text](https://raw.githubusercontent.com/parthnan/SubsetSum-BacktrackAlgorithm/master/tenmillion.png)

The graph of time taken vs number of terms N was linear, as below:

![alt text](https://raw.githubusercontent.com/parthnan/SubsetSum-BacktrackAlgorithm/master/timelinear.png)


