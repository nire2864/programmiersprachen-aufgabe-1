#include <iostream>


double mile_to_kilometer(double in) {
  if(in < 0) {
    std::cout << "Please instert a positive distance. \n";
    return -1;
  }
  in *= 1.609344;
  return in;
}


int main()
{
    std::cout << "For converting miles to kilometers please insert a number with the folowing format: 12.34 \n";
    double temp = 0.0;
    std::cin >> temp;
    std::cout << temp << " miles are " << mile_to_kilometer(temp)<< " kilometers. \n";
    
    return 0; 
}