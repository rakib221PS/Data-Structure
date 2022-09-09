#include <bits/stdc++.h>

int main()
{
	std::vector<int> vec{10, 20, 30, 40};
	std::vector<int>::iterator it;

	std::cout << "Original vector :";
	for (int i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];

	std::cout << "\n";

	int ser = 300;

	it = std::find(vec.begin(), vec.begin()+10, ser);

	if (it != vec.end())
	{
		std::cout << "Element " << ser << " found at position : ";
		std::cout << it - vec.begin() << " (counting from zero) \n";
	}
	else
		std::cout << "Element not found.\n\n";

	return 0;
}
