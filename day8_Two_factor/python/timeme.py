from timeit import Timer

t = Timer('part1.run()', 'import part1')
reps = 100
print "Pure python: %0.5f" %(sum(t.repeat(repeat=reps,
                                            number=1)) / reps)
