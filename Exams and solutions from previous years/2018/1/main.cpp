#include "Const.hpp"
#include "Var.hpp"
#include "Product.hpp"
#include "Sum.hpp" 

int main() {
	Const const1(5);
	char name[] = "Chetiri";
	Var var1(name, 9, 4);
	var1.print();
	Sum Sum1(&const1, &var1);

	Sum1.print();
	return 0;
}