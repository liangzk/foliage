#include <vector>
#include <iostream>

using namespace std ;

typedef vector<int>::iterator VI ;

vector<int> Intvec ;

VI find(int val)
{
    VI ptr ;
    for (ptr = Intvec.begin() ; ptr != Intvec.end() ; ptr++)
	if (*ptr == val) return ptr ;
    return (VI)0 ;
}
int main()
{

    Intvec.push_back(5) ;
    Intvec.push_back(6) ;
    vector<int>::iterator it, it2 ;
    it = find(5) ;
    cout << *it << endl;
    //Intvec.erase(Intvec.begin()) ;
    it2 = it+1;
    Intvec.erase(it);

    cout << Intvec.size() << endl ;
    cout << Intvec[0] << endl ;
    cout << *it2 << endl;
    return 0 ;
}
