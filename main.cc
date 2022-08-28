#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#define ERROR(msg) \
  do { std::cerr << "[ERROR] " << msg << "\n"; return EXIT_FAILURE; } while (false)

int main(int argc, const char** argv) {
  std::ios_base::sync_with_stdio(false);
  if (argc != 2) ERROR("Must provide input file name");

  std::ifstream ifs(argv[1]);
  if (!ifs) ERROR("Cannot open file: " + std::string{argv[1]});

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(ifs, line)) {
    lines.push_back(std::move(line));
  }

  std::sort(lines.begin(), lines.end());
  std::for_each(lines.begin(), lines.end(), [](std::string const& line) {
    std::cout << line << "\n";
  });

  return 0;
}