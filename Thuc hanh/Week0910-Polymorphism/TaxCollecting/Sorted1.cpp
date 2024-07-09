#include "Sorted1.h"


void SelectionSort1::byRentAscerd(std::vector<ITaxCollecting*>& Tax) {
	for (int i = 0; i < Tax.size() - 1; i++) {
		int index = i;
		for (int j = i + 1; j < Tax.size(); j++) {
			if (Tax[index]->LeaseholdCash() > Tax[j]->LeaseholdCash()) {
				index = j;
			}
		}
		std::swap(Tax[index], Tax[i]);
	}
}