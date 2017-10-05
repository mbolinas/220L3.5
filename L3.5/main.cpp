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

#include "filter.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "filter.hpp"
using namespace std;

int main(){
	srand(time(NULL));
	filter *filt = new filter();
	filt->array_int_gen();


	cout << "Values in the default array: " << endl;
	filt->print_array(filt->get_array_default());
	cout << "Graph of the default array: " << endl;
	filt->print_array_graph(filt->get_array_default());

	filt->filter_array();
	cout << endl << endl << "ARRAY HAS BEEN FILTERED" << endl << endl;

	cout << "Values in the filtered array: " << endl;
	filt->print_array(filt->get_array_filtered());
	cout << "Graph of the filtered array: " << endl;
	filt->print_array_graph(filt->get_array_filtered());



	return 0;
}

