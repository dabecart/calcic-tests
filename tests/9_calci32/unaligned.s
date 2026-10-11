    # Test reading of unaligned memory.

    .section data
data:
    .long 0

    .section text
    .global main
main:
    mov $0xcafe0000, %r0
    sto %r0, data
    mov $0x0000bebe, %r0
    sto %r0, data+4

    mov data, %op1
    mov $0xcafe0000, %op2
    sub
    bne error

    mov data+1, %op1
    mov $0xbecafe00, %op2
    sub
    bne error

    mov data+2, %op1
    mov $0xbebecafe, %op2
    sub
    bne error

    mov data+3, %op1
    mov $0x00bebeca, %op2
    sub
    bne error

    mov data+4, %op1
    mov $0x0000bebe, %op2
    sub
    bne error

    # Test writing to unaligned memory.
    mov $0xb1, %r0
    sto8 %r0, data+3
    mov $0x6b, %r0
    sto8 %r0, data+2
    mov $0xb, %r0
    sto8 %r0, data+1
    mov $0x13, %r0
    sto8 %r0, data

    mov data, %op1
    mov $0xb16b0b13, %op2
    sub
    bne error

    clr %r0
    ret

error:
    set %r0
    ret
