#include <iostream>
using namespace std;

class clase {
  public:
   clase() {}
   void EresTu(clase& c) {
      if(&c == this) cout << "Si, soy yo." << endl;
      else cout << "No, no soy yo." << endl;
   }
};

int main() {
   clase c1, c2;

   c1.EresTu(c2);
   c1.EresTu(c1);

   return 0;
}
