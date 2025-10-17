#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

// cpr knowledge base:
//https://www.studyplan.dev/pro-cpp/http
//nfl api
//https://rapidapi.com/Creativesdev/api/nfl-api-data

int main() {
  cpr::Response r = cpr::Get(cpr::Url{"https://nfl-api-data.p.rapidapi.com/nfl-livescores"},
                            cpr::Header{{"X-RapidAPI-Key", "461dd69170mshee1346d1aac95c7p13de84jsn5a60f90aed53"},
                                        {"X-RapidAPI-Host", "nfl-api-data.p.rapidapi.com"}});

  json Doc{json::parse(r.text)};

  cout << Doc.dump(4) << endl;
  
  return 0;
}