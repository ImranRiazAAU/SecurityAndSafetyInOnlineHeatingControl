strategy S = minE(D) [minute_clock<= (time_offset+(12*60))] {} -> {minute_clock, Ti[0], Ti[1], Ti[2], Ti[3], Toutdoor, Tforward}: <> minute_clock >=(time_offset+(11*60))
saveStrategy(strategy_path, S)
simulate 1 [minute_clock<=(time_offset+16)]{consumed_power} under S
