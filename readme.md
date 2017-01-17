# Advent of code 2016 #
http://adventofcode.com/2016

Timing done internally for c++ and wih timeti for python.
Run multible times to get an average but allowed to return to idle after each
 run. These numbers are really just so I could try and keep the run times in the
 low milliseconds.

 TODO: Looking through these the main improvement I need to make with with my
 string/char handling. Day6 for example, python is considerably faster than c++.

| Day     |  Answer | Python  |   pypy   |  C++11  |  C++11 -O2  |
| ------- | ------- |-------- |  ------  | ------- | ----------- |
| Day 1-1 |    278  | \/  \/  |  \/  \/  | 0.4 msec  | 0.4 msec  |
| Day 1-2 |    161  | 18 msec |  23 msec | 5 msec  | 0.8 msec|
| Day 2-1 |  47978  |-------- |  ------  | 0.2 msec | 0.2 msec |
| Day 2-2 |  659AD  |-------- |  ------  | 10 msec | 1.8 msec |
| Day 3-1 |    983  | 7 msec  |  3 msec  |  5 msec  | 4.5 msec |
| Day 3-2 |   1836  | 12 msec |  4 msec  |  9 msec  | 7 msec |
| Day 4-1 | 361724  | 18 msec | 11 msec  | ------- | ------- |
| Day 4-2 |    482  | 13 msec | 6 msec | ------- | ------- |
| Day 5-1 | 1a3099aa|  37 sec |  ------  | 11 sec | 11 sec |
| Day 5-2 | 694190cd|  58 sec |  ------  | 20 sec | 23 msec |
| Day 6-1 | umejzgdw| 2 msec  |  ------  | 12 msec | 0.9 msec |
| Day 6-2 | aovueakv| 2 msec  |  ------  | 13 msec | 1.7 msec |
| Day 7-1 |    118  |-------- |  ------  | 100 msec | 40 msec |
| Day 7-2 |    260  |-------- |  ------  | -------- | ------- |
| Day 8-1 |    110  |-------- |  ------  | \/ \/ | \/ \/ |
| Day 8-2 |ZJHRKCPLYJ|-------- |  ------  | 8 msec | 3  msec |
| Day 9-1 |  74532  |-------- |  ------  | 1 msec | 0.7 msec |
| Day 9-2 |         |-------- |  ------  | ------- | -------- |
| Day 10-1 |   157  | -------- |  ------  | MISSING | MISSING |
| Day 10-2 |  1085  | -------- |  ------  | MISSING | MISSING |
| Day 11-1 |        | -------- |  ------  |  TBC    |  TBC   |
| Day 11-2 |        | -------- |  ------  |  TBC    |  TBC   |
| Day 12-1 | 318020 | -------- |  ------  | 1.2 sec | 1.1 sec |
| Day 12-2 | 9227674| -------- |  ------  |  40 sec | 30 sec |
| Day 13-1 |    90  | -------- |  ------  |  8 msec | 1.7 msec |
| Day 13-2 |   135  | -------- |  ------  |  2.5 msec | 0.6  msec |
| Day 14-1 | 15035  | -------- |  ------  |  4.7 sec | 1.9 sec |
| Day 14-2 |        | -------- |  ------  |  ------ | --------- |
| Day 15-1 | 376777 | 135 msec |  12 msec  |  30 msec | 10 msec |
| Day 15-2 |3903937 | 1.3 sec  |  100 msec  |  130 msec | 30 msec |
| Day 16-1 |01110011101111011| 0.2 msec |0.1 msec| ------ | ------ |
| Day 16-2 |11001111011000111| 21.2 sec  |5 sec   | ------ | ------ |
| Day 17-1 |RDRLDRDURD| 0.2 msec |0.1 msec| ------ | ------ |
| Day 17-2 |   596  |  500 msec  |5 sec   | ------ | ------ |
