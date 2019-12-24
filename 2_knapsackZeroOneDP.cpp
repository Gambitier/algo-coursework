#include <iostream>
#include<algorithm>
using namespace std;

int knapsack_dp(int number_of_items, int capacity_of_knapsack, int weight_of_items[], int value_of_items[])
{
    //create a matrix to memoize the values using dynamic programming
    int knapsack[number_of_items + 1][capacity_of_knapsack + 1];

    //knapsack[i][j] denotes the maximum attainable value of items in knpasack with i available
    //items and capacity of knapsack being j

    //initializing knapsack[0][j]=0 for 0<=j<=capacity_of_knapsack
    //because if there is no item, no value can be attained
    for (int j = 0; j <= capacity_of_knapsack; j++)
        knapsack[0][j] = 0;

    //initializing knapsack[i][0]=0 for 0<=i<=number_of_items,
    //because in a bag of zero capacity, no item can be placed
    for (int i = 0; i <= number_of_items; i++)
        knapsack[i][0] = 0;

    //now, filling the matrix in bottom up manner
    for (int i = 1; i <= number_of_items; i++)
    {
        for (int j = 1; j <= capacity_of_knapsack; j++)
        {
            //check if the weight of current item i is less than or equal to the capacity of sack,
            //take maximum of once including the current item and once not including
            if (weight_of_items[i - 1] <= j)
            {
                knapsack[i][j] = max(knapsack[i - 1][j], value_of_items[i - 1] + knapsack[i - 1][j - weight_of_items[i - 1]]);
            }

            //can not include the current item in this case
            else
            {
                knapsack[i][j] = knapsack[i - 1][j];
            }
        }
    }

    return knapsack[number_of_items][capacity_of_knapsack];
}

int main()
{
    int number_of_items; //number of items
    int capacity_of_knapsack; //capacity of knapsack

    cout << "Enter the no. of items ";
    cin >> number_of_items;

    int weight_of_items[number_of_items]; //weight of items
    int value_of_items[number_of_items]; //value of items

    cout << "Enter the weight and price of all items" << endl;
    for (int i = 0; i < number_of_items; i++)
    {
        cin >> weight_of_items[i] >> value_of_items[i];
    }

    cout << "enter the capacity of knapsack  ";
    cin >> capacity_of_knapsack;

    int result = knapsack_dp(number_of_items, capacity_of_knapsack, weight_of_items, value_of_items);

    //the maximum value will be given by knasack[number_of_items][capacity_of_knapsack], ie. using number_of_items items with capacity capacity_of_knapsack
    cout << "The maximum value of items that can be put into knapsack is " << result;

    return 0;
}