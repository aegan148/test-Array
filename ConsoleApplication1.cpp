#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

std::string global;
void chos();
void strok_name();
void check(std::map<int, std::string>& map);
bool tru= false;
bool test(const std::string const &kl);
std::map<int, std::string> spisok;
std::map<int, std::string> myMap;
void map2(std::map<int, std::string>& map, int& v, std::string& s);
void prover();
std::string key;
int value;
void compare(std::map<int, std::string>& r, int & val, std::string & name);
bool test_empty(std::ifstream& file, bool& tes);
std::string name1;
int id1;

int main()
{
	do {
		chos();//осн меню 
		test(global);// проверка на выход из do
		if (global[0] == '1') {
			strok_name();
		}
		else if (global[0] == '2') {
			prover();
		}
		else if (global[0] == '3') {
			check(myMap);
		}
		else if (global[0] == '4') {
			return 0;
		}
		else { std::cout << "Uknown command. Reenter your choose"<< std::endl << std::endl;};
	} while (tru == false);

	return 0;
}
	//меню
	void chos() {
		std::cout << "Hello! Press the button what do you wanna do" << std::endl;
		std::cout << "1- Filling the list of pass;" << std::endl;
		std::cout << "2- Showing all of the key;" << std::endl;
		std::cout << "3- Get validition;" << std::endl;
		std::cout << "4- Exit" << std::endl;
		std::cin >> global;
	};

	//заполнение карты и передача пар-ключей в файл
	void strok_name()
	{
		std::cout << "Enter a new user from keybord"<< std::endl;
			for (int i = 0; i < 1; i++) {
				int a;
				std::string b;
				std::cout << "Enter id" << std::endl;
				while (!(std::cin >> a) || (std::cin.peek() != '\n'))
				{
					std::cin.clear();
					while (std::cin.get() != '\n');
					std::cout << "Error!The entered id isn't number. Reenter correct id(number)" << std::endl;
				};
				std::cout << "Enter password" << std::endl;
				std::cin >> b;
				spisok[a] = b;
				std::cout<< std::endl;
			};
			std::ofstream fil("file.txt", std::ios::in | std::ios::app);
			if (!fil) {
				std::cout << "File error - can't open to write data!";
			};
			for (std::map<int, std::string>::iterator i = spisok.begin(); i != spisok.end(); ++i)
			{
				fil << i->first<< " "<<  i->second << "\n";
			}
		fil.close();
		std::cout << "Done!"<< std::endl;
	}
	// проверка на выход из do{}
	bool test(const std::string const& kl) {
		if (kl == "4") {
			tru = true;
		}
		return tru;
	};
	// при вызове 2. вывод пар-ключей из файла
	void prover() {
		map2(myMap, value, key);
	for (std::map<int ,std::string >::iterator i = myMap.begin(); i != myMap.end(); ++i)
	{
		std::cout << i->first << " = " << i->second << "\n";
	}
	};
	// при вызове 3. Создание карты из текстового файла с дальнейшим сравнением запроса пар от пользователя
	void check(std::map<int, std::string>& map) {
		map2(map, value, key);
		if (map.size() != 0) {
			id1;
			int test_num = 0;
			name1;
			std::cout << "Enter the id(number)" << std::endl;
			while (!(std::cin >> id1) || (std::cin.peek() != '\n'))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "Error!The entered id isn't number. Reenter correct id(number)" << std::endl;
			}
			std::cout << std::endl;
			std::cout << "Enter the password" << std::endl;
			std::cin >> name1;
			std::cout << std::endl;
			std::cout << std::endl << "Comparing the key...." << std::endl;
			compare(myMap, id1, name1);
		}
	}

	//продолжение 3. Сравнение на совпадение пар-ключей и данных от пользователя
	void compare(std::map<int, std::string>& r,int  &val, std::string & name)
	{
		std::map<int, std::string>::iterator ri = r.find(val);
		std::map<int, std::string>::iterator i = r.begin(); i != r.end();
		
		if (ri != r.end()) {
			std::map<int, std::string>::iterator i = r.begin(); i != r.end();
			if((ri->second)== name)
			std::cout << "Entering allowed" << std::endl << "____________________________" << std::endl << std::endl;
			else {
				std::cout << "Entering not allowed" << std::endl << "____________________________" << std::endl << std::endl;
			}
		}
		else {
			std::cout << "Entering not allowed" << std::endl << "____________________________" << std::endl << std::endl;
		}
	};
	//заполнение массива из готового файла пар-ключей(БД)
	void map2(std::map<int, std::string> & map, int & v, std::string & s) {
		std::ifstream fil("file.txt");
		//проверка существования файла
		bool test = false;
		test_empty(fil, test);
		if (test == false)
			std::cout << "File is opened\n\n" << std::endl;
		else {
			std::cout << "File isn't opened! Back to the menu and create the data file\n" << std::endl;
		}
		while (fil >> v >> s)
			map[v] = s;
		fil.close();
	}
	// реализация проверки существования файла
	bool test_empty(std::ifstream & file, bool & tes) {
		tes = false;
		if (file.is_open()) {}		
		else{tes = true;return tes ;}
	}
