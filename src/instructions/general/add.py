"""add.py - S/360, S/370, S/390, and z/Architecture ADD instructions"""

import z.formats

# Register-and-register formats:

class AR(z.formats.RRFormat):
  """
  The second operand is added to the first operand, and the sum is 
  placed at the first operand location. The operands and the sum
  are treated as 32-bit signed binary integers.
  """
  def __init__(self, *args, **kwargs):
    super().__init__(0x1A, *args, **kwargs)

# Register-and-storage formats:

class A(z.formats.RXFormat):
  """
  The second operand is added to the first operand, and the sum is 
  placed at the first operand location. The operands and the sum
  are treated as 32-bit signed binary integers.
  """
  def __init__(self, *args, **kwargs):
    super().__init__(0x5A, *args, **kwargs)
