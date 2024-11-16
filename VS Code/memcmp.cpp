#include <iostream>
#include <cstring>
#include<vector>

int main() {
    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";

    int result = memcmp(buffer1, buffer2, sizeof(buffer1));

    if (result > 0)
        std::cout << "'" << buffer1 << "' is greater than '" << buffer2 << "'.\n";
    else if (result < 0)
        std::cout << "'" << buffer1 << "' is less than '" << buffer2 << "'.\n";
    else
        std::cout << "'" << buffer1 << "' is the same as '" << buffer2 << "'.\n";

    return 0;
}