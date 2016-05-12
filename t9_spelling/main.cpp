#include <iostream>
#include <string>

using namespace std;

int main()
{
  string ascii_to_t9_table[128];

  ascii_to_t9_table[static_cast<int>(' ')] = string("0");
  ascii_to_t9_table[static_cast<int>('a')] = string("2");
  ascii_to_t9_table[static_cast<int>('b')] = string("22");
  ascii_to_t9_table[static_cast<int>('c')] = string("222");
  ascii_to_t9_table[static_cast<int>('d')] = string("3");
  ascii_to_t9_table[static_cast<int>('e')] = string("33");
  ascii_to_t9_table[static_cast<int>('f')] = string("333");
  ascii_to_t9_table[static_cast<int>('g')] = string("4");
  ascii_to_t9_table[static_cast<int>('h')] = string("44");
  ascii_to_t9_table[static_cast<int>('i')] = string("444");
  ascii_to_t9_table[static_cast<int>('j')] = string("5");
  ascii_to_t9_table[static_cast<int>('k')] = string("55");
  ascii_to_t9_table[static_cast<int>('l')] = string("555");
  ascii_to_t9_table[static_cast<int>('m')] = string("6");
  ascii_to_t9_table[static_cast<int>('n')] = string("66");
  ascii_to_t9_table[static_cast<int>('o')] = string("666");
  ascii_to_t9_table[static_cast<int>('p')] = string("7");
  ascii_to_t9_table[static_cast<int>('q')] = string("77");
  ascii_to_t9_table[static_cast<int>('r')] = string("777");
  ascii_to_t9_table[static_cast<int>('s')] = string("7777");
  ascii_to_t9_table[static_cast<int>('t')] = string("8");
  ascii_to_t9_table[static_cast<int>('u')] = string("88");
  ascii_to_t9_table[static_cast<int>('v')] = string("888");
  ascii_to_t9_table[static_cast<int>('w')] = string("9");
  ascii_to_t9_table[static_cast<int>('x')] = string("99");
  ascii_to_t9_table[static_cast<int>('y')] = string("999");
  ascii_to_t9_table[static_cast<int>('z')] = string("9999");

  int num_cases;
  cin >> num_cases;

  cin.ignore(1, '\n');

  for (int i = 0; i < num_cases; ++i) {
    string line_str;
    getline(cin, line_str);

    cout << "Case #" << i + 1 << ": ";

    string last_key = "x";
    for (int j = 0; j < line_str.size(); ++j) {
      string key = ascii_to_t9_table[static_cast<int>(line_str[j])];

      if (key[0] == last_key[0]) {
        cout << " ";
      }

      cout << key;

      last_key = key;
    }
    cout << endl;
  }

  return 0;
}
