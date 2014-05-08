Introduction
============

This is an implementation on inversion counting in a number array.

Inversion Count for an array indicates – how far (or close) the array is from
being sorted. If array is already sorted then inversion count is 0. If array
is sorted in reverse order that inversion count is the maximum. Formally
speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and
i < j [#f2]_.
E.g.::

        1 2 3 4 (Indexes)
        2 3 1 4 (Array elements)

This array has 2 inversions.

E.g.::

        1 2 3 4 5
        2 4 1 3 5

This array has 3 inversions.


2 approaches
============

To solve this problem, two methods were tried: naive and divide and conquer
algorithms.


Naive algorithm
---------------

It's simple to implement:

.. code-block:: cpp

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

But it's complexity is O(n^2). On my machine with test data
(*res/integer_array.txt*) it ran for 64.71 seconds.


Divide and conquer
------------------

This alforithm is way faster (O(n log n)). On my machine with the same test
data as before it ran for 0.16 seconds, which is about 400 times faster than
the naive implementation!


.. rubric:: References

.. [#f1] http://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
