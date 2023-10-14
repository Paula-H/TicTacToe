#include <QApplication>

#include "Testing.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    Testing test;
    test.testAll();
    QApplication a(argc, argv);
    Repository repository= Repository("D:\\OOP_Laboratoare\\TicTacToe\\jocuri.txt");
    Service service= Service(repository);
    GUI gui=GUI(service);
    gui.show();
    return QApplication::exec();
}
