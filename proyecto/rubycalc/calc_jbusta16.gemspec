
Gem::Specification.new do |s|
  s.name    = 'calc_jbusta16'
  s.version = '0.2.6'
  s.date    = '2015-11-13'
  s.summary = 'Another calculator in ruby'
  s.description = 'An calculator implementation on ruby'
  s.author  = 'Kent D. Lee - Juan Francisco Cardona Mc - Josue Daniel Bustamante'
  s.email   = 'j@coderise.org'
  s.homepage = 'http://github.com/JosueDanielBust/rubycalc'
  s.files    = ["lib/token.rb",
                "lib/scanner.rb",
                "lib/ast.rb",
                "lib/parser.rb",
                "lib/calculator.rb",
                "lib/calcex.rb"]
  s.license  = 'ARTISTIC'
  s.executables << 'calcex'
end
