#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int num_cases;
  cin >> num_cases;

  for (int i = 0; i < num_cases; ++i) {
    int num_integers;
    cin >> num_integers;

    vector<long long int> v1;
    for (int j = 0; j < num_integers; ++j) {
      long long int integer;
      cin >> integer;

      v1.push_back(integer);
    }

    vector<long long int> v2;
    for (int j = 0; j < num_integers; ++j) {
      long long int integer;
      cin >> integer;

      v2.push_back(integer);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());

    long long int sum = 0;
    for (int j = 0; j < v1.size(); ++j) {
      sum += v1[j] * v2[j];
    }

    cout << "Case #" << i + 1 << ": " << sum << endl;
  }

  return 0;
}
