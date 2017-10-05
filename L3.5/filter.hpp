/*
 * Marc Bolinas
 *
 * TA: Eeshita Biswas
 *
 * 9/27/17
 * LAB 3 PART 2
 *
 *
 *
 */

#ifndef FILTER_HPP_
#define FILTER_HPP_

class filter{
	int *array_default;
	int array_size = 0;
	int *array_filtered;
	int high = 0;
	int low = 0;
	int window_size = 5;

public:
	filter();

	int *get_array_default();

	int *get_array_filtered();

	void array_int_gen(); //iteratively creates an array of length 25-50, sets high between 10-5 and low between -10 - -5

	void array_int_gen_rec(); //recursively creates an array of length 25-50, sets high between 10-5 and low between -10 - -5

	void fill_array(int *arr, int length, int high, int low); //fills given array with ints between low and high

	int hanning_window(int *array); //applies a smoothing filter to given array, strength of smoothing determined by window_size

	void filter_array(); //uses smoothing filter from hanning_window() to apply to the entire array

	void print_array(int *array); //prints out the given array, new line every 10 ints

	void print_array_graph(int *array); //graphically prints out array

	~filter();
};











#endif /* FILTER_HPP_ */
