#pragma once

#include <chrono>
#include <radsim_config.hpp>
#include <client_wrapper.hpp>
#include <stdlib.h>
#include <systemc.h>
#include <time.h>
#include <queue>

class rtl_add_driver : public sc_module {
private:
  std::queue<int> numbers_to_send;
  
public:
  sc_in<bool> clk;
  sc_out<bool> rst;
  sc_out<sc_bv<DATAW>> client_tdata;
  sc_out<bool> client_tlast;
  sc_out<bool> client_valid;
  sc_in<bool> client_ready;

  rtl_add_driver(const sc_module_name &name);
  ~rtl_add_driver();

  void source();
  void sink();

  SC_HAS_PROCESS(rtl_add_driver);
};