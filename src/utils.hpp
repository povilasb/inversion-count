#ifndef UTILS_HPP
#define UTILS_HPP 1

#include <cstdlib>
#include <vector>


/**
 * Generates vector of random numbers. Numbers are uniformly distributed in
 * the range [1..size]. There are no duplicates in the result vector.
 *
 * @param size ouput vector size.
 * @return vector of random numbers;
 */
std::vector<int> generate_random_number_vector(size_t size);


#endif /* UTILS_HPP */
