import os
root='.'
dirlist = [ item for item in os.listdir(root) ]
for item in dirlist:
	print(item)