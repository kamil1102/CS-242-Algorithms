// Arnold Beckmann, 17.12.2009 (Swansea)

/*!
  \file 200910/Week01/Experiment_rand.cpp
  \brief Experiments with sorting algorithms on random inputs

  "Experiment N" calls the sorting algorithm N times with random
  inputs; the statistics are output to standard output.
*/

#include <string>
#include <iostream>

#include <200910/Framework/Measurement.hpp>
#include <200910/Framework/Utilities.hpp>

#include <200910/Week01/Sorting.hpp>
#include <200910/Week01/Generators.hpp>

namespace {

  const std::string program = "Experiment";
  const std::string err = "ERROR[" + program + "]: ";

}

int main(const int argc, const char* const argv[]) {
  using namespace IntroAlgo::Framework;
  if (argc != 2) {
    std::cerr << err << "Exactly one parameter is required, the number N of experiments.\n";
    return parameter_error;
  }

  const int N = lexical_cast<int>(argv[1]);
  OutputMeasurement::header_line("\n#  Insertion-sort on random lists\n size comparisons\n");
  for (int i = 0; i <= N; ++i) {
    using IntroAlgo::Week01::ArrayGenerators;
    typedef ArrayGenerators::vector_type vector_type;
    vector_type A = ArrayGenerators::random(i);
    IntroAlgo::Week01::insertion_sort(A);
    // std::cout << cw(A) << "\n";
  }
  
}
