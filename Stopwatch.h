#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <ctime>
#include <iostream>

class Stopwatch {
 private:
  clock_t starttime;
 public:
  void start();
  double stop();
  
};





#endif
