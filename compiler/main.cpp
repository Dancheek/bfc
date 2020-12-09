#include <fstream>
#include <iostream>
#include <map>
#include <string>
int main(int argc, char **argv) {
        std::map<char, std::string> cmd{{'>', "++i;"},
                                        {'<', "--i;"},
                                        {'+', "++arr[i];"},
                                        {'-', "--arr[i];"},
                                        {'[', "while(arr[i]){"},
                                        {']', "}"},
                                        {'.', "std::cout << arr[i];"},
                                        {',', "std::cin >> arr[i];"}};
        if (argc == 1) {
                std ::cerr << "bfc: no input file" << std::endl;
                return (1);
        }

        char c;
        std::ifstream bf_code(argv[1]);
        std::ofstream bf_out("bf.cpp");

        bf_out << "#include <map>" << std::endl
               << "#include <iostream>" << std::endl
               << " int main(){int i=0;std::map<int,char> arr;";
        while (!bf_code.eof()) {
								bf_code >> c;
                bf_out << cmd[c];
        }
				bf_out << '}';
        bf_out.close();
        system("g++ bf.cpp -O3 -o bf; rm -f bf.cpp");
}
