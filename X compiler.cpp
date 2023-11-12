#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class xc {
	private:
		struct processed_code {
			vector<string> line;
			char code_line_break[1000001];
		};
		int semicolon = 0;
	public:
		xc(string coding) {
			processed_code cod;
			for (const string& str : cod.line) {
				if (ckeck_semicolon(str)) {
					auto it = find(cod.line.begin(), cod.line.end(), str);
					int index = distance(cod.line.begin(), it);
					string error = "The " + to_string(index) + " line is missing a semicolon.";
					throw runtime_error(error);
				}
			}
			cod.line = splitString(coding, ";");
			cod.line.erase(remove(cod.line.begin(), cod.line.end(), ""), cod.line.end());
			for (size_t i = 0; i < cod.line.size(); i++) {
				if (i < cod.line.size() - 1) {
					cod.line[i] += "\n";
				}
			}
			for (string& str : cod.line) {
				if (!str.empty()) {
					for (char c : str) {
						if (c == '{' || c == '}') {
							size_t pos = str.find(c);
							if (pos != string::npos) {
								str.insert(pos + 1, 1, '\n');
							}
						}
					}
				}
			}
			debug(cod.line);
			regex fn("fn [a-zA-Z]*\\([a-zA-Z].*\\)\\{[^\\}]*\\}");
			for (size_t i = 0; i < cod.line.size(); i++) {
				if (regex_search(cod.line[i], fn)) {

				}
			}
		}
		~xc() {
			cout << "--------------------------------------------------------" << endl << "The program has finished running. Press any key to exit." << endl;
			if (getchar()) {
				HWND hwnd = GetConsoleWindow();
				ShowWindow(hwnd, SW_MINIMIZE);
				ShowWindow(hwnd, SW_HIDE);
			}
		}
		bool ckeck_semicolon(const string& line) {
			if (line.back() == ';') {
				return true;
			}
			return false;
		}
		vector<string> splitString(const string& input, const string& delimiter) {
			vector<string> result;
			size_t pos = 0;
			string token;
			string inputCopy = input;
			while ((pos = inputCopy.find(delimiter)) != string::npos) {
				token = inputCopy.substr(0, pos);
				result.push_back(token);
				inputCopy.erase(0, pos + delimiter.length());
			}
			result.push_back(inputCopy);
			return result;
		}
		void debug(vector<string> s) {
			for (const auto& c : s) {
				cout << c;
			}
		}
};
int main() {
	string s;
	try {
		xc XC("fn main(){int a=1;int b=1;}");
	} catch (const runtime_error& e) {
		cout << e.what();
	}
	
	return 0;
}
