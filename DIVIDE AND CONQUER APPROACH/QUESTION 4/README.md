Ahmed is running a shoe shop. One day a bulk quantity of sports shoes came to his store. 

He was told that the pack contains one pair of shoe for each size. But the dealer also told that one random shoe fell 
down while travelling. 

Now the task is that to find the size of the shoe which fell down. He wantd to find this very fast so 
write a code that finds the missing shoe in O(log n)

( hint ) 

Since the pair of all the shoes expect one are available, the size will have exactly two shoes for all those sizes and only one shoe for the size of the shoe that fell down.

**Input:** An array of all shoes available represented by their sizes sorted in non descending order. 

**( A number will occur not more than 2 times in the array)**

**output:** The size of the shoe which fell down

<hr>


> **INPUT**                 :     [ 1, 1, 2, 2, 5, 8, 8, 9, 9]



> **OUTPUT**             :     5

**EXPLAINATION**  :     There are two shoes for sizes 1,2,8 and 9 but only one shoe for size 5, so the other shoe has fell down.
> 


> **INPUT**                 :     [ 2, 2, 4, 4, 9, 9, 10, 10, 11]

> **OUTPUT**             :     11

**EXPLAINATION**  :     There are two shoes for sizes 2,4,9 and 10 but only one shoe for size 11, so the other shoe has fell down.
>
