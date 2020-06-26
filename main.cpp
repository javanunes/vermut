#include "form.h"
#include "ui_form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FORM w;
    w.show();

    return a.exec();
}
