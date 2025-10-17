#include <cpr/cpr.h>
#include <iostream>

using namespace std;

// cpr knowledge base:
//https://www.studyplan.dev/pro-cpp/http
//nfl api
//https://rapidapi.com/Creativesdev/api/nfl-api-data

int main() {
  cpr::Response r = cpr::Get(cpr::Url{"https://nfl-api-data.p.rapidapi.com/nfl-livescores"},
                            cpr::Header{{"X-RapidAPI-Key", "461dd69170mshee1346d1aac95c7p13de84jsn5a60f90aed53"},
                                        {"X-RapidAPI-Host", "nfl-api-data.p.rapidapi.com"}});

  cout << r.text;
  return 0;
}