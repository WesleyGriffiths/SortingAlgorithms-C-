# SortingAlgorithms-C
This program utilizes the merge sort, insertion sort, and binary search algorithms.

The input file first takes 5 values. The first two being the user's coordinates on an x and y plane. The third being the number of "Shops". The 4th being the number of coordinates to check for shops, and the fifth representing the threshold for whether insertion sort or merge sort will be used.
The rest of the file will contain a list of coordinates.

Say the user wants to check for the closest clothing shop to their location. The input file would contain their location, all the nearby clothing shops, and coordinates to check for clothing shops.

The output file will first contain a the x y coordinates of the shops in a list organized with the shops closest to the user being on the top and furthest on the bottom. The rest of the file will contain whether shops were found at certain coordinates or not. Being either "x y found at rank R" (R being it's place on the list) or "x y not found"
