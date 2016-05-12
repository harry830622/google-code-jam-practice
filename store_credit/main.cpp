#include <iostream>

using namespace std;

int main()
{
  int num_cases;
  cin >> num_cases;

  for (int i = 0; i < num_cases; ++i) {
    int credit;
    cin >> credit;

    int num_items;
    cin >> num_items;

    int* item_prices = new int[num_items];

    for (int j = 0; j < num_items; ++j) {
      cin >> item_prices[j];
    }

    for (int j = 0; j < num_items; ++j) {
      for (int k = j + 1; k < num_items; ++k) {
        if (item_prices[j] + item_prices[k] == credit) {
          cout << "Case #" << i + 1 << ": " << j + 1 << " " << k + 1 << endl;

          j = num_items; // Break the outer loop
          break;
        }
      }
    }
  }

  return 0;
}
