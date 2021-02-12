import os
from os.path import isfile, join onlyfileslist= [ f for os.listdir(".") if os.path.isfile(os.path.join(".",f))]
for x in onlyfileslist
	a = x.replace("Hello there ", "Hi you, " )
	os.rename(x,a)
