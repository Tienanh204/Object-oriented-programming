#include "ProductEmployee.h"


ProductEmployee::ProductEmployee() {
	_productCount = 0;
	_paymentPerProduct = 0;
}
ProductEmployee::ProductEmployee(int productCount, int paymentPerProduct) {
	_productCount = productCount;
	_paymentPerProduct = paymentPerProduct;
}

int ProductEmployee::getProductCount() const {
	return _productCount;
}

int ProductEmployee::getPaymentPerProduct() const {
	return _paymentPerProduct;
}

void ProductEmployee::setProductCount(int productCount) {
	_productCount = productCount;
}

void ProductEmployee::setPaymentPerProduct(int paymentPerProduct) {
	_paymentPerProduct = paymentPerProduct;
}

int ProductEmployee::salary()  {
	return _productCount * _paymentPerProduct;
}

std::string ProductEmployee::toString()  {
	return "Product employee";
}