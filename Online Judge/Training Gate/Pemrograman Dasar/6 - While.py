from sys import stdin
lines = []
for line in stdin:
    print(line,end='')
    #this is because it will automatically have an '\n' at the end
    """
    lines.append(line.replace('\n',''))
    this is how you make it into a list
    """
#print("\n".join(lines))
