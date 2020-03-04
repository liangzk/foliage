#include <iostream>
#include <ext/hash_map>

using namespace std ;
using __gnu_cxx::hash_map ;
using __gnu_cxx::hash ;

struct eqstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) == 0;
  }
};

int main()
{
  hash_map<const char*, int, hash<const char*>, eqstr> months;

  char jan[10] = "january" ;

  months[jan] = 31;
  strcpy(jan, "february") ;
  months[jan] = 28;
  months["march"] = 31;
  months["april"] = 30;
  months["may"] = 31;
  months["june"] = 30;
  months["july"] = 31;
  months["august"] = 31;
  months["september"] = 30;
  months["october"] = 31;
  months["november"] = 30;
  months["december"] = 31;
 
  cout << "january  -> " << months["january"] << endl ; 
  cout << "february  -> " << months["february"] << endl ; 
  cout << "september -> " << months["september"] << endl;
  cout << "april     -> " << months["april"] << endl;
  cout << "june      -> " << months["june"] << endl;
  cout << "november  -> " << months["november"] << endl;
}

