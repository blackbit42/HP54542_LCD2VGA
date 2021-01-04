// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VHP54542C_LCD2VGA__Syms.h"


//======================

void VHP54542C_LCD2VGA::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VHP54542C_LCD2VGA::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = static_cast<VHP54542C_LCD2VGA__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VHP54542C_LCD2VGA::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VHP54542C_LCD2VGA::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = static_cast<VHP54542C_LCD2VGA__Syms*>(userp);
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VHP54542C_LCD2VGA::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = static_cast<VHP54542C_LCD2VGA__Syms*>(userp);
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+10,"iw_clk", false,-1);
        tracep->declBit(c+11,"iw_sync", false,-1);
        tracep->declBit(c+12,"iw_r0", false,-1);
        tracep->declBit(c+13,"iw_g0", false,-1);
        tracep->declBit(c+14,"iw_b0", false,-1);
        tracep->declBit(c+15,"ow_r0", false,-1);
        tracep->declBit(c+16,"ow_g0", false,-1);
        tracep->declBit(c+17,"ow_b0", false,-1);
        tracep->declBit(c+18,"ow_hsync", false,-1);
        tracep->declBit(c+19,"ow_vsync", false,-1);
        tracep->declBit(c+20,"D1", false,-1);
        tracep->declBit(c+21,"D2", false,-1);
        tracep->declBit(c+22,"D3", false,-1);
        tracep->declBit(c+23,"D4", false,-1);
        tracep->declBit(c+24,"D5", false,-1);
        tracep->declBit(c+10,"HP54542C_LCD2VGA iw_clk", false,-1);
        tracep->declBit(c+11,"HP54542C_LCD2VGA iw_sync", false,-1);
        tracep->declBit(c+12,"HP54542C_LCD2VGA iw_r0", false,-1);
        tracep->declBit(c+13,"HP54542C_LCD2VGA iw_g0", false,-1);
        tracep->declBit(c+14,"HP54542C_LCD2VGA iw_b0", false,-1);
        tracep->declBit(c+15,"HP54542C_LCD2VGA ow_r0", false,-1);
        tracep->declBit(c+16,"HP54542C_LCD2VGA ow_g0", false,-1);
        tracep->declBit(c+17,"HP54542C_LCD2VGA ow_b0", false,-1);
        tracep->declBit(c+18,"HP54542C_LCD2VGA ow_hsync", false,-1);
        tracep->declBit(c+19,"HP54542C_LCD2VGA ow_vsync", false,-1);
        tracep->declBit(c+20,"HP54542C_LCD2VGA D1", false,-1);
        tracep->declBit(c+21,"HP54542C_LCD2VGA D2", false,-1);
        tracep->declBit(c+22,"HP54542C_LCD2VGA D3", false,-1);
        tracep->declBit(c+23,"HP54542C_LCD2VGA D4", false,-1);
        tracep->declBit(c+24,"HP54542C_LCD2VGA D5", false,-1);
        tracep->declBus(c+25,"HP54542C_LCD2VGA p_hpixels_active", false,-1, 31,0);
        tracep->declBus(c+26,"HP54542C_LCD2VGA p_vga_hfp", false,-1, 31,0);
        tracep->declBus(c+27,"HP54542C_LCD2VGA p_vga_hsp", false,-1, 31,0);
        tracep->declBus(c+28,"HP54542C_LCD2VGA p_vga_hbp", false,-1, 31,0);
        tracep->declBus(c+29,"HP54542C_LCD2VGA p_vga_hpixels", false,-1, 31,0);
        tracep->declBus(c+30,"HP54542C_LCD2VGA p_vpixels_active", false,-1, 31,0);
        tracep->declBus(c+31,"HP54542C_LCD2VGA p_vga_vfp", false,-1, 31,0);
        tracep->declBus(c+32,"HP54542C_LCD2VGA p_vga_vsp", false,-1, 31,0);
        tracep->declBus(c+33,"HP54542C_LCD2VGA p_vga_vbp", false,-1, 31,0);
        tracep->declBus(c+34,"HP54542C_LCD2VGA p_vga_vpixels", false,-1, 31,0);
        tracep->declBit(c+35,"HP54542C_LCD2VGA r_found_start", false,-1);
        tracep->declBit(c+1,"HP54542C_LCD2VGA reset", false,-1);
        tracep->declBus(c+2,"HP54542C_LCD2VGA r32_clk_counter", false,-1, 31,0);
        tracep->declBus(c+3,"HP54542C_LCD2VGA r32_last_sync_pulse", false,-1, 31,0);
        tracep->declBus(c+4,"HP54542C_LCD2VGA r32_ticks_between_sync", false,-1, 31,0);
        tracep->declBus(c+5,"HP54542C_LCD2VGA clock_blinker", false,-1, 24,0);
        tracep->declBit(c+6,"HP54542C_LCD2VGA clock_led", false,-1);
        tracep->declBit(c+35,"HP54542C_LCD2VGA sync_led", false,-1);
        tracep->declBus(c+7,"HP54542C_LCD2VGA hpos", false,-1, 9,0);
        tracep->declBus(c+8,"HP54542C_LCD2VGA vpos", false,-1, 9,0);
        tracep->declBit(c+9,"HP54542C_LCD2VGA last_clk_was_sync", false,-1);
    }
}

