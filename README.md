
使用 Clion 编写 

# Encoding specification

| Instr     | Opcode | Oprand1     | Oprand2 | Size | Desc                   |
|-----------|--------|-------------|---------|------|------------------------|
| Cst(i)    | 0      | i           |         | 2    | 添加 i 到栈顶               |
| Add       | 1      |             |         | 1    | 加法，栈顶前两个元素相加           |
| Mul       | 2      |             |         | 1    | 乘法                     |
| Var(i)    | 3      | i           |         | 2    | 引用变量，把距离栈顶深度 i 的值添加到栈顶 |
| Pop       | 4      |             |         | 1    | 丢弃栈顶元素                 |
| Swap      | 5      |             |         | 1    | 交换栈顶前两个元素              |
| Call(l,n) | 6      | get_addr(l) | n       | 3    | 函数调用，pc 指向 l           |
| Ret(n)    | 7      | n           |         | 2    | 函数返回                   |
| IfZero(l) | 8      | get_addr(l) |         | 2    | if_then_else           |
| Goto(l)   | 9      | get_addr(l) |         | 2    | goto l, pc 指向 l        |
| Exit      | 10     |             |         | 1    | 退出                     |
|           |        |             |         |      |                        |
