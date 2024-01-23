#include "Stopwatch.h"


void Stopwatch::start() {
  starttime = clock();
}

double Stopwatch::stop() {
  clock_t endTime = clock();
  double elapsedTime = static_cast<double> (endTime - starttime) /  CLOCKS_PER_SEC;
  return elapsedTime;
}
