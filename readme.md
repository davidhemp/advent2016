# Advent of code 2016 #
http://adventofcode.com/2016

Timing done internally for c++ and wih timeti for python.
Run multible times to get an average but allowed to return to idle after each
 run. These numbers are really just so I could try and keep the run times in the
 low milliseconds.

 TODO: Looking through these the main improvement I need to make with with my
 string/char handling. Day6 for example, python is considerably faster than c++.

| Day     |  Python  |   pypy   |  C++11  |  C++11 -O2  |
| ------- | -------- |  ------  | ------- | ----------- |
| Day 1-1 |  \/  \/  |  \/  \/  | 0.4 msec  | 0.4 msec  |
| Day 1-2 |  18 msec |  23 msec | 5 msec  | 0.8 msec|
| Day 2-1 | -------- |  ------  | 0.2 msec | 0.2 msec |
| Day 2-2 | -------- |  ------  | 10 msec | 1.8 msec |
| Day 3-1 |  6 msec  | 1.5 msec | 8 msec | 7 msec |
| Day 3-2 |  4 msec  | 1.1 msec | 9 msec | 7 msec |
| Day 4-1 | 14 msec  |  1 msec  | ------- | ------- |
| Day 4-2 | 25 msec  |  1 msec  | ------- | ------- |
| Day 5-1 | -------- |  ------  | 11 sec | 11 sec |
| Day 5-2 | -------- |  ------  | 20 sec | 23 msec |
| Day 6-1 |  2 msec  |  ------  | 12 msec | 0.9 msec |
| Day 6-2 |  2 msec  |  ------  | 13 msec | 1.7 msec |
| Day 7-1 | -------- |  ------  | 100 msec | 40 msec |
| Day 7-2 | -------- |  ------  | -------- | ------- |
| Day 8-1 | -------- |  ------  | \/ \/ | \/ \/ |
| Day 8-2 | -------- |  ------  | 8 msec | 3  msec |
| Day 9-1 | -------- |  ------  | 1 msec | 0.7 msec |
| Day 9-2 | -------- |  ------  | ------- | -------- |
| Day 10-2 | -------- |  ------  | MISSING | MISSING |
| Day 10-2 | -------- |  ------  | MISSING | MISSING |
| Day 11-1 | -------- |  ------  |  TBC    |  TBC   |
| Day 11-2 | -------- |  ------  |  TBC    |  TBC   |
| Day 12-1 | -------- |  ------  | 1.2 sec | 1.1 sec |
| Day 12-2 | -------- |  ------  |  40 sec | 30 sec |
| Day 13-1 | -------- |  ------  |  8 msec | 1.7 msec |
| Day 13-2 | -------- |  ------  |  2.5 msec | 0.6  msec |
| Day 14-1 | -------- |  ------  |  4.7 sec | 1.9 sec |
| Day 14-2 | -------- |  ------  |  ------ | --------- |
| Day 15-1 | 135 msec |  12 msec  |  30 msec | 10 msec |
| Day 15-2 | 1.3 sec  |  100 msec  |  130 msec | 30 msec |
