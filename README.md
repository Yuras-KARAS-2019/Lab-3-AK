# Lab-3-AK

### Displays syntax of command and useful information
--help (-h)


### Create list by entered numbers
--create (-i)

### Arguments
**$1** (list<number>): The input list.

### Execute create operations
  -i1,2,3  
  --create=1,2,3

### Execute sum operations(sum all elements if *n was not added)
  --sum (-s) 

### Arguments  
**$1** (int): n (optional).

### Example  
--create=1,2,3 --sum  
--create=1,2,3 -s2

### Counting the number of items in the list.
  --count (-c)

### Example

--i1,2,3,4,5 -c

### Reversing order of all members in the list.  
  --reverse (-r)

### Example
-i1,2,3,4,5 -r
