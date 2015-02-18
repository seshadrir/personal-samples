#include <iostream>
#include <thread>

using namespace std;

void helloWorld(){
    cout << "Hello concurrent world !" << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    thread t(helloWorld);

    t.join();
    return 0;
}

