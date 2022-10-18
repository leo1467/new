#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main(void) {
    int a = 0;
    a = a + 1;
    cout << "124563" << a << endl;
    cout << is_directory(".vscode") << endl;
}