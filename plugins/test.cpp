#include <iostream.h>
#include <fstream.h>

main() {
  char *buffer = new char[100];
  while (cin.good()) {
    cin.getline(buffer, 100, '\n');
    cout << buffer << '\n';
  }
}
