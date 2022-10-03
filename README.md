# SC2001_Team 8

# Example Class 1: Implementing Hybrid Sort - A mix of Mergesort and Insert Sort

> Contributors: Rishabh_Alex, Kit Ye, Ngoc, Jia Wei

In Mergesort, when the sizes of subarrays are small, the overhead of many recursive
calls makes the algorithm inefficient. 

Therefore, in real use, we often combine Mergesort with Insertion Sort to come up with a hybrid sorting algorithm for better efficiency. The idea is to set a small integer S as a threshold for the size of subarrays.
Once the size of a subarray in a recursive call of Mergesort is less than or equal to S,
the algorithm will switch to Insertion Sort, which is efficient for small-sized input.

Presentation link: https://docs.google.com/presentation/d/1j8u_ie7UYgj7jgVX7oDw5L-rRS6GCL2t3fBm_k2BEus/edit?usp=sharing


## To navigate our repository, we have included a brief explaination of the important files.

> InsertSort.cpp: Our initial implementation of InsertSort and not-in-place MergeSort.


> mergesort.cpp: Our initial implementataion of in-place MergeSort.


> final.cpp: Our attempt at integrating MergeSort and InsertionSort, with the generation of random elements in arrays of variable lengths.



