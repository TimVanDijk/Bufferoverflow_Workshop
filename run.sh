#!/usr/bin/env bash
echo "Challenges are running on ports 2500 to 2507" &
socat TCP-LISTEN:2500,reuseaddr,fork EXEC:"./chal1/ch1" &
socat TCP-LISTEN:2501,reuseaddr,fork EXEC:"./chal2/ch2" &
socat TCP-LISTEN:2502,reuseaddr,fork EXEC:"./chal3/ch3" &
socat TCP-LISTEN:2503,reuseaddr,fork EXEC:"./chal4/ch4" &
socat TCP-LISTEN:2504,reuseaddr,fork EXEC:"./chal5/ch5" &
socat TCP-LISTEN:2505,reuseaddr,fork EXEC:"./chal6/ch6" &
socat TCP-LISTEN:2506,reuseaddr,fork EXEC:"./chal7a/ch7a" &
socat TCP-LISTEN:2507,reuseaddr,fork EXEC:"./chal7b/ch7b" 