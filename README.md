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
##### GCC
```gcc main.c lib/rms.c -Ilib  -o rms```
##### CMAKE
```cmake path/to/rms/folder && make```

If file does happen to be recovered, the only data recovered will be garbage.
