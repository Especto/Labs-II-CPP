#include "Time.h"

int main()
{
    Time time1("23:31:10");
    Time time2(2, 30, 11);
    Time time3(time2);

    time1.printTime();
    time2.printTime();
    time3.printTime();
    cout << endl;

    time1 += 17;
    time2 += 34;
    Time time4 = time1 - time2;
    time3.left();

    cout << endl;
    time1.printTime();
    time2.printTime();
    time3.printTime();

}
