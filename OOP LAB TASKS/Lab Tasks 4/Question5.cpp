#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MenuItem {
public:
	string name;
	string type;
	double price;
	
	MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
	string name;
	vector<MenuItem> menu; // a vector of menu (to make my life easier)
	vector<string> orders; // a vector of orders (to make my life easier)

public:
	CoffeeShop(string shopName, vector<MenuItem> shopMenu) 
		: name(shopName), menu(shopMenu) {}

	string addOrder(string itemName) {
		for (auto& item : menu) { // using for each loop
			if (item.name == itemName) {
				orders.push_back(itemName);
				return "Added: " + itemName;
			}
		}
		return "Item unavailable";
	}

	string fulfillOrder() {
		if (!orders.empty()) {
			string fulfilledItem = orders.front();
			orders.erase(orders.begin());
			return fulfilledItem + " is ready";
		}
		return "Orders have been fulfilled";
	}

	vector<string> listOrders() {
		return orders;
	}

	double dueAmount() {
		double total = 0;
		for (auto& order : orders) { // for each order
			for (auto& item : menu) { // calculatr how much each item costs
				if (item.name == order) {
					total += item.price;
					break;
				}
			}
		}
		return total;
	}

	string cheapestItem() {
		if (menu.empty()) return "No items in menu";
		auto cheapest = menu.front();
		for (auto& item : menu) {
			if (item.price < cheapest.price) {
				cheapest = item;
			}
		}
		return cheapest.name;
	}

	vector<string> drinksOnly() {
		vector<string> drinks;
		for (auto& item : menu) {
			if (item.type == "drink") {
				drinks.push_back(item.name);
			}
		}
		return drinks;
	}

	vector<string> foodOnly() {
		vector<string> food;
		for (auto& item : menu) {
			if (item.type == "food") {
				food.push_back(item.name);
			}
		}
		return food;
	}
};

int main() {
	vector<MenuItem> menu = {
		{"Nihari", "food", 8.0},
		{"Biryani", "food", 6.5},
		{"Haleem", "food", 7.0},
		{"Lassi", "drink", 3.0},
		{"Doodh Patti", "drink", 2.0}
	};
	
	CoffeeShop shop("Desi Delight", menu);
	
	cout << shop.addOrder("Biryani") << endl;
	cout << shop.addOrder("Lassi") << endl;
	cout << shop.addOrder("Pizza") << endl;
	
	cout << "Total due: $" << shop.dueAmount() << endl;
	
	cout << shop.fulfillOrder() << endl;
	cout << shop.fulfillOrder() << endl;
	cout << shop.fulfillOrder() << endl;
	
	cout << "Cheapest item: " << shop.cheapestItem() << endl;
	
	cout << "Drinks available: ";
	for (auto& drink : shop.drinksOnly()) cout << drink << " ";
	cout << endl;
	
	cout << "Food available: ";
	for (auto& food : shop.foodOnly()) cout << food << " ";
	cout << endl;
	
	return 0;
}

