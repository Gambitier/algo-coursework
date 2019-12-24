#include <iostream> 
#include <algorithm>
using namespace std; 

struct Item 
{ 
	int value, weight; 

	// Constructor 
	Item(int value, int weight) : value(value), weight(weight) 
	{} 
}; 

// Comparison function to sort Item according to val/weight ratio 
bool cmp(struct Item item, struct Item b) 
{ 
    // A high value-to-weight ratio means that the product is expensive 
    // and doesn't weigh a lot so the cost to ship the products is low
	double r1 = (double)item.value / item.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 

// Main greedy function to solve problem 
double fractionalKnapsack(int weight, struct Item items[], int n) 
{ 
	// sorting Item on basis of ratio 
	sort(items, items + n, cmp); 

	// Uncomment to see new order of Items with their ratio 
	for (int i = 0; i < n; i++) 
	{ 
		cout << items[i].value << " " << items[i].weight << " : " 
			<< ((double)items[i].value / items[i].weight) << endl; 
	} 


	int currentWeight = 0; // Current weight in knapsack 
	double finalvalue = 0.0; // Result (value in Knapsack) 

	// Looping through all Items 
	for (int i = 0; i < n; i++) 
	{ 
		if (currentWeight + items[i].weight <= weight) 
		{ 
            // If adding Item won't overflow, add it completely 
			currentWeight += items[i].weight; 
			finalvalue += items[i].value; 
		} 
		else
		{ 
            // If we can't add current Item, add fractional part of it 
			int remainingWeight = weight - currentWeight; 
			finalvalue += items[i].value * ((double) remainingWeight / items[i].weight); 
			break; 
		} 
	} 

	// Returning final value 
	return finalvalue; 
} 

// driver program to test above function 
int main() 
{ 
	int maxWeight = 50; // Weight of knapsack 
	Item items[] = {{60, 10}, {100, 20}, {120, 30}}; 

	int n = sizeof(items) / sizeof(items[0]); 

	double maxValueForGivenWeight = fractionalKnapsack(maxWeight, items, n); 
	
	cout << "\nMaximum value we can obtain = "<<maxValueForGivenWeight;
	return 0; 
}
