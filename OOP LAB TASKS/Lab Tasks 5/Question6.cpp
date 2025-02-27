#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

struct Item {
	string itemname;
	float cost;
	bool food;
};

class CoffeeShop {
	public:
		const string name;
		vector<Item> menu;
		vector<string> orders;

		CoffeeShop(string n, vector<Item> m) : name(n), menu(m) {}

		string addOrder(string Iname) {
			for (const auto& item : menu) {
				if (item.itemname == Iname) {
					orders.push_back(Iname);
					return "Order Added.";
				}
			}
			return "This item is currently unavailable.";
		}

		string fulfillOrder() {
			if (!orders.empty()) {
				string fulfilled = orders.front();
				orders.erase(orders.begin());
				return "The " + fulfilled + " is ready.";
			}
			return "All orders have been fulfilled.";
		}

		void listOrders() {
			if (orders.empty()) {
				cout << "[]" << endl;
				return;
			}
			cout << "Orders: ";
			for (size_t i = 0; i < orders.size(); i++) {
				cout << orders[i] << (i < orders.size() - 1 ? ", " : "");
			}
			cout << endl;
		}

		float dueAmount() {
			float total = 0;
			for (const auto& order : orders) {
				for (const auto& item : menu) {
					if (order == item.itemname) {
						total += item.cost;
						break;
					}
				}
			}
			return total;
		}

		string cheapestItem() {
			if (menu.empty()) return "";
			auto cheapIt = min_element(menu.begin(), menu.end(), [](const Item& a, const Item& b) {
				return a.cost < b.cost;
			});
			return cheapIt->itemname;
		}

		void drinksOnly() {
			cout << "Drinks: ";
			for (const auto& item : menu) {
				if (!item.food) {
					cout << item.itemname << " ";
				}
			}
			cout << endl;
		}

		void foodOnly() {
			cout << "Food: ";
			for (const auto& item : menu) {
				if (item.food) {
					cout << item.itemname << " ";
				}
			}
			cout << endl;
		}
};

int main() {
	vector<Item> menu = {
		{ "Anda", 2.5, true },
		{ "chai", 1.5, false },
		{ "Pharatha", 4.0, true },
		{ "Cake", 3.0, true }
	};

	CoffeeShop shop("Imran HoTeL", menu);
	cout << shop.addOrder("Anda") << endl;
	cout << shop.addOrder("Pharatha") << endl;
	cout << shop.addOrder("Bread") << endl;

	shop.listOrders();

	cout << "Total: " << shop.dueAmount() << endl;

	cout << shop.fulfillOrder() << endl;

	shop.listOrders();

	cout << "Cheapest: " << shop.cheapestItem() << endl;
	shop.foodOnly();
	shop.drinksOnly();

	return 0;
}