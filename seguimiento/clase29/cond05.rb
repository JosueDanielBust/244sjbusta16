#!/usr/bin/ruby
# fichero: cond05.rb
#
# proposito: mostrar valores que son considerados verdaderos y falso
#

# Cualquier valor diferente de nil y de false son considerados verdaderos

def cond05
  s = true
  puts "s: #{s} es verdadero" if s

  s = 10.23

  puts "s: #{s} es considerado verdadero" if s

  s = "Hola Mundo"

  puts "s: #{s} es considerado verdadero" if s
end

# filename: cond05.rb
