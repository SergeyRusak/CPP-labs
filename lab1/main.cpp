#include "iostream"
#include "string"
#include <fstream>
using namespace std;
int main(void) {
	string type1, value1, opr, type2, value2;
	cout << "enter expresion like \"type1 value1 operator type2 value2\" :";
	cin >> type1 >> value1 >> opr >> type2 >> value2;
	ofstream fout("func_1.cpp");
	fout << "#include <iostream>" << endl;
	fout << "int main(void) {" << endl;
	fout << type1 << " var1 ="<<value1 <<";" << endl;
	fout << type2 << " var2 =" << value2 << ";" << endl;
	fout << "std::cout << var1 "<<opr<<" var2 << std::endl;" << endl;
	fout << "return 0;" << endl;
	fout << "}" << endl;
	fout.close();
	return 0;
}
