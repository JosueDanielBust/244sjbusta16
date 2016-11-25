require 'set'

class BinaryNode
  attr_reader :left, :right
  
  def initialize(left,right)
    @left = left
    @right = right
  end
end
   
class UnaryNode
  attr_reader :subTree
   
  def initialize(subTree)
    @subTree = subTree
  end
end

class AddNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate
    return @left.evaluate() + @right.evaluate()
  end
end

class SubNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate
    return @left.evaluate() - @right.evaluate()
  end
end

class TimesNode < BinaryNode
  def initialize(left, right)
    super(left, right)
  end

  def evaluate
    left.evaluate * right.evaluate
  end
end

class DivideNode < BinaryNode
  def initialize(left, right)
    super(left, right)
  end
  
  def evaluate
    left.evaluate / right.evaluate
  end
end

class ModNode < BinaryNode
  def initialize(left, right)
    super(left, right)
  end

  def evaluate
    left.evaluate % right.evaluate
  end
end

class StoreNode < UnaryNode
  def initialize(sub)
    super(sub)
  end

  def evaluate
    $calc.memory = subTree.evaluate
  end
end

class RecallNode
  def evaluate
    $calc.memory
  end
end

class NumNode
  def initialize(num)
    @num = num
  end
   
  def evaluate
    return @num
  end
end

class PlusNode < UnaryNode
  def initialize(sub)
    super(sub)
  end

  def evaluate
    valc = $calc.memory + subTree.evaluate
    $calc.memory = valc
    return valc
  end
end

class MinusNode < UnaryNode
  def initialize(sub)
    super(sub)
  end

  def evaluate
    valc = $calc.memory - subTree.evaluate
    $calc.memory = valc
    return valc
  end
end

class ClearNode
  def evaluate
    valc = 0
    $calc.memory = valc
    return valc
  end
end

class SetNode < UnaryNode
  def initialize(sub, key)
    super(sub)
    @key = key
  end

  def evaluate
    val = subTree.evaluate
    $calc.set(@key, val)
    return val
  end
end

class GetNode
  def initialize(key)
    @key = key
  end

  def evaluate
    return $calc.get(@key)
  end
end
