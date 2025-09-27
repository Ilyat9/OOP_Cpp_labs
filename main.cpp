#include <iostream> 
#include "include/days.h"
using namespace std;

int main(){
    int UpSpeed, DownSpeed, desiredHeight;
    cin >> UpSpeed >> DownSpeed >> desiredHeight;
    int days_passed = days(UpSpeed, DownSpeed, desiredHeight);
    cout << days << endl;
    return 0;
}
