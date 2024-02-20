#include <iostream>
#include "vector"
#include "vm.h"
#include "instr.h"

using namespace std;

void test(vector<int> &code, int val) {
    vector<Operand> stack(40);
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
    vector<int> call_test2 { 0, 2, 0, 3, 6, 8, 2, 10, 3, 2, 3, 3,1, 7, 2,};

    test(cst_test, 1);
    test(add_test, 3);
    test(swap_test, 2);
    test(if_test1, 10);
    test(if_test2, 5);
    test(call_test1, 10);
    test(call_test2, 4);

    return 0;
}
