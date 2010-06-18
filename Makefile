default:
	python scons/scons.py

clean:
	python scons/scons.py -c

%:
	python scons/scons.py $@
