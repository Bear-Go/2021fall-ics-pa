
def_EHelper(csrrw) {
    rtl_hostcall(s, HOSTCALL_CSR, ddest, dsrc1, NULL, id_src2->imm);
}

def_EHelper(csrrs) {
    rtl_hostcall(s, HOSTCALL_CSR, s0, NULL, NULL, id_src2->imm);
    rtl_or(s, s1, s0, dsrc1);
    rtl_mv(s, ddest, s0);
    rtl_hostcall(s, HOSTCALL_CSR, NULL, s1, NULL, id_src2->imm);
}

def_EHelper(ecall) {
    rtl_trap(s, s->pc, 1); // 1
    rtl_jr(s, t0);
}