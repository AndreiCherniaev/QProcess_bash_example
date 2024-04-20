#include <QCoreApplication>
#include <signal.h>
#include "MainClass.h"

void SigInt_Handler(int n_signal){
    printf("interrupted with code %u\n", n_signal); //Ctrl+C
    QCoreApplication::instance()->quit(); //exit(1);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainClass mainClass(QCoreApplication::instance());

    signal(SIGINT, &SigInt_Handler); //thanks https://github.com/AndreiCherniaev/QCoreApplication_quit_example

    int ret= QCoreApplication::exec();
    return ret;
}
