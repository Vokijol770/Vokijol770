#include <iostream>

using namespace std;
int main() {
    // put your code here
    int a, b, c;
    std::cin >> a >> b;

    c = (((a * a) - b) * ((a * a) - b)) - (4 * ( a * (b * b) )) + (4 * ((( a * a * a) - 5) * (( a * a * a) - 5)));

    std::cout << c;
    return 0;
}