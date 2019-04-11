#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd(int a, int b)
{
 if(a == 0 && b == 0) {
   std::cout << "Du kannst dein ggT von 0 und 0 nicht bestimmen \n";
   return -1;
   
 }
 if (b == 0) {
   return a;
 } else if(a == 0){
   return b;
 } else {
   gcd(b, a % b);
 }
  
}
TEST_CASE("describe:gcd", "[gcd]")
{
  REQUIRE(gcd(2,4) == 2);
  REQUIRE(gcd(9,6) == 3);
  REQUIRE(gcd(3,7) == 1);
  REQUIRE(gcd(0,0) == -1);
}

int checksum(int in) {
  if(in < 0){
    std::cout << "Eine Quersumme darf nur von natürlichen Zahlen berechent werden.";
    return -1;
  }
  int sum = 0; 
  
  while(in != 0) {
  int temp = in % 10;
  in /= 10;
  sum += temp;
  }
  return sum;

}

TEST_CASE("checksum", "Test") {
  REQUIRE(checksum(1234) == 10);
  REQUIRE(checksum(119649) == 30);
  REQUIRE(checksum(-123512) == -1);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
