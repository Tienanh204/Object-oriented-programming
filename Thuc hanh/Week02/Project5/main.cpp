#include"Product.h"

int main()
{
	ProductInput product;
	cout << "Input product information" << endl;
	product.input();

	cout << endl;
	
	cout << "Output product information" << endl;
	product.output();

	product.setExDate(1, 2, 3);
	product.output();
}