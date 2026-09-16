#include <iostream>
#include <fstream>

#include "./third_party/nlohmann/json.hpp"

int main(){

  using json = nlohmann::json;

  std::ifstream f1("example1.json");
  json data1 = json::parse(f1);

  std::ifstream f2("example2.json");
  json data2 = json::parse(f2);

  json patch = json::diff(data1, data2);

  for (const auto& item : data1["Data"]["LineItems"])
  {
      std::cout << item["LineItemId"] << " | "
                << item["ItemNumber"] << " | "
                << item["Category"] << '\n';
  }

  std::cout << "\n--- NEW FILE ---\n";

  for (const auto& item : data2["Data"]["LineItems"])
  {
      std::cout << item["LineItemId"] << " | "
                << item["ItemNumber"] << " | "
                << item["Category"] << '\n';
  }

  for (const auto& item : data2["Data"]["LineItems"])
  {
    if(item["ItemNumber"] == "S15"){
        std::cout << item["SubLineItems"].dump(4) << '\n';
    }
  }

  return 0;
}

