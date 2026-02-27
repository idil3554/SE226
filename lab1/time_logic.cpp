
#include <iostream>
using namespace std;
int main() {
    int total_seconds;
    cout<<"Enter total seconds: ";
    cin>> total_seconds;

    int hours = total_seconds / 3600;
    int remaining = total_seconds % 3600;
    int minutes = remaining / 60;
    int seconds = remaining % 60;

    cout<<total_seconds<<" second is "<<hours<<" hours, "<<minutes<<" minutes, and "<< seconds<<" seconds."<<endl;
    return 0;

}