////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*
*	AUTHOR : Rutvik Page
*	DATE OF CREATION : 21 / 01 / 2019
*	FILE DESCRIPTION : 
*   1. main.c : Contains the function calls to different functions in the project. This is just the caller.   
*   
*   2. utility.h : Contains the prototype decalrations, #include/s and #define/s used in the file. Also, it includes the 
*                  Node struct which has typically been used as the node.
*   3. staticSet.c : Contains all the functions required for the implementation of the static set data structure. 
*                   
*   4. dynamicSet.c : Contains all the functions required for the implementation of the dynamic set data structure.
*
*   5. specOps.c : Contains all the special operations defined on the data structure like union, intersection, difference,
*                   and subset check.
*   
*   6. makefile : Contains the commpilation commands of the whole project, such that, typing "make" compiles all the files.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DUE care has been taken care such that, none of the functions of the file staticSet.c uses the functions of the file
dynamicSet.c.

Some utility functions have also been defined in the file main.c which are used to examine the return values of the
functions called in the main function. These methods are : 
1. min(a, b) : returns the minimum value off a and b.
2. verify(a) : prints "Yes" if 'a' is true, else prints false.