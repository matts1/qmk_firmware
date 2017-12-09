import re

out = open("formatted.c", "w")
layout = """
// Left hand
.......
.......
......
.......
.....

// Left Thumb Cluster
+..
++.
...

// Right hand
.......
.......
+......
.......
++.....

// Right Thumb Cluster
..+
.++
...
""".rstrip().replace("\n", "\n    ")

SIZE = 15


for line in open("keymap.c"):
    if "KEYMAP(" in line:
        start, keys = re.match("(.* = KEYMAP\()(.*)\),$", line).groups()
        keys = keys.split(",")
        assert len(keys) == 76
        assert layout.count(".") == 76

        upto = 0
        out.write(start + '\n')
        for c in layout:
            if c == '+':
                out.write(' ' * SIZE)
            elif c == '.':
                out.write((keys[upto] + ",").ljust(SIZE))
                upto += 1
            else:
                out.write(c)

        out.write("\n  )\n")
    else:
        out.write(line)

out.close()
