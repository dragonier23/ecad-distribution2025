// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_timer.h for the primary calling header

#include "Vtb_timer__pch.h"

VlCoroutine Vtb_timer___024root___eval_initial__TOP__Vtiming__0(Vtb_timer___024root* vlSelf);
VlCoroutine Vtb_timer___024root___eval_initial__TOP__Vtiming__1(Vtb_timer___024root* vlSelf);

void Vtb_timer___024root___eval_initial(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_initial\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_timer___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_timer___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VlCoroutine Vtb_timer___024root___eval_initial__TOP__Vtiming__0(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("tb_timer_trace.vcd"s);
    vlSymsp->_traceDumpOpen();
    vlSelfRef.clk = 1U;
    vlSelfRef.rst = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000014ULL, 
                                         nullptr, "tb_timer.sv", 
                                         12);
    vlSelfRef.rst = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000064ULL, 
                                         nullptr, "tb_timer.sv", 
                                         13);
    VL_FINISH_MT("tb_timer.sv", 13, "");
}

VlCoroutine Vtb_timer___024root___eval_initial__TOP__Vtiming__1(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb_timer.sv", 
                                             17);
        vlSelfRef.clk = (1U & (~ (IData)(vlSelfRef.clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_timer___024root___dump_triggers__act(Vtb_timer___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_timer___024root___eval_triggers__act(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_triggers__act\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.rst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_timer___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtb_timer___024root___eval_act(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_act\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_timer___024root___nba_sequent__TOP__0(Vtb_timer___024root* vlSelf);
void Vtb_timer___024root___nba_sequent__TOP__1(Vtb_timer___024root* vlSelf);

void Vtb_timer___024root___eval_nba(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_nba\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_timer___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_timer___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtb_timer___024root___nba_sequent__TOP__0(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___nba_sequent__TOP__0\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("sim_time=%4#      t=%4#\n",0,64,VL_TIME_UNITED_Q(1),
                 64,vlSelfRef.t);
}

void Vtb_timer___024root___nba_sequent__TOP__1(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___nba_sequent__TOP__1\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.t = ((IData)(vlSelfRef.rst) ? 0ULL : 
                   (1ULL + vlSelfRef.t));
}

void Vtb_timer___024root___timing_resume(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___timing_resume\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

bool Vtb_timer___024root___eval_phase__act(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_phase__act\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_timer___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_timer___024root___timing_resume(vlSelf);
        Vtb_timer___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_timer___024root___eval_phase__nba(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_phase__nba\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_timer___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_timer___024root___dump_triggers__nba(Vtb_timer___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_timer___024root___eval(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_timer___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_timer.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_timer___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_timer.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_timer___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_timer___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_timer___024root___eval_debug_assertions(Vtb_timer___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_timer___024root___eval_debug_assertions\n"); );
    Vtb_timer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
