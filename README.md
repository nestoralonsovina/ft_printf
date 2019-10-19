<center> <h1> Libft </h1> </center>
<center> <h2> Personal C library </h2> </center>

This project is my personal library used at all the projects @42paris.

Some of the functions are based on the ones in the original *libc*, it's just our own implementation (We're just allowed to use a few basic functions per project).

### Some of the things to point out:
	 - Hash algorithm djb2 
	 - Basic data structures like:
		 - Queue
		 - Priority Queue
		 - AVL (Self balancing binary tree)
	 - Implementation of printf

### Basic usage

```make
make all
```
And on the top of your .c/.h file:
```c
#include "libft.h"
```
