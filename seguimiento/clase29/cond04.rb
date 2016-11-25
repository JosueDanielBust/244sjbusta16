#!/usr/bin/ruby
# fichero: cond04.rb
#
# proposito: mostrar valores que son considerados falso y otras
#            formas de condicional
#

def cond04
  s = nil

  puts "s: #{s} es falso" unless s

  s = false

  print "s: #{s} es considerado falso" unless s
end

# filename: cond04.rb
