#include"FractionsText.h"
#include"fractionsTextProvider.h"
using namespace std;

int main()
{
	FractionKeyboardProvider provider;
	FractionsText frac = provider.getAll("input");

	frac.displayFraction();
	frac.lowestTermMixed();
	frac.Decimal();
	frac.Percentage();
}