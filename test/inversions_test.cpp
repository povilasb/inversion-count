#include <vector>

#include <gtest/gtest.h>

#include <inversions.hpp>
#include <utils.hpp>


using namespace std;


TEST(inversions, simple1)
{
	vector<int> numbers = {2, 4, 1, 3, 5};
	unsigned long inversions = inversion_count(numbers);
	ASSERT_TRUE(inversions == 3);
}


TEST(inversions, simple2)
{
	vector<int> numbers = {2, 3, 1, 4};
	unsigned long inversions = inversion_count(numbers);
	ASSERT_TRUE(inversions == 2);
}


TEST(inversions_dnc, simple1)
{
	vector<int> numbers = {2, 4, 1, 3, 5};
	unsigned long inversions = inversion_count_dnc(numbers);
	ASSERT_TRUE(inversions == 3);
}


TEST(inversions_dnc, simple2)
{
	vector<int> numbers = {2, 3, 1, 4};
	unsigned long inversions = inversion_count_dnc(numbers);
	ASSERT_TRUE(inversions == 2);
}


TEST(inversions_dnc, simple3)
{
	vector<int> numbers = {5, 4};
	unsigned long inversions = inversion_count_dnc(numbers);
	ASSERT_TRUE(inversions == 1);
}


TEST(inversions_dnc, simple4)
{
	vector<int> numbers = {5, 4, 1, 2, 3};
	unsigned long inversions = inversion_count_dnc(numbers);
	ASSERT_TRUE(inversions == 7);
}


TEST(inversions_vs_inversions_dnc, random)
{
	for (int i = 0; i < 1000; i++) {
		vector<int> numbers = generate_random_number_vector(5);
		unsigned long inversions1 = inversion_count(numbers);
		unsigned long inversions2 = inversion_count_dnc(numbers);

		// For debugging purposes.
		if (inversions1 != inversions2) {
			cout << "Test number array: " << '\n';
			for (vector<int>::size_type i = 0; i < numbers.size();
				i++) {
				cout << numbers[i] << " ";
			}
			cout << '\n';

			cout << "Naive algorithm inversions: " << inversions1
				<< '\n';
			cout << "Divide and conquer algorithm inversions: "
				<< inversions2 << '\n';
		}

		ASSERT_TRUE(inversions1 == inversions2);
	}
}
