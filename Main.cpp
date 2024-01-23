#include "Main.h"

template <typename T>
void printVec(const std::vector<T>& vec) {
  for (const auto& num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

std::vector<int> createVec(size_t n) {
  std::vector<int> inputVec;

  for (std::size_t i = 0; i < n; i++) {
    inputVec.push_back(rand() % 1000);
  }
  return inputVec;
}

double measureTime(size_t n) {
  Stopwatch* watch = new Stopwatch();
  watch->start();
  std::vector <int> inputVec = createVec(n);
  selectionSort(inputVec);
  double endTime = watch->stop();
  delete watch;
  return endTime;
}

std::vector<double> measureTimes(std::vector<size_t> inputSizes) {
  std::vector<double> timeElapsed;
  for (const auto& sz : inputSizes) {
    timeElapsed.push_back(measureTime(sz));
  }
  return timeElapsed;
}

std::vector<double> calculateRatio(std::vector<double> timeElapsed) {
  std::vector<double> ratio;
  ratio.push_back(0);
  for (size_t i = 1; i < timeElapsed.size(); i++) {
    ratio.push_back(timeElapsed[i] / timeElapsed[i - 1]);
  }
    return ratio;
}

void printTable(std::vector<size_t> inputSizes, std::vector<double> timeElapsed, std::vector<double> ratio) {
  std::cout << std::left << std::setw(10) << "N" << std::setw(15) << "Time(seconds)" << std::setw(15) << "Ratio" << std::endl;
  std::cout << std::setw(10) << std::setfill('-') << "" << std::setw(15) << "" << std::setw(15) << "" << std::setfill(' ') << std::endl;
  for (size_t i = 0; i < inputSizes.size(); i++) {
    std::cout << std::left << std::setw(10) << inputSizes[i]
	      << std::setw(15) << std::fixed << std::setprecision(2) << timeElapsed[i]
	      << std::setw(15) << std::fixed << std::setprecision(2) << ratio[i] << std::endl;
  }
}

std::string estimateRunningTime(size_t inputSize, double prevRatio, double prevRunningTime) {
  std::string runningTime;
  double b = log2(round(prevRatio));
  double a = prevRunningTime / pow(inputSize,b);
  std::ostringstream oss;
  oss << std::scientific << std::setprecision(2) << a;
  std::string pwr = std::to_string(b);
  pwr = pwr.substr(0,pwr.find(".") + 2);
  return oss.str() + " x n^" + pwr;
}

int main() {
  size_t specificN = 16000;
  std::vector<size_t> inputSizes {1000, 2000, 4000, 8000, specificN};
  std::vector<double> timeElapsed = measureTimes(inputSizes);
  std::vector<double> ratio = calculateRatio(timeElapsed); 
  printTable(inputSizes, timeElapsed, ratio);
  std::string estimateTime = estimateRunningTime(specificN, ratio[ratio.size() - 2], timeElapsed[timeElapsed.size() - 2]);
  std::cout << "Estimate running time for " << specificN << " is: " << estimateTime << std::endl;
  return 0;
}
