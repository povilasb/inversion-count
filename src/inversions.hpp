#ifndef INVERSIONS_HPP
#define INVERSIONS_HPP 1

#include <vector>


/**
 * Implementation of naive inversion counting algoritm that is O(n^2).
 *
 * @param numbers array of numbers.
 * @return inversion count in the spefied number array.
 */
unsigned long inversion_count(const std::vector<int> &numbers);


/**
 * Implementation of divide and conquer algorithm to count number inversions.
 * This algorithm is O(n log n) complexity.
 */
unsigned long inversion_count_dnc(const std::vector<int> &numbers);


#endif /* INVERSIONS_HPP */
