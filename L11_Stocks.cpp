
#include <iostream>
#include <cstring>

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

int main(){
	using std::cout;
	using std::endl;
	
	Stock stock1, stock2;
	
	stock1.acquire("Nanosmart", 20, 12.50);
	stock2.acquire("Amazon", 30, 100);
	
	cout << "\nTest..." << endl;

	return 0;
}