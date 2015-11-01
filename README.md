# RMS (RM Secure)

[![Build Status](https://travis-ci.org/lostlevels/rms.svg)](https://travis-ci.org/lostlevels/rms)

### Securely delete files!

###    Syntax:
	rms 'path to file to delete'
	rms -rf 'path to folder to delete'

###    How it works:
	1. Opens the file to be delete
	2. Overwrite file content with garbage
	3. Save the file
	4. Then unlink the file

###    Building
##### with only GCC
```gcc main.c lib/rms.c -Ilib  -o rms```
##### with CMAKE
```cmake path/to/rms/folder && make```

If file does happen to be recovered, the only data recovered will be garbage.

### File Deletion Times
	- Deleting a file of size 1M: 0.017 seconds
	- Deleting a file of size 100M: 1.190 seconds
	- Deleting a file of size 1G: 12.018 seconds