// Time Complextiy - O(n)
// Space Complexity - O(n)

const memoizedFibonacci = (num, map = {}) => {
  //Fibonacci Terms start from 0
  if (num < 0) return "Invalid Input";

  //0th and 1st Fibonacci terms are 0 and 1 respectively
  if (num <= 1) return num;

  //Check map for stored terms and return it if it exists
  if (map[num]) return map[num];

  //Otherwise, calculate the fibonacci and store it in the map
  return (map[num] =
    memoizedFibonacci(num - 1, map) + memoizedFibonacci(num - 2, map));
};
