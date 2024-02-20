#include "vector"
using namespace std;

// 定义操作数类型
typedef int Operand;

// 定义虚拟机类型
class VM {
public:
    VM(const vector<int> & _code, const vector<Operand> & _stack, int _pc);
    vector<int> code;       // code segment (immutable)
    vector<Operand> stack;  // runtime stack
    int pc;                 // pc register
    int sp;                 // pc register

    void push(Operand x);
    Operand pop();
    Operand run();
};

