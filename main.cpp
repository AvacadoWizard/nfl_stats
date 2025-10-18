#include <cpr/cpr.h>
#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>


using namespace std;
using json = nlohmann::json;

// cpr knowledge base:
//https://www.studyplan.dev/pro-cpp/http
//nfl api
//https://rapidapi.com/Creativesdev/api/nfl-api-data

// codespace line
//    g++ main.cpp -o my_program -I/cpr/include -L/cpr/lib -lcpr -lcurl -lpthread -lssl -lcrypto -ldl

string apiKey = "461dd69170mshee1346d1aac95c7p13de84jsn5a60f90aed53";

void saveToFile(const string& filename, const json& j) {
  ofstream file(filename);
  if (file.is_open()) {
    file << j.dump(4); // Pretty-print with 4 spaces indentation
    file.close();
    cout << "Data saved to " << filename << endl;
  } else {
    cerr << "Unable to open file " << filename << " for writing." << endl;
  }
}

cpr::Response getResponse(const string& endpoint) {
  return cpr::Get(cpr::Url{"https://nfl-api-data.p.rapidapi.com/" + endpoint},
                  cpr::Header{{"X-RapidAPI-Key", apiKey},
                              {"X-RapidAPI-Host", "nfl-api-data.p.rapidapi.com"}});
}

void listTeams(const bool saveToFileFlag = false) {
  cpr::Response r = getResponse("nfl-team-listing/v1/data");
  json Doc{json::parse(r.text)};

  if (saveToFileFlag) {
    saveToFile("nfl_teams.json", Doc);
  }

  for (auto& element : Doc[0]) {
    cout << element["team"]["displayName"] << " - " << element["team"]["abbreviation"] << endl;
  }
}

void liveGames(const bool saveToFileFlag = false) {
  cpr::Response r = getResponse("nfl-live");

  json Doc{json::parse(r.text)};
  for (auto& element : Doc["live"]) {
    cout << element["homeCompetitor"]["name"] << " vs " << element["awayCompetitor"]["name"] << " : " << element["statusText"] << endl;
    cout << "Score: " << element["homeCompetitor"]["score"] << " - " << element["awayCompetitor"]["score"] << endl;
  }
}

boolean isGameLive

int main() {
  listTeams(true);

  return 0;
}
