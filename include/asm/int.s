global isr0
isr0:
  cli
  push byte 0
  push byte 0
  jmp isr_common_stub

%macro ISR_NOERRCODE 1
  [GLOBAL isr%1]
  isr%1:
    cli
    push byte 0
    push byte %1
    jmp isr_common_stub
%endmacro

%macro ISR_ERRCODE 1
  [GLOBAL isr%1]
  isr%1:
    cli
    push byte %1
    jmp isr_common_stub
%endmacro 