#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

int main() {
    cpp_int a = 1;
    cpp_int b = 1;

    for (int i = 0; i < 4784967; ++i) {
        cpp_int next_a = b;
        b += a;
        a = next_a; 
   }

    cout << b << endl;

    return 0;
}

