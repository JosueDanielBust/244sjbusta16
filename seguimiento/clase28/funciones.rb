# Comentarios

def echo()
  s = gets
  puts s
end

def echo2
  s = gets
  puts s
  s.chomp
end

def suma(a,b)
  a + b
end

def suma2 a,b
  return a + b
end

$count = 0
def genNroCons
  $count += 1
end
