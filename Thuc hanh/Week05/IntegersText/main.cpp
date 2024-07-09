#include"IntegersText.h"
#include"IntegersTextProvider.h"

int main()
{
	IntegersTextProvider ITP;
	Integer result;
	result.setVector(ITP.read("input"));
	result.displayResult();
}