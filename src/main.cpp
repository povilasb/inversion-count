#include <iostream>
#include <fstream>
#include <vector>
#include <ios>
#include <stdexcept>

#include "inversions.hpp"
#include "utils.hpp"

using namespace std;


/**
 * Reads numbers from the specified text file.
 *
 * @param fname file name to read numbers from.
 * @return vector of numbers.
 * @throws ios_base::failure if fails to open file for reading.
 */
vector<int> read_numbers(string fname);


int
main(int argc, char *argv[])
{
	int retval = 0;

	if (argc != 2) {
		throw new invalid_argument("Expected exactly 1 argument - "
			"file name of file containing integer numbers.");
	}

	cout << "Reading numbers from: " << argv[1] << '\n';

	vector<int> numbers = read_numbers(argv[1]);
	long inversions = inversion_count_dnc(numbers);

	cout << "Inversions: " << inversions << endl;

	return retval;
}


vector<int>
read_numbers(string fname)
{
	ifstream ifs(fname, fstream::in);

	if (!ifs.is_open()) {
		throw new ios_base::failure("Failed to open file: " + fname);
	}

	vector<int> retval;
	int num = 0;
	ifs >> num;

	while (!ifs.eof()) {
		retval.push_back(num);
		ifs >> num;
	}

	ifs.close();
	return retval;
}
