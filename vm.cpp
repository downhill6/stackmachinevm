#include "cassert"
#include "vm.h"
#include "instr.h"

VM::VM(const vector<int> &_code, const vector<Operand> &_stack, int _pc):
    code{_code},
    stack{_stack},
    pc{_pc},
    sp{0} {}

void VM::push(Operand x) {
    stack[sp] = x;
    sp = sp + 1;
}

Operand VM::pop() {
    if (sp >= 0) {
        sp = sp - 1;
        return stack[sp];
    } else {
        assert(sp >= 0);
        return 0;
    }
}

Operand VM::run() {
    bool interrupt = false;
    while (!interrupt) {
        int opcode = code.at(pc);
        switch (opcode) {
            case Instr::Cst: {
                int i = code.at(pc + 1);
                push(i);
                pc = pc + 2;
                break;
            }
            case Instr::Add: {
                int a = pop();
                int b = pop();
                push(a + b);
                pc = pc + 1;
                break;
            }
            case Instr::Mul: {
                int a = pop();
                int b = pop();
                push(a * b);
                pc = pc + 1;
                break;
            }
            case Instr::Var: {
                int i = code.at(pc + 1);
                int var = stack.at(sp - i);
                push(var);
                pc = pc + 2;
                break;
            }
            case Instr::Pop: {
                pop();
                pc = pc + 1;
                break;
            }
            case Instr::Swap: {
                int a = pop();
                int b = pop();
                push(a);
                push(b);
                pc = pc + 1;
                break;
            }
            case Instr::Call: {
                int target_pc = code.at(pc + 1);
                int arity = code.at(pc + 2);
                int next_pc = target_pc;
                auto pos = stack.begin() + sp - arity;
                stack.insert(pos, pc + 3);
                sp = sp + 1;
                pc = next_pc;
                break;
            }
            case Instr::Ret: {
                int arity = code.at(pc + 1);
                int res = pop();
                sp = sp - arity;
                int next_pc = pop();
                push(res);
                pc = next_pc;
                break;
            }
            case Instr::IfZero: {
                int to = code.at(pc + 1);
                int cond = pop();
                if (cond == 0) {
                    pc = to;
                } else {
                    pc = pc + 2;
                }
                break;
            }
            case Instr::Goto: {
                int to = code.at(pc + 1);
                pc = to;
                break;
            }
            case Instr::Exit: {
                interrupt = true;
                break;
            }
            default:
                assert(false);
        }
    }
    return pop();
}
