from timeit import Timer

t = Timer('part1and2.run()', 'import part1and2')
reps = 100
print "Pure python: %0.5f" %(sum(t.repeat(repeat=reps,
                                            number=1)) / reps)
# t = Timer('part1.run()', 'import part1')
# reps = 100
# print "Pure python: %0.3f" %(sum(t.repeat(repeat=reps,
#                                             number=1)) / reps)
