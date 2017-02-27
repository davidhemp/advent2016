def process(regs, pos, cmd, nums):
    if cmd == "cpy":
        try:
            regs[nums[1]] = regs[nums[0]]
        except KeyError:
            regs[nums[1]] = int(nums[0])
    elif cmd == "inc":
        regs[nums[0]] += 1
    elif cmd == "dec":
        regs[nums[0]] -= 1
    elif cmd == "jnz":
        try:
            if regs[nums[0]] != 0:
                pos += int(nums[1]) - 1
        except KeyError:
            if int(nums[0]) != 0:
                pos += int(nums[1]) - 1
    return pos, regs


def run(filename="input.txt"):
    regs = {'a':0, 'b':0, 'c':1, 'd':0}
    with open(filename) as f:
        cmd_list = []
        for line in f:
            data = line.strip().split(" ")
            cmd_list.append([data[0], data[1:]])
    pos = 0
    while pos < len(cmd_list):
        pos, regs = process(regs, pos, *cmd_list[pos])
        pos += 1
    return regs['a']

if __name__ == "__main__":
    print(run())
