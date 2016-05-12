#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  int num_cases;
  cin >> num_cases;

  cin.ignore(1, '\n');

  for (int i = 0; i < num_cases; ++i) {
    stack<string> reverse_words;

    string line_str;
    getline(cin, line_str);

    stringstream line_ss(line_str);
    while (!line_ss.eof()) {
      string str;
      line_ss >> str;

      reverse_words.push(str);
    }

    cout << "Case #" << i + 1 << ": ";
    while (!reverse_words.empty()) {
      cout << reverse_words.top() << " ";

      reverse_words.pop();
    }
    cout << endl;
  }

  return 0;
}
