"""add_halfword.py - S/360, S/370, S/390, and z/Architecture ADD HALFWORD instructions"""

import z.formats

# Register-and-storage formats:

class AH(z.formats.RXFormat):
  """
  The second operand is added to the first operand, and the sum is 
  placed at the first operand location. The first operand and the
  sum are treated as 32-bit signed binary integers. The second
  operand is two bytes in length and is treated as a 16-bit signed
  binary integer.
  """
  def __init__(self, *args, **kwargs):
    super().__init__(0x4A, *args, **kwargs)
