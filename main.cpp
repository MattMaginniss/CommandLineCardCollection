#include <iostream>

using namespace std;

#include "CardController.h"
using namespace controller;

int main() {
    cout << "Hello, World!" << endl;
    CardController controller;
    controller.Run();
    return 0;
}