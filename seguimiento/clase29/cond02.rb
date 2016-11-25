#!/usr/bin/ruby
# fichero: cond02.rb
#
# proposito: mostrar otros tipos de condiciones
#

def cond02
  s = gets.chomp
  v = s.to_i

  unless v == 10 then
    puts "v: #{v} es diferente de 10"
  end
end
# filename: cond02.rb
