cheatsheet: cheatsheet.cxx aliases.cxx
	g++ -o cheatsheet cheatsheet.cxx aliases.cxx
	# check if this exists!
	cp cheatsheet ~/.local/bin/cheatsheet
	
clean:
	rm cheatsheet
