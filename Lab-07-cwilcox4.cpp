

#include "Lab-07-cwilcox4.h"
#include "winTimer.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;





int main()
{
	vector<double> numbers=getNums(2000000, 1, 500);
	Timer time;
		
	time.start();
	sort(begin(numbers), end(numbers));
	time.stop();

	cout << "\nstd::sort: " << time() << " seconds\n";

	/*time.start();
	numbers = bubble(numbers);
	time.stop();
	cout << "\n\n";


	cout << "\nBubble sort: " << time() << " seconds\n";
	time.start();
	numbers = selection(numbers);
	time.stop();
	cout << "\n\n";


	cout << "\nSelection sort: " << time() << " seconds\n";

	time.start();
	numbers = insertion(numbers);
	time.stop();
	cout << "\n\n";


	cout << "\nInsertion sort: " << time() << " seconds\n";


	time.start();
	numbers = mergeSort(numbers);
	time.stop();
	cout << "\n\n"; 


	cout << "\nMerge sort: " << time() << " seconds\n";
	*/
		system("pause");
		return 0;

}