void VHP54542C_LCD2VGA::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VHP54542C_LCD2VGA::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = static_cast<VHP54542C_LCD2VGA__Syms*>(userp);
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VHP54542C_LCD2VGA::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = static_cast<VHP54542C_LCD2VGA__Syms*>(userp);
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->HP54542C_LCD2VGA__DOT__reset));
        tracep->fullIData(oldp+2,(vlTOPp->HP54542C_LCD2VGA__DOT__r32_clk_counter),32);
        tracep->fullIData(oldp+3,(vlTOPp->HP54542C_LCD2VGA__DOT__r32_last_sync_pulse),32);
        tracep->fullIData(oldp+4,(vlTOPp->HP54542C_LCD2VGA__DOT__r32_ticks_between_sync),32);
        tracep->fullIData(oldp+5,(vlTOPp->HP54542C_LCD2VGA__DOT__clock_blinker),25);
        tracep->fullBit(oldp+6,(vlTOPp->HP54542C_LCD2VGA__DOT__clock_led));
        tracep->fullSData(oldp+7,(vlTOPp->HP54542C_LCD2VGA__DOT__hpos),10);
        tracep->fullSData(oldp+8,(vlTOPp->HP54542C_LCD2VGA__DOT__vpos),10);
        tracep->fullBit(oldp+9,(vlTOPp->HP54542C_LCD2VGA__DOT__last_clk_was_sync));
        tracep->fullBit(oldp+10,(vlTOPp->iw_clk));
        tracep->fullBit(oldp+11,(vlTOPp->iw_sync));
        tracep->fullBit(oldp+12,(vlTOPp->iw_r0));
        tracep->fullBit(oldp+13,(vlTOPp->iw_g0));
        tracep->fullBit(oldp+14,(vlTOPp->iw_b0));
        tracep->fullBit(oldp+15,(vlTOPp->ow_r0));
        tracep->fullBit(oldp+16,(vlTOPp->ow_g0));
        tracep->fullBit(oldp+17,(vlTOPp->ow_b0));
        tracep->fullBit(oldp+18,(vlTOPp->ow_hsync));
        tracep->fullBit(oldp+19,(vlTOPp->ow_vsync));
        tracep->fullBit(oldp+20,(vlTOPp->D1));
        tracep->fullBit(oldp+21,(vlTOPp->D2));
        tracep->fullBit(oldp+22,(vlTOPp->D3));
        tracep->fullBit(oldp+23,(vlTOPp->D4));
        tracep->fullBit(oldp+24,(vlTOPp->D5));
        tracep->fullIData(oldp+25,(0x27fU),32);
        tracep->fullIData(oldp+26,(0x10U),32);
        tracep->fullIData(oldp+27,(0x60U),32);
        tracep->fullIData(oldp+28,(0x30U),32);
        tracep->fullIData(oldp+29,(0x31fU),32);
        tracep->fullIData(oldp+30,(0x1e0U),32);
        tracep->fullIData(oldp+31,(0xaU),32);
        tracep->fullIData(oldp+32,(2U),32);
        tracep->fullIData(oldp+33,(0x21U),32);
        tracep->fullIData(oldp+34,(0x20dU),32);
        tracep->fullBit(oldp+35,(0U));
    }
}
