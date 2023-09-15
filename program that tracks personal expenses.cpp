#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Expense {
public:
    string category;
    double amount;
    string date;

    Expense(string cat, double amt, string dt) {
        category = cat;
        amount = amt;
        date = dt;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Expense> expenses;

    for (int i = 0; i < n; i++) {
        string cat;
        double amt;
        string dt;
        cin >> cat >> amt >> dt;
        expenses.push_back(Expense(cat, amt, dt));
    }

    string categoryToCalculate;
    cin >> categoryToCalculate;

    double totalExpenses = 0;
    double categoryExpenses = 0;

    for (int i = 0; i < n; i++) {
        totalExpenses += expenses[i].amount;
        if (expenses[i].category == categoryToCalculate) {
            categoryExpenses += expenses[i].amount;
        }
    }

    cout << fixed << setprecision(2); // Set output to two decimal places
    cout << "Total Expenses: " << totalExpenses << endl;
    cout << categoryToCalculate << ": " << categoryExpenses << endl;

    return 0;
}

