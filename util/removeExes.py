import os

def removeExes(folder_path):
    for file in os.listdir(folder_path):
        if os.path.isdir(os.path.join(folder_path,file)):
            removeExes(os.path.join(folder_path,file))
        elif file.replace('.exe','`')[-1]=='`':
            os.remove(os.path.join(folder_path,file))

removeExes(".")