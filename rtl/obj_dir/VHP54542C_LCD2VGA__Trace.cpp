// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VHP54542C_LCD2VGA__Syms.h"


void VHP54542C_LCD2VGA::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = static_cast<VHP54542C_LCD2VGA__Syms*>(userp);
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VHP54542C_LCD2VGA::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = static_cast<VHP54542C_LCD2VGA__Syms*>(userp);
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->HP54542C_LCD2VGA__DOT__reset));
            tracep->chgIData(oldp+1,(vlTOPp->HP54542C_LCD2VGA__DOT__r32_clk_counter),32);
            tracep->chgIData(oldp+2,(vlTOPp->HP54542C_LCD2VGA__DOT__r32_last_sync_pulse),32);
            tracep->chgIData(oldp+3,(vlTOPp->HP54542C_LCD2VGA__DOT__r32_ticks_between_sync),32);
            tracep->chgIData(oldp+4,(vlTOPp->HP54542C_LCD2VGA__DOT__clock_blinker),25);
            tracep->chgBit(oldp+5,(vlTOPp->HP54542C_LCD2VGA__DOT__clock_led));
            tracep->chgSData(oldp+6,(vlTOPp->HP54542C_LCD2VGA__DOT__hpos),10);
            tracep->chgSData(oldp+7,(vlTOPp->HP54542C_LCD2VGA__DOT__vpos),10);
            tracep->chgBit(oldp+8,(vlTOPp->HP54542C_LCD2VGA__DOT__last_clk_was_sync));
        }
        tracep->chgBit(oldp+9,(vlTOPp->iw_clk));
        tracep->chgBit(oldp+10,(vlTOPp->iw_sync));
        tracep->chgBit(oldp+11,(vlTOPp->iw_r0));
        tracep->chgBit(oldp+12,(vlTOPp->iw_g0));
        tracep->chgBit(oldp+13,(vlTOPp->iw_b0));
        tracep->chgBit(oldp+14,(vlTOPp->ow_r0));
        tracep->chgBit(oldp+15,(vlTOPp->ow_g0));
        tracep->chgBit(oldp+16,(vlTOPp->ow_b0));
        tracep->chgBit(oldp+17,(vlTOPp->ow_hsync));
        tracep->chgBit(oldp+18,(vlTOPp->ow_vsync));
        tracep->chgBit(oldp+19,(vlTOPp->D1));
        tracep->chgBit(oldp+20,(vlTOPp->D2));
        tracep->chgBit(oldp+21,(vlTOPp->D3));
        tracep->chgBit(oldp+22,(vlTOPp->D4));
        tracep->chgBit(oldp+23,(vlTOPp->D5));
    }
}

void VHP54542C_LCD2VGA::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = static_cast<VHP54542C_LCD2VGA__Syms*>(userp);
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
