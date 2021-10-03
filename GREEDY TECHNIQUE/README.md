# What is a 'Greedy algorithm'? :moneybag:

> A greedy algorithm, as the name suggests, always makes the choice that seems to be the best at that moment. This means that it makes a locally-optimal choice in the hope that this choice will lead to a globally-optimal solution.

<hr>

![image](https://user-images.githubusercontent.com/77975418/135317059-5432489a-6b54-44bb-b028-d0c72fa365d9.png)

<hr>

# :thinking:How do you decide which choice is optimal?

> Assume that you have an objective function that needs to be optimized (either maximized or minimized) at a given point. A Greedy algorithm makes greedy choices at each step to ensure that the objective function is optimized. The Greedy algorithm has only one shot to compute the optimal solution so that it never goes back and reverses the decision.

<hr>

# :pencil:How to create a Greedy Algorithm?

> Being a very busy person, you have exactly T time to do some interesting things and you want to do maximum such things.
You are given an array A of integers, where each element indicates the time a thing takes for completion. You want to calculate the maximum number of things that you can do in the limited time that you have.


This is a simple Greedy-algorithm problem. In each iteration, you have to greedily select the things which will take the minimum amount of time to complete while maintaining two variables currentTime and numberOfThings. To complete the calculation, you must:

:arrow_right: Sort the array A in a non-decreasing order.

:arrow_right: Select each to-do item one-by-one.

:arrow_right: Add the time that it will take to complete that to-do item into currentTime.

:arrow_right: Add one to numberOfThings.

:arrow_right: Repeat this as long as the currentTime is less than or equal to T.

:arrow_right: Let A = {5, 3, 4, 2, 1} and T = 6

:arrow_right: After sorting, A = {1, 2, 3, 4, 5}

:arrow_right: After the 1st iteration:

 :black_circle: currentTime = 1

:black_circle: numberOfThings = 1

:arrow_right:After the 2nd iteration:

 :black_circle: currentTime is 1 + 2 = 3

 :black_circle: numberOfThings = 2

:arrow_right: After the 3rd iteration:

 :black_circle: currentTime is 3 + 3 = 6

 :black_circle: numberOfThings = 3

:arrow_right: After the 4th iteration, currentTime is 6 + 4 = 10, which is greater than T. Therefore, the answer is 3.

<hr>

# :computer:Implementation

    #include <iostream>
    #include <algorithm>

    using namespace std;
    const int MAX = 105;
    int A[MAX];

    int main()
    {
        int T, N, numberOfThings = 0, currentTime = 0;
        cin >> N >> T;
        for(int i = 0;i < N;++i)
            cin >> A[i];
        sort(A, A + N);
        for(int i = 0;i < N;++i)
        {
            currentTime += A[i];
            if(currentTime > T)
                break;
            numberOfThings++;
        }
        cout << numberOfThings << endl;
        return 0;
    }

<hr>

<h2> For better Illustration on Greedy Approach refer the 
 
[Solved Examples](https://github.com/ISTE-VIT/The-Algo-Companion/tree/main/GREEDY%20TECHNIQUE/SOLVED%20EXAMPLES) </h2>

<hr>

        
[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?v=102)](https://hacktoberfest.digitalocean.com/)&nbsp;
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)]()&nbsp;


<hr>


<h1><p align="center">HAPPY CODING :money_mouth_face:	</p></h1>

