# :computer:CODE + PICTORIAL REPRESENTATION:framed_picture:

<h2>:one:BINARY EXPONENTIATION </h2>

- When we are asked to find the powers of a particular number the normal (or naïve) way to do it will be to multiply the same number ‘n-1’ times. 

- As an Example, to find 3 to the power of 3, 3 will be multiplied with 3, twice. Although our computer is meticulously fast and can-do 10^8 operations per second. This way of finding the exponential becomes a problem, for numbers of higher magnitude. 
- For instance, let’s say that your program needs to do 112^10 multiplication, hundred times to produce some result. So, your program needs to multiply 112 to itself 900 times. A program which takes lesser number of times to produce the same result would be considered as a better program, hence we must arrive with an algorithm that reduces the number of multiplications. 
- How about we arrive at an algorithm that only takes 600 times and thereby reducing the number of operations by 30%.


<br>

<h3>This amazing method is called Binary Exponentiation.<h3>

<hr>

![BIN EXPONENTIATION](https://user-images.githubusercontent.com/77975418/135484764-12d37a01-f7ae-49e5-a8a3-18e6d0a35767.jpg)

<hr>

> - We use the fact that any number can be represented as their sum of powers of two. The powers of Two’s also have an interesting property where if you want to find the exponential of say 2^8 all you need to do is to find 2^4 and multiply by it by 2. 

> - By doing this innocent trick, we reduce the number of times ‘2’ has to be repeatedly multiplied from 7 to 5, but wait! 2^4 can again be figured out by finding 2^2 and then multiplying it by 2. Therefore, we reduced the number of total multiplications from 8 to 3 thereby decreasing the time it takes to get to the same result.

```

2^8 = 2^4 * 2		---	3

2^4 = 2^2 * 2		---	2

2^2 = 2 * 2		---	1

```

> - But what if we have 2^9 instead of 2^8, if that’s the case then all you need to do is to figure out 2^8 and then multiply a 2. Thereby reducing the number of multiplications from 8 to a mere 4



> - But how does this come under a divide and conquer strategy? Well, think about our explanation about divide and conquer, If the problem is too big to solve [eg, 2^8], then the problem should be broken down to manageable sub-problems [2^4 or 2^2] and then we would reconstruct or combine the answer we got from the sub-problems [4 or 16], which’ll provide the answer to the bigger problem [256].

The general form of our Recursive Divide and Conquer looks like this,
 
Where at each step we’ll divide the number and call the function again until we get to a point where n becomes 1, where we return the same number or we can go till n becomes 0 where we’ll return 1 as any number with an exponent 0 will give you 1

<hr>

<h2> :two:MAX ELEMENT IN AN ARRAY </h2>

> Moving from binary exponentiation we face another intriguing problem which is to find the maximum element in an array. 
> While it may sound simple and you even might be thinking of a solution that would work! this simple problem stands the base for many other fascinating problems that you’ll solve in your coding journey.

![MAX ELEMENT](https://user-images.githubusercontent.com/77975418/135484771-1e7cf2f2-332e-4796-b544-ca8cddc11bb8.jpg)

<hr>


> But first, why does finding a max element come under divide and conquer? 

> - Carrying over from our previous examples, we know that if we’re not able to figure out the solution on one go, we try to divide the problem to solve it, so to find the max element of a ‘n’ sized array we try to get the max element for ‘n/2’ sized array. 

> - Are we able to solve it now? No? Let’s try to divide it once more! ‘n/4’ well it’s not that easy, we keep on dividing the size until we reach to a position where we can just say the max element easily, and that is when we have only two elements! Why? 

> -  Well if you have two elements then you can say one is higher than the other! so finally, we got an answer to a problem, Now, we pass that answer to the previous arrangement containing 4 elements, now, One Max Element from the elements at position 1 and 2 and One Max Element from the elements at the position 3 and 4 will be compared, by this way, we’ll figure out the maximum element for 4 elements, we’ll do the same thing over and over again until we reach the top, that is n elements. 

> This problem serves as a prologue to a marvelous concept called as a recursion tree where we call the function twice instead of once inside the same function block, there by generating a beautiful abstract tree like structure that consists of two branches at every node. 

<hr>

<h1><p align="center"> HAPPY CODING :man_technologist:	</p></h1>
