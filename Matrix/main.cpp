//
//  main.cpp
//  Matrix
//
//  Created by Tobiasz Filar on 20/11/2018.
//  Copyright © 2018 Tobiasz Filar. All rights reserved.
//

#include "matrix_view.h"

using namespace mtrx;

int main(int argc, const char * argv[]) {
    matrix<int, 5, 6> mt;
    show_mtr(mt);
    mt[0][3] = 2;
    std::cout << '\n';
    show_mtr(mt);
    matrix<int, 3,2> mt1(2);
    matrix<int, 3, 2> mt2(3);
    matrix<int, 3, 2> sumtest = mt1 + mt2;
    std::cout << '\n';
    show_mtr(sumtest);
    matrix<int, 3, 2> multiplytest = sumtest * 3;
    std::cout << '\n';
    show_mtr(multiplytest);
    matrix<int, 3, 2> multest2 = 3 * multiplytest;
    std::cout << "multest2 3*multiplaytest[result should be 45 \n";
    show_mtr(multest2);
    std::cout << "mt1 *=2 [result should be 4 \n";
    mt1 *= 2;
    show_mtr(mt1);
    
    matrix<int, 3, 4> cintest;
    std::cin >> cintest;
    
}
