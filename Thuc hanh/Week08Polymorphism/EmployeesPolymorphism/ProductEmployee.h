#pragma once
#include"Employee.h"

class ProductEmployee : public Employee {
private:
	int _productCount;
	int _paymentPerProduct;
public:
	ProductEmployee();
	ProductEmployee(int productCount, int paymentPerProduct);

	int getProductCount() const;

	int getPaymentPerProduct() const;

	void setProductCount(int productCount);

	void setPaymentPerProduct(int paymentPerProduct);

	int salary() override;
	std::string toString() override;
};