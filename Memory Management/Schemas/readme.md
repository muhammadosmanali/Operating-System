#Objective
To schedule the first fit, best fit and worst fit storage allocation algorithms 
for memory management

#Description
A set of holes of various sizes is scattered through the memory at any given time. 
when a process arrives and needs the memory, the system searches for a hole that 
is large enough for this process, the first fit, best fit and the worst fit are 
the strategies used to select a free hole from the set of available holes.

#First-Fit
Allocate the first hole that is big enough. Searching can start either at the 
beginning of the set of holes or where the previous first-fit search ended. 
We can stop searching as soon as we find a free hole that is large enough. 

#Best-Fit
Allocate the smallest hole that is big enough. We must search the entire list 
unless the list is kept ordered by size. The strategy produces the smallest 
leftover hole

#Worst-Fit
Allocate the biggest hole 

#Task
Write a program that asks the user the number of available blocks and their sizes. 
Then it asks the number of arriving processes and their sizes. Your program 
should result in allocating the memory block to the processes according to the
required memory management scheme in the lab.
