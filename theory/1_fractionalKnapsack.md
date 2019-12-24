
Given weights and values of n items, we need to put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack.

In the 0-1 Knapsack problem, we are not allowed to break items. We either take the whole item or don’t take it.

Input:
  Items as (value, weight) pairs
  arr[] = {{60, 10}, {100, 20}, {120, 30}}
  Knapsack Capacity, W = 50;

Output (0-1 knapsack):
  Maximum possible value = 220
  by taking items of weight 20 and 30 kg

Output (fractional  ):
   Maximum possible value = 240
   By taking full items of 10 kg, 20 kg and 
   2/3rd of last item of 30 kg

An efficient solution is to use Greedy approach. 
The basic idea of the greedy approach is to calculate the ratio value/weight 
for each item and sort the item on basis of this ratio. 
Then take the item with the highest ratio and add them until we can’t add the next item 
as a whole and at the end add the next item as much as we can. 
Which will always be the optimal solution to this problem.

A high value-to-weight ratio means that the product is 
expensive and doesn't weigh a lot so the cost to ship the products is low