#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <forward_list>



/* This is a quick sort algorithm using modern C++ */
/* Reference: cppreference.com */

template<class FT>
void quickSortModernCpp(FT first, FT last) {

	if (first == last)
		return;

	auto pivot = *std::next(first, std::distance(first, last) / 2);
	//get the partition 1
	auto middle1 = std::partition(first, last, [pivot](const auto& em) 
	{ 
			return em < pivot;
	});
	//get the partition 2
	auto middle2 = std::partition(middle1, last, [pivot](const auto& em) 
	{
			return (em <= pivot); 
	});

	//call the quicksort algorithm recursively
	quickSortModernCpp(first, middle1);
	quickSortModernCpp(middle2, last);

}

int main()
{
	//unsorted array 
	int arr[] = {9,4,8,3,7,1,6,2,5};
	//print unsorted array 
	std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, ","));
	std::cout << "\n";
	//call the quicksort function to sort the array
	quickSortModernCpp(std::begin(arr), std::end(arr));
	//print sorted array
	std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, ","));


	return 0;
}