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





#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "filter.hpp"

using namespace std;

filter::filter(){
	array_int_gen();
}

int *filter::get_array_default(){
	return array_default;
}

int *filter::get_array_filtered(){
	return array_filtered;
}

void filter::array_int_gen(){
	array_size = (rand() % 25) + 25; //25-50
	high = (rand() % 5) + 5; //5-10
	low = (rand() % 5) - 10; //-10- -5
	array_default = new int[array_size];

	for(int i = 0; i < array_size; i++){
		array_default[i] = rand() % (high - low + 1) + low;
	}
}

//Problem 2

void filter::array_int_gen_rec(){
	array_size = (rand() % 25) + 25; //25-50
	high = (rand() % 5) + 5; //5-10
	low = (rand() % 5) - 10; //-10- -5
	array_default = new int[array_size];

	fill_array(&array_default[0], array_size, high, low);

}

void filter::fill_array(int *arr, int length, int high, int low){
	if(length > 0){ //works by passing in the next element in the array as the first value. continue until reaching length
		arr[0] = rand() % (high - low + 1) + low;
		fill_array(&arr[1], length - 1, high, low);
	}
}

//Problem 3

void filter::print_array(int *array){
	int count = 0;
	for(int i = 0; i < array_size; i++){

		if(array[i] < 0){ //I do this because the minus sign makes it take more space
			cout << array[i] << ", ";
		}
		else{
			cout << " " << array[i] << ", "; //prints an extra space so that everything stays lined up
		}

		count++;


		if(count == 10){
			cout << endl;
			count = 0;
		}
	}
	cout << endl;
}

//Problem 4

int filter::hanning_window(int *array){
	int total_weight = 0;
	int weight = 1;
	int sum = 0;
	for(int i = 0 - (window_size / 2); i <= (window_size / 2); i++){ //array[0] is the center of the hanning window. go negative to get previous values
		sum += (array[i] * weight);
		total_weight += weight;
		if(i < 0){ //weight increases as it gets to the center, then decreases: 1,2,3,2,1
			weight++;
		}
		else{
			weight--;
		}
	}
	sum /= total_weight;

	return sum;
}

//Problem 5

void filter::filter_array(){
	array_filtered = new int[array_size];

	int border = window_size / 2; //how many 0's to put at the start and end of the array because the hanning window won't work on those
	int index = 0;
	for(; index < border; index++){
		array_filtered[index] = 0;
	}

	for(; index < array_size - border; index++){ //apply smoothing filter
		array_filtered[index] = hanning_window(&array_default[index]);
	}
	for(; index < array_size; index++){
		array_filtered[index] = 0;
	}
}

//Problem 6

void filter::print_array_graph(int *array){
	int temp_low = low;
	for(; temp_low <= high; temp_low++){
		if(temp_low < 0){ //again, this is so that the minus sign doesn't make things go out of alignment
			cout << temp_low << ": ";
		}
		else{
			cout << " " << temp_low << ": ";
		}


		for(int i = 0; i < array_size; i++){
			if(array[i] == temp_low){
				cout << "x ";
			}
			else{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

filter::~filter(){
	delete [] array_default;
	delete [] array_filtered;
	cout << "destroying filter" << endl;
}

