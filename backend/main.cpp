#include <iostream>
#include <sqlite3.h>
#include "requests.h"

int main() {
    std::cout << "Maintenance Web App Backend Running..." << std::endl;

    // Example of adding a maintenance request
    addRequest(101, "kitchen", "Leaking sink", "2024-11-09 10:00");

    return 0;
}

