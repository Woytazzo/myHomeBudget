#include <ctime>
#include <string>
#include <iostream>
#include "Markup.h"
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Incomes.xml", "Expenses.xml", "Users.xml");

    personalBudget.mainMenus();
    return 0;
}

