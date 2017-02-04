# Advent of code 2016 #
http://adventofcode.com/2016

Timing done internally for c++ and wih timeti for python.
Run multible times to get an average but allowed to return to idle after each
 run. These numbers are really just so I could try and keep the run times in the
 low milliseconds.

 TODO:
 1. Looking through these the main improvement I need to make is with my
 string/char handling. Day6 for example, python is considerably faster than c++.
 2. Loading the text file is also very slow with fstream, need to look into
    mmap. In Day 4, for example, just running through the file takes 25 msec.
    Another ~5 msec might be gained by using a vector and sorting as a set sorts
    after every insert.


| Day     |  Answer | Python  |   pypy   |  C++11   | C++11 -O2 |
| ------- | ------- |-------- |  ------  | -------  | --------- |
| Day 1-1 |     278 | \/  \/  |  \/  \/  | 0.4 msec |  0.4 msec |
| Day 1-2 |     161 | 18 msec |  23 msec |   5 msec |  0.8 msec |
| Day 2-1 |   47978 |0.4 msec | 0.1 msec | 0.2 msec |  0.2 msec |
| Day 2-2 |   659AD |  2 msec |   2 msec |  10 msec |  1.8 msec |
| Day 3-1 |     983 |  7 msec |   3 msec |   5 msec |  4.5 msec |
| Day 3-2 |    1836 | 12 msec |   4 msec |   9 msec |    7 msec |
| Day 4-1 |  361724 | 18 msec |  11 msec |  55 msec |   16 msec |
| Day 4-2 |     482 | 13 msec |   6 msec |  37 msec |    9 msec |
| Day 5-1 | 1a3099aa|    37 s |   19.8 s |     11 s |      11 s |
| Day 5-2 | 694190cd|    58 s |   38.5 s |     20 s |   23 msec |
| Day 6-1 | umejzgdw|  2 msec |   5 msec |  12 msec |  0.9 msec |
| Day 6-2 | aovueakv|  2 msec |   5 msec |  13 msec |  1.7 msec |
| Day 7-1 |     118 | 60 msec |  14 msec | 100 msec |   40 msec |
| Day 7-2 |     260 | 40 msec |   8 msec |  50 msec |   35 msec |
| Day 8-1 |     110 |  \/  \/ |  \/  \/  |   \/ \/  |   \/ \/   |
| Day 8-2 |ZJHRKCPLYJ|4.5 msec|   2 msec |   8 msec |   3  msec |
| Day 9-1 |   74532 |  2 msec*|   7 msec | 0.4 msec |  0.7 msec |
| Day 9-2 |         |-------- |  ------  | -------  |  -------- |
| Day 10-1 |    157 |   \/ \/  |  \/ \/   |  \/ \/  |   \/ \/   |
| Day 10-2 |   1085 |   6 msec |  16 msec | 20 msec |    6 msec |
| Day 11-1 |        | -------- |  ------  |    TBC  |     TBC   |
| Day 11-2 |        | -------- |  ------  |    TBC  |     TBC   |
| Day 12-1 | 318020 |    3.1 s |    0.1 s |   1.2 s |     1.1 s |
| Day 12-2 |9227674 |   61.8 s |    6.5 s |    40 s |      30 s |
| Day 13-1 |     90 |  13 msec |  13 msec |  8 msec |  1.7 msec |
| Day 13-2 |    135 | 1.2 msec |   2 msec | 2.5 msec| 0.6  msec |
| Day 14-1 |  15035 | -------- |  ------  |   4.7 s |     1.9 s |
| Day 14-2 |  19968 | -------- |  ------  |   102 s |     102 s |
| Day 15-1 | 376777 | 135 msec |  12 msec | 30 msec |   10 msec |
| Day 15-2 |3903937 |   1.3 s  |  100 msec| 130 msec|   30 msec |
| Day 16-1 |01110011101111011| 0.2 msec | 0.1 msec | 0.1 msec | 0.1 msec |
| Day 16-2 |11001111011000111|   21.2 s |   5 s    |    2.2 s | 360 msec |
| Day 17-1 |RDRLDRDURD|0.2 msec| 0.2 msec |  ------ |  ------  |
| Day 17-2 |   596  | 300 msec | 340 msec |  ------ |  ------  |
| Day 18-1 |  2005  |   1 msec | 0.7 msec |  ------ |  ------  |
| Day 18-2 |20008491|     12 s |    2.1 s |  ------ |  ------  |
| Day 19-1 |1815603 | 200 msec | 11 msec  |  ------ |  ------  |
| Day 19-2 |        |     msec |     msec |  ------ |  ------  |
