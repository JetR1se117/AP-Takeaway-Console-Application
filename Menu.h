//#include <string>
#include "ItemList.h"
#include <string>
using namespace std;

class Menu:public ItemList
{
private:
	void appImport(stringstream& sbase, string line);
	void mainImport(stringstream& sbase, string line);
	void bevImport(stringstream& sbase, string line);
public:
	Menu(string menuStr);
	string toString();
	void importFile(string menuStr);
	Item* getItemChoice(int x);
	int getItemVectorSize();
}
;