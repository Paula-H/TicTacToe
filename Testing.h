//
// Created by Paula on 6/18/2023.
//

#ifndef TICTACTOE_TESTING_H
#define TICTACTOE_TESTING_H

class Testing{
private:
    void testJoc();
    void testRepository();
    void testService();
    void testValidator();
public:
    void testAll(){
        testJoc();
        testRepository();
        testService();
        testValidator();
    }
};

#endif //TICTACTOE_TESTING_H
