A = arch
A == ARCH_X86_64 ? next : dead
A = sys_number
A >= 0x40000000 ? dead : next
A == write ? ok : next
A == read ? ok : next
A == exit ? ok : next
A == exit_group ? ok : next
A == munmap ? ok : next
dead:
return KILL
ok:
return ALLOW