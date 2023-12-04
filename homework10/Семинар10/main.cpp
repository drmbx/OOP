#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include "xml.h"
#include "json.h"
using namespace std;
//программа управления финансами

struct Spending {
    string category; //категория затрат
    int amount; //количество затрат
};
//считает сколько денег потратили
int CalculateTotalSpendings(const vector<Spending>& spendings) {
    int result = 0;
    for (const Spending& s : spendings) {
        result += s.amount;
    }
    return result;
}
//функция обработки расходов
//находит саму дорогую категорию расходов
string MostExpensiveCategory(const vector<Spending>& spendings) {
    auto compare_by_amount = [](const Spending& lhs, const Spending& rhs) {
        return lhs.amount < rhs.amount;
    };
    return max_element(begin(spendings), end(spendings), compare_by_amount)->category;
}
vector<Spending> LoadFromXml(istream& input) {
  Xml::Document doc = Xml::Load(input);
  vector<Spending> result;
  for (const Xml::Node& node : doc.GetRoot().Children()) {
    result.push_back({
      node.AttributeValue<string>("category"),
      node.AttributeValue<int>("amount")
    });
  }
  return result;
}

vector<Spending> LoadFromJson(istream& input) {
  Json::Document doc = Json::Load(input);
  vector<Spending> result;
  for (const Json::Node& node : doc.GetRoot().AsArray()) {
    result.push_back({
      node.AsMap().at("category").AsString(),
      node.AsMap().at("amount").AsInt()
    });
  }
  return result;
}

int main() {
    const vector<Spending> spendings = {
    {"food", 2500},
    {"transport", 1150},
    {"restaurants", 5780},
    {"clothes", 7500},
    {"travel", 23740},
    {"sport", 12000}
    };
    cout << "Total " << CalculateTotalSpendings(spendings) << endl;
    cout << "Most expensive " << MostExpensiveCategory(spendings) << endl;
}