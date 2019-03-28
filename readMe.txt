/////////////////////////////////////////////////////////////////////////////////////////////////////
*
*   AUTHOR : Rutvik Page
*   DATE OF CREATION : 24 / 01 / 2019
*   DESCRIPTION :  
*   This project contains 4 files, 3 '.c' files and 1 header files. This project basically implements the set data 
*   structure with the Hash Table implementation, using the  linear chaining method. Roughly, the time needed for the 
*   updation and the data retrieval is constant in the average case. In the worst case, it becomes O(n).
*
*   Following are the files used : 
*   1. main.c : Contains the call log of the functions, i.e. all the function calls are made here.
*   2. staticSet.c : Contains the hash table implementation of static set, which cannot be dynamically updated. 
*   3. dynamicSet.c : Contains the hash table implementation of dynamic set, which can be dynamically updated using 
*                     functions like add, subtract, etc. Special operations like union, intersection, is_subset and
*                     difference are also implemented here.