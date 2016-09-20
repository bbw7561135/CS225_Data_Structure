/* Problem of the Day -- Question 2 -- Students Code */

#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    time_t result = time(nullptr);
    signed long sec = result;
    signed long hrs = sec / 3600;
    signed long yrs = hrs / (24 * 365);
    cout << "Seconds: " << sec << endl;
    cout << "Hours: " << hrs << endl;
    cout << "Years: " << yrs << endl;
    
    return 0;
}