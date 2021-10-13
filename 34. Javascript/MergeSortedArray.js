//Time Complexity - O(m+n) where m = Array1 Length and n = Array2 Length
//Space Complexity - O(m+n)

const mergeSortedArray = (arr1, arr2) => {
  //Initialize pointers for both arrays
  let pointer1 = 0,
    pointer2 = 0;
  //Store results in this array
  let result = [];

  //Loop through both arrays
  while (pointer1 < arr1.length || pointer2 < arr2.length) {
    //If we are still within bounds of both arrays,
    //Push the lower value into the result array
    if (pointer1 < arr1.length && pointer2 < arr2.length) {
      let arr1Value = arr1[pointer1];
      let arr2Value = arr2[pointer2];
      if (arr1Value < arr2Value) {
        result.push(arr1Value);
        pointer1++;
      } else {
        result.push(arr2Value);
        pointer2++;
      }
    } else {
      //If one of the arrays are out of bounds,
      //Push all values left in the other array into the result array
      if (pointer1 < arr1.length) {
        result.push(arr1[pointer1]);
        pointer1++;
      }
      if (pointer2 < arr2.length) {
        result.push(arr2[pointer2]);
        pointer2++;
      }
    }
  }
  return result;
};

const first = [1, 4, 5, 7, 8, 9, 12, 15];

const second = [2, 4, 7, 13, 23, 45, 67];

console.log(mergeSortedArray(first, second));
