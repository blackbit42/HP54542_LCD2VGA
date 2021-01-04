// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VHP54542C_LCD2VGA_H_
#define _VHP54542C_LCD2VGA_H_  // guard

#include "verilated.h"

//==========

class VHP54542C_LCD2VGA__Syms;
class VHP54542C_LCD2VGA_VerilatedVcd;


//----------

VL_MODULE(VHP54542C_LCD2VGA) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(iw_clk,0,0);
    VL_IN8(iw_sync,0,0);
    VL_IN8(iw_r0,0,0);
    VL_IN8(iw_g0,0,0);
    VL_IN8(iw_b0,0,0);
    VL_OUT8(ow_r0,0,0);
    VL_OUT8(ow_g0,0,0);
    VL_OUT8(ow_b0,0,0);
    VL_OUT8(ow_hsync,0,0);
    VL_OUT8(ow_vsync,0,0);
    VL_OUT8(D1,0,0);
    VL_OUT8(D2,0,0);
    VL_OUT8(D3,0,0);
    VL_OUT8(D4,0,0);
    VL_OUT8(D5,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ HP54542C_LCD2VGA__DOT__reset;
    CData/*0:0*/ HP54542C_LCD2VGA__DOT__clock_led;
    CData/*0:0*/ HP54542C_LCD2VGA__DOT__last_clk_was_sync;
    SData/*9:0*/ HP54542C_LCD2VGA__DOT__hpos;
    SData/*9:0*/ HP54542C_LCD2VGA__DOT__vpos;
    IData/*31:0*/ HP54542C_LCD2VGA__DOT__r32_clk_counter;
    IData/*31:0*/ HP54542C_LCD2VGA__DOT__r32_last_sync_pulse;
    IData/*31:0*/ HP54542C_LCD2VGA__DOT__r32_ticks_between_sync;
    IData/*24:0*/ HP54542C_LCD2VGA__DOT__clock_blinker;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__iw_clk;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VHP54542C_LCD2VGA__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VHP54542C_LCD2VGA);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VHP54542C_LCD2VGA(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VHP54542C_LCD2VGA();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VHP54542C_LCD2VGA__Syms* symsp, bool first);
  private:
    static QData _change_request(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp);
    static QData _change_request_1(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VHP54542C_LCD2VGA__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
