f = open ("selfOutput.py")
try:
	for line in f:
		print line;
finally:
	f.close()