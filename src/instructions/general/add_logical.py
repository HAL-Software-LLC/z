"""add_logical.py - z/Architecture ADD LOGICAL instructions"""

import z.formats

# Register-and-register formats:

class ALR(z.formats.RRFormat):
  """
  The second operand is added to the first operand, and the sum is 
  placed at the first operand location. The oeprands and the sum
  are treated as 32-bit unsigned binary integers.
  """
  def __init__(self, *args, **kwargs):
    super().__init__(0x1E, *args, **kwargs)

# Register-and-storage formats:

class AL(z.formats.RXFormat):
  """
  The second operand is added to the first operand, and the sum is 
  placed at the first operand location. The operands and the sum
  are treated as 32-bit unsigned binary integers.
  """
  def __init__(self, *args, **kwargs):
    super().__init__(0x5E, *args, **kwargs)
