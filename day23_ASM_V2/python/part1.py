import os
from time import sleep

def process(regs, pos, cmd_list):
    cmd, nums = cmd_list[pos]
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
                try:
                    pos += int(nums[1]) - 1
                except ValueError:
                    pos += regs[nums[1]]
        except KeyError:
            if int(nums[0]) != 0:
                try:
                    pos += int(nums[1]) - 1
                except ValueError:
                    pos+= regs[nums[1]]
    elif cmd == "tgl":
        i = regs[nums[0]] + pos
        try:
            old_cmd = cmd_list[i][0]
        except IndexError:
            pass
        else:
            if len(cmd_list[i][1]) == 1:
                if old_cmd == "inc":
                    new_cmd = "dec"
                else:
                    new_cmd = "inc"
            else:
                if old_cmd == "jnz":
                    new_cmd = "cpy"
                else:
                    new_cmd = "jnz"
            try:
                cmd_list[i][0] = new_cmd
            except IndexError:
                pass
    return pos, regs, cmd_list


def run(filename="input.txt"):
    if filename.endswith("input.txt"):
        regs = {'a':7, 'b':0, 'c':0, 'd':0}
    else:
        regs = {'a':0, 'b':0, 'c':0, 'd':0}
    with open(filename) as f:
        cmd_list = []
        for line in f:
            data = line.strip().split(" ")
            cmd_list.append([data[0], data[1:]])
    pos = 0
    count = 0
    while pos < len(cmd_list):
        if int(count%1) == 0:
            sleep(2)
            os.system('clear')
            print(regs)
            for cmd,i in zip(cmd_list, range(len(cmd_list))):
                if i == pos:
                    print("%s <--" %cmd)
                else:
                    print("%s" %cmd)
            print('------------')
        pos, regs, cmd_list = process(regs, pos, cmd_list)
        pos += 1
        count += 1
    return regs['a']

if __name__ == "__main__":
    print(run())
