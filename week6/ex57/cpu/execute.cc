#include "cpu.ih"

bool CPU::execute(Opcode opcode)
{
    if (opcode == Opcode::STOP)
        return false;

        // call appropriate function through pointer in exec[]
    (this->*d_exec[static_cast<int>(opcode)])();
    return true;
}