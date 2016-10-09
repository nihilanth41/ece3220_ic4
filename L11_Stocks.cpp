#include <iostream>
#include <cstring>
#include <cstdio>

class Stock{
	private:
		char company[30];
		int shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val; }
		
	public:
		void acquire(const char * co, int n, double pr);
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void display(void);
};

void Stock::acquire(const char * co, int n, double pr){
	std::strncpy(company, co, 29);
	company[29] = '\0';
	
	if(n < 0){
		std::cerr << "Number of shares can't be negative; "
				  << company << " shares set to 0.\n";
		shares = 0;
	}
	else{
		shares = n;
		std::cout << "Updated shares." << std::endl;
	}
	
	share_val = pr;
	set_tot();
}

void Stock::buy(int num, double price) {

	if(num < 0){
		shares += 0;
		std::cout << "Number of shares can't be negative." << std::endl;
		std::cout << "Buying 0 shares." << std::endl;
	}
	else{
		shares += num;
		share_val += (price * num); 
		std::cout << "Bought " << num << " share(s)"
			     " of " << company << " for $"
			     << price << " per share." << std::endl;
	}

	set_tot();

}

void Stock::sell(int num, double price) {
	if(num < 0){
		shares -= 0;
		std::cout << "Number of shares can't be negative." << std::endl;
		std::cout << "Selling 0 shares." << std::endl;
	}
	else{
		shares -= num;
		share_val -= (price * num); 
		std::cout << "Sold " << num << " share(s)"
			     " of " << company << " for $"
			     << price << " per share." << std::endl;
	}


	set_tot();
}

void Stock::update(double price) {
	if(price < 0.0)
	{
		share_val = 0.0;
		std::cout << "Share price can't be negative." << std::endl;
		std::cout << "Setting share value to $0.00" << std::endl;
	}
	else
	{
		share_val = price;
		std::cout << "Setting share price to $" << price << std::endl;
	}

	set_tot();
}

void Stock::display(void) {
		printf("\nCompany: %s\n", company);
		printf("Number of Shares: %d\n", shares);
		printf("Share Value: $%0.4lf\n", share_val);
		printf("Total Value: $%0.4lf\n\n", total_val);
}

int main(){
	using std::cout;
	using std::endl;
	
	Stock stock1, stock2;
	
	stock1.acquire("Nanosmart", 20, 12.50);
	
	stock1.display();

	stock1.buy(1, 2.99);
	
	stock1.display();

	stock1.sell(1, 5.99);

	stock1.update(24.00);

	stock1.display();
	
	stock2.acquire("Amazon", 30, 100);
	stock2.display();

	// Can't print private class members directly
	//  - Need accessor methods
	//  - Or make variables public class members
	//cout << stock1.shares << endl;

	//cout << "\nTest..." << endl;

	return 0;
}
