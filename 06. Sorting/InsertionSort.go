package main

import "fmt"

func main() {
   
    arr := []int{3, -2, 2, 6, 5, 4, -1, 7, -3}

	fmt.Println("Before sorting")
	for _, val := range(arr) {
		fmt.Printf("%v ", val)
	}

    insertionSort(arr)
}

func insertionSort(arr []int) {
    len := len(arr)
    for i := 1; i < len; i++ {
        for j := 0; j < i; j++ {
            if arr[j] > arr[i] {
                arr[j], arr[i] = arr[i], arr[j]
            }
        }
    }
    
    fmt.Printf("\nAfter Sorting\n")
    for _, val := range arr {
        fmt.Printf("%v ", val)
    }
}
