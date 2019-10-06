# SubsetSum-BacktrackAlgorithm
Solving the popular NP problem, The Subset Sum Problem, with a Amortized O(n) algorithm based on Recursive Backtracking. Literally takes 0.01sec to find sums 10000+ terms long!

Problem Statement : Find a set of N numbers from 1 to 1,000,000 that sum up to a random number X (1,000,000 < X < N×1,000,000).

The Algorithm stood second fastest in the organized Intra-University competition, and needs no extra storage space/buffers. Lost only to a Randomized Dynamic programming algorithm, which has a small chance of giving an invalid answer.

An Example run is as below, Number of terms to find N=10 and 100, takes zero time.

![alt text](https://raw.githubusercontent.com/parthnan/SubsetSum-BacktrackAlgorithm/master/test.png){:height="60%" width="60%"}

Number of terms to find N=10,000,000?? Now that's something! Takes under 3 seconds :

![alt text](https://raw.githubusercontent.com/parthnan/SubsetSum-BacktrackAlgorithm/master/tenmillion.png){:height="60%" width="60%"}

The graph of time taken vs number of terms N was linear, as below:

![alt text](https://raw.githubusercontent.com/parthnan/SubsetSum-BacktrackAlgorithm/master/timelinear.png)


