# Execute test setup script
do ../tests/CPU_graphs.tcl

# Run simulation
run -all

# Read the register value (-value returns raw data without signal name)
set reg_val [examine -radix hex -value {sim:/cpu_test/DUT/GenerateRegisters(0)/regInst/registerData}]

# Output formatted string for capture
puts "REGISTER_VALUE_OUTPUT: $reg_val"

# Exit Questa batch mode
exit -f