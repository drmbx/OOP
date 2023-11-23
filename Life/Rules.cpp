#include "Rules.h"
#include <fstream>
#include <iostream>

bool endsWith(const std::string& str, const std::string& suffix) {
  if (str.length() < suffix.length())
	return false;
  return str.substr(str.length() - suffix.length()) == suffix;
}

Rules::Rules() {

}

Rules::Rules(const std::string &fileName) {
  if (!(endsWith(fileName,".lif") || (endsWith(fileName,".life"))))
	std::cout << "Warning! Wrong file extension.";
  std::string buf;
  std::ifstream input(fileName);
  std::getline(input, buf);
  if (buf != "#Life 1.06") {
	std::cout << "Warning! No format specification.";

  }

}
