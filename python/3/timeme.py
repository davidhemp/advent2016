from timeit import Timer

t = Timer('part2.run()', 'import part2')
reps = 100
print "Pure python: %0.3f" %(sum(t.repeat(repeat=reps,
                                            number=1)) / reps)
t = Timer('part1.run()', 'import part1')
reps = 100
print "Pure python: %0.3f" %(sum(t.repeat(repeat=reps,
                                            number=1)) / reps)
