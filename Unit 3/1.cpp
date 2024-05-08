#include <iostream>

using namespace std;

int& Ref_func(int& param) {

return (++param);

}

int main() {

int x = 10, y = 15, z = 14;

y = Ref_func(x);

cout << x << " " << y << " ";

Ref_func(x) = z;

cout << x << " " << y;

return 0;

}
