This program is designed to read the input file listings.csv and implement two new functions to sort the data based on the host_name and price columns. The program performs the following steps:

Compile the Program:

bash
Copy code
gcc listingsreader.c -o listingsreader
Execute the Program:

bash
Copy code
./listingsreader
Steps Implemented:

Exercise #2, Steps 1 to 6 from the Workbook are implemented.
Sorting Algorithm:

Any sorting algorithm can be used to sort by the keys host_name and price separately.
The program utilizes the qsort function provided by the C library for sorting.
Sorting Process:

When sorting by a particular attribute, the program rearranges the entire structure based on that attribute. For example, sorting the whole list by host_name involves changing the order of structures based on host_name.
Output:

The sorted structure is written to new files created in write mode.
The program loops through the new structure and uses fputs or similar functions to write the sorted structure to the new file.
Closing Files:

It's crucial to remember to close the files when the sorting process is completed.
File Structure
listingsreader.c: The main C program file containing the implementation of the sorting functions.
listings.csv: Input file containing the listings data.
sorted_by_host_name.csv: Output file containing the listings sorted by host name.
sorted_by_price.csv: Output file containing the listings sorted by price.
Usage Notes
Ensure that the input file listings.csv is present in the same directory as the executable.
The program will create two new output files: sorted_by_host_name.csv and sorted_by_price.csv.