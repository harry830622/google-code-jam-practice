#include <iostream>
#include <vector>

using namespace std;

bool AssignFlavorTypes(vector<vector<pair<int, int> > >& types_customers_like, int current_customer, vector<int>& flavor_types)
{
  if (current_customer == types_customers_like.size()) {
    return true;
  }

  vector<pair<int, int> >& types_customer_like = types_customers_like[current_customer];
  pair<int, int> last_flavor_type(-1, -1);
  for (int i = 0; i < types_customer_like.size(); ++i) {
    int flavor = types_customer_like[i].first;
    int flavor_type = types_customer_like[i].second;

    if (flavor_types[flavor] != -1 && flavor_types[flavor] != flavor_type) {
      continue;
    }

    if (last_flavor_type.first != -1) {
      flavor_types[last_flavor_type.first] = last_flavor_type.second;
    }
    last_flavor_type = make_pair(flavor, flavor_types[flavor]);

    flavor_types[flavor] = flavor_type;

    if (AssignFlavorTypes(types_customers_like, current_customer + 1, flavor_types)) {
      return true;
    }
  }

  return false;
}

int main()
{
  int num_cases;
  cin >> num_cases;

  for (int i = 0; i < num_cases; ++i) {
    int num_flavors;
    cin >> num_flavors;

    int num_customers;
    cin >> num_customers;

    vector<vector<pair<int, int> > > types_customers_like;
    for (int j = 0; j < num_customers; ++j) {
      int num_pairs;
      cin >> num_pairs;

      types_customers_like.push_back(vector<pair<int, int> >());

      for (int k = 0; k < num_pairs; ++k) {
        int flavor;
        cin >> flavor;

        int is_malted;
        cin >> is_malted;

        types_customers_like[j].push_back(make_pair(flavor - 1, is_malted));
      }
    }

    vector<int> flavor_types(num_flavors, -1);

    cout << "Case #" << i + 1 << ": ";
    if (AssignFlavorTypes(types_customers_like, 0, flavor_types)) {
      for (int j = 0; j < flavor_types.size(); ++j) {
        if (flavor_types[j] == -1) {
          cout << 0;
        } else {
          cout << flavor_types[j];
        }

        if (j != flavor_types.size() - 1) {
          cout << " ";
        }
      }
      cout << endl;
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }

  return 0;
}
