all:
	python scons/scons.py -Q

clean:
	python scons/scons.py -Qc
	rm -f tags

TAGS:
	rm -rf .tags* tags
	python scons/scons.py -Q tags

i:
	gnome-terminal -e "vim -n -c make"

%:
	python scons/scons.py -Q $@
