#include <iostream>
#include "vector"
#include "vm.h"
#include "instr.h"

using namespace std;

void test(vector<int> &code, int val) {
    vector<Operand> stack(100);
    int init_pc = 0;
    VM machine {code, stack, init_pc};
    int res = machine.run();
    if (res == val) {
        cout << "success" << endl;
    } else {
        cout << "fail, res is: " << res << endl;
    }
}

int main() {
    vector<int> cst_test {Instr::Cst, 1, Instr::Exit};
    vector<int> add_test {Instr::Cst, 1, Instr::Cst, 2, Instr::Add, Instr::Exit};
    vector<int> swap_test {Instr::Cst, 1, Instr::Cst, 2, Instr::Swap, Instr::Pop, Instr::Exit};
    vector<int> if_test1 { 0, 0, 8, 8, 0, 5, 9, 10, 0, 10, 10,};
    vector<int> if_test2 { 0, 1, 8, 8, 0, 5, 9, 10, 0, 10, 10,};
    vector<int> call_test1 { 6, 4, 0, 10, 0, 10, 7, 0,};
    vector<int> call_test2 { 6, 4, 0, 10, 0, 2, 0, 3, 6, 13, 2, 7,
                             0, 3, 1,  3, 1, 1, 7, 2};
    // fact(5)
    vector<int> fact_test {6, 4,  0, 10, 0, 5, 6, 11,  1, 7, 0,  3,
                           0, 8, 28,  3, 0, 3, 1,  0, -1, 1, 6, 11,
                           1, 2,  9, 30, 0, 1, 7,  1};
    // fib(7)
    vector<int> fib_test {6,  4,  0, 10,  0, 7,  6, 11,  1,  7, 0, 3,
                          0,  8, 45,  3,  0, 0, -1,  1,  8, 41, 3, 0,
                          0, -1,  1,  6, 11, 1,  3,  1,  0, -2, 1, 6,
                          11,  1,  1,  9, 43, 0,  1,  9, 47,  0, 1, 7,
                          1, };
    test(cst_test, 1);
    test(add_test, 3);
    test(swap_test, 2);
    test(if_test1, 10);
    test(if_test2, 5);
    test(call_test1, 10);
    test(call_test2, 5);
    test(fact_test, 120);
    test(fib_test, 21);

    return 0;
}
