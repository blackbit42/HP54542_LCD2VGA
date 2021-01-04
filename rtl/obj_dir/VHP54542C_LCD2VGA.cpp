// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VHP54542C_LCD2VGA.h for the primary calling header

#include "VHP54542C_LCD2VGA.h"
#include "VHP54542C_LCD2VGA__Syms.h"

//==========

void VHP54542C_LCD2VGA::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VHP54542C_LCD2VGA::eval\n"); );
    VHP54542C_LCD2VGA__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("rtl/HP54542C_LCD2VGA.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VHP54542C_LCD2VGA::_eval_initial_loop(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("rtl/HP54542C_LCD2VGA.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VHP54542C_LCD2VGA::_sequent__TOP__3(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_sequent__TOP__3\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__HP54542C_LCD2VGA__DOT__hpos;
    SData/*9:0*/ __Vdly__HP54542C_LCD2VGA__DOT__vpos;
    IData/*31:0*/ __Vdly__HP54542C_LCD2VGA__DOT__r32_clk_counter;
    IData/*24:0*/ __Vdly__HP54542C_LCD2VGA__DOT__clock_blinker;
    // Body
    __Vdly__HP54542C_LCD2VGA__DOT__clock_blinker = vlTOPp->HP54542C_LCD2VGA__DOT__clock_blinker;
    __Vdly__HP54542C_LCD2VGA__DOT__r32_clk_counter 
        = vlTOPp->HP54542C_LCD2VGA__DOT__r32_clk_counter;
    __Vdly__HP54542C_LCD2VGA__DOT__vpos = vlTOPp->HP54542C_LCD2VGA__DOT__vpos;
    __Vdly__HP54542C_LCD2VGA__DOT__hpos = vlTOPp->HP54542C_LCD2VGA__DOT__hpos;
    if ((0x17d7840U == vlTOPp->HP54542C_LCD2VGA__DOT__clock_blinker)) {
        vlTOPp->HP54542C_LCD2VGA__DOT__clock_led = 
            ((IData)(vlTOPp->HP54542C_LCD2VGA__DOT__clock_led)
              ? 0U : 1U);
        __Vdly__HP54542C_LCD2VGA__DOT__clock_blinker = 0U;
    } else {
        __Vdly__HP54542C_LCD2VGA__DOT__clock_blinker 
            = (0x1ffffffU & ((IData)(1U) + vlTOPp->HP54542C_LCD2VGA__DOT__clock_blinker));
    }
    __Vdly__HP54542C_LCD2VGA__DOT__r32_clk_counter 
        = ((IData)(vlTOPp->HP54542C_LCD2VGA__DOT__reset)
            ? 0U : ((IData)(1U) + vlTOPp->HP54542C_LCD2VGA__DOT__r32_clk_counter));
    if (vlTOPp->HP54542C_LCD2VGA__DOT__reset) {
        __Vdly__HP54542C_LCD2VGA__DOT__hpos = 0U;
        __Vdly__HP54542C_LCD2VGA__DOT__vpos = 0U;
        vlTOPp->HP54542C_LCD2VGA__DOT__reset = 0U;
    } else {
        if ((0x31fU > (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__hpos))) {
            __Vdly__HP54542C_LCD2VGA__DOT__hpos = (0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__hpos)));
        } else {
            __Vdly__HP54542C_LCD2VGA__DOT__vpos = (
                                                   (0x20dU 
                                                    > (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__vpos))
                                                    ? 
                                                   (0x3ffU 
                                                    & ((IData)(1U) 
                                                       + (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__vpos)))
                                                    : 0U);
            __Vdly__HP54542C_LCD2VGA__DOT__hpos = 0U;
        }
    }
    if (vlTOPp->iw_sync) {
        if ((1U & (~ (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__last_clk_was_sync)))) {
            if ((0x3e8U < vlTOPp->HP54542C_LCD2VGA__DOT__r32_ticks_between_sync)) {
                vlTOPp->HP54542C_LCD2VGA__DOT__reset = 1U;
            }
            vlTOPp->HP54542C_LCD2VGA__DOT__r32_ticks_between_sync 
                = (vlTOPp->HP54542C_LCD2VGA__DOT__r32_clk_counter 
                   - vlTOPp->HP54542C_LCD2VGA__DOT__r32_last_sync_pulse);
            vlTOPp->HP54542C_LCD2VGA__DOT__r32_last_sync_pulse 
                = vlTOPp->HP54542C_LCD2VGA__DOT__r32_clk_counter;
        }
    }
    vlTOPp->HP54542C_LCD2VGA__DOT__clock_blinker = __Vdly__HP54542C_LCD2VGA__DOT__clock_blinker;
    vlTOPp->HP54542C_LCD2VGA__DOT__r32_clk_counter 
        = __Vdly__HP54542C_LCD2VGA__DOT__r32_clk_counter;
    vlTOPp->HP54542C_LCD2VGA__DOT__vpos = __Vdly__HP54542C_LCD2VGA__DOT__vpos;
    vlTOPp->HP54542C_LCD2VGA__DOT__hpos = __Vdly__HP54542C_LCD2VGA__DOT__hpos;
    vlTOPp->D2 = vlTOPp->HP54542C_LCD2VGA__DOT__clock_led;
    vlTOPp->HP54542C_LCD2VGA__DOT__last_clk_was_sync 
        = vlTOPp->iw_sync;
    vlTOPp->ow_vsync = (1U & (~ ((0x1eaU < (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__vpos)) 
                                 & (0x1ecU > (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__vpos)))));
    vlTOPp->ow_hsync = (1U & (~ ((0x28fU < (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__hpos)) 
                                 & (0x2efU > (IData)(vlTOPp->HP54542C_LCD2VGA__DOT__hpos)))));
}

VL_INLINE_OPT void VHP54542C_LCD2VGA::_combo__TOP__4(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_combo__TOP__4\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void VHP54542C_LCD2VGA::_eval(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_eval\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->iw_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__iw_clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__iw_clk = vlTOPp->iw_clk;
}

VL_INLINE_OPT QData VHP54542C_LCD2VGA::_change_request(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_change_request\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VHP54542C_LCD2VGA::_change_request_1(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_change_request_1\n"); );
    VHP54542C_LCD2VGA* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VHP54542C_LCD2VGA::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VHP54542C_LCD2VGA::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((iw_clk & 0xfeU))) {
        Verilated::overWidthError("iw_clk");}
    if (VL_UNLIKELY((iw_sync & 0xfeU))) {
        Verilated::overWidthError("iw_sync");}
    if (VL_UNLIKELY((iw_r0 & 0xfeU))) {
        Verilated::overWidthError("iw_r0");}
    if (VL_UNLIKELY((iw_g0 & 0xfeU))) {
        Verilated::overWidthError("iw_g0");}
    if (VL_UNLIKELY((iw_b0 & 0xfeU))) {
        Verilated::overWidthError("iw_b0");}
}
#endif  // VL_DEBUG
