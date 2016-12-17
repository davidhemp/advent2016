import re

rgx = "(123|abc)"
string = "testd123abcta123nvdoa"

match = re.findall(rgx, string)
print(match)
