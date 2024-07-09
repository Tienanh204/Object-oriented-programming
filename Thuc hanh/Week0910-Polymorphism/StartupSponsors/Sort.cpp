#include "Sort.h"
bool Sorted::byFundAscerd(IProject* projectA, IProject* projectB) {
	return projectA->Funding() < projectB->Funding();
}