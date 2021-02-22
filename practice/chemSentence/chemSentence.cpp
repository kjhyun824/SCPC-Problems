#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <locale>
using namespace std;

vector<string> elements = {
		"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
		"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
		"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
		"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
		"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
		"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
		"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
		"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
		"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"};

std::string lower_function(std::string input) {
	std::locale loc;
	std::string output;

	for(std::string::size_type i = 0; i < input.length(); i++) {
		output += std::tolower(input[i], loc);
	}

	return output;
}

bool isChemSentence(std::string input) {
	if(input == "") return true;

	bool result = false;

	if(input.size() >= 2 && std::find(elements.begin(), elements.end(), input.substr(0,2)) != elements.end()) {
		result = isChemSentence(input.substr(2, input.size() - 2));

		if(result) {
			return true;
		}
	} 

	if(std::find(elements.begin(), elements.end(), input.substr(0,1)) != elements.end()) {
		result = isChemSentence(input.substr(1, input.size() - 1));
	}

	return result;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	std::locale loc;
	for(int i = 0; i < elements.size(); i++) {
		elements[i] = lower_function(elements[i]);
	}

	int T, test_case;
	cin >> T;

	for(test_case = 0; test_case  < T; test_case++)
	{
		string input;
		cin >> input;

		input = lower_function(input);

		bool result = isChemSentence(input);

		cout << "Case #" << test_case+1 << endl;
		cout << (result ? "YES" : "NO") << endl;
	}

	return 0;
}
