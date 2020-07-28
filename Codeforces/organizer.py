import requests as rq
import os, sys
from time import sleep

CUR = os.path.join("/", "home", "thelethalcode", "Programming", "CP", "Codeforces")
README = os.path.join(CUR, "README.md")
CODES = os.path.join(CUR, "codes")

RENEW = """# Codeforces Solution
Program codes for a wide range of Codeforces problem (constantly updating)

## PROBLEMS ({})
"""

# Key function for sorting
def sort_key(elem):
    return "{:05d}{}".format(elem[0],elem[1])


# Clear Readme file
def clear_readme(num):
    with open(README,"w") as op:
        op.write(RENEW.format(num))


# Find the problems already present in the readme file 
def alread_present():

    problems = []
    with open(README, "r") as op:
        for item in op.readlines():
            if item[0]=='-':
                ind = item.find(":")
                a, b = item[4:ind].split("-")
                problems.append(a+b+".cpp")
    return problems


# Find the name of the the problem corresponding to the code
def find_name(prob):

    baseURL = "https://codeforces.com/problemset/problem/"
    START = "<div class=\"title\">"
    END = "</div>"

    URL = baseURL + prob[0]+"/"+prob[1]
    request = rq.get(URL)
    page = request.text
    ind = page.find(START)
    page = page[ind+len(START)+2:]
    ind = page.find(END)
    name = page[:ind].strip()
    if name[0] == '.':
        name = name[1:].strip()
    return name


# Append names
def append_name(prob, name):
    
    with open(README, "a+") as op:
        op.write("- **{}-{}:** {}\n".format(prob[0], prob[1], name))


# Find names of new problems and append it to readme
def find_names(files):
    
    for file in files:
        for ind, el in enumerate(file):
            if not el.isdigit():
                item = (file[:ind], file[ind:])
                name = find_name(item)
                append_name(item, name)
                print("- {}-{}: {}".format(item[0], item[1], name))
                break
    

# Sort the problems in the readme
def sort_readme():
    
    problems = []
    with open(README) as op:
        for item in op.readlines():
            if item[0]=='-':
                ind = item.find(":")
                a, b = item[4:ind].split("-")
                c = item[ind+4:-1]
                problems.append((int(a), b, c))

    problems.sort(key=sort_key)
    clear_readme(len(problems))
    
    for problem in problems:
        append_name((problem[0], problem[1]), problem[2])


if __name__ == '__main__':
    
    # Rewrite readme if given the option
    if len(sys.argv) == 2:
        if sys.argv[1] == "clear":
            clear_readme(0)
    
    # Find Names of already present problem in readme
    prev = alread_present()

    # Get the new problems to update
    files = [it[:-4] for it in os.listdir(CODES) if (".cpp" in it) and (it not in prev)]
    find_names(files) # Update readme
    sort_readme()

    # Move the problems to their directories
    for file in os.listdir(CODES):
        if ".cpp" in file:
            for ind, el in enumerate(file):
                if not el.isdigit():
                    item = file[:ind]
                    if not os.path.exists(os.path.join(CODES, item)):
                        os.mkdir(os.path.join(CODES, item))
                    os.rename(os.path.join(CODES, file), os.path.join(CODES, item, file))
                    break
    
