# :1234: Achilles Numbers

Project 1 for the course "Introduction to Programming" in Semester 1 @ University of Athens.  
This project is about checking (consecutive or random generated) numbers and finds which of them are Achilles Numbers.  
Reference for Achilles Numbers: https://en.wikipedia.org/wiki/Achilles_number.   
Optimizations have been made in order to reduce the processing time of the algorithm.  
The time for checking 10<sup>7</sup> numbers was downed, from ~110 secs (with a very plain algorithm), to under 20 secs.


Here is an example of running the program for the first 1000 numbers:

```bash

$ ./achilles
       72 is achilles number
       108 is achilles number
       200 is achilles number
       288 is achilles number
       392 is achilles number
       432 is achilles number
       500 is achilles number
       648 is achilles number
       675 is achilles number
       800 is achilles number
       864 is achilles number
       968 is achilles number
       972 is achilles number

Found 13 achilles numbers up to 1000
$

```

An example of running the program for 10<sup>7</sup> randomly generated numbers:


```bash

$ ./achilles
Current time is 1572712634
  21807104 is Achilles number
  72595656 is Achilles number
 205789993 is Achilles number
   4121741 is Achilles number
 171478296 is Achilles number
...................................
 192589600 is Achilles number
  65802492 is Achilles number
   7469451 is Achilles number
    245000 is Achilles number
  62989088 is Achilles number
Found 255 Achilles out of 10000000 tested numbers
$
```

### Usage:

Open a terminal in the current directory and do the following for _compile_ and _run_:

```bash
$ gcc -o achilles achilles.c 
$ time ./achilles
```

It is included the statement of the project in Greek which provides a more extensive description of the project.
