simulate 1 [minute_clock<=(time_offset+16)]{consumed_power}
strategy S = loadStrategy {} -> {minute_clock, Ti[0], Ti[1], Ti[2], Ti[3], Toutdoor, Tforward} (strategy_path)
simulate 1 [minute_clock<=(time_offset+16)]{consumed_power} under S
