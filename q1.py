def group_by_owners(files):
    D = {}
    for (file_name, owner) in files.items():
        if owner in D:
            D[owner].append( file_name )
        else :
            D[owner] = [file_name]
    return D


files = {
    'Input.txt': 'Randy',
    'Code.py': 'Stan',
    'Output.txt': 'Randy'
}   
print(group_by_owners(files))
