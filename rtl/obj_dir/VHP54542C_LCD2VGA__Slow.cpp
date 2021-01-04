// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VHP54542C_LCD2VGA.h for the primary calling header

#include "VHP54542C_LCD2VGA.h"
#include "VHP54542C_LCD2VGA__Syms.h"

//==========

VL_CTOR_IMP(VHP54542C_LCD2VGA) {
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = __VlSymsp = new VHP54542C_LCD2VGA__Syms(this, name());
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VHP54542C_LCD2VGA::__Vconfigure(VHP54542C_LCD2VGA__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VHP54542C_LCD2VGA::~VHP54542C_LCD2VGA() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VHP54542C_LCD2VGA::_initial__TOP__1(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_initial__TOP__1\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->D4 = 0U;
    vlTOPp->D5 = 1U;
    vlTOPp->HP54542C_LCD2VGA__DOT__reset = 0U;
    vlTOPp->HP54542C_LCD2VGA__DOT__r32_clk_counter = 0U;
    vlTOPp->HP54542C_LCD2VGA__DOT__r32_last_sync_pulse = 0U;
    vlTOPp->HP54542C_LCD2VGA__DOT__r32_ticks_between_sync = 0U;
    vlTOPp->HP54542C_LCD2VGA__DOT__clock_blinker = 0U;
    vlTOPp->HP54542C_LCD2VGA__DOT__last_clk_was_sync = 0U;
    vlTOPp->HP54542C_LCD2VGA__DOT__clock_led = 0U;
    vlTOPp->HP54542C_LCD2VGA__DOT__vpos = 0U;
    vlTOPp->HP54542C_LCD2VGA__DOT__hpos = 0U;
}

void VHP54542C_LCD2VGA::_settle__TOP__2(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_settle__TOP__2\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->D1 = 0U;
    vlTOPp->D3 = 0U;
    vlTOPp->D2 = vlTOPp->HP54542C_LCD2VGA__DOT__clock_led;
    vlTOPp->ow_vsync = (1U & (~ ((0x1eaU < (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__vpos)) 
                                 & (0x1ecU > (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__vpos)))));
    vlTOPp->ow_hsync = (1U & (~ ((0x28fU < (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__hpos)) 
                                 & (0x2efU > (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__hpos)))));
    if (((0x27fU < (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__hpos)) 
         & (0x31fU > (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__hpos)))) {
        vlTOPp->ow_r0 = 0U;
        vlTOPp->ow_g0 = 0U;
        vlTOPp->ow_b0 = 0U;
    } else {
        vlTOPp->ow_r0 = (1U & (IData)(vlTOPp->iw_r0));
        vlTOPp->ow_g0 = (1U & (IData)(vlTOPp->iw_g0));
        vlTOPp->ow_b0 = (1U & (IData)(vlTOPp->iw_b0));
    }
}

void VHP54542C_LCD2VGA::_eval_initial(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_eval_initial\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__iw_clk = vlTOPp->iw_clk;
}

void VHP54542C_LCD2VGA::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::final\n"); );
    // Variables
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = this->__VlSymsp;
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VHP54542C_LCD2VGA::_eval_settle(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_eval_settle\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VHP54542C_LCD2VGA::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_ctor_var_reset\n"); );
    // Body
    iw_clk = VL_RAND_RESET_I(1);
    iw_sync = VL_RAND_RESET_I(1);
    iw_r0 = VL_RAND_RESET_I(1);
    iw_g0 = VL_RAND_RESET_I(1);
    iw_b0 = VL_RAND_RESET_I(1);
    ow_r0 = VL_RAND_RESET_I(1);
    ow_g0 = VL_RAND_RESET_I(1);
    ow_b0 = VL_RAND_RESET_I(1);
    ow_hsync = VL_RAND_RESET_I(1);
    ow_vsync = VL_RAND_RESET_I(1);
    D1 = VL_RAND_RESET_I(1);
    D2 = VL_RAND_RESET_I(1);
    D3 = VL_RAND_RESET_I(1);
    D4 = VL_RAND_RESET_I(1);
    D5 = VL_RAND_RESET_I(1);
    HP54542C_LCD2VGA__DOT__reset = VL_RAND_RESET_I(1);
    HP54542C_LCD2VGA__DOT__r32_clk_counter = VL_RAND_RESET_I(32);
    HP54542C_LCD2VGA__DOT__r32_last_sync_pulse = VL_RAND_RESET_I(32);
    HP54542C_LCD2VGA__DOT__r32_ticks_between_sync = VL_RAND_RESET_I(32);
    HP54542C_LCD2VGA__DOT__clock_blinker = VL_RAND_RESET_I(25);
    HP54542C_LCD2VGA__DOT__clock_led = VL_RAND_RESET_I(1);
    HP54542C_LCD2VGA__DOT__hpos = VL_RAND_RESET_I(10);
    HP54542C_LCD2VGA__DOT__vpos = VL_RAND_RESET_I(10);
    HP54542C_LCD2VGA__DOT__last_clk_was_sync = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
