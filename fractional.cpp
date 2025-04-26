#include <bits/stdc++.h>
using namespace std;

struct Item {
  int value, weight;
  Item(int value, int weight) : value(value), weight(weight) {}
};

bool cmp(struct Item a, struct Item b) {
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n, int &latestWeight) {
  sort(arr, arr + n, cmp);

  int curWeight = 0;
  double finalvalue = 0.0;

  for (int i = 0; i < n; i++) {
    if (curWeight + arr[i].weight <= W) {
      curWeight += arr[i].weight;
      finalvalue += arr[i].value;
    } else {
      int remain = W - curWeight;
      finalvalue += arr[i].value * ((double)remain / arr[i].weight);
      curWeight += remain;
      break;
    }
  }

  latestWeight = curWeight;  // Store the final weight used
  return finalvalue;
}

int main() {
  int W = 25;
  Item arr[] = {{25, 18}, {24, 15}, {15, 10} , {8,5}};
  int n = sizeof(arr) / sizeof(arr[0]);

  int latestWeight = 0;
  double maxValue = fractionalKnapsack(W, arr, n, latestWeight);

  cout << "Maximum value we can obtain = " << maxValue << endl;
  cout << "Latest weight used = " << latestWeight << endl;

  return 0;
}

