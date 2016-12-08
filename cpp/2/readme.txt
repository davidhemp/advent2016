Part1

Because the code ignores points it can't move to we only need to find the reset
point. Where the code does (RR||LL && UU||DD) as anything before that is
lost information. The order doesn't matter and it can have more than two, there
can also be oppersites so long as there are extra;s to cancel them.
e.g

RRDUULRU = RRUU and no matter where the start it will always end on 3.

Input.
digit1 = RRDDLDDULDLLDU
digit2 = UURRLDDUDRUURUDLLDLDLURDLULDRLLLULLLUDLLDLD
digit3 = LLRRLLRDDULLDLDLDDLDLDULURRDURURDRDRRDLR
digit4 = DDRRRRLRLRDRURUDDRDLDRURLULDDL
digit5 = UUDDDLUDULRUUUUDRLDDD

I think there is an even quicker away doing it backwards but this is good enough

Part2

Oh Geez. The best way I could come up with is generating a vector/list of
disallowed edge squares and preventing the move if the curser attempted to move
into one of them. For this I just used the full movement list as it is just as
quick. 
