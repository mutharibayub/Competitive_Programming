import os

for file in os.listdir("."):
    if file.replace('.exe','`')[-1]=='`':
        os.remove(file)
