#include "useby.h"
#include "usebyConfig.h"

#include <ctime>
#include <iostream>
#include <sstream>

// Make a tm structure representing this date
std::tm make_tm(int year, int month, int day)
{
  std::tm tm = {0};
  tm.tm_year = year - 1900; // years count from 1900
  tm.tm_mon = month - 1;    // months count from January=0
  tm.tm_mday = day;         // days count from 1
  return tm;
}

std::string authentificate()
{
  return(UB_AUTHENTIFICATION_KEY); 
}

bool authorize()
{
  std::tm tmTime;
  std::stringstream parser(UB_DEADLINE);
  int y,m,d;
  parser >> y >> m >> d;
  tmTime = make_tm(y,-m,-d+1);
  time_t t2 = mktime(&tmTime);
  time_t rawTime;
  time(&rawTime);
  return(t2-rawTime>=0);
}

