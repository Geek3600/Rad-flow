#pragma once

#include <aximm_interface.hpp>
#include <design_context.hpp>
#include <queue>
#include <radsim_defines.hpp>
#include <radsim_module.hpp>
#include <sim_utils.hpp>
#include <string>
#include <systemc.h>
#include <vector>

class embedding_lookup : public radsim_module {
private:
  std::vector<std::queue<uint64_t>>
      _lookup_indecies_fifo; // Lookup indecies FIFO per channel
  std::vector<std::queue<uint64_t>>
      _base_addresses_fifo;              // Base addresses FIFO per channel
  unsigned int _fifo_depth;              // Depth of request FIFOs
  sc_vector<sc_signal<bool>> _fifo_full; // Signals flagging FIFOs are full
  sc_vector<sc_signal<unsigned int>> _id_count; // Counters for transaction IDs
  unsigned int _num_received_responses; // Coutnter for received responses
  unsigned int _num_mem_channels;       // No. of memory channels
  unsigned int _num_mem_controllers;    // No. of memory controllers
  unsigned int _num_mem_channels_per_controller; // No. of channels/controller
  unsigned int _dataw;                           // Data interface bitwidth

public:
  sc_in<bool> rst;
  // Interface to driver logic
  sc_in<data_vector<uint64_t>> lookup_indecies_data;
  sc_in<data_vector<unsigned int>> lookup_indecies_target_channels;
  sc_in<data_vector<uint64_t>> lookup_indecies_base_addresses;
  sc_in<bool> lookup_indecies_valid;
  sc_out<bool> lookup_indecies_ready;
  // Interface to the NoC
  sc_vector<aximm_master_port> aximm_req_interface;

  embedding_lookup(const sc_module_name &name, unsigned int dataw,
                   unsigned int num_mem_channels,
                   unsigned int num_mem_controllers, unsigned int fifo_depth);
  ~embedding_lookup();

  void Assign(); // Combinational logic process
  void Tick();   // Sequential logic process
  SC_HAS_PROCESS(embedding_lookup);
  void RegisterModuleInfo();
};