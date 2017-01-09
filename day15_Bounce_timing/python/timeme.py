from timeit import Timer

t1 = Timer('part1.run()', 'import part1')
reps = 10
part1 = sum(t1.repeat(repeat=reps, number=1)) / reps

t2 = Timer('part2.run()', 'import part2')
part2 = sum(t2.repeat(repeat=reps, number=1)) / reps

print "Pure python: %0.4f" %(part1)
print "Pure python: %0.4f" %(part2)
