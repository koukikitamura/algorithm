#include <iostream>

int main() {
  std::string last_week_contest;

  std::cin >> last_week_contest;

  std::string current_week_contest;
  if(last_week_contest == "ABC") {
    current_week_contest = "ARC";
  } else if (last_week_contest == "ARC") {
    current_week_contest = "ABC";
  }

  std::cout << current_week_contest << std::endl;

  return 0;
}
