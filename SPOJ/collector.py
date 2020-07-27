import os, sys

README = "README.md"
CODES = "codes"

RENEW = """# SPOJ_Solution
Program codes for a wide range of SPOJ problems

## PROBLEMS ({})
"""

if __name__ == '__main__':

    files = [file.split('.')[0] for file in os.listdir(CODES)]
    files.sort()
    with open(README,"w") as op:
        op.write(RENEW.format(len(files)))
        for file in files:
            op.write("- {}\n".format(file))