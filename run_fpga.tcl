# Run simulation
run -all

# Read the register value (-value returns raw data without signal name)
set reg_val [examine -radix hex -value {sim:/cpu_test/DUT/GenerateRegisters(0)/regInst/registerData}]
set cpu_state_val [examine -value {sim:/cpu_test/DUT/cpuState}]

# Output formatted string for capture
puts "R0: $reg_val"
puts "CPU_STATE: $cpu_state_val"

# Exit Questa batch mode
exit -f