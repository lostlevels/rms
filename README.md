# RMS (RM Secure)
Securely delete files!

###    Syntax:
	rms 'path to file to delete'

###    How it works:
	1. Opens the file to be delete
	2. Overwrite file content with garbage
	3. Save the file
	4. Then unlink the file

###    Building (OS X)
    gcc main.c -o rms

###	Building (Linux)
	Install Dependencies
		sudo apt-get install libbsd-dev

	gcc -lbsd main.c -o rms


If file does happen to be recovered, the only data recovered will be garbage.
