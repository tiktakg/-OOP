#include <iostream>
#include <string.h>
#include <Windows.h>


class Product
{
private:
	static float margin;


	float price;
	std::string name;

public:
	Product(std::string _name, float _price)
	{
		name = _name;
		price = _price + margin;
	}
	~Product()
	{
		std::cout << "Product is delete. \n";
	}

	void ShowDate()
	{
		std::cout << "Name of porduct : " << name << std::endl;
		std::cout << "price of porduct : " << price << std::endl;

	}



};

  
float Product::margin = 10;

int main()
{


	Product product1("Potato", 10);
	Product product2("Tomato", 15);

	product1.ShowDate();
	product2.ShowDate();

}


