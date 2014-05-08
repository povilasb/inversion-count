#include <vector>
#include <cassert>

#include <inversions.hpp>

using namespace std;


unsigned long
inversion_count(const vector<int> &numbers)
{
	unsigned long retval = 0;

	for (unsigned long i = 0; i < numbers.size() - 1; i++) {
		for (unsigned long j = i + 1; j < numbers.size(); j++) {
			if (numbers[i] > numbers[j]) {
				retval++;
			}
		}
	}

	return retval;
}


/**
 * NOTE: does not check if start and end indexes are valid for the specified
 * numbers vector.
 */
static unsigned long
divide_merge_count(vector<int> &numbers, const vector<int>::size_type start,
	const vector<int>::size_type end)
{
	unsigned long retval = 0;
	vector<int>::size_type element_count = end - start + 1;

	if (element_count > 1) {
		vector<int>::size_type mid = element_count / 2;
		vector<int> sorted_numbers;

		retval += divide_merge_count(numbers, start, start + mid - 1);
		retval += divide_merge_count(numbers, start + mid, end);

		vector<int>::size_type merged = 0;
		vector<int>::size_type i = start;
		vector<int>::size_type j = start + mid;

		while (merged < element_count) {
			if (i > start + mid - 1) {
				sorted_numbers.push_back(numbers[j]);
				j++;
			}

			else if (j > end) {
				sorted_numbers.push_back(numbers[i]);
				i++;
			}

			else if (numbers[j] < numbers[i]) {
				sorted_numbers.push_back(numbers[j]);
				j++;
				retval += start + mid - i;
			}

			else {
				sorted_numbers.push_back(numbers[i]);
				i++;
			}

			merged++;
		}

		for (i = start; i <= end; i++) {
			numbers[i] = sorted_numbers[i - start];
		}
	}

	return retval;
}


unsigned long
inversion_count_dnc(const vector<int> &numbers)
{
	long retval = 0;
	vector<int> numbers_copy = numbers;

	retval += divide_merge_count(numbers_copy, 0, numbers.size() - 1);

	return retval;
}
