#include "menu.h"
#include <QApplication>
#include <string.h>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();

    return a.exec();
}




