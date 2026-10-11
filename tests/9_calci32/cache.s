    # Test automatic cache loading and flushing.

    .section text
    .global main
main:
    mov $0xbebecafe, %r0
    sto %r0, 0x00000000

    mov $0xdeadbeef, %r0
    sto %r0, 0x00020000

    mov $0x8badf00d, %r0
    sto %r0, 0x00040000

    mov $0xb16b00b5, %r0
    sto %r0, 0x00060000


    mov 0x00000000, %op1
    mov $0xbebecafe, %op2
    sub
    bne failure

    mov 0x00020000, %op1
    mov $0xdeadbeef, %op2
    sub
    bne failure

    mov 0x00040000, %op1
    mov $0x8badf00d, %op2
    sub
    bne failure

    mov 0x00060000, %op1
    mov $0xb16b00b5, %op2
    sub
    bne failure

    clr %r0
    ret

failure:
    set %r0
    ret