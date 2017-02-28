def propagate(n):
    past = range(1, n+1, 2)
    nxt = []
    i = 1
    while len(past) > 1:
        nxt = past[i::2]
        i = abs(i-len(past)%2)
        past = nxt
    return past[0]

def run(input=3004953):
    return propagate(3004953)

if __name__ == "__main__":
    print(run())
