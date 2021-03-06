#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd(int a, int b)
{
 if(a == 0 && b == 0) {
   std::cout << "The greatest common divisor is for 0 and 0 undefined. \n";
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
    std::cout << "The cross sum is defined only for natural numbers. \n";
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


int sum_multiples() {
  int tempsum = 0;
  for(int i = 3; i < 1001; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      tempsum += i;
    }
  }
  return tempsum;
}

TEST_CASE("sum_multiples") {
  REQUIRE(sum_multiples() == 234168);
}

double fract (double in) {
  if(in < 0) {
    in *= -1;
  }

  int temp = in;
  double out = in - temp;
  return out;
}

TEST_CASE("fract") {
  REQUIRE(fract(5.2) == Approx(0.2));
  REQUIRE(fract(-13.7) == Approx(0.7));
  REQUIRE(fract(132.789) == Approx(0.789));

}


double cylinder_surface(double radius, double height) {
 
 if(radius < 0) {
   std::cout << "Please insert a positive value for the radius. \n";
   return -1;
 }
 
 if(height < 0) {
   height *= -1;
 }
 
 double A = 2* M_PI * radius * (radius + height);
  return A;
}

TEST_CASE("cylinder_surface") {
  REQUIRE(cylinder_surface(10.0 , 10.0)== Approx(1256.637));
  REQUIRE(cylinder_surface(3 , -17) == Approx(376.991));
  REQUIRE(cylinder_surface(-1, 12) == -1);
}

double cylinder_volume(double radius, double height) {
 
   if(radius < 0) {
   std::cout << "Please insert a positive value for the radius. \n";
   return -1;
 }
 
 if(height < 0) {
   height *= -1;
 }

  double V = M_PI * pow(radius, 2.0) * height;
  return V;
}

TEST_CASE("cylinder_volume") {
  REQUIRE(cylinder_volume(10.0 , 10.0)== Approx(3141.593));
  REQUIRE(cylinder_volume(3 , -17) == Approx(480.664));
  REQUIRE(cylinder_volume(-1, 12) == -1);
}

int fractorial(int in) {
  
  if(in < 0) {
    std::cout << "Please insert a natural number. \n";
    return -1;
  }

  int temp = 1;
  
  for (int i = 1; i <= in; i++) {
    temp *= i;
  }
    return temp;
}

TEST_CASE("fractorial") {
  REQUIRE(fractorial(-10) == -1);
  REQUIRE(fractorial(4) == 24);
  REQUIRE(fractorial(10) == 3628800);
}

bool is_prime(int in) {
  bool check = true;
  if(in < 0) {
    std::cout << "A negative number can not be a prime number. \n";
    return false;
  }
  for(int i = 2; i <= in / 2; i++) {
    if (in % i == 0) {
      check = false;
      break;
    }
  }
  return check;
}

TEST_CASE("is_prime") {
  REQUIRE(is_prime(3) == true);
  REQUIRE(is_prime(7) == true);
  REQUIRE(is_prime(4) == false);
  REQUIRE(is_prime(-3) == false);
}


double mile_to_kilometer(double in) {
  if(in < 0) {
    std::cout << "Please instert a positive distance. \n";
    return -1;
  }
  in *= 1.609344;
  return in;
}

TEST_CASE("mile_to_kilometer") {
  REQUIRE(mile_to_kilometer(3) == Approx(4.828032));
  REQUIRE(mile_to_kilometer(7) == Approx(11.265408));
  REQUIRE(mile_to_kilometer(-12) == -1);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
