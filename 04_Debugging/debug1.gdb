set pagination off
set args 1 12

b 25

condition 1 i % 5 == 0

commands 1
	silent
	printf "@@@ start=%d stop=%d step=%d current=%d\n", M, N, S, i
	c
end

run 
