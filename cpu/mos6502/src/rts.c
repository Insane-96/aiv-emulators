#include <mos6502.h>

// MODE:  Implied
// HEX:   $60
// LEN:   1
// TIM:   6
// FLAGS: None

static int rts(mos6502_t *cpu)
{
    // read return address from the stack
    unsigned short rt_address = cpu->read16(cpu, ++cpu->sp);
    cpu->sp++;

    // jump to return address
    cpu->pc = rt_address;
    return 6;
}

void rts_init(mos6502_t *cpu) 
{
    cpu->op_codes[0x60] = rts;
}