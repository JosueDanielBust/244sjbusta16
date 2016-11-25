all: main

clean:
	rm -f Makefile~
	rm -f *.gemspec~
	rm -f lib/*.rb~
	rm -f bin/calcex~

rmgem:
	rm -f calc_jbusta16-0.*.*.gem

gembuild:
	gem build calc_jbusta16.gemspec

main:
	rm -f calc_jbusta16-0.*.*.gem
	gem build calc_jbusta16.gemspec
	gem install calc_jbusta16-0.*.*.gem
	calcex -v a=2 -v b=10 -v c=a+b

push:
	gem build calc_jbusta16.gemspec
	gem push calc_jbusta16-0.*.*.gem
