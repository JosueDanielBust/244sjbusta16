require 'parser'
require 'ast'

class Calculator
  attr_reader :memory
  attr_writer :memory
  
  def initialize()
    @memory = 0
    @useEnvVars = false
    @setEnvVars = false
    @createVar = false
    @lastCreateKey = ''
    @varsEnv = Hash.new()
    @vars = Hash.new()
  end
  
  def eval(expr)
    parser = Parser.new(StringIO.new(expr))
    ast = parser.parse()
    return ast.evaluate()
  end

  def set(key, value)
    if @setEnvVars == true then
      @varsEnv.store(key, value)
    else
      @vars.store(key, value)
    end
    @createVar = true;
    @lastCreateKey = key
  end

  def get(keyToGet)
    if @useEnvVars == true && isEnvVar(key) == true then
      @varsEnv.each {|key, val| if keyToGet == key then return val end }
    else
      @vars.each {|key, val| if keyToGet == key then return val end }
    end
    return 0
  end
  
  def isEnvVar(key)
    if @varsEnv.has_key?(key) == true then
      return true
    else
      return false
    end
  end

  def envConf
    @useEnvVars = true
  end

  def changeSetEnvVars(bool)
    @setEnvVars = bool
  end

  def printVar
    result = ''
    if @createVar == true then
      result = " [ #{@lastCreateKey} <- #{get(@lastCreateKey)} ]"
      @createVar = false
    end
    return result
  end
end
