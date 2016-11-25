require 'ast'
require 'scanner'
require 'token'
require 'calcex'

class Parser
  def initialize(istream)
    @scan = Scanner.new(istream)
  end
  
  def parse
    Prog()
  end
  
  private
  def Prog
    result = Expr()
    t = @scan.getToken
    if t.type != :eof then
      print "Expected EOF. Found ", t.type, ".\n"
      raise ParseError.new
    end
    
    result
  end
  
  def Expr
    RestExpr(Term())
  end
  
  def RestExpr(e) 
    t = @scan.getToken
    
    if t.type == :add then
      return RestExpr(AddNode.new(e,Term()))
    end
    
    if t.type == :sub then
      return RestExpr(SubNode.new(e,Term()))
    end
    
    @scan.putBackToken
    
    e
  end
  
  def Term
    RestTerm(Storable())
  end
  
  def RestTerm(e)
    t = @scan.getToken

    if t.type == :times then
      return RestTerm(TimesNode.new(e,Storable()))
    end

    if t.type == :divide then
      return RestTerm(DivideNode.new(e,Storable()))
    end

    if t.type == :mod then
      return RestTerm(ModNode.new(e,Storable()))
    end

    @scan.putBackToken

    e
  end

  def Storable
    MemOperation(Factor())
  end
  
  def MemOperation(e)
    t = @scan.getToken

    if t.type == :keyword
      if t.lex == "S"
        return StoreNode.new(e)
      end

      if t.lex == 'P'
        return PlusNode.new(e)
      end

      if t.lex == 'M'
        return MinusNode.new(e)
      end
      
      puts "We found an error on MemOperation #{t.lex}"
      print " at line #{t.line} col: #{t.col}"
      raise ParseError.new
    end

    @scan.putBackToken

    e
  end
  
  def Factor
    t = @scan.getToken

    if t.type == :number
      return NumNode.new(t.lex.to_i)
    end

    if t.type == :keyword
      if t.lex == 'R'
        return RecallNode.new
      end

      if t.lex == 'C'
        return ClearNode.new
      end
      puts "We found an error on Factor::keyword"
      raise ParseError.new
    end
    
    if t.type == :lparen
      result = Expr()
      t = @scan.getToken
      if t.type == :rparen
        return result
      end
      puts "We found an error on Factor::rparen"
      print " at line #{t.line} col: #{t.col}"
      raise ParseError.new
    end
    
    if t.type == :identifier
      Assignable(t.lex)
    end
  end
  
  def Assignable(key)
    t = @scan.getToken
    if t.type == :assign
      return Assign(key)
    end

    @scan.putBackToken

    return GetNode.new(key)
  end

  def Assign(key)
    return SetNode.new(Expr(), key)
  end
end
