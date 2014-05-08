#include <cstdlib>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;


vector<int>
generate_random_number_vector(size_t size)
{
	vector<int> retval;
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(1, size);

	for (size_t i = 0; i < size; i++) {
		int new_number = distribution(generator);
		while (find(begin(retval), end(retval), new_number)
			!= end(retval)) {
			new_number = distribution(generator);
		}

		retval.push_back(new_number);
	}

	return retval;
}
