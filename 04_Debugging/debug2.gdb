set pagination off
set args  -100 100 3
set $k = 0

b 25
command 1
    silent
    set $k = $k + 1
    if $k >= 28 && $k <= 35
        printf "@@@ start=%d stop=%d step=%d current=%d\n", M, N, S, i
    end
    c
end

run